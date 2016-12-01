document.writeln("Дата последней модификации документа: " + document.lastModified);

function click_window(){
	alert(window.status);
	window.status = "Open";
}

function click_navigator(){
	var n = navigator.appName;
	var v = navigator.appVersion;
	alert("Информация о используемом браузере: " + n + v);
}

function click_location(){
	var name = prompt("Пожалуйста, введите ваше имя:","Name");
	alert("Здравствуйте, " + name +  "        URL: " + window.location.href);
}

function click_screen(){
	var wid = screen.width;
	var hei = screen.height;
	alert("width: " + wid + " height: " + hei);
}
