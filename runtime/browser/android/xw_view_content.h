// Copyright (c) 2013 Intel Corporation. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef XWALK_RUNTIME_BROWSER_ANDROID_XW_VIEW_CONTENT_H_
#define XWALK_RUNTIME_BROWSER_ANDROID_XW_VIEW_CONTENT_H_

#include "base/android/jni_helper.h"
#include "base/android/scoped_java_ref.h"
#include "base/memory/scoped_ptr.h"

namespace content {
class BrowserContext;
class WebContents;
}

namespace xwalk {

class XwViewContent {
 public:
  XwViewContent(JNIEnv* env, jobject obj);
  ~XwViewContent();

  jint GetWebContents(JNIEnv* env, jobject obj);
  void Destroy(JNIEnv* env, jobject obj);

 private:
  content::WebContents* CreateWebContents();

  JavaObjectWeakGlobalRef java_ref_;
  scoped_ptr<content::WebContents> web_contents_;
};

bool RegisterXwViewContent(JNIEnv* env);

}  // namespace xwalk

#endif  // XWALK_RUNTIME_BROWSER_ANDROID_XW_VIEW_CONTENT_H_
