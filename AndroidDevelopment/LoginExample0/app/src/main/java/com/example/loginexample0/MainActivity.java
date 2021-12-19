package com.example.loginexample0;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Get the Username and Password EditText Views
    EditText usernameEditText;
    EditText passwordEditText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void login(View view) {
        // Getting Credentials
        usernameEditText = findViewById(R.id.usernameEditText);
        passwordEditText = findViewById(R.id.passwordEditText);
        String username = usernameEditText.getText().toString();
        String password = passwordEditText.getText().toString();

        if(username.equals(getResources().getString(R.string.USERNAME)) && password.equals(getResources().getString(R.string.PASSWORD))){

            // Creating an AlertDialog builder Object which will be used to Create AlertDialog object
            AlertDialog.Builder builder = new AlertDialog.Builder(this);
            builder.setMessage(R.string.dialog_message);
            builder.setTitle(R.string.dialog_title);

            // Displaying the Dialog
            AlertDialog dialog = builder.create();
            dialog.show();
        }
        else
        {
            Toast.makeText(this, "INCORRECT CREDENTIALS", Toast.LENGTH_SHORT).show();
        }
    }
}