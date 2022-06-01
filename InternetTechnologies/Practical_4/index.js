document.addEventListener("DOMContentLoaded", () => {
  var colors = [
    "Red",
    "Green",
    "Blue",
    "BlueVoilet",
    "CornflowerBlue",
    "BlurryWood",
    "CadetBlue",
    "DarkOrchid",
    "DarkSlateGrey",
    "Indigo",
    "LightSeaGreen",
  ];
  var i = 1;
  var interval = setInterval(() => {
    i++;
    if (i > 10) {
      clearInterval(interval);
    } else {
      var div = document.createElement("div");
      var br = document.createElement("br");
      for (var j = 1; j <= 10; j++) {
        div.innerHTML += "\t" + i * j;
      }
      div.style.textAlign = "center";
      div.style.fontSize = 18 * (i / 2) + "px";
      div.style.color = colors[i];
      document.getElementById("container").appendChild(div);
      document.getElementById("container").appendChild(br);
    }
  }, 5000);
});
