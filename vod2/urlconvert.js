function urlconvert(a,o){
var oldurl=trimString(a);
    if (o==true){
	    return Thunderdecode(oldurl);
	}else{
        return ThunderEncode(oldurl);
    }
}

function ThunderEncode(t_url) {
	var thunderPrefix = "";
	var thunderPosix = "";
	var thunderTitle = "";
	var tem_t_url = t_url;
	var thunderUrl = encode64(tem_t_url);
	return thunderUrl;
}

function Thunderdecode(url) {

	 url=url.replace('&url=','');
     thunderUrl='&url='+decode64(url);

	 return thunderUrl;
}

function trimString(str)
  {   
  var   re;   
  var   newstr;   
  re   =   new   RegExp("^(\\s)*");   
  re2   =   new   RegExp("(\\s)*$");   
  newstr   =   str.replace(re,"");   
  newstr   =   newstr.replace(re2,"");
  return   newstr;
}

function getRootPath() {
    var strFullPath = window.document.location.href;
    var strPath = window.document.location.pathname;
    var pos = strFullPath.indexOf(strPath);
    var prePath = strFullPath.substring(0, pos);
    var postPath = strPath.substring(0, strPath.substr(1).indexOf('/') + 1);
    return (prePath + postPath);
} 