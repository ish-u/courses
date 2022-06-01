function changeText(element) {
  const sentence = document.getElementById("sentence");
  sentence.innerHTML = element.innerHTML;
}

function addToList(event) {
  event.preventDefault();
  const toAdd = document.getElementById("to-add");
  if (toAdd.value !== "") {
    // creating a new li element
    const li = document.createElement("li");
    // setting the innerHTML created 'li' element to the one given by User
    li.innerHTML = toAdd.value;
    // adding ID to the created 'li'
    li.id = window.crypto.getRandomValues(new Uint32Array(1));
    // Sibling Methods
    li.addEventListener("dblclick", () => {
      getPrevSibling(li.id);
    });
    li.addEventListener("click", () => {
      getNextSibling(li.id);
    });
    // append the 'li' to the 'ul' element with id="list"
    document.getElementById("list").appendChild(li);
    // reseting id="to-add" element
    toAdd.value = "";
  }
}

function getFirstChild() {
  const first = document.getElementById("list").firstChild;
  if (first !== null) {
    document.getElementById("action").innerHTML =
      "FIRST ELEMENT " + first.innerHTML;
  }
}

function getLastChild() {
  const last = document.getElementById("list").lastChild;
  if (last !== null) {
    document.getElementById("action").innerHTML =
      "LAST ELEMENT " + last.innerHTML;
  }
}

function getParentNode() {
  const parent = document.getElementById("list").parentNode;
  document.getElementById("action").innerText =
    "\n" + "Parent ID : " + parent.id + parent.innerHTML;
}

function getPrevSibling(id) {
  const prevSib = document.getElementById(id).previousSibling;
  if (prevSib !== null) {
    document.getElementById("action").innerHTML =
      "PREVIOUS SIBLING " + prevSib.innerHTML;
  }
}

function getNextSibling(id) {
  const nextSib = document.getElementById(id).nextSibling;
  if (nextSib !== null) {
    document.getElementById("action").innerHTML =
      "NEXT SIBLING " + nextSib.innerHTML;
  }
}

function removeFirst() {
  const first = document.getElementById("list").firstChild;
  if (first !== null) {
    document.getElementById("action").innerHTML =
      "REMOVED " + document.getElementById("list").firstChild.innerHTML;
    document.getElementById("list").firstChild.remove();
  }
}

function getChildNodes() {
  var childNodes = "";
  document.getElementById("list").childNodes.forEach((node) => {
    childNodes += node.innerHTML + "";
  });

  document.getElementById("action").innerHTML = childNodes;
}

function displayAttr() {
  const element = document.getElementById("id-of-this-element");
  const className = element.getAttribute("class");
  const style = element.getAttribute("style");
  const id = element.getAttribute("id");
  document.getElementById("display-attributes").innerHTML =
    "Class - " +
    className +
    "<br>" +
    "Style - " +
    style +
    "<br>" +
    "ID - " +
    id +
    "<br>";
}

function changeColor(color) {
  const listItems = document.getElementsByTagName("li");
  for (var i = 0; i < listItems.length; i++) {
    listItems[i].setAttribute("style", `color:${color}`);
  }
}
