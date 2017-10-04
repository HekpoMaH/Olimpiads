var id = "theLogo";
var logoSelected = -1;
var logoText = "";
var html;

function updateImage() {
	   	var logoImageUrl;
	   	if (logoSelected == 1) logoImageUrl = "images/logo_welcome.gif";
		else if (logoSelected == 2) logoImageUrl = "images/logo_contests.gif";
		else if (logoSelected == 3) logoImageUrl = "images/logo_resources.gif";
		else if (logoSelected == 4) logoImageUrl = "images/logo_magazine.gif";
		else if (logoSelected == 5) logoImageUrl = "images/logo_contactus.gif";
		else logoImageUrl = "images/logo_blank.gif";

		if (document.images["logoNavigationImage"]) {
		   document.images["logoNavigationImage"].src = logoImageUrl;
		}
		else {
			setTimeout("updateImage()", 10);
			return;
		}
}

function updateLogoSelected(logoSelectedVal) {
	if (logoSelected != logoSelectedVal) { 
	   logoSelected = logoSelectedVal; 
	   updateImage(); 
	}
}

function makeLogo() {
  //parse the URL, if necessary
	var i = location.href.indexOf("?");
	if (i > -1) {
	   var params = location.href.substring(i+1);
	   
	   logoText = unescape( params.substring(1) );
	   
	   var logoSelectedVal = params.charAt(0); 
	   updateLogoSelected(logoSelectedVal)
	}

  //write logo text
	html = "&nbsp;" + logoText;
	document.write(html);
}



function updateText() {
	if (document.getElementById(id) || document.all[id]) {
	   if (document.getElementById) document.getElementById(id).innerHTML = html;
	   else document.all[id].innerHTML = html;
	}
	else {
	   setTimeout("updateText()", 10);
	   return;  
	}
}

function update(logoSelectedVal, logoTextVal) {
	if (logoSelectedVal != null) 
	   	if (document.layers) {
		   logoSelected = logoSelectedVal;
		   logoText = logoTextVal;
		   var i = top.frames.logo.location.href.indexOf("?");
		   if (i == -1) i = top.frames.logo.location.href.length;

		   top.frames.logo.location.href = top.frames.logo.location.href.substring(0,i)+"?"+logoSelected+escape(logoText);
		}
		else { 
	   		updateLogoSelected(logoSelectedVal)

			logoText = logoTextVal; html = "&nbsp;" + logoText;	updateText();
		}

}
