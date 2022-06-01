var mysql = require("mysql2");

require("dotenv").config();

var con = mysql.createConnection({
  host: "localhost",
  user: process.env.USERNAME,
  password: process.env.PASSWORD,
  port: 3306,
});

con.connect(function (err, result) {
  if (err) throw err;
  console.log("Connected!", result);

  // Creating a DB
  // var query = "CREATE DATABASE db";

  // Creating a Table
  // var query = "CREATE TABLE details (name VARCHAR(255), address VARCHAR(255))";

  // Adding Data to Table
  //   var query =
  //     "INSERT INTO details (name, address) VALUES ('Company Inc', 'Highway 37')";

  // Select Data from Table
  var query = "SELECT * FROM details";

  con.query("USE db", (err, result) => {
    if (err) throw err;
    console.log("USING DB");
  });

  con.query(query, (err, result) => {
    if (err) throw err;
    console.log("Query Result : ", result);
  });
});
