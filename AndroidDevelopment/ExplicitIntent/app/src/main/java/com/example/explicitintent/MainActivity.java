package com.example.explicitintent;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    public static final String EXTRA_MESSAGE = "/::|::/";
    EditText message;
    String messageText;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        message = (EditText)findViewById(R.id.message);
    }

    public void sendMessage(View view) {
        messageText = message.getText().toString();
        Intent intent = new Intent(this,MessageActivity.class);
        intent.putExtra(EXTRA_MESSAGE,messageText);
        startActivity(intent);
    }
}