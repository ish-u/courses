package com.example.sqlliteexample;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;

import java.util.ArrayList;
import java.util.List;

public class ViewNote extends AppCompatActivity {

    // EditText of values to be modified
    private EditText toModifyTitleEditText;
    private EditText toModifyNoteEditText;
    private DBManager dbManager;
    private long _ID;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_note);

        // Getting the EditText Views
        toModifyTitleEditText = (EditText) findViewById(R.id.toModifyNoteTitle);
        toModifyNoteEditText = (EditText) findViewById(R.id.toModifyNote);

        // Getting the Intent Data (ID of the Row)
        Intent intent = getIntent();
         _ID = Long.parseLong(intent.getStringExtra("ID"));
//        Log.d("ID : ",id);

        // Opening the Database
        dbManager = new DBManager(this);
        dbManager.open();

        // Getting the Row/Object/Tuple that is to be modified
        Cursor cursor = dbManager.getNote(_ID);

//        Log.d("CURSOR", String.valueOf(cursor.getCount()));


        while(cursor.moveToNext()) {
            String title = cursor.getString(cursor.getColumnIndex(DatabaseHelper.TITLE));
            String note = cursor.getString(cursor.getColumnIndex(DatabaseHelper.NOTE));

            // Setting the EditText Views text to values from Database
            toModifyTitleEditText.setText(title);
            toModifyNoteEditText.setText(note);
        }
        cursor.close();
        


    }

    public void updateNote(View view) {
        // Getting the New Values
        final String toModifyTitle = toModifyTitleEditText.getText().toString();
        final String toModifyNote = toModifyNoteEditText.getText().toString();

        // Calling the Update Operation
        dbManager.update(_ID,toModifyTitle,toModifyNote);

        // Going Back to Main Activity
        goBackToMainActivity();
    }

    public void deleteNote(View view) {
        //Calling the Delete Operation
        dbManager.delete(_ID);

        // Going Back to Main Activity
        goBackToMainActivity();
    }

    public void goBackToMainActivity(){
        Intent main = new Intent(ViewNote.this, MainActivity.class);
        main.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        startActivity(main);
    }
}