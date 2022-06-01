const http = require("http");
const fs = require("fs");

fs.readFile("./test.txt", "utf-8", (err, data) => {
  if (err) {
    console.log(`Error ${err}`);
    ret;
  }
  console.log(data);
});

const port = "6969";

const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader("Content-type", "text/plain");
  res.end("LOL");
});

server.listen(port, () => {
  console.log(`server live at http://localhost:${port}`);
});
