document.addEventListener("DOMContentLoaded", () => {
  const buttons = document.getElementsByClassName("button");
  for (let i = 0; i < buttons.length; i++) {
    buttons.item(i).addEventListener("click", (event) => {
      changeActiveButton(buttons.item(i).dataset.name);
    });
  }
});

// Clock Function
setInterval(() => {
  const clock = document.getElementById("clock");
  clock.innerHTML = new Date().toLocaleTimeString().toString();
}, 1000);

// Chnage Active Button
function changeActiveButton(name) {
  const buttons = document.getElementsByClassName("button");
  const windows = document.getElementsByClassName("container");
  console.log;
  for (let i = 0; i < buttons.length; i++) {
    if (buttons.item(i).dataset.name == name) {
      buttons.item(i).className = "button active";
      windows.item(i).className = "container";
    } else {
      buttons.item(i).className = "button";
      windows.item(i).className = "container hide";
    }
  }
}
