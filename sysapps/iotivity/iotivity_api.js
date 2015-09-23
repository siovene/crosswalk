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
  var _callbacks = {},
      _nextCallbackId = 0;

  common.BindingObject.call(this, object_id ? object_id : common.getUniqueId());
  common.EventTarget.call(this);

  if (object_id == undefined)
    internal.postMessage("IotivityElevenConstructor", [this._id]);

  this._addEvent("callback");
  this.oncallback = function(event) {
    var id = event.data;
    if (_callbacks[id] !== undefined) {
      _callbacks[id]();
    }
  };

  // Methods starting with a _ have a wrapper defined below.
  this._addMethod("_OCInit", true);
  this._addMethod("OCStop", true);
  this._addMethod("OCProcess", true);
  this._addMethod("_OCDoResource", true);

  function _wrapCallback(cb) {
    _nextCallbackId += 1;
    _callbacks[_nextCallbackId] = cb;
    return _nextCallbackId;
  }

  // Wrapper functions sanitize some arguments and wrap callbacks.

  function OCInitWrapper(ip, port, mode, resultCb) {
    if (ip === null) ip = "";
    this._OCInit(ip, port, mode, resultCb);
  }

  function OCDoResourceWrapper(
      handle, method, requestUri, destination, payload, connectivityType,
      qos, options, cb, resultCb)
  {
    if (handle === null) handle = [];
    if (destination === null) destination = {};
    if (payload === null) payload = {};
    if (options === null) options = {};

    this._OCDoResource(
      handle, method, requestUri, destination, payload, connectivityType,
      qos, options, _wrapCallback(cb), resultCb);
  }

  Object.defineProperties(this, {
    "OCInit": {
      value: OCInitWrapper,
      enumerable: true
    },

    "OCDoResource": {
      value: OCDoResourceWrapper,
      enumerable: true
    }
  });
};

IotivityEleven.prototype = new common.EventTargetPrototype();
IotivityEleven.prototype.constructor = IotivityEleven;

// Exported API.
exports.IotivityEleven = IotivityEleven;
