package com.uwjx.ndk;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

import androidx.annotation.Nullable;

public class DynamicActivity extends Activity {

    TextView textView;
    EditText plusX , plusY;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.layout_dynamic);
        textView = findViewById(R.id.dynamic_text);
        plusX = findViewById(R.id.plus_x);
        plusY = findViewById(R.id.plus_y);

        DynamicUtil dynamicUtil = new DynamicUtil();

        findViewById(R.id.dynamic_btn_msg).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Log.w("hugh" , "开始动态注册");
                String msg = dynamicUtil.dynamicString();
                textView.setText(msg);
            }
        });

        findViewById(R.id.dynamic_btn_plus).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int x = Integer.parseInt(plusX.getText().toString());
                int y = Integer.parseInt(plusY.getText().toString());
                Log.w("hugh" , "加法计算 x = " + x + ",  y = " + y);
                textView.setText("计算结果 : "+dynamicUtil.plus(x , y) + "");
            }
        });
    }
}
