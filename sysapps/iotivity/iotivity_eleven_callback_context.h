// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_SYSAPPS_IOTIVITY_IOTIVITY_ELEVEN_CALLBACK_CONTEXT_H_
#define XWALK_SYSAPPS_IOTIVITY_IOTIVITY_ELEVEN_CALLBACK_CONTEXT_H_

#include "xwalk/sysapps/iotivity/iotivity_eleven_object.h"

namespace xwalk {
namespace sysapps {

class IotivityElevenCallbackContext {
    public:
        IotivityElevenCallbackContext(IotivityElevenObject* ie, int callbackId);
        ~IotivityElevenCallbackContext();

        IotivityElevenObject* getIotivityElevenObject() const;
        int getCallbackId() const;

        void setIotivityElevenObject(IotivityElevenObject * ie);
        void setCallbackId(int callbackId);

    private:
        IotivityElevenObject * _ie;
        int _callbackId;
};

}  // namespace sysapps
}  // namespace xwalk

#endif  // XWALK_SYSAPPS_IOTIVITY_IOTIVITY_ELEVEN_CALLBACK_CONTEXT_H_
