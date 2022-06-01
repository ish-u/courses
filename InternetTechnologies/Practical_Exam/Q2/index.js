$(function () {
  $(".container").css({
    display: "flex",
    "flex-direction": "column",
    "justify-content": "center",
    "align-items": "center",
    width: "80vw",
    margin: "0 auto",
  });

  var $veg = $(".veg");
  var $nonVeg = $(".non-veg");
  var $switch = $("#switch");
  $switch.addClass("veg-button");
  $nonVeg.hide();

  $switch.click(() => {
    var displayveg = $nonVeg.css("display");
    if (displayveg === "none") {
      $veg.hide();
      $nonVeg.show();
      $switch.text("Non-Veg");
      $switch.addClass("non-veg-button");
    } else {
      $nonVeg.hide();
      $veg.show();
      $switch.text("Veg");
      $switch.removeClass("non-veg-button");
      $switch.addClass("veg-button");
    }
  });
});
