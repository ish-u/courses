document.addEventListener("DOMContentLoaded", () => {
  function checkLength(e, length) {
    var el = e.target || e.srcElement;
    var username = el.value;
    if (username.length < 8) {
      el.setAttribute("style", "border-color:red;");
    } else {
      el.removeAttribute("style");
    }
    n;
  }
  const username = document.getElementById("username");
  username.addEventListener("blur", (e) => {
    checkLength(e);
  });

  function getTarget(e) {
    return e.target || e.srcElement;
  }

  function itemDone(e) {
    // getting the element to be removed and removing it
    var target, elParent, elGrandparent;
    target = getTarget(e);
    elParent = target.parentNode;
    elGrandparent = elParent.parentNode;
    console.log(target, elParent, elGrandparent);
    // elGrandparent.removeChild(elParent);

    // stopping the redirection from the a tag
    e.preventDefault();
  }

  document.getElementById("ul").addEventListener(
    "click",
    function (e) {
      itemDone(e);
    },
    false
  );

  document
    .getElementsByTagName("html")[0]
    .addEventListener("mousemove", (e) => {
      var pos = "x : " + e.clientX + "y : " + e.clientY;
      var h1 = document.createElement("h1");
      var textNode = document.createTextNode(pos);
      h1.appendChild(textNode);
      document.getElementById("pos").innerHTML = h1.outerHTML;
    });

  // Event Flow

  // const ul = document.getElementById("ul");
  // const li = document.getElementById("li");
  // const a = document.getElementById("a");

  // ul.addEventListener(
  //   "click",
  //   () => {
  //     alert("ul");
  //   },
  //   false
  // );

  // li.addEventListener(
  //   "click",
  //   () => {
  //     alert("li");
  //   },
  //   false
  // );

  // ul.addEventListener(
  //   "click",
  //   () => {
  //     alert("a");
  //   },
  //   false
  // );
});
