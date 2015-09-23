// Copyright (c) 2015Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/sysapps/iotivity/iotivity_eleven_callback_context.h"

namespace xwalk {
namespace sysapps {

IotivityElevenCallbackContext::IotivityElevenCallbackContext(
    IotivityElevenObject * ie, int callbackId) : _ie(ie), _callbackId(callbackId) {}

IotivityElevenCallbackContext::~IotivityElevenCallbackContext() {}

IotivityElevenObject* IotivityElevenCallbackContext::getIotivityElevenObject() const {
    return _ie;
}

int IotivityElevenCallbackContext::getCallbackId() const {
    return _callbackId;
}

void IotivityElevenCallbackContext::setIotivityElevenObject(IotivityElevenObject * ie) {
    _ie = ie;
}

void IotivityElevenCallbackContext::setCallbackId(int callbackId) {
    _callbackId = callbackId;
}

}  // namespace sysapps
}  // namespace xwalk
