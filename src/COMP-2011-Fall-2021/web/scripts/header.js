 // JavaScript Document
//if (/Android/.test(navigator.userAgent)) {
//  var oldlink = document.getElementsByTagName("link").item(1);
//  document.getElementsByTagName("head").item(0).removeChild(oldlink);
//}
document.write('<meta name="viewport" content="width=device-width, initial-scale=1.0">');
document.write('  <link rel="stylesheet" type="text/css" href="dropdown_menu.css" />');
// document.write('    <center><h2><a href="announcement.html" style="text-decoration: none; color:#333333;">COMP 2011 Introduction to Object-Oriented Programming</a></h2></center>\n');

document.write('<img class="bannerimg" src="./images/banner.png">\n');
// document.write('<br>\n');



document.write('<nav id="nav" role="navigation" class="nav-bar">');
document.write('	<a href="#nav" title="Show navigation">Show navigation</a>	<a href="#" title="Hide navigation">Hide navigation</a>');
//document.write('<img style="float: left; position:absolute; left:10px; padding-left:0px; margin:0px; cursor: pointer" src="images/fb.png" onclick="window.location.href=\'https://www.facebook.com/groups/566602710418758/\';"/>');
document.write('<ul class="nav">');
document.write('        <li><a href="announcements.html">Home</a></li>\n');
document.write('        <li><a href="courseDescription.html">Course Info</a>\n');
document.write('            <ul>\n');
document.write('               <li><a href="courseDescription.html">Course Details</a></li>\n');
document.write('               <li><a href="schedule.html">Schedule</a></li>\n');
document.write('               <li><a href="gradingScheme.html">Grading Scheme</a></li>\n');
document.write('               <li><a href="faq.html">FAQ</a></li>\n');
document.write('               <li><a href="code.html">Honor Code</a></li>\n');
document.write('            </ul>\n');
document.write('        </li>\n');
document.write('        <li><a href="instructors.html">People</a>\n');
document.write('            <ul>\n');
document.write('               <li><a href="instructors.html">Instructors</a></li>\n');
document.write('                <li><a href="tas.html">TAs</a></li>\n');
document.write('            </ul>\n');
document.write('        </li>\n');
document.write('        <li><a href="lectureNotes.html">Lectures</a>\n');
//document.write('            <ul>\n');
//document.write('               <li><a href="lectureNotes.html">Lecture Notes</a></li>\n');
//document.write('                  <li><a href="selfvid.html">Videos for self-study</a></li>\n');
//document.write('                  <li><a href="vid.html">Current Semester\'s Videos</a></li>\n');
// document.write('                  <li><a href="../lecture-videos/l1.html">L1 Videos</a></li>\n');
// document.write('                  <li><a href="../lecture-videos/l2.html">L2 Videos</a></li>\n');
// document.write('                  <li><a href="../lecture-videos/l3.html">L3/L4 Videos</a></li>\n');
//document.write('            </ul>\n');
document.write('        </li>\n');
document.write('        <li><a href="labs.html">Labs</a></li>\n');
document.write('        <li><a href="assignments.html">Assignments</a></li>\n');
document.write('         <li><a href="books.html">Other Materials</a>\n');
document.write('             <ul>\n');
document.write('                  <li><a href="books.html">Books in Library</a></li>\n');
document.write('                  <li><a href="self-tests.html">Self-Tests</a></li>\n');
document.write('                  <li><a href="past-papers.html">Past-papers</a></li>\n');
document.write('                  <li><a href="supplementary.html">Supplementary Materials</a></li>\n');
document.write('             </ul>\n');
document.write('         </li>\n');
document.write('      </ul>\n');
document.write('</nav>\n');
document.write('      <br style="clear: left;">\n');


/*
	VIEWPORT BUG FIX
	iOS viewport scaling bug fix, by @mathias, @cheeaun and @jdalton
*/

;(function(e){function o(){s.content="width=device-width,minimum-scale="+i[0]+",maximum-scale="+i[1];e.removeEventListener(n,o,true)}var t="addEventListener",n="gesturestart",r="querySelectorAll",i=[1,1],s=r in e?e[r]("meta[name=viewport]"):[];if((s=s[s.length-1])&&t in e){o();i=[.25,1.6];e[t](n,o,true)}})(document);




/*
	By Osvaldas Valutis, www.osvaldas.info
	Available for use under the MIT License
*/
	$( function()
	{
		$( '#nav li:has(ul)' ).doubleTapToGo();
	});


;(function( $, window, document, undefined )
{
	$.fn.doubleTapToGo = function( params )
	{
		if( !( 'ontouchstart' in window ) &&
			!navigator.msMaxTouchPoints &&
			!navigator.userAgent.toLowerCase().match( /windows phone os 7/i ) ) return false;

		this.each( function()
		{
			var curItem = false;

			$( this ).on( 'click', function( e )
			{
				var item = $( this );
				if( item[ 0 ] != curItem[ 0 ] )
				{
					e.preventDefault();
					curItem = item;
				}
			});

			$( document ).on( 'click touchstart MSPointerDown', function( e )
			{
				var resetItem = true,
					parents	  = $( e.target ).parents();

				for( var i = 0; i < parents.length; i++ )
					if( parents[ i ] == curItem[ 0 ] )
						resetItem = false;

				if( resetItem )
					curItem = false;
			});
		});
		return this;
	};
})( jQuery, window, document );
