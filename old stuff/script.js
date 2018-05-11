$(function(){
 $("#question").hide();
         $("button").click(function(){
             $("#f1_card").css({
                 "-webkit-transform":" rotateY(180deg)",
                 "-moz-transform":" rotateY(180deg)",
                 "-o-transform":" rotateY(180deg)",
                 "transform":" rotateY(180deg)",
                 "-webkit-box-shadow":" -5px 5px 5px #aaa",
                 "-moz-box-shadow":" -5px 5px 5px #aaa",
                 "box-shadow":" -5px 5px 5px #aaa"
             });
             $("#answer").hide();
             $("#question").show();
         });
         $("#question").click(function(){
             $("#answer").show();
             $("#question").hide();
             $("#f1_card").css({
                 "-webkit-transform":" ",
                 "-moz-transform":" ",
                 "-o-transform":" ",
                 "transform":" ",
                 "-webkit-box-shadow":" ",
                 "-moz-box-shadow":" ",
                 "box-shadow":" "
             });
         });
});