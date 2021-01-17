
#include <jni.h>

#define JAVA_CLASS "com/uwjx/ndk/DynamicUtil"

jstring getMsg(JNIEnv *env , jobject jobj){
    return env->NewStringUTF("get msg success!");
}

jint getPlusResult(JNIEnv *env , jobject jobj , int x, int y){
    return x + y;
}

int registerNativeMethods(JNIEnv *env ,
                          const char* name ,
                          JNINativeMethod* methods ,
                          jint nMethods){
    jclass jcls;
    jcls = env->FindClass(name);
    if(jcls == nullptr){
        return JNI_FALSE;
    }
    if(env->RegisterNatives(jcls , methods , nMethods) < 0){
        return JNI_FALSE;
    }
    return JNI_TRUE;
}

static JNINativeMethod jniNativeMethod[] = {
        {
            "dynamicString" , "()Ljava/lang/String;" , (void *)getMsg
        },
        {
            "plus" , "(II)I" , (void *)getPlusResult
        }
};

JNIEXPORT
int JNICALL JNI_OnLoad(JavaVM *vm , void  *reserved){
        JNIEnv *env;
        if(vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6)){
            return JNI_FALSE;
        }
        registerNativeMethods(env , JAVA_CLASS , jniNativeMethod , 2);
    return JNI_VERSION_1_6;
}
