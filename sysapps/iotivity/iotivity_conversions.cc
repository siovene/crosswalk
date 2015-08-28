// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/sysapps/iotivity/iotivity_conversions.h"

namespace xwalk {
namespace sysapps {

OCMode IotivityConversions::InternalToOCMode(EOCMode mode) {
    return OCMode::OC_CLIENT;
}

} // namespace sysapps
} // namespace xwalk

