// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/sysapps/iotivity/iotivity_eleven_object.h"
#include "xwalk/sysapps/iotivity/iotivity_eleven.h" // generated
#include "xwalk/sysapps/iotivity/iotivity_conversions.h"
#include "xwalk/sysapps/iotivity/iotivity_eleven_callback_context.h"

/*****************************************************************************\
|*  C A L L B A C K S                                                        *|
\*****************************************************************************/

static OCStackApplicationResult defaultOCClientResponseHandler(
    void* context, OCDoHandle handle, OCClientResponse* clientResponse)
{
    using xwalk::sysapps::IotivityElevenCallbackContext;
    using xwalk::sysapps::IotivityElevenObject;
    using xwalk::sysapps::IotivityConversions;

    IotivityElevenCallbackContext* cbContext = (IotivityElevenCallbackContext*) context;
    IotivityElevenObject* ie = cbContext->getIotivityElevenObject();
    int callbackId = cbContext->getCallbackId();

    scoped_ptr<base::ListValue> eventData(new base::ListValue);
    scoped_ptr<base::ListValue> content(new base::ListValue);

    content->AppendInteger(callbackId);
    content->AppendInteger(ie->AppendHandle(handle));
    content->Append(IotivityConversions::c2js_OCClientResponse(*clientResponse).get()->ToValue());

    eventData->Append(content.release());

    ie->DispatchEvent("callback", eventData.Pass());

    delete cbContext;

    return OC_STACK_DELETE_TRANSACTION;
}

using namespace xwalk::jsapi::iotivity_eleven;

namespace xwalk {
namespace sysapps {

/*****************************************************************************\
|*  M A I N   O B J E C T                                                    *|
\*****************************************************************************/

IotivityElevenObject::IotivityElevenObject(IotivityInstance* instance)
    : instance_(instance)
{
    RegisterHandlers();
}

IotivityElevenObject::~IotivityElevenObject() {}

void IotivityElevenObject::RegisterHandlers() {
    handler_.Register("_OCInit",
        base::Bind(&IotivityElevenObject::OnOCInit, base::Unretained(this)));
    handler_.Register("_OCStop",
        base::Bind(&IotivityElevenObject::OnOCStop, base::Unretained(this)));
    handler_.Register("_OCProcess",
        base::Bind(&IotivityElevenObject::OnOCProcess, base::Unretained(this)));
    handler_.Register("_OCDoResource",
        base::Bind(&IotivityElevenObject::OnOCDoResource, base::Unretained(this)));
}

void IotivityElevenObject::OnOCInit(scoped_ptr<XWalkExtensionFunctionInfo> info) {
    scoped_ptr<EOCInit::Params>
        params(EOCInit::Params::Create(*info->arguments()));
    if (!params) {
        LOG(WARNING) << "Malformed parameters passed to " << info->name();
        return;
    }

    OCStackResult stackResult = OCInit(params->ip.c_str(), params->port,
        IotivityConversions::js2c_OCMode(params->mode));

    scoped_ptr<base::ListValue> result(new base::ListValue());
    result->AppendInteger(stackResult);
    info->PostResult(result.Pass());
}

void IotivityElevenObject::OnOCStop(scoped_ptr<XWalkExtensionFunctionInfo> info) {
    OCStackResult stackResult = OCStop();

    scoped_ptr<base::ListValue> result(new base::ListValue());
    result->AppendInteger(stackResult);
    info->PostResult(result.Pass());
}

void IotivityElevenObject::OnOCProcess(scoped_ptr<XWalkExtensionFunctionInfo> info) {
    OCStackResult stackResult = OCProcess();

    scoped_ptr<base::ListValue> result(new base::ListValue());
    result->AppendInteger(stackResult);
    info->PostResult(result.Pass());
}

void IotivityElevenObject::OnOCDoResource(scoped_ptr<XWalkExtensionFunctionInfo> info) {
    scoped_ptr<EOCDoResource::Params> params;
    OCDoHandle * handle;
    OCMethod method;
    const char * requestUri;
    OCDevAddr * destination;
    OCPayload * payload;
    OCConnectivityType connectivityType;
    OCQualityOfService qos;
    OCCallbackData * cbData;
    OCHeaderOption * options;
    uint8_t numOptions;

    params = EOCDoResource::Params::Create(*info->arguments());
    if (!params) {
        LOG(WARNING) << "Malformed parameters passed to " << info->name();
        return;
    }

    handle = NULL;
    method = IotivityConversions::js2c_OCMethod(params->method);
    requestUri = params->request_uri.c_str();
    destination = NULL;
    payload = NULL;
    connectivityType = IotivityConversions::js2c_OCConnectivityType(params->connectivity_type);
    qos = IotivityConversions::js2c_OCQualityOfService(params->qos);
    cbData = (OCCallbackData *) malloc(sizeof (OCCallbackData));
    options = NULL;

    if (!params->destination.ToValue()->empty()) {
        destination = (OCDevAddr *) malloc(sizeof (OCDevAddr));
        OCIdentity identity;
        if (params->destination.identity && params->destination.identity->id) {
            identity.id_length = params->destination.identity->id->length();
            strncpy((char *) identity.id, params->destination.identity->id->c_str(), 32);
        }

        destination->adapter = IotivityConversions::js2c_OCTransportAdapter(params->destination.adapter);
        destination->flags = IotivityConversions::js2c_OCTransportFlags(params->destination.flags);
        if (params->destination.addr) {
            strncpy(destination->addr, params->destination.addr->c_str(), 40);
        }
        if (params->destination.iface) {
            destination->interface = *params->destination.iface;
        }
        if (params->destination.port) {
            destination->port = *params->destination.port;
        }
        destination->identity = identity;
    }

    if (!params->payload.ToValue()->empty()) {
        payload = (OCPayload *) malloc(sizeof (OCPayload));
        // TODO: do payload
    }

    if (!params->options.ToValue()->empty()) {
        options = (OCHeaderOption *) malloc(sizeof (OCHeaderOption));
        // TODO: do options
    }

    cbData->context = new IotivityElevenCallbackContext(this, params->callback_id);
    cbData->cb = defaultOCClientResponseHandler;
    cbData->cd = NULL; // TODO

    OCStackResult stackResult = OCDoResource(
        handle, method, requestUri, destination, payload, connectivityType,
        qos, cbData, options, numOptions);

    if (destination) {
        free(destination->addr);
        free(destination);
    }
    free(payload);
    free(cbData);
    free(options);

    scoped_ptr<base::ListValue> result(new base::ListValue());
    result->AppendInteger(stackResult);
    info->PostResult(result.Pass());
}

size_t IotivityElevenObject::AppendHandle(OCDoHandle handle) {
    doHandles_.push_back(handle);
    return doHandles_.size() - 1;
}

}  // namespace sysapps
}  // namespace xwalk
