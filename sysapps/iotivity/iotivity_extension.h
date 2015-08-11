// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_SYSAPPS_IOTIVITY_EXTENSION_H_
#define XWALK_SYSAPPS_IOTIVITY_EXTENSION_H_

#include <string>
#include "base/values.h"
#include "xwalk/sysapps/common/binding_object_store.h"

namespace xwalk {
namespace sysapps {

using extensions::XWalkExtension;
using extensions::XWalkExtensionInstance;
using extensions::XWalkExtensionFunctionInfo;
using extensions::XWalkExtensionFunctionHandler;


class IotivityExtension : public XWalkExtension {
    public:
        IotivityExtension();
        ~IotivityExtension() override;

        XWalkExtensionInstance* CreateInstance() override;
};

class IotivityInstance : public XWalkExtensionInstance {
    public:
        IotivityInstance();

        void HandleMessage(scoped_ptr<base::Value> msg) override;
        void AddBindingObject(const std::string& object_id,
                              scoped_ptr<BindingObject> obj);

    private:
        void OnOicResourceConstructor(
            scoped_ptr<XWalkExtensionFunctionInfo> info);

        XWalkExtensionFunctionHandler handler_;
        BindingObjectStore store_;
};

} // namespace sysapps
} // namespace xwalk

#endif // XWALK_SYSAPPS_IOTIVITY_EXTENSION_H_
