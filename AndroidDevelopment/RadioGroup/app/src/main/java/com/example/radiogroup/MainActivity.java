package com.example.radiogroup;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Toast;

import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity {

    // Creating HashMap for adding Radio Button and for their onClick Responses
    HashMap<String,String> course_teacher = new HashMap<String, String>();
    RadioButton button;
    RadioGroup group;
    
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Adding Data to HashMap
        course_teacher.put("BSc(H) - Computer Science","Teacher A");
        course_teacher.put("BSc(H) - Mathematics","Teacher B");
        course_teacher.put("BSc(H) - Chemistry","Teacher C");
        course_teacher.put("BA(H) - English","Teacher D");
        course_teacher.put("BA(H) - History","Teacher E");
        course_teacher.put("BSc(H) - Physics","Teacher F");

        // getting the RadioGroup View and Adding RadioButtons using the course_teacher HashMap
        RadioGroup group = (RadioGroup)findViewById(R.id.CoursesGroup);
        for(Map.Entry<String,String> entry: course_teacher.entrySet()){
            button = new RadioButton(this);
            button.setText(entry.getKey());
            button.setChecked(false);
            button.setOnClickListener(this::onRadioButtonClicked);
            group.addView(button);
        }
    }

    // handling Click Events on Radio Button
    public void onRadioButtonClicked(View view) {
        String key = ((RadioButton)view).getText().toString();
        Toast.makeText(this, "Teacher In Charge : " + course_teacher.get(key), Toast.LENGTH_SHORT).show();
    }
}