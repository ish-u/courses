package com.example.explicitintent;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class MessageActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_message);
        Intent intent = getIntent();
        String recievedMessage = intent.getStringExtra(MainActivity.EXTRA_MESSAGE);
        TextView message = (TextView)findViewById(R.id.getMessage);
        message.setText(recievedMessage);
    }
}