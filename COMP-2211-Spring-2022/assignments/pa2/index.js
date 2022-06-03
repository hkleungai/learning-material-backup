(function() {
	var j = 0
	function han(){if(document.visibilityState=='hidden'&&j==1){j=2}else if(document.visibilityState=='visible'&&j==2){console.log('Welcome back!');$('#troll-alert').removeClass('invisible');document.removeEventListener('visibilitychange',han)}}
	document.addEventListener("visibilitychange",han);
	var us=['https://youtu.be/klfT41uZniI','https://www.bilibili.com/video/BV1uT4y1P7CX/']
	var idx=(navigator.language.toLowerCase()=='zh-cn')+0
	var con = new AbortController()
	setTimeout(con.abort.bind(con),2000)
	var p=us.map((u,i)=>fetch(u,{method:'HEAD',mode:'no-cors',signal:con.signal}).then(function(){return i}))
	Promise.race(p).catch(function(){return idx}).then(function(r){idx=r;console.log(idx)})
	$(function(){$('a[href="files/pa2_solution.zip"]').click(function(){j==0&&(j=1);window.open(us[idx],'_blank').focus();return false;})});
})()
