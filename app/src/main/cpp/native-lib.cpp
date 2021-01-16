#include <jni.h>
#include <string>

#include "user/UserInfo.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_uwjx_ndk_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    UserInfo userInfo;

    return env->NewStringUTF(userInfo.getName().c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_uwjx_ndk_MainActivity_stringOfName(JNIEnv *env, jobject thiz) {
    UserInfo userInfo;

    return env->NewStringUTF(userInfo.getName().c_str());
}