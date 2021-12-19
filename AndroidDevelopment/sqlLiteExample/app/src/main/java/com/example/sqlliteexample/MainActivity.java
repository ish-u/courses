package com.example.sqlliteexample;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Context;
import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.CursorAdapter;
import android.widget.ListView;
import android.widget.SimpleCursorAdapter;
import android.widget.TextView;
import android.widget.Toast;

import java.sql.SQLDataException;

public class MainActivity extends AppCompatActivity {

    ListView listView;
    DBManager dbManager;
    SimpleCursorAdapter adapter;

    @SuppressLint("ShowToast")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // finding the List View and creating the dbManager Object
        listView = findViewById(R.id.notes);
        dbManager = new DBManager(this);

        // opening the Database and getting the Cursor
        dbManager.open();
        Cursor cursor = dbManager.fetch();

        // Checking if the Cursor is empty
        if(cursor.getCount() == 0){
            Toast.makeText(getApplicationContext(),"NO NOTES SAVED",Toast.LENGTH_LONG);
        }

        // Populating the ListView with the obtained cursor
        final String[] from = new String[]{DatabaseHelper._ID, DatabaseHelper.TITLE};
        final int[] to = new int[]{ android.R.id.text1, android.R.id.text2 };
        adapter = new SimpleCursorAdapter(this, android.R.layout.simple_list_item_2, cursor,from, to, 0);
        adapter.notifyDataSetChanged();
        listView.setAdapter(adapter);

        // OnClick Handler for ListView
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String id = ((TextView) view.findViewById(android.R.id.text1)).getText().toString();

                // Creating an Intent and Starting ViewNote Activity
                Intent intent = new Intent(getApplicationContext(), ViewNote.class);
                intent.putExtra("ID", id);
                startActivity(intent);
            }
        });
    }

    @Override
    protected void onDestroy() {
        dbManager.close();
        super.onDestroy();
    }

    // Going to AddNote Activity
    public void addNote(View view) {
        Intent intent = new Intent(this,AddNote.class);
        startActivity(intent);
    }
}