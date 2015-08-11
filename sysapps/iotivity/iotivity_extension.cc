// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/sysapps/iotivity/iotivity_extension.h"

#include "grit/xwalk_sysapps_resources.h"
#include "ui/base/resource/resource_bundle.h"
#include "xwalk/sysapps/iotivity/iotivity.h" // generated
#include "xwalk/sysapps/iotivity/oic_resource_object.h"

#include "base/logging.h"

using namespace xwalk::jsapi::iotivity;

namespace xwalk {
namespace sysapps {

IotivityExtension::IotivityExtension() {
    set_name("xwalk.experimental.iotivity");
    set_javascript_api(ResourceBundle::GetSharedInstance().GetRawDataResource(
        IDR_XWALK_SYSAPPS_IOTIVITY_API).as_string());
    LOG(INFO) << "IotivityExtension";
}

IotivityExtension::~IotivityExtension() {}

XWalkExtensionInstance* IotivityExtension::CreateInstance() {
    return new IotivityInstance();
}

IotivityInstance::IotivityInstance() : handler_(this), store_(&handler_) {
    handler_.Register(
        "OicResourceConstructor",
        base::Bind(
            &IotivityInstance::OnOicResourceConstructor,
            base::Unretained(this)));
}

void IotivityInstance::HandleMessage(scoped_ptr<base::Value> msg) {
    handler_.HandleMessage(msg.Pass());
}

void IotivityInstance::AddBindingObject(const std::string& object_id,
                                        scoped_ptr<BindingObject> obj) {
    store_.AddBindingObject(object_id, obj.Pass());
}

void IotivityInstance::OnOicResourceConstructor(
    scoped_ptr<XWalkExtensionFunctionInfo> info)
{
    scoped_ptr<OicResourceConstructor::Params>
        params(OicResourceConstructor::Params::Create(*info->arguments()));

    if (!params) {
        LOG(WARNING) << "Malformed parameters passed to " << info->name();
        return;
    }

    scoped_ptr<BindingObject> obj(new OicResourceObject(this));
    store_.AddBindingObject(params->object_id, obj.Pass());
}

}  // namespace sysapps
}  // namespace xwalk
