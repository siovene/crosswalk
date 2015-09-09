// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_SYSAPPS_IOTIVITY_ELEVEN_OBJECT_H_
#define XWALK_SYSAPPS_IOTIVITY_ELEVEN_OBJECT_H_

#include "xwalk/sysapps/iotivity/iotivity_extension.h"
#include "xwalk/sysapps/iotivity/iotivity_object.h"

namespace xwalk {
namespace sysapps {

class BindingObjectStore;

class IotivityElevenObject : public IotivityObject {
    public:
        explicit IotivityElevenObject(IotivityInstance* instance);
        ~IotivityElevenObject();

    private:
        void RegisterHandlers();
        void OnOCInit(scoped_ptr<XWalkExtensionFunctionInfo> info);
        void OnOCStop(scoped_ptr<XWalkExtensionFunctionInfo> info);
        void OnOCProcess(scoped_ptr<XWalkExtensionFunctionInfo> info);
        void OnOCDoResource(scoped_ptr<XWalkExtensionFunctionInfo> info);

        IotivityInstance* instance_;
};

}  // namespace sysapps
}  // namespace xwalk

#endif  // XWALK_SYSAPPS_IOTIVITY_ELEVEN_OBJECT_H_
