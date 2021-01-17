#include <jni.h>
#include <string>

#include <android/log.h>

#define TAG "JNITEST"
// 定义info信息
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)

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
    LOGI("msg................");
    return env->NewStringUTF(userInfo.getName().c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_uwjx_ndk_MainActivity_printStr(JNIEnv *env, jobject thiz , jstring msg) {
    const char *str = env->GetStringUTFChars(msg , 0);

    int len = env->GetStringLength(msg);
    LOGI("msg len -> %d" , len);

    char buff[len];

    env->GetStringUTFRegion(msg , 0 , len-1 , buff);

    LOGI("msg -> %s" , str);

    env->ReleaseStringUTFChars(msg , str);
}