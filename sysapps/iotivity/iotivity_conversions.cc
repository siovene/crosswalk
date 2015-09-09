// Copyright (c) 2015 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "xwalk/sysapps/iotivity/iotivity_conversions.h"

namespace xwalk {
namespace sysapps {

OCMode IotivityConversions::InternalToOCMode(EOCMode mode) {
    switch (mode) {
        case EOCMode::E_OC_MODE_OC_CLIENT: return OC_CLIENT;
        case EOCMode::E_OC_MODE_OC_SERVER: return OC_SERVER;
        case EOCMode::E_OC_MODE_OC_CLIENT_SERVER: default: return OC_CLIENT_SERVER;
    };
}

OCMethod IotivityConversions::InternalToOCMethod(EOCMethod method) {
    switch (method) {
        case EOCMethod::E_OC_METHOD_OC_REST_GET: return OC_REST_GET;
        case EOCMethod::E_OC_METHOD_OC_REST_PUT: return OC_REST_PUT;
        case EOCMethod::E_OC_METHOD_OC_REST_POST: return OC_REST_POST;
        case EOCMethod::E_OC_METHOD_OC_REST_DELETE: return OC_REST_DELETE;
        case EOCMethod::E_OC_METHOD_OC_REST_OBSERVE: return OC_REST_OBSERVE;
        case EOCMethod::E_OC_METHOD_OC_REST_OBSERVE_ALL: return OC_REST_OBSERVE_ALL;
        case EOCMethod::E_OC_METHOD_OC_REST_CANCEL_OBSERVE: return OC_REST_CANCEL_OBSERVE;
        case EOCMethod::E_OC_METHOD_OC_REST_PRESENCE: return OC_REST_PRESENCE;
        case EOCMethod::E_OC_METHOD_OC_REST_DISCOVER: return OC_REST_DISCOVER;
        case EOCMethod::E_OC_METHOD_OC_REST_NOMETHOD: default: return OC_REST_NOMETHOD;
    };
}

OCConnectivityType IotivityConversions::InternalToOCConnectivityType(EOCConnectivityType ct) {
    switch (ct) {
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_IP: return CT_ADAPTER_IP;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_GATT_BTLE: return CT_ADAPTER_GATT_BTLE;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_RFCOMM_BTEDR: return CT_ADAPTER_RFCOMM_BTEDR;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_REMOTE_ACCESS: return (OCConnectivityType) (1 << 13);
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_ADAPTER_SHIFT: return (OCConnectivityType) CT_ADAPTER_SHIFT;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_MASK_FLAGS: return (OCConnectivityType) CT_MASK_FLAGS;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_MASK_ADAPTER: return (OCConnectivityType) CT_MASK_ADAPTER;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_FLAG_SECURE: return CT_FLAG_SECURE;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_IP_USE_V6: return CT_IP_USE_V6;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_IP_USE_V4: return CT_IP_USE_V4;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_INTERFACE: return CT_SCOPE_INTERFACE;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_LINK: return CT_SCOPE_LINK;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_REALM: return CT_SCOPE_REALM;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_ADMIN: return CT_SCOPE_ADMIN;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_SITE: return CT_SCOPE_SITE;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_ORG: return CT_SCOPE_ORG;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_SCOPE_GLOBAL: return CT_SCOPE_GLOBAL;
        case EOCConnectivityType::E_OC_CONNECTIVITY_TYPE_CT_DEFAULT: default: return CT_DEFAULT;
    };
}

OCQualityOfService IotivityConversions::InternalToOCQualityOfService(EOCQualityOfService qos) {
    switch (qos) {
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_LOW_QOS: return OC_LOW_QOS;
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_MEDIUM_QOS: return OC_MEDIUM_QOS;
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_HIGH_QOS: return OC_HIGH_QOS;
        case EOCQualityOfService::E_OC_QUALITY_OF_SERVICE_OC_NA_QOS: default: return OC_NA_QOS;
    };
}

OCTransportAdapter IotivityConversions::InternalToOCTransportAdapter(EOCTransportAdapter ta) {
    switch (ta) {
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_IP: return OC_ADAPTER_IP;
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_GATT_BTLE: return OC_ADAPTER_GATT_BTLE;
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_RFCOMM_BTEDR: return OC_ADAPTER_RFCOMM_BTEDR;
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_ADAPTER_REMOTE_ACCESS: return (OCTransportAdapter) (1 << 3);
        case EOCTransportAdapter::E_OC_TRANSPORT_ADAPTER_OC_DEFAULT_ADAPTER: default: return OC_DEFAULT_ADAPTER;
    };
}

OCTransportFlags IotivityConversions::InternalToOCTransportFlags(EOCTransportFlags tf) {
    switch (tf) {
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_FLAG_SECURE: return OC_FLAG_SECURE;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_IP_USE_V6: return OC_IP_USE_V6;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_IP_USE_V4: return OC_IP_USE_V4;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_RESERVED1: return OC_RESERVED1;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_INTERFACE: return OC_SCOPE_INTERFACE;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_LINK: return OC_SCOPE_LINK;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_REALM: return OC_SCOPE_REALM;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_ADMIN: return OC_SCOPE_ADMIN;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_SITE: return OC_SCOPE_SITE;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_ORG: return OC_SCOPE_ORG;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_SCOPE_GLOBAL: return OC_SCOPE_GLOBAL;
        case EOCTransportFlags::E_OC_TRANSPORT_FLAGS_OC_DEFAULT_FLAGS: default: return OC_DEFAULT_FLAGS;
    };
}

} // namespace sysapps
} // namespace xwalk

