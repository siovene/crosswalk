{
  'targets': [
    {
      'target_name': 'sysapps',
      'type': 'static_library',
      'dependencies': [
        '../../base/base.gyp:base',
        '../../net/net.gyp:net',
        '../../ui/base/ui_base.gyp:ui_base',
        '../../ui/gfx/gfx.gyp:gfx',
        '../../ui/gfx/gfx.gyp:gfx_geometry',
        '../extensions/extensions.gyp:xwalk_extensions',
        'sysapps_resources.gyp:xwalk_sysapps_resources',
      ],
      'variables': {
        'jsapi_component': 'sysapps',
      },
      'includes': [
        '../../build/filename_rules.gypi',
        '../xwalk_jsapi.gypi',
      ],
      'sources': [
        'common/binding_object.h',
        'common/binding_object_store.cc',
        'common/binding_object_store.h',
        'common/common.idl',
        'common/event_target.cc',
        'common/event_target.h',
        'common/sysapps_manager.cc',
        'common/sysapps_manager.h',
        'common/sysapps_manager_android.cc',
        'common/sysapps_manager_linux.cc',
        'common/sysapps_manager_mac.cc',
        'common/sysapps_manager_win.cc',
        'device_capabilities/av_codecs_provider.h',
        'device_capabilities/av_codecs_provider_android.cc',
        'device_capabilities/av_codecs_provider_android.h',
        'device_capabilities/cpu_info_provider.cc',
        'device_capabilities/cpu_info_provider.h',
        'device_capabilities/cpu_info_provider_android.cc',
        'device_capabilities/cpu_info_provider_linux.cc',
        'device_capabilities/cpu_info_provider_mac.cc',
        'device_capabilities/cpu_info_provider_win.cc',
        'device_capabilities/device_capabilities.idl',
        'device_capabilities/device_capabilities_extension.cc',
        'device_capabilities/device_capabilities_extension.h',
        'device_capabilities/device_capabilities_object.cc',
        'device_capabilities/device_capabilities_object.h',
        'device_capabilities/display_info_provider.cc',
        'device_capabilities/display_info_provider.h',
        'device_capabilities/memory_info_provider.cc',
        'device_capabilities/memory_info_provider.h',
        'device_capabilities/storage_info_provider.cc',
        'device_capabilities/storage_info_provider.h',
        'device_capabilities/storage_info_provider_android.cc',
        'device_capabilities/storage_info_provider_android.h',
        'raw_socket/raw_socket.idl',
        'raw_socket/raw_socket_extension.cc',
        'raw_socket/raw_socket_extension.h',
        'raw_socket/raw_socket_object.cc',
        'raw_socket/raw_socket_object.h',
        'raw_socket/tcp_server_socket.idl',
        'raw_socket/tcp_server_socket_object.cc',
        'raw_socket/tcp_server_socket_object.h',
        'raw_socket/tcp_socket.idl',
        'raw_socket/tcp_socket_object.cc',
        'raw_socket/tcp_socket_object.h',
        'raw_socket/udp_socket.idl',
        'raw_socket/udp_socket_object.cc',
        'raw_socket/udp_socket_object.h',
        'iotivity/iotivity.idl',
        'iotivity/iotivity_extension.cc',
        'iotivity/iotivity_extension.h',
        'iotivity/iotivity_object.cc',
        'iotivity/iotivity_object.h',
        'iotivity/oic_resource.idl',
        'iotivity/oic_resource_object.cc',
        'iotivity/oic_resource_object.h'
      ],
      'conditions': [
        ['OS!="android"', {
          'dependencies': [
            '../../components/components.gyp:storage_monitor',
            '../../media/media.gyp:media',
            '../../third_party/ffmpeg/ffmpeg.gyp:ffmpeg',
          ],
          'sources': [
            'device_capabilities/av_codecs_provider_ffmpeg.cc',
            'device_capabilities/av_codecs_provider_ffmpeg.h',
            'device_capabilities/storage_info_provider_chromium.cc',
            'device_capabilities/storage_info_provider_chromium.h',
          ],
        }],
        ['OS=="win"', {
          'link_settings': {
            'libraries': [
              '-lPdh.lib',
            ],
          },
        }]
      ],
      'direct_dependent_settings': {
        'include_dirs': [
          # Build units including this module should have this
          # on theirs include path because of the code we generate
          # from the IDL files.
          '<(SHARED_INTERMEDIATE_DIR)',
        ]
      },
    },
  ],
}
