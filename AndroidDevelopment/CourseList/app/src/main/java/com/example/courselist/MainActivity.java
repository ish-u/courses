package com.example.courselist;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    // Declaring the HashMap to store Data and ListView View for Displaying Information
    ListView listView;
    HashMap<String,String>  course_teacher = new HashMap<String,String>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Adding Data to HashMap
        course_teacher.put("BSc(H) - Computer Science","Teacher A");
        course_teacher.put("BSc(H) - Mathematics","Teacher B");
        course_teacher.put("BSc(H) - Chemistry","Teacher C");
        course_teacher.put("BA(H) - English","Teacher E");
        course_teacher.put("BA(H) - History","Teacher F");
        course_teacher.put("BSc(H) - Physics","Teacher G");

        //getting the ListView; Creating an Array Adapter and setting the adapter of ListView View to the created ArrayAdapter
        listView = (ListView) findViewById(R.id.listView);
        List<String> courses = new ArrayList<String>();
        for (String i: course_teacher.keySet())
        {
            courses.add(i);
        }
        ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,R.layout.list_view_element ,courses);
        listView.setAdapter(adapter);

        // handling Click Event on List Items
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String incharge = course_teacher.get(((TextView)view).getText().toString());
                Toast.makeText(getApplicationContext(), incharge, Toast.LENGTH_SHORT).show();
            }
        });

    }
}