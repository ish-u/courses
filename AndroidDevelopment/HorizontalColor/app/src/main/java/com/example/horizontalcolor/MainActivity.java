package com.example.horizontalcolor;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.constraintlayout.widget.ConstraintSet;

import android.graphics.Color;
import android.os.Bundle;
import android.text.Layout;
import android.util.Log;
import android.view.View;
import android.widget.Button;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void changeColor(View view) {
        Button btn = (Button)view;
        ConstraintLayout layout = (ConstraintLayout)(findViewById(R.id.layout));
        String color = btn.getText().toString();
        switch (color)
        {
            case "Red":
                layout.setBackgroundColor(Color.RED);
                break;
            case "Green":
                layout.setBackgroundColor(Color.GREEN);
                break;
            case "Blue":
                layout.setBackgroundColor(Color.BLUE);
                break;
            default:
                break;
        }
    }
}