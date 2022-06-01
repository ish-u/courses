document.addEventListener("DOMContentLoaded", () => {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "https://jsonplaceholder.typicode.com/todos/1", true);

  xhr.onload = () => {
    if (xhr.status === 200) {
      document.getElementsByTagName("code")[0].innerHTML = xhr.response;
      //   console.log(JSON.parse(xhr.responseText), xhr.status);
    }
  };

  xhr.send(null);
});
