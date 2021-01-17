package com.uwjx.ndk;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import androidx.annotation.Nullable;

public class DynamicActivity extends Activity {

    TextView textView;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_dynamic);
        textView = findViewById(R.id.dynamic_text);

        DynamicUtil dynamicUtil = new DynamicUtil();

        findViewById(R.id.dynamic_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.w("hugh" , "开始动态注册");
                String msg = dynamicUtil.dynamicString();
                textView.setText(msg);
            }
        });
    }
}
