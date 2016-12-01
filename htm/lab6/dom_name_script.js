

$(document).ready(function(){
    $("#h").mouseover(function(){
        $("#h").css("color", "yellow");
        $("#h").css("background-color", "#F8E0F7");
        $("#h").css("font-style", "italic");
    });
    $("#h").mouseout(function(){
        $("#h").css("color", "");
        $("#h").css("background-color", "");
        $("#h").css("font-style", "");
    });
});

$(document).ready(function(){
    $("#p").mouseover(function(){
        $("#p").css("color", "purpule");
        $("#p").css("background-color", "#CECEF6");
        $("#p").css("font-weight", "bold");
        $("#p").css("font-style", "italic");
    });
    $("#p").mouseout(function(){
        $("#p").css("color", "");
        $("#p").css("background-color", "");
        $("#p").css("font-weight", "");
        $("#p").css("font-style", "");
    });
});

$(document).ready(function(){
    $("#pp").mouseover(function(){
        $("#pp").css("color", "#0B610B");
        $("#pp").css("background-color", "#D0F5A9");
        $("#pp").css("font-weight", "bold");
        $("#pp").css("font-style", "italic");
        $("#pp").css("position", "relative");
        $("#pp").css("top", "-20px");
    });
    $("#pp").mouseout(function(){
        $("#pp").css("color", "");
        $("#pp").css("background-color", "");
        $("#pp").css("font-weight", "");
        $("#pp").css("font-style", "");
        $("#pp").css("position", "relative");
        $("#pp").css("top", "0px");
    });
});

function format(){
     $("#p").css("padding-left", "2.5em");
     $("#p").css("line-height", "1.5");
     $("#p").css("text-indent", "25px");
}

function cancel(){
    $("#p").css("padding-left", "0px");
    $("#p").css("line-height", "1");
    $("#p").css("text-indent", "0px");
}

function ly1(){
$(".pic2").css({opacity:'0'});
}

function ly2(){
$(".pic2").css({opacity:'1'});
}

function ly3(){
$(".pic3").css({top:'-800px'});
$(".pic1").css({top:'400px'});
}
