package com.example.sqlliteexample;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DatabaseHelper extends SQLiteOpenHelper {

    // Database Name and Version
    public static final String DB_NAME = "NOTES_DATABASE.DB";
    public static final int DB_VERSION = 1;

    // Table Name
    public static final String TABLE_NAME = "NOTES";

    // Table Columns
    public static final String _ID = "_id";
    public static final String TITLE = "title";
    public static final String NOTE = "note";

    // Queries for Creating and Deleting Table
    private static final String CREATE_TABLE = "CREATE TABLE " + TABLE_NAME + " (" + _ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " + TITLE + " TEXT, " + NOTE + " TEXT );";
    private static final String DELETE_TABLE = "DROP TABLE IF EXISTS " + TABLE_NAME;

    // constructor
    public DatabaseHelper(@Nullable Context context) {
        super(context, DB_NAME, null, DB_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase sqLiteDatabase) {
        sqLiteDatabase.execSQL(CREATE_TABLE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase sqLiteDatabase, int i, int i1) {
        sqLiteDatabase.execSQL(DELETE_TABLE);
        onCreate(sqLiteDatabase);
    }
}
