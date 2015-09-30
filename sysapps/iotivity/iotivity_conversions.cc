// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/sysapps/iotivity/iotivity_conversions.h"

namespace xwalk {
namespace sysapps {

/*****************************************************************************\
|*  ENUMS: JS TO C.                                                          *|
\*****************************************************************************/

OCMode IotivityConversions::js2c_OCMode(const EOCMode mode) {
    switch (mode) {
        case EOCMode::E_OC_MODE_OC_CLIENT: return OC_CLIENT;
        case EOCMode::E_OC_MODE_OC_SERVER: return OC_SERVER;
        case EOCMode::E_OC_MODE_OC_CLIENT_SERVER: default: return OC_CLIENT_SERVER;
    };
}

OCMethod IotivityConversions::js2c_OCMethod(const EOCMethod method) {
    switch (method) {
        case EOCMethod::E_OC_METHOD_OC_REST_GET: return OC_REST_GET;
        case EOCMethod::E_OC_METHOD_OC_REST_PUT: return OC_REST_PUT;
        case EOCMethod::E_OC_METHOD_OC_REST_POST: return OC_REST_POST;
        case EOCMethod::E_OC_METHOD_OC_REST_DELETE: return OC_REST_DELETE;
        case EOCMethod::E_OC_METHOD_OC_REST_OBSERVE: return OC_REST_OBSERVE;
        case EOCMethod::E_OC_METHOD_OC_REST_OBSERVE_ALL: return OC_REST_OBSERVE_ALL;
        case EOCMethod::E_OC_METHOD_OC_REST_CANCEL_OBSERVE: return OC_REST_CANCEL_OBSERVE;
        case EOCMethod::E_OC_METHOD_OC_REST_PRESENCE: return OC_REST_PRESENCE;
        case EOCMethod::E_OC_METHOD_OC_REST_DISCOVER: return OC_REST_DISCOVER;
        case EOCMethod::E_OC_METHOD_OC_REST_NOMETHOD: default: return OC_REST_NOMETHOD;
    };
}

OCConnectivityType IotivityConversions::js2c_OCConnectivityType(const EOCConnectivityType ct) {
    switch (ct) {
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_IP: return CT_ADAPTER_IP;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_GATT_BTLE: return CT_ADAPTER_GATT_BTLE;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_RFCOMM_BTEDR: return CT_ADAPTER_RFCOMM_BTEDR;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_REMOTE_ACCESS: return (OCConnectivityType) (1 << 13);
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_SHIFT: return (OCConnectivityType) CT_ADAPTER_SHIFT;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_IP_USE_V6: return CT_IP_USE_V6;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_IP_USE_V4: return CT_IP_USE_V4;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_INTERFACE: return CT_SCOPE_INTERFACE;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_LINK: return CT_SCOPE_LINK;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_REALM: return CT_SCOPE_REALM;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_ADMIN: return CT_SCOPE_ADMIN;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_SITE: return CT_SCOPE_SITE;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_ORG: return CT_SCOPE_ORG;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_GLOBAL: return CT_SCOPE_GLOBAL;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_DEFAULT: default: return CT_DEFAULT;
    };
}

OCQualityOfService IotivityConversions::js2c_OCQualityOfService(const EOCQualityOfService qos) {
    switch (qos) {
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_LOW_QOS: return OC_LOW_QOS;
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_MEDIUM_QOS: return OC_MEDIUM_QOS;
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_HIGH_QOS: return OC_HIGH_QOS;
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_NA_QOS: default: return OC_NA_QOS;
    };
}

OCTransportAdapter IotivityConversions::js2c_OCTransportAdapter(const EOCTransportAdapter ta) {
    switch (ta) {
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_IP: return OC_ADAPTER_IP;
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_GATT_BTLE: return OC_ADAPTER_GATT_BTLE;
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_RFCOMM_BTEDR: return OC_ADAPTER_RFCOMM_BTEDR;
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_REMOTE_ACCESS: return (OCTransportAdapter) (1 << 3);
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_DEFAULT_ADAPTER: default: return OC_DEFAULT_ADAPTER;
    };
}

OCTransportFlags IotivityConversions::js2c_OCTransportFlags(const EOCTransportFlags tf) {
    switch (tf) {
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_FLAG_SECURE: return OC_FLAG_SECURE;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_IP_USE_V6: return OC_IP_USE_V6;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_IP_USE_V4: return OC_IP_USE_V4;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_RESERVED1: return OC_RESERVED1;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_INTERFACE: return OC_SCOPE_INTERFACE;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_LINK: return OC_SCOPE_LINK;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_REALM: return OC_SCOPE_REALM;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_ADMIN: return OC_SCOPE_ADMIN;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_SITE: return OC_SCOPE_SITE;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_ORG: return OC_SCOPE_ORG;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_GLOBAL: return OC_SCOPE_GLOBAL;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_DEFAULT_FLAGS: default: return OC_DEFAULT_FLAGS;
    };
}

/*****************************************************************************\
|*  ENUMS: C TO JS.                                                          *|
\*****************************************************************************/

EOCTransportAdapter IotivityConversions::c2js_OCTransportAdapter(const OCTransportAdapter ta) {
    switch (ta) {
        case OC_ADAPTER_IP: return EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_IP;
        case OC_ADAPTER_GATT_BTLE: return EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_GATT_BTLE;
        case OC_ADAPTER_RFCOMM_BTEDR: return EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_RFCOMM_BTEDR;
        case (OCTransportAdapter) (1 << 3): return EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_REMOTE_ACCESS;
        case OC_DEFAULT_ADAPTER: default: return EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_DEFAULT_ADAPTER;
    };
}

EOCTransportFlags IotivityConversions::c2js_OCTransportFlags(const OCTransportFlags tf) {
    switch (tf) {
        case OC_FLAG_SECURE: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_FLAG_SECURE;
        case OC_IP_USE_V6: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_IP_USE_V6;
        case OC_IP_USE_V4: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_IP_USE_V4;
        case OC_RESERVED1: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_RESERVED1;
        case OC_SCOPE_INTERFACE: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_INTERFACE;
        case OC_SCOPE_LINK: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_LINK;
        case OC_SCOPE_REALM: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_REALM;
        case OC_SCOPE_ADMIN: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_ADMIN;
        case OC_SCOPE_SITE: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_SITE;
        case OC_SCOPE_ORG: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_ORG;
        case OC_SCOPE_GLOBAL: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_GLOBAL;
        case OC_DEFAULT_FLAGS: default: return EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_DEFAULT_FLAGS;
    };
}

EOCConnectivityType IotivityConversions::c2js_OCConnectivityType(const OCConnectivityType ct) {
    switch (ct) {
        case CT_ADAPTER_IP: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_IP;
        case CT_ADAPTER_GATT_BTLE: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_GATT_BTLE;
        case CT_ADAPTER_RFCOMM_BTEDR: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_RFCOMM_BTEDR;
        case (OCConnectivityType) (1 << 13): return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_REMOTE_ACCESS;
        case CT_ADAPTER_SHIFT: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_SHIFT;
        case CT_IP_USE_V6: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_IP_USE_V6;
        case CT_IP_USE_V4: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_IP_USE_V4;
        case CT_SCOPE_INTERFACE: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_INTERFACE;
        case CT_SCOPE_LINK: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_LINK;
        case CT_SCOPE_REALM: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_REALM;
        case CT_SCOPE_ADMIN: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_ADMIN;
        case CT_SCOPE_SITE: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_SITE;
        case CT_SCOPE_ORG: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_ORG;
        case CT_SCOPE_GLOBAL: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_GLOBAL;
        case CT_DEFAULT: default: return EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_DEFAULT;
    };
}

EOCStackResult IotivityConversions::c2js_OCStackResult(const OCStackResult sr) {
    switch (sr) {
        case OC_STACK_OK: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_OK;
        case OC_STACK_RESOURCE_CREATED: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_RESOURCE_CREATED;
        case OC_STACK_RESOURCE_DELETED: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_RESOURCE_DELETED;
        case OC_STACK_CONTINUE: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_CONTINUE;
        case OC_STACK_INVALID_URI: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_URI;
        case OC_STACK_INVALID_QUERY: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_QUERY;
        case OC_STACK_INVALID_IP: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_IP;
        case OC_STACK_INVALID_PORT: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_PORT;
        case OC_STACK_INVALID_CALLBACK: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_CALLBACK;
        case OC_STACK_INVALID_METHOD: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_METHOD;
        case OC_STACK_INVALID_PARAM: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_PARAM;
        case OC_STACK_INVALID_OBSERVE_PARAM: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_OBSERVE_PARAM;
        case OC_STACK_NO_MEMORY: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_NO_MEMORY;
        case OC_STACK_COMM_ERROR: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_COMM_ERROR;
        case OC_STACK_TIMEOUT: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_TIMEOUT;
        case OC_STACK_ADAPTER_NOT_ENABLED: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_ADAPTER_NOT_ENABLED;
        case OC_STACK_NOTIMPL: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_NOTIMPL;
        case OC_STACK_NO_RESOURCE: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_NO_RESOURCE;
        case OC_STACK_RESOURCE_ERROR: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_RESOURCE_ERROR;
        case OC_STACK_SLOW_RESOURCE: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_SLOW_RESOURCE;
        case OC_STACK_DUPLICATE_REQUEST: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_DUPLICATE_REQUEST;
        case OC_STACK_NO_OBSERVERS: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_NO_OBSERVERS;
        case OC_STACK_OBSERVER_NOT_FOUND: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_OBSERVER_NOT_FOUND;
        case OC_STACK_VIRTUAL_DO_NOT_HANDLE: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_VIRTUAL_DO_NOT_HANDLE;
        case OC_STACK_INVALID_OPTION: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_OPTION;
        case OC_STACK_MALFORMED_RESPONSE: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_MALFORMED_RESPONSE;
        case OC_STACK_PERSISTENT_BUFFER_REQUIRED: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_PERSISTENT_BUFFER_REQUIRED;
        case OC_STACK_INVALID_REQUEST_HANDLE: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_REQUEST_HANDLE;
        case OC_STACK_INVALID_DEVICE_INFO: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_DEVICE_INFO;
        case OC_STACK_INVALID_JSON: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_INVALID_JSON;
        case OC_STACK_UNAUTHORIZED_REQ: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_UNAUTHORIZED_REQ;
        case OC_STACK_PRESENCE_STOPPED: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_PRESENCE_STOPPED;
        case OC_STACK_PRESENCE_TIMEOUT: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_PRESENCE_TIMEOUT;
        case OC_STACK_PRESENCE_DO_NOT_HANDLE: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_PRESENCE_DO_NOT_HANDLE;
        case OC_STACK_ERROR: default: return EOCStackResult::E_OC_STACK_RESULT_OC_STACK_ERROR;
    };
}

EOCPayloadType IotivityConversions::c2js_OCPayloadType(const OCPayloadType t) {
    switch (t) {
        case PAYLOAD_TYPE_DISCOVERY: return EOCPayloadType::E_OC_PAYLOAD_TYPE_PAYLOAD_TYPE_DISCOVERY;
        case PAYLOAD_TYPE_DEVICE: return EOCPayloadType::E_OC_PAYLOAD_TYPE_PAYLOAD_TYPE_DEVICE;
        case PAYLOAD_TYPE_PLATFORM: return EOCPayloadType::E_OC_PAYLOAD_TYPE_PAYLOAD_TYPE_PLATFORM;
        case PAYLOAD_TYPE_REPRESENTATION: return EOCPayloadType::E_OC_PAYLOAD_TYPE_PAYLOAD_TYPE_REPRESENTATION;
        case PAYLOAD_TYPE_SECURITY: return EOCPayloadType::E_OC_PAYLOAD_TYPE_PAYLOAD_TYPE_SECURITY;
        case PAYLOAD_TYPE_PRESENCE: return EOCPayloadType::E_OC_PAYLOAD_TYPE_PAYLOAD_TYPE_PRESENCE;
        case PAYLOAD_TYPE_INVALID: default: return EOCPayloadType::E_OC_PAYLOAD_TYPE_PAYLOAD_TYPE_INVALID;
    };
}


/*****************************************************************************\
|*  DICTS: JS TO C.                                                          *|
\*****************************************************************************/

scoped_ptr<EOCIdentity> IotivityConversions::c2js_OCIdentity(const OCIdentity& id) {
    scoped_ptr<EOCIdentity> ret(new EOCIdentity);

    ret->id.reset(new std::string((const char *)id.id));

    return ret.Pass();
}

scoped_ptr<EOCDevAddr> IotivityConversions::c2js_OCDevAddr(const OCDevAddr& devAddr) {
    scoped_ptr<EOCDevAddr> ret(new EOCDevAddr);

    ret->adapter = IotivityConversions::c2js_OCTransportAdapter(devAddr.adapter);
    ret->flags = IotivityConversions::c2js_OCTransportFlags(devAddr.flags);
    ret->addr.reset(new std::string((const char*) devAddr.addr));
    ret->iface.reset(new int(devAddr.interface));
    ret->port.reset(new int(devAddr.port));
    ret->identity = IotivityConversions::c2js_OCIdentity(devAddr.identity);

    return ret.Pass();
}

scoped_ptr<EOCPayload> IotivityConversions::c2js_OCPayload(const OCPayload& payload) {
    scoped_ptr<EOCPayload> ret(new EOCPayload);

    ret->type = IotivityConversions::c2js_OCPayloadType(payload.type);

    return ret.Pass();
}

scoped_ptr<EOCClientResponse> IotivityConversions::c2js_OCClientResponse(const OCClientResponse& response) {
    scoped_ptr<EOCClientResponse> ret(new EOCClientResponse);

    ret->dev_addr = IotivityConversions::c2js_OCDevAddr(response.devAddr);
    ret->conn_type = IotivityConversions::c2js_OCConnectivityType(response.connType);
    ret->result = IotivityConversions::c2js_OCStackResult(response.result);
    ret->sequence_number.reset(new int(response.sequenceNumber));
    ret->resource_uri.reset(new std::string(response.resourceUri));
    ret->payload = IotivityConversions::c2js_OCPayload(*response.payload);

    return ret.Pass();
}

} // namespace sysapps
} // namespace xwalk

