/////No further editting needed
//// other stuff is just the static part for all pages

////claculate the forwarding anchor and ensure that we display in a frameset
var MapData = location.hash; 
var Name;
var ForwardName;
var bMove = false;
if (MapData.indexOf("Declaration")!=-1) {
    bMove = true;
    MapData = MapData.substring(MapData.indexOf("Declaration") + 11 );
    Name = "Declaration";
    ForwardName = "Definition";
}
if (MapData.indexOf("Definition")!=-1) {
    	bMove = true;
    	MapData = MapData.substring(MapData.indexOf("Definition") + 10 );
	Name = "Definition";
	ForwardName = "Definition";
}
if (MapData.indexOf("Computation")!=-1) {
    	bMove = true;
    	MapData = MapData.substring(MapData.indexOf("Computation") + 11 );
	Name = "Computation";
	ForwardName = "Computation";   
}
if  (bMove)
{
	var DataPage = location.href;
	var MapResult = MapAnchors(MapData,Name);
	if (MapResult.substring(0,1) == 'L')
	{
	   DataPage = 'index.html' + '#Page' + MapResult.substring(2);
	} 
	else
	{
	  if (MapResult.substring(0,1) == 'F')
	  {
	      ////forward to another page
	    DataPage = MapResult.substring(2) + '#' + ForwardName + MapData;
	  }
	  else { DataPage = 'index.html#' + MapResult.substring(2);}; 
	}
        top.location.href= DataPage;
        window.status=('DataPage is ' + DataPage + '  Input ' + MapData);
}

////check which version we have
var ie4=document.all
var ns6=document.getElementById&&!document.all

//// write the entry tag to the data
if (ie4||ns6)
document.write('<div id="dropmenudiv" style="visibility:hidden;width:'+menuwidth+';background-color:'+menubgcolor+'"></div>')

////function to calculate offset in browser
function getposOffset(what, offsettype){
	var totaloffset=(offsettype=="left")? what.offsetLeft : what.offsetTop;
	var parentEl=what.offsetParent;
	while (parentEl!=null){
		totaloffset=(offsettype=="left")? totaloffset+parentEl.offsetLeft : totaloffset+parentEl.offsetTop;
		parentEl=parentEl.offsetParent;
	}
	return totaloffset;
}

////function to check compatibility
function iecompattest(){
return (document.compatMode && document.compatMode!="BackCompat")? document.documentElement : document.body
}

////reset browser data
function clearbrowseredge(obj, whichedge){
	var edgeoffset=0
	if (whichedge=="rightedge"){
	var windowedge=ie4 && !window.opera? iecompattest().scrollLeft+iecompattest().clientWidth-15 : window.pageXOffset+window.innerWidth-15
	dropmenuobj.contentmeasure=dropmenuobj.offsetWidth
	if (windowedge-dropmenuobj.x < dropmenuobj.contentmeasure)
		edgeoffset=dropmenuobj.contentmeasure-obj.offsetWidth
	}
	else{
		var topedge=ie4 && !window.opera? iecompattest().scrollTop : window.pageYOffset
		var windowedge=ie4 && !window.opera? iecompattest().scrollTop+iecompattest().clientHeight-15 : window.pageYOffset+window.innerHeight-18
		dropmenuobj.contentmeasure=dropmenuobj.offsetHeight
		if (windowedge-dropmenuobj.y < dropmenuobj.contentmeasure){ //move up?
			edgeoffset=dropmenuobj.contentmeasure+obj.offsetHeight
			if ((dropmenuobj.y-topedge)<dropmenuobj.contentmeasure) //up no good either?
				edgeoffset=dropmenuobj.y+obj.offsetHeight-topedge
		}
	}
	return edgeoffset
}

////populate menu data
function populatemenu(what){
	if (ie4||ns6)
	dropmenuobj.innerHTML=what.join("")
}

var currentMenuRef;

////function to show or hide the drop down menu
function showhide(hrefObj, obj, e, visible, hidden, menuwidth){
if (ie4||ns6)
	dropmenuobj.style.left=dropmenuobj.style.top=-500
if (menuwidth!=""){
	dropmenuobj.widthobj=dropmenuobj.style
	dropmenuobj.widthobj.width=menuwidth
}
if (e.type=="click" && obj.visibility==hidden) 
{
	obj.visibility=visible
}
else if (e.type=="click")
{
	obj.visibility=hidden
} 
}


//// show drop down menu
function dropdownmenu(obj, e, menucontents, menuwidth){
	if (window.event) event.cancelBubble=true
	else if (e.stopPropagation) e.stopPropagation()
	dropmenuobj=document.getElementById? document.getElementById("dropmenudiv") : dropmenudiv
	if (currentMenuRef != obj) 		////display the new data
	{    dropmenuobj.visibility = "hidden";
	     populatemenu(menucontents);
	     currentMenuRef = obj
	}
	else
	{
	     dropmenuobj.visibility = "visible";	
	}
	if (ie4||ns6){
		showhide(obj, dropmenuobj.style, e, "visible", "hidden", menuwidth)
		
		dropmenuobj.x=getposOffset(obj, "left")
		dropmenuobj.y=getposOffset(obj, "top")
		dropmenuobj.style.left=dropmenuobj.x-clearbrowseredge(obj, "rightedge")+"px"
		dropmenuobj.style.top=dropmenuobj.y-clearbrowseredge(obj, "bottomedge")+obj.offsetHeight+"px"
	}

	return clickreturnvalue()
}


////function for return value handling
function clickreturnvalue(){
	if (ie4||ns6) return false
	else return true
}

////function to hide the menu
function hidemenu(e){
  if (typeof dropmenuobj!="undefined"){
    if (ie4||ns6)
    {
	dropmenuobj.style.visibility="hidden"
    }
    dropmenuobj.innerHTML="updating data"
    currentMenuRef = "undefined";
  }
}

document.onclick=hidemenu