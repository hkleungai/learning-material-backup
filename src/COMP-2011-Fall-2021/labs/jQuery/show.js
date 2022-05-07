  // entry point for the javascript function...
  //  javascript interaction logic - powered by JQuery
 $(document).ready(function(){
   // default operations
   // id naming convention
   // menuXXX - id of menu items
   // blockXXX - id of blocks
   {
	
	$("#block0").siblings().hide();$("#block0").show();<!--INITIALIZE-SCRIPT-->
	
   }
   
      // Toggle between two views...
   
   $("#tabShowAllOnePage").click( function() {
	$("#block0").siblings().show();
	$("#block0").show();
	$("#sidebar").hide();
	$("#main").css("width","100%");
	$("#footer").hide();
	$("#deadline_blockquote").hide();
        }
   );
   
   $("#tabShowNormalView").click( function() {
	$("#block0").siblings().hide();
	$("#block0").show();
	$("#sidebar").show();		
	$("#main").css("width","730px");
	$("#footer").show();
	$("#deadline_blockquote").show();
        }
   );


   // font size manipulation
   $("#tabIncFontSize").click(function(){
	var s = $("#main").css("font-size");
	s = parseInt(s.substring(0, s.length-2));
	s = s+1;
	if (s>18) return false;
	$("#main").css("font-size", s+"px");
	}
   );
   
   $("#tabDecFontSize").click(function(){
	var s = $("#main").css("font-size");
	s = parseInt(s.substring(0, s.length-2));
	s = s-1;
	if (s<10) return false;
	$("#main").css("font-size",s+"px");
	}
   );
   

$("#menu0").click(function(){
$("#block0").siblings().hide();
$("#block0").show();
});
$("#menu1").click(function(){
$("#block1").siblings().hide();
$("#block1").show();
});
$("#menu2").click(function(){
$("#block2").siblings().hide();
$("#block2").show();
});
$("#menu3").click(function(){
$("#block3").siblings().hide();
$("#block3").show();
});
$("#menu4").click(function(){
$("#block4").siblings().hide();
$("#block4").show();
});
$("#menu5").click(function(){
$("#block5").siblings().hide();
$("#block5").show();
});
$("#menu6").click(function(){
$("#block6").siblings().hide();
$("#block6").show();
});
$("#menu7").click(function(){
$("#block7").siblings().hide();
$("#block7").show();
});
$("#menu8").click(function(){
$("#block8").siblings().hide();
$("#block8").show();
});
$("#menu9").click(function(){
$("#block9").siblings().hide();
$("#block9").show();
});
$("#menu10").click(function(){
$("#block10").siblings().hide();
$("#block10").show();
});

 });
