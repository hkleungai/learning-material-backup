   var group="/287917698266936"; 


 // This is called with the results from from FB.getLoginStatus().
  function statusChangeCallback(response) {
    // The response object is returned with a status field that lets the
    // app know the current login status of the person.
    // Full docs on the response object can be found in the documentation
    // for FB.getLoginStatus().
    console.log(response.status); 
    if (response.status === 'connected') {
      // Logged into your app and Facebook.
      testAPI();
    } else if (response.status === 'not_authorized') {
      // The person is logged into Facebook, but not your app.
      document.getElementById('status').innerHTML = 'Please log ' +
        'into this app.';
    } else {
      // The person is not logged into Facebook, so we're not sure if
      // they are logged into this app or not.
      document.getElementById('status').innerHTML = 'Please kindly log ' +
        'into Facebook. If you have signed in and the situation persists, please consider using browsers other IE and Edge.';
    }
  }

  // This function is called when someone finishes with the Login
  // Button.  See the onlogin handler attached to it in the sample
  // code below.
  function checkLoginState() {
    FB.getLoginStatus(function(response) {
      statusChangeCallback(response);
    });
  }

  window.fbAsyncInit = function() {
  FB.init({
    appId      : '1756655111223047',
    cookie     : true,  // enable cookies to allow the server to access 
                        // the session
    xfbml      : true,  // parse social plugins on this page
    version    : 'v2.7' // use version 2.2
  });

  // Now that we've initialized the JavaScript SDK, we call 
  // FB.getLoginStatus().  This function gets the state of the
  // person visiting this page and can return one of three states to
  // the callback you provide.  They can be:
  //
  // 1. Logged into your app ('connected')
  // 2. Logged into Facebook, but not your app ('not_authorized')
  // 3. Not logged into Facebook and can't tell if they are logged into
  //    your app or not.
  //
  // These three cases are handled in the callback function.

  FB.getLoginStatus(function(response) {
    statusChangeCallback(response);
  });

  };

  // Load the SDK asynchronously
  (function(d, s, id) {
    var js, fjs = d.getElementsByTagName(s)[0];
    if (d.getElementById(id)) return;
    js = d.createElement(s); js.id = id;
    js.src = "https://connect.facebook.net/en_US/sdk.js";
    fjs.parentNode.insertBefore(js, fjs);
  }(document, 'script', 'facebook-jssdk'));


  function setSenderPic(tag, id) {
     FB.api(id + "/picture",  function (response) {
      if (response && !response.error) {
       var img = document.createElement("img");
       img.src = response.data.url;
       img.style.verticalAlign = "middle";
       img.style.paddingRight = "10px";
       var senderBox = document.getElementById(tag);
       senderBox.insertBefore(img, senderBox.firstChild);
      }
     })   
  }

  // Here we run a very simple test of the Graph API after login is
  // successful.  See statusChangeCallback() for when this call is made.
  function testAPI() {
    var result="";
    FB.api(
    group + "/feed",
    {"fields": "id,updated_time,created_time,icon,full_picture,message,story,from"},
    function (response) {
      if (response && !response.error) {
        /* handle the result */
	var data = response.data;
	for (index = 0; index < data.length && index < 10; index++) {
	   var item=document.createElement("div");
	   var time_node=document.createElement("div");
           var time_text="";
	   if (typeof data[index].updated_time !== 'undefined')
	       time_text=document.createTextNode(timeAgo(data[index].updated_time));
           else if (typeof data[index].created_time !== 'undefined')
	       time_text=document.createTextNode(timeAgo(data[index].created_time));
	   var story_node=document.createElement("div");
           var story_text=document.createTextNode(data[index].story);
           var story_text2=document.createTextNode(data[index].message);
	   var sender_node=document.createElement("div");
	   var pic_node=document.createElement("img");
	   sender_node.id="sender"+index;

	   /** init style**/
	   item.className = "itemClass";
	   time_node.className = "timeClass";
	   story_node.className = "storyClass";
	   sender_node.className = "senderContainerClass";
	   pic_node.className = "imgClass";


	   if (typeof data[index].story !== 'undefined') {
	       story_node.appendChild(story_text);
           } else {
	       var sender_name=document.createTextNode(data[index].from.name + " posted");
	       sender_name.className = "senderClass";
	       sender_node.appendChild(sender_name);
	   }
           if (typeof data[index].message !== 'undefined')
	       story_node.appendChild(story_text2);
           if (typeof data[index].updated_time !== 'undefined')
               time_node.appendChild(time_text);
	   else
	       time_node.innerHTML = '--';
	   item.appendChild(time_node);
	   item.appendChild(sender_node);
	   if (typeof data[index].full_picture !== 'undefined') { 
	       pic_node.src=data[index].full_picture;
	       item.appendChild(pic_node);
	   }
	    item.appendChild(story_node);
	    //story_node.appendChild(story_text);
	    setSenderPic(sender_node.id, data[index].from.id);
	   getComments(data[index].id, item);
  	    document.getElementById('feed').appendChild(item);         
	   
	}
      }
    });

  }

function getComments(postid, pitem) {
    FB.api(
    "/" + postid + "/comments",
    {
	"summary": true,
	"filter":"stream" 
    },
    function (response) {
      if (response && !response.error) {
	var data = response.data;
	if (data.length == 0) {
	    return; 
	}
        /* handle the result */
	var reply=document.createElement("div");
	for (index = 0; index < data.length; index++) {
	   var item=document.createElement("div");
	   var time_node=document.createElement("div");
	   time_node.className = "commentClass";
           var time_text="";
           var story_text=document.createTextNode(data[index].story);
           var story_text2=document.createTextNode(data[index].message);
	    

	    var sender_name=document.createTextNode(data[index].from.name + ": ...");
	    //sender_name.className = "senderClass";
	    var sender_node=document.createElement("label");
	    sender_node.appendChild(sender_name);
	    sender_node.htmlFor = data[index].id;
	    sender_node.className = "commentCollapse";
	    var content_node = document.createElement("input");
	    content_node.id=data[index].id;
	    content_node.type="checkbox";
	    var data_node = document.createElement("div");
	    data_node.appendChild(story_text2);
	    
	    time_node.appendChild(sender_node);
	    time_node.appendChild(content_node);
	    time_node.appendChild(data_node);

	    reply.appendChild(time_node);
	}
//	console.log ("before exit");
//	console.log(reply);
	pitem.appendChild(reply);
      }
    });
}

// copy from stackoverflow: http://stackoverflow.com/questions/2782976/convert-facebook-date-format-to-javascript-date

function timeAgo(time){
var dateString = new String(time);//.replace(/\.[0-9]*/g,"").replace(/\+0000/g,"");
var date1 = new Date(dateString);
var d = new Date();
var diff = ((d.getTime() - date1.getTime()) / 1000);
var day_diff = Math.floor(diff / 86400);

if ( isNaN(day_diff) || day_diff < 0 || day_diff >= 31 )
    return;

return day_diff == 0 && (
        diff < 60 && "just now" ||
        diff < 120 && "1 minute ago" ||
        diff < 3600 && Math.floor( diff / 60 ) + " minutes ago" ||
        diff < 7200 && "1 hour ago" ||
        diff < 86400 && Math.floor( diff / 3600 ) + " hours ago" || "") ||
    day_diff == 1 && "Yesterday" ||
    day_diff < 7 && day_diff + " days ago" ||
    day_diff < 31 && Math.ceil( day_diff / 7 ) + " weeks ago";
}

