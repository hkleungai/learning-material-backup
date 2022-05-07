
	function loadCode(file, id) {
	  var xmlhttp = new XMLHttpRequest();
	  xmlhttp.onreadystatechange = function() {
	    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
	      var x = document.createElement("PRE");
	      x.className = "brush: c, cpp";
	      var code = document.getElementById(id);
	      while (code.hasChildNodes()) {
	    code.removeChild(code.firstChild);
	}
	x.innerHTML = xmlhttp.responseText.replace(/&/g, '&amp;').replace(/</g, '&lt;').replace(/>/g, '&gt;');
      code.appendChild(x);
      SyntaxHighlighter.highlight();

    }
  };
  xmlhttp.open("GET", file, true);
xmlhttp.setRequestHeader("Cache-Control", "no-cache");
xmlhttp.setRequestHeader("Pragma", "no-cache");
xmlhttp.setRequestHeader("If-Modified-Since", "Sat, 1 Jan 2000 00:00:00 GMT");
  xmlhttp.send();
}

