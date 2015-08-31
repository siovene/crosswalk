// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/sysapps/iotivity/iotivity_eleven_object.h"
#include "xwalk/sysapps/iotivity/iotivity_eleven.h" // generated
#include "xwalk/sysapps/iotivity/iotivity_conversions.h"

extern "C" {
    #include "ocstack.h"
}

using namespace xwalk::jsapi::iotivity_eleven;

namespace xwalk {
namespace sysapps {

IotivityElevenObject::IotivityElevenObject(IotivityInstance* instance)
    : instance_(instance)
{
    RegisterHandlers();
}

IotivityElevenObject::~IotivityElevenObject() {}

void IotivityElevenObject::RegisterHandlers() {
    handler_.Register("OCInit",
        base::Bind(&IotivityElevenObject::OnOCInit, base::Unretained(this)));
    handler_.Register("OCStop",
        base::Bind(&IotivityElevenObject::OnOCStop, base::Unretained(this)));
}

void IotivityElevenObject::OnOCInit(scoped_ptr<XWalkExtensionFunctionInfo> info) {
    scoped_ptr<EOCInit::Params>
        params(EOCInit::Params::Create(*info->arguments()));
    if (!params) {
        LOG(WARNING) << "Malformed parameters passed to " << info->name();
        return;
    }

    OCInit(params->ip.c_str(), params->port,
        IotivityConversions::InternalToOCMode(params->mode));
}

void IotivityElevenObject::OnOCStop(scoped_ptr<XWalkExtensionFunctionInfo> info) {
    OCStop();
}

}  // namespace sysapps
}  // namespace xwalk
