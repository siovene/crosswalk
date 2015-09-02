// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var v8tools = requireNative('v8tools');

var internal = requireNative('internal');
internal.setupInternalExtension(extension);

var common = requireNative('sysapps_common');
common.setupSysAppsCommon(internal, v8tools);

// IotivityEleven interface.
// IotivityEleven is 1:1 mapping to the Iotivity C SDK.
// 1:1... 11... Eleven, get it?
var IotivityEleven = function(object_id) {
  common.BindingObject.call(this, object_id ? object_id : common.getUniqueId());
  common.EventTarget.call(this);

  if (object_id == undefined)
    internal.postMessage("IotivityElevenConstructor", [this._id]);

  this._addMethod("OCInit");
  this._addMethod("OCStop");
  this._addMethod("OCProcess");
};

IotivityEleven.prototype = new common.EventTargetPrototype();
IotivityEleven.prototype.constructor = IotivityEleven;

// Exported API.
exports.IotivityEleven = IotivityEleven;
