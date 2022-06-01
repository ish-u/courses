const http = require("http");

const hostname = "localhost";
const port = 5000;
const server = http.createServer((req, res) => {
  res.statusCode = 200;
  res.setHeader("Content-type", "text/plain");
  res.setHeader("Cookie", ["lol=lmao"]);
  res.end("LOL\n");
});

server.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}`);
});
