package com.example.sidsharma.spellathon;

import android.app.Activity;
import android.os.Bundle;
import android.provider.Settings;
import android.text.method.ScrollingMovementMethod;
import android.util.Log;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.util.ArrayList;

public class MainActivity extends Activity {

    //public native String spell(String s);
    public native String[] spellList(String s);
    public native int train();

    static {
        System.loadLibrary("spellcheck");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        int err = train();
        Button b1 =  (Button) findViewById(R.id.button_solve);

        Button b2 =  (Button) findViewById(R.id.button_exit);
        Button b3 =  (Button) findViewById(R.id.button_next);
        final EditText et0 = (EditText) findViewById(R.id.editText0);
        final EditText et1 = (EditText) findViewById(R.id.editText1);
        final EditText et2 = (EditText) findViewById(R.id.editText2);
        final EditText et3 = (EditText) findViewById(R.id.editText3);
        final EditText et4 = (EditText) findViewById(R.id.editText4);
        final EditText et5 = (EditText) findViewById(R.id.editText5);
        final EditText et6 = (EditText) findViewById(R.id.editText6);
        final EditText et7 = (EditText) findViewById(R.id.editText7);
//        et0.setVisibility(View.INVISIBLE);
//        et1.setVisibility(View.INVISIBLE);
//        et2.setVisibility(View.INVISIBLE);
//        et3.setVisibility(View.INVISIBLE);
//        et4.setVisibility(View.INVISIBLE);
//        et5.setVisibility(View.INVISIBLE);
//        et6.setVisibility(View.INVISIBLE);
        final TextView tv1 = (TextView)findViewById(R.id.textView1);
        tv1.setMovementMethod(new ScrollingMovementMethod());
//        tv1.setVisibility(View.INVISIBLE);
        if(err==0)
        b1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //String s ;
                //String s2 = "residue";
                String s2 = et7.getText().toString();
//                tv1.setVisibility(View.VISIBLE);
                String sol[] = spellList(s2);
                int cou=0;

                for (String str : sol) {
                    tv1.append(str);//.toUpperCase());
                    tv1.append("\n");
                    cou ++;
                    Log.d("output", str);
                }
//                et0.setVisibility(View.VISIBLE);
//                et1.setVisibility(View.VISIBLE);
//                et2.setVisibility(View.VISIBLE);
//                et3.setVisibility(View.VISIBLE);
//                et4.setVisibility(View.VISIBLE);
//                et5.setVisibility(View.VISIBLE);
//                et6.setVisibility(View.VISIBLE);

                //String s = sol[cou-1] ;
                et0.setText(Character.toString(sol[cou-1].charAt(0)));
                et1.setText(Character.toString(sol[cou-1].charAt(1)));
                et2.setText(Character.toString(sol[cou-1].charAt(2)));
                et3.setText(Character.toString(sol[cou-1].charAt(3)));
                et4.setText(Character.toString(sol[cou-1].charAt(4)));
                et5.setText(Character.toString(sol[cou-1].charAt(5)));
                et6.setText(Character.toString(sol[cou-1].charAt(6)));

            }
        });
        b3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                et7.setText("");
                tv1.getEditableText().clear();
                et0.setText("");
                et1.setText("");
                et2.setText("");
                et3.setText("");
                et4.setText("");
                et5.setText("");
                et6.setText("");
            }
        });
        b2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                MainActivity.this.finish();
            }
        });
    }
}
