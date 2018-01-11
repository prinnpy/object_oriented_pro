//Check off specific todos
$("ul").on("click", "li", function(){
  $(this).toggleClass("completed");
});

//click on x to delete todos
$("ul").on("click","span", function(event){
  $(this).parent().fadeOut(500, function(){
    $(this).remove();
  });
  event.stopPropagation();
});

//text input
$("input[type='text']").keypress(function(event){
  if (event.which === 13) {
    var todoText = $(this).val();
    $(this).val(" ");
    //create new li and add to ul
    $("ul").append("<li><span>X</span>" + " " + todoText + "</li>");
  }
});
