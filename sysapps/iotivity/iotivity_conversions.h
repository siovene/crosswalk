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
using xwalk::jsapi::iotivity_eleven::EOCMethod;
using xwalk::jsapi::iotivity_eleven::EOCConnectivityType;
using xwalk::jsapi::iotivity_eleven::EOCQualityOfService;
using xwalk::jsapi::iotivity_eleven::EOCTransportAdapter;
using xwalk::jsapi::iotivity_eleven::EOCTransportFlags;
using xwalk::jsapi::iotivity_eleven::EOCIdentity;
using xwalk::jsapi::iotivity_eleven::EOCDevAddr;
using xwalk::jsapi::iotivity_eleven::EOCClientResponse;
using xwalk::jsapi::iotivity_eleven::EOCStackResult;
using xwalk::jsapi::iotivity_eleven::EOCPayloadType;
using xwalk::jsapi::iotivity_eleven::EOCResourcePayload;
using xwalk::jsapi::iotivity_eleven::EOCDiscoveryPayload;

class IotivityConversions {
    public:
        // Enums: JS to C.
        static OCMode js2c_OCMode(const EOCMode mode);
        static OCMethod js2c_OCMethod(const EOCMethod method);
        static OCConnectivityType js2c_OCConnectivityType(const EOCConnectivityType ct);
        static OCQualityOfService js2c_OCQualityOfService(const EOCQualityOfService qos);
        static OCTransportAdapter js2c_OCTransportAdapter(const EOCTransportAdapter ta);
        static OCTransportFlags js2c_OCTransportFlags(const EOCTransportFlags tf);

        // Enums: C to JS.
        static EOCTransportAdapter c2js_OCTransportAdapter(const OCTransportAdapter ta);
        static EOCTransportFlags c2js_OCTransportFlags(const OCTransportFlags tf);
        static EOCConnectivityType c2js_OCConnectivityType(const OCConnectivityType ct);
        static EOCStackResult c2js_OCStackResult(const OCStackResult sr);
        static EOCPayloadType c2js_OCPayloadType(const OCPayloadType t);

        // Dicts: C to JS.
        static scoped_ptr<EOCIdentity> c2js_OCIdentity(const OCIdentity& id);
        static scoped_ptr<EOCDevAddr> c2js_OCDevAddr(const OCDevAddr& devAddr);
        static scoped_ptr<EOCResourcePayload> c2js_OCResourcePayload(const OCResourcePayload& payload);
        static scoped_ptr<EOCDiscoveryPayload> c2js_OCDiscoveryPayload(const OCDiscoveryPayload& payload);
        static scoped_ptr<EOCClientResponse> c2js_OCClientResponse(const OCClientResponse& response);
};

} // namespace sysapps
} // namespace xwalk

#endif // XWALK_SYSAPPS_IOTIVITY_CONVERSIONS_H_
