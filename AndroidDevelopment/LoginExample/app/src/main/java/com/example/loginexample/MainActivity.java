package com.example.loginexample;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    // Get the Username and Password from the EditText Views entered by the User
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

        // Validating the User Input
        if(username.equals(getResources().getString(R.string.USERNAME)) && password.equals(getResources().getString(R.string.PASSWORD))){
            Intent intent = new Intent(this,LoggedIn.class);
            startActivity(intent);
        }
        else{
            Toast.makeText(this, "INCORRECT CREDENTIALS", Toast.LENGTH_SHORT).show();
        }

    }
}