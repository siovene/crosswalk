// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_SYSAPPS_IOTIVITY_CONVERSIONS_H_
#define XWALK_SYSAPPS_IOTIVITY_CONVERSIONS_H_

#include "xwalk/sysapps/iotivity/iotivity_eleven.h" // generated

extern "C" {
    #include "octypes.h"
}

namespace xwalk {
namespace sysapps {

using xwalk::jsapi::iotivity_eleven::EOCMode;

class IotivityConversions {
    public:
        static OCMode InternalToOCMode(EOCMode mode);
};

} // namespace sysapps
} // namespace xwalk

#endif // XWALK_SYSAPPS_IOTIVITY_CONVERSIONS_H_
