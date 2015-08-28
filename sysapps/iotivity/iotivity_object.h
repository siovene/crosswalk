// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_SYSAPPS_IOTIVITY_IOTIVITY_OBJECT_H_
#define XWALK_SYSAPPS_IOTIVITY_IOTIVITY_OBJECT_H_

#include "xwalk/sysapps/iotivity/iotivity.h" // generated
#include "xwalk/sysapps/common/event_target.h"

namespace xwalk {
namespace sysapps {

// Base class for the objects of the Iotivity API.
class IotivityObject : public EventTarget {
 public:
  ~IotivityObject();

 protected:
  IotivityObject();
};

}  // namespace sysapps
}  // namespace xwalk

#endif  // XWALK_SYSAPPS_IOTIVITY_IOTIVITY_OBJECT_H_
