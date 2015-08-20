// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_SYSAPPS_IOTIVITY_OIC_RESOURCE_OBJECT_H_
#define XWALK_SYSAPPS_IOTIVITY_OIC_RESOURCE_OBJECT_H_

#include "xwalk/sysapps/iotivity/iotivity_extension.h"
#include "xwalk/sysapps/common/event_target.h"

namespace xwalk {
namespace sysapps {

class BindingObjectStore;

class OicResourceObject : public EventTarget{
    public:
        explicit OicResourceObject(IotivityInstance* instance);
        ~OicResourceObject();

    private:
        void RegisterHandlers();

        IotivityInstance* instance_;
};

}  // namespace sysapps
}  // namespace xwalk

#endif  // XWALK_SYSAPPS_IOTIVITY_OIC_RESOURCE_OBJECT_H_
