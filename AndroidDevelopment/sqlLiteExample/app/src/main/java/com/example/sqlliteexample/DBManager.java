package com.example.sqlliteexample;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.sql.SQLDataException;

public class DBManager {

    // creating a DatabaseHelper Object
    private DatabaseHelper helper;

    Context context;
    private SQLiteDatabase database;

    // constructor
    public DBManager(Context c){
        context = c;
    }

    // opening the Database
    public DBManager open(){
        helper = new DatabaseHelper(context);
        database = helper.getWritableDatabase();
        return this;
    }

    // closing the Database
    public void close(){
        database.close();
    }

    // CRUD Operations
    // INSERT OPERATION
    public void insert(String title, String note){
        // Using ContentValue object to store values
        ContentValues values = new ContentValues();
        values.put(DatabaseHelper.TITLE, title);
        values.put(DatabaseHelper.NOTE, note);

        // Performing INSERT operation
        database.insert(DatabaseHelper.TABLE_NAME, null, values);
    }

    // READ/FETCH OPERATION
    public Cursor fetch(){
        // defining columns that needs to be fetched
        String[] columns = new String[]{DatabaseHelper._ID, DatabaseHelper.TITLE,DatabaseHelper.NOTE};

        // Performing FETCH ALL and storing the result in Cursor Object
        Cursor cursor = database.query(DatabaseHelper.TABLE_NAME, columns,null,null,null,null,null);

        // moving the cursor back to its start
        if(cursor != null){
            cursor.moveToFirst();
        }
        return cursor;
    }

    // to get a  Single Record
    public Cursor getNote(long _id){
        // defining columns that needs to be fetched
        String[] columns = new String[]{DatabaseHelper._ID, DatabaseHelper.TITLE,DatabaseHelper.NOTE};

        // Performing FETCH ALL and storing the result in Cursor Object
        Cursor cursor = database.query(DatabaseHelper.TABLE_NAME, columns,DatabaseHelper._ID + "=" + _id,null,null,null,null);

        return cursor;
    }

    // UPDATE OPERATION
    public int update(long _id, String title, String note){
        // Storing the new values in ContentValue Object
        ContentValues newValues = new ContentValues();
        newValues.put(DatabaseHelper.TITLE, title);
        newValues.put(DatabaseHelper.NOTE, note);

        // Performing UPDATE operation
        int i = database.update(DatabaseHelper.TABLE_NAME,newValues,DatabaseHelper._ID + "=" +_id,null);
        return i;
    }

    // DELETE OPERATION
    public void delete(long _id){
        // Performing DELETE operation
        database.delete(DatabaseHelper.TABLE_NAME, DatabaseHelper._ID + "=" +_id, null);
    }
}
