package com.example.sqlliteexample;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class AddNote extends AppCompatActivity {

    // Data Variables
    private EditText titleEditText;
    private EditText noteEditText;
    private DBManager dbManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_note);

        // Getting the Data Variables
        titleEditText = (EditText)findViewById(R.id.noteTitle);
        noteEditText = (EditText)findViewById(R.id.note);

        // Opening the Database
        dbManager = new DBManager(this);
        dbManager.open();
    }

    public void createNote(View view) {
        final String title = titleEditText.getText().toString();
        final String note = noteEditText.getText().toString();

        // Perfroming INSERT operation
        dbManager.insert(title, note);

        // Going Back to the Main Activity
        Intent main = new Intent(AddNote.this, MainActivity.class);
        main.setFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        startActivity(main);
    }
}