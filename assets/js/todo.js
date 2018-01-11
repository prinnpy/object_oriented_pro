//Check off specific todos
$("li").click(function(){
  $(this).toggleClass("completed");
});

//click on x to delete todos
$("span").click(function(event){
  $(this).parent().fadeOut(500, function(){
    $(this).remove();
  });
  event.stopPropagation();
});
