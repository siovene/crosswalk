// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

var v8tools = requireNative('v8tools');

var internal = requireNative('internal');
internal.setupInternalExtension(extension);

var common = requireNative('sysapps_common');
common.setupSysAppsCommon(internal, v8tools);

// OicResource interface.
var OicResource = function(url, object_id) {
  common.BindingObject.call(this, object_id ? object_id : common.getUniqueId());
  common.EventTarget.call(this);

  if (object_id == undefined)
    internal.postMessage("OicResourceConstructor", [this._id]);

  Object.defineProperties(this, {
    "url": {
      value: url,
      enumerable: true,
    }
  });

  // This is needed, otherwise events like "error" can get fired before
  // we give the user a chance to register a listener.
  function delayedInitialization(obj) {
    obj._postMessage("init", [url]);
  };

  this._registerLifecycleTracker();
  setTimeout(delayedInitialization, 0, this);
};

OicResource.prototype = new common.EventTargetPrototype();
OicResource.prototype.constructor = OicResource;

// Exported API.
exports.OicResource = OicResource;
