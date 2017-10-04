var menuSelected = -1;
var Menu = new Array(); // array of: ID No. | Parent ID | Name | URL or = | Offset
				
		Menu[0]  = "1|0|Здравейте|welcome/main.html|1";
		
		Menu[1]	 = "2|0|Състезания|=|1";
		Menu[2]  = "21|2|Национални|=|2";
		Menu[3]  = "211|21|Ученически|contests/main_nat_hs.html|3";
		Menu[4]  = "212|21|Други|contests/main_nat_other.html|3";
		Menu[5]  = "22|2|Международни|=|2";
		Menu[6]  = "221|22|Ученически|contests/main_int_hs.html|3";
		Menu[7]  = "222|22|Други|contests/main_int_other.html|3";
		Menu[8] = "223|22|IOI 2009|contests/ioi/2009/main.html|3";		
		
		Menu[9]  = "3|0|Ресурси|=|1";
		Menu[10]  = "31|3|Български|=|2";
		Menu[11] = "311|31|Библиотеки|resources/main_bg_libraries.html|3";
		Menu[12] = "312|31|Книги и статии|resources/main_bg_papers.html|3";
		Menu[13] = "313|31|Вестници и списания|resources/main_bg_journals.html|3";
		Menu[14] = "32|3|Английски|=|2";
		Menu[15] = "321|32|Библиотеки|resources/main_en_libraries.html|3";
		Menu[16] = "322|32|Книги и статии|resources/main_en_papers.html|3";
		Menu[17] = "323|32|Вестници и списания|resources/main_en_journals.html|3";
		
		Menu[18] = "4|0|ИнфоМан списанието|=|1";
		Menu[19] = "46|4|<b>10 ГОДИНИ ИНФОМАН!!!</b>|anniversary/main.html|2";
		Menu[20] = "41|4|За списанието|magazine/main_about.html|2";
		Menu[21] = "42|4|Текущ брой|magazine/main_current.html|2";
		Menu[22] = "45|4|Въведение в...|articles/main.html|2"
		Menu[23] = "43|4|Архив|magazine/main_archive.html|2";
				
			 
		Menu[24] = "6|0|Форум|/forum|1";

		Menu[25] = "7|0|Национална ранглиста|resources/ranglist/2007-2008/ranglista-24-03-2008.htm|1";

		Menu[26] = "5|0|За контакти|contactus/main.html|1";	
			
function makeMenu() {
	//parse the URL, if necessary
		var i = location.href.indexOf("?");
		if (i > -1) {
		   var params = location.href.substring(i+1);
		   menuSelected = params;
		}

	//create menu
		 var html = "<table border=0 cellpadding=0 cellspacing=0 width=178>";
		 
		 for (var i = 0; i < Menu.length; i++) {
		 	//get element properties
		 		var menuItemVal = Menu[i].split("|");
				
			//output line separator if necessary
				if(1 < menuItemVal[0] && menuItemVal[0] < 10) 
				  html += "<tr><td><img src=\"images/menu_line.gif\" border=0 width=178></td></tr>";
				
			//compute the offset in the menu
				var offset;
				if (menuItemVal[4] == 1) offset = 5; 
				else if (menuItemVal[4] == 2) offset = 20;
				else if (menuItemVal[4] == 3) offset = 35; 
				
			//output next element
				html += "<tr><td>";
				
				html += "<img src=\"images/menu_pixel.gif\" border=0 height=1 width="+offset+">";
				
				if ( menuItemVal[3] == "=" ) html += menuItemVal[2];
				else {
					 html += "<a";
					 if(menuItemVal[0] == menuSelected) html += " class=\'current\'"; 
					 if(menuItemVal[0] == 6) html += " onClick='top.frames.menu.update(6);'"; 
					 html += " id=\'link" + menuItemVal[0] + "\'";
					 html += " href=\'"+menuItemVal[3]+"\'" ;
					 html += " onMouseOver=\'linkHoover(" + menuItemVal[0] + ",\"red\")\'";
					 html += " onMouseOut=\'linkHoover(" + menuItemVal[0] + ",\"black\")\'";
					 html += ">"+menuItemVal[2]+"</a>";
				}
				
				html += "</td></tr>";
		 }
		 html += "</table>";

		 document.write(html);
}

function linkHoover(idNumber, idColor) {
	if (!document.leayers && idNumber != menuSelected) {
		id = "link"+idNumber; color = idColor; updateLinkStyle();
	}
}



var id;
var color;

function updateLinkStyle() {
    if (menuSelected <= 0) return;
	
	if (document.getElementById(id) || document.all[id]) {
	   if (document.getElementById) document.getElementById(id).style.color = color;
	   else document.all[id].style.color = color;
	}
	else {
	   setTimeout("updateLinkStyle()", 10);
	   return;  
	}
}

function update(menuSelectedVal) {
	if (menuSelectedVal != null && menuSelectedVal != menuSelected) 
	   	if (document.layers) {
		   menuSelected = menuSelectedVal;
		   var i = top.frames.menu.location.href.indexOf("?");
		   if (i == -1) i = top.frames.menu.location.href.length;

		   top.frames.menu.location.href = top.frames.menu.location.href.substring(0,i)+"?"+menuSelected;
		}
		else { 
			id = "link"+menuSelected; color = "black"; updateLinkStyle();
			menuSelected = menuSelectedVal; 			 
			id = "link"+menuSelected; color = "red"; updateLinkStyle();

			if (menuSelectedVal == 6) {
				top.frames.logo.update(6, "форум");
			}
		}
}
