$(document).ready(() => {
  // return the first 'li'
  var $li = $("li");
  console.log($li.html(), $li.text());
  // wil; update all 'li'
  //   $li.html("updated");

  // selecting all 'a' tags that are descendant of 'li' tags
  console.log($("li a"));

  // appeding the li to ul
  $("ul").append($("ul").html());

  // chaining
  $("li a").hide().delay(500).fadeIn(1400);

  // first li inner HTML appended to all li
  //   $li.append($li.html());

  // updating the content
  // creating new element
  var liList = [];
  liList.push($(`<li>before</li>`));
  liList.push($(`<li>after</li>`));
  liList.push($(`<span>prepend  </span>`));
  liList.push($(`<span>  append</span>`));
  // getting the first li element to perform addition on
  var $liFirst = $li.first();
  $liFirst.before(liList[0]);
  $liFirst.after(liList[1]);
  $liFirst.prepend(liList[2]);
  $liFirst.append(liList[3]);

  // adding attributes
  $liFirst.addClass("LOL");
  $liFirst.addClass("LMAO");
  $liFirst.removeClass("LMAO");

  // adding and setting css
  // getting the background color of first li
  var backgroundColor = $liFirst.css("background-color");
  console.log(backgroundColor);
  // setting the background color of the first li
  $liFirst.css("background-color", "#FF00FF");
  // setting the css props of the last li
  $("li:last").css({
    "background-color": "red",
    color: "green",
    "font-size": "300px",
  });

  // using each()
  // removing the li from the 'li' matched set whose class = "LOL"
  $li.each(function () {
    var className = $(this).attr("class");
    if (className !== undefined && className.includes("LOL")) {
      $(this).remove();
    }
  });

  // adding events to
  $li = $("li");
  $li.on("mouseover", function () {
    $(this).css("color", "green");
    $(this).children().first().css("text-decoration", "none");
  });
  $li.on("mouseout", function () {
    $(this).css("color", "black");
    $(this).children().first().css("text-decoration", "underline");
  });

  // event object
  $li.on("click", function (e) {
    var date = new Date();
    console.log(e);
    $li.last().after(`<li>${e.type + "\t" + date.toUTCString()}</li>`);
    e.preventDefault();
    $li = $("li");
  });

  //forms
  var $form = $("#form");
  $form.on("submit", function (e) {
    e.preventDefault();
    var text = $("input:text");
    var username = text.first().val();
    var password = text.last().val();

    $("li").last().after(`<li>${username}</li>`);
  });
  // making AJAX request to jQuery
  $("#shuffle").on("click", function (e) {
    var random = Math.floor(Math.random() * 100 + 1);
    $("code").load(`https://jsonplaceholder.typicode.com/todos/${random}`);
  });

  // creating a table
  var body = $("body");
  var newTable = $("<table>");

  for (var i = 0; i < 3; i++) {
    newTable.append($("<tr>"));
  }

  body.append(newTable);
  var th = $("<th>");
  for (var i = 0; i < 3; i++) {
    $("table tr").first().append($("<th>"));
  }

  $("table th").each(function (i) {
    console.log(this);
    $(this).append(i);
  });

  $("table").css("border", "1px solid black");

  $("table").on("click", function (e) {
    console.log(e.target, e.currentTarget);
    $("table").load("question.html");
    $.post(
      "https://jsonplaceholder.typicode.com/posts",
      $("#form").serialize(),
      function (data) {
        console.log(data);
      }
    );
  });

  $.getJSON("https://jsonplaceholder.typicode.com/posts/1")
    .done(function (data) {
      console.log(data);
    })
    .fail(function (data) {
      console.log(data);
    })
    .always(function (data) {
      console.log(data);
    });

  $("#form2").on("submit", (e) => {
    e.preventDefault();
    $.post(
      "https://jsonplaceholder.typicode.com/posts",
      $("#form2").serialize(),
      function (data) {
        console.log(data);
      }
    );
  });
});
