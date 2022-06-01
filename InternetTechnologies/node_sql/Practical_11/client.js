document.addEventListener("DOMContentLoaded", () => {
  var signupForm = document.querySelector("#signup-form");
  var signinForm = document.querySelector("#signin-form");
  // creating a new XHR request
  var signUpXHR = new XMLHttpRequest();
  var signInXHR = new XMLHttpRequest();

  // opening the request
  signUpXHR.open("POST", "http://localhost:10000/signup", true);
  signUpXHR.setRequestHeader(
    "Content-Type",
    "application/x-www-form-urlencoded"
  );
  signInXHR.open("POST", "http://localhost:10000/signin", true);
  signInXHR.setRequestHeader(
    "Content-Type",
    "application/x-www-form-urlencoded"
  );

  // on recieving xhr response
  signUpXHR.onload = () => {
    var response = JSON.parse(signUpXHR.responseText);
    if (response.status === "CREATED") {
      signupForm.setAttribute("style", "display:none;");
      signinForm.setAttribute("style", "");
    }
  };
  signInXHR.onload = () => {
    var response = JSON.parse(signInXHR.responseText);
    if (response.status === "EXISTS") {
      console.log("EXIST");
    } else {
      console.log("SORRY");
    }
  };

  // sending the xhr request on form submission of signup form
  signupForm.addEventListener("submit", (e) => {
    e.preventDefault();
    // getting the input form data
    var name = signupForm.querySelector("input[name='name']").value;
    var email = signupForm.querySelector("input[name='email']").value;
    var username = signupForm.querySelector("input[name='username']").value;
    var password = signupForm.querySelector("input[name='password']").value;

    var data = { name, email, username, password };

    // converting to x-www-form-data
    let formData = Object.entries(data)
      .map((e) => e.join("="))
      .join("&");

    // sending the form using xhr.send(formData)
    signUpXHR.send(formData);
  });

  // sending the xhr request on form submission of signin form
  signinForm.addEventListener("submit", (e) => {
    e.preventDefault();
    // getting the input form data
    var username = signinForm.querySelector("input[name='username']").value;
    var password = signinForm.querySelector("input[name='password']").value;

    var data = { username, password };

    // converting to x-www-form-data
    let formData = Object.entries(data)
      .map((e) => e.join("="))
      .join("&");

    // sending the form using xhr.send(formData)
    signInXHR.send(formData);
  });
});
