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

  this._addMethod("_OCInit", true);
  this._addMethod("_OCStop", true);
  this._addMethod("_OCProcess", true);
  this._addMethod("_OCDoResource", true);

  function _wrapCallback(cb) {
    _nextCallbackId += 1;
    _callbacks[_nextCallbackId] = cb;
    return _nextCallbackId;
  }

  // -------------------------------------------------------------------------\
  // Wrapper functions:                                                       |
  // -------------------------------------------------------------------------|
  //  * sanitize arguments                                                    |
  //  * wrap external callbacks to ids                                        |
  //  * wrap internal callbacks to promises                                   |
  // -------------------------------------------------------------------------/

  function OCInitWrapper(ip, port, mode, resultCb) {
    var self = this;

    if (ip === null) ip = "";

    return new Promise(function(resolve, reject) {
      self._OCInit(ip, port, mode, function(status) {
        if (status === 0) {
          resolve();
        } else {
          reject(status);
        }
      });
    });
  }

  function OCStopWrapper(resultCb) {
    var self = this;

    return new Promise(function(resolve, reject) {
      self._OCStop(function(status) {
        if (status === 0) {
          resolve();
        } else {
          reject(status);
        }
      });
    });
  }

  function OCProcessWrapper(resultCb) {
    var self = this;

    return new Promise(function(resolve, reject) {
      self._OCProcess(function(status) {
        if (status === 0) {
          resolve();
        } else {
          reject(status);
        }
      });
    });
  }

  function OCDoResourceWrapper(
      handle, method, requestUri, destination, payload, connectivityType,
      qos, options, cb, resultCb)
  {
    var self = this;

    if (handle === null) handle = [];
    if (destination === null) destination = {};
    if (payload === null) payload = {};
    if (options === null) options = {};

    return new Promise(function(resolve, reject) {
      self._OCDoResource(
        handle, method, requestUri, destination, payload, connectivityType,
        qos, options, _wrapCallback(cb), function(status) {
          if (status === 0) {
            resolve();
          } else {
            reject(status);
          }
        });
    });
  }

  Object.defineProperties(this, {
    "OCInit": {
      value: OCInitWrapper,
      enumerable: true
    },

    "OCStop": {
      value: OCStopWrapper,
      enumerable: true
    },

    "OCProcess": {
      value: OCProcessWrapper,
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
