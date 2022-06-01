const http = require("http");
const mysql = require("mysql2");
const queryString = require("query-string");

require("dotenv").config();

// cors headers
const headers = {
  "Access-Control-Allow-Origin": "*",
  "Access-Control-Allow-Methods": "OPTIONS, POST, GET",
  "Access-Control-Max-Age": 2592000, // 30 days
  /** add other headers as per requirement */
};

// mysql connection
var con = mysql.createConnection({
  host: "localhost",
  user: process.env.USERNAME,
  password: process.env.PASSWORD,
  port: 3306,
});

con.connect(function (err, result) {
  if (err) throw err;
  console.log("Connected!");
  //   con.query("CREATE DATABASE users", function (err, result) {
  //     if (err) throw err;
  //     console.log("Database created");
  //   });

  con.query("USE users", (err, result) => {
    if (err) throw err;
    console.log("USING DB");
  });

  //   var sql =
  //     "CREATE TABLE customers (name VARCHAR(255), password VARCHAR(255), email VARCHAR(255), username VARCHAR(255))";
  //   con.query(sql, function (err, result) {
  //     if (err) throw err;
  //     console.log("Table created");
  //   });
});

const hostname = "localhost";
const port = 10000 || Math.floor(Math.random() * 10000) + 10000;

const server = http.createServer((req, res) => {
  const { method, url } = req;
  console.log(method, url);
  // handling the post request
  if (method === "POST") {
    console.log(req.headers);1
    if (url === "/signup") {
      console.log("Create User Route");
      var body = "";
      req.on("data", function (data) {
        body += data;
      });
      req.on("end", function () {
        const { name, username, password, email } = queryString.parse(body);
        var sql = `INSERT INTO customers (name, password, email, username) VALUES ('${name}', '${password}', '${email}', '${username}')`;
        con.query(sql, function (err, result) {
          if (err) throw err;
          res.setHeader("Content-type", "application/json");
          res.writeHead(200, headers);
          res.end(JSON.stringify({ status: "CREATED" }));
        });
      });
    } else if (url === "/signin") {
      console.log("Get User Route");
      var body = "";
      req.on("data", function (data) {
        body += data;
      });
      req.on("end", function () {
        const { username, password } = queryString.parse(body);
        var sql = `SELECT * FROM customers WHERE username = '${username}' AND password = '${password}'`;
        con.query(sql, (err, result) => {
          if (err) throw err;
          var status;
          if (result.length) {
            status = { status: "EXISTS" };
          } else {
            status = { status: " DOES NOT EXISTS" };
          }
          res.setHeader("Set-Cookie", "lol=lmao");
          res.setHeader("Content-type", "application/json");
          res.writeHead(200, headers);
          res.end(JSON.stringify(status));
        });
      });
    } else {
      res.statusCode = 300;
      res.setHeader("Content-type", "application/json");
      res.end(JSON.stringify({ msg: "NOT ALLOWED" }));
    }
  } else if (method === "GET") {
    if (url === "/") {
      var query = "SELECT * FROM customers";
      con.query(query, (err, result) => {
        if (err) throw err;
        res.statusCode = 200;
        res.setHeader("Content-type", "application/json");
        res.end(JSON.stringify({ users: result }));
      });
    } else if (url.includes("delete")) {
      var username = url.split("/")[2];
      var deleteQuery = `DELETE FROM customers WHERE username = '${username}'`;
      con.query(deleteQuery, (err, result) => {
        if (err) throw err;
        res.statusCode = 200;
        res.setHeader("Content-type", "application/json");
        res.end(JSON.stringify({ message: result }));
      });
    }
  }
});

server.listen(port, hostname, () => {
  console.log(`Server Listening on http://${hostname}:${port}`);
});
