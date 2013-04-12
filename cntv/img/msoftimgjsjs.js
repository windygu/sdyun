function $(v){
	return document["getElementById"](v);
}
function killErrors(){return true;}
function shows(){
	whichEl=eval("tv_left");
	if(whichEl["style"]["display"]=="none"){
		eval("tv_left.style.display='';");
		f1["innerHTML"]="";
	}
	else {
		eval("tv_left.style.display='none';");
		f1["innerHTML"]="";
	} 
} 
function showsr(){
	whichEl=eval("tv_right");
	if(whichEl["style"]["display"]=="none"){
		eval("tv_right.style.display='';");
		f2["innerHTML"]="";}
	else {
		eval("tv_right.style.display='none';");
		f2["innerHTML"]="";
	} 
} 
var c=1;
function v(i,u,h){
	$("c"+c)["className"]="";
	$("c"+i)["className"]="cur";
	c=i;
	if(h==1){
		$("playkk")["src"]=u;
		$("k2")["style"]["display"]="";
		$("k1")["style"]["display"]="none";
		var uu=window["frames"]["playpp"]["document"]["location"]["href"];
		if(uu["indexOf"]("live.htm")==-1){
			$("playpp")["src"]="live.htm";
		} 
	}
	else {
		$("playpp")["src"]=u;$("k1")["style"]["display"]="";
		$("k2")["style"]["display"]="none";
		$("playkk")["src"]="about:blank";
	} 
} 