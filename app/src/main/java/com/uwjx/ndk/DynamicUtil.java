package com.uwjx.ndk;

public class DynamicUtil {

    static {
        System.loadLibrary("dynamic-lib");
    }

    public native String dynamicString();
}
