function urlconvert(a,o){
var oldurl=trimString(a);
    if (o==true){
	    return Thunderdecode(oldurl);
	}else{
        return ThunderEncode(oldurl);
    }
}

function ThunderEncode(t_url) { //地址加密
	var thunderPrefix = "";
	var thunderPosix = "";
	var thunderTitle = "";
	var tem_t_url = t_url;
	var thunderUrl = encode64(tem_t_url);
	return thunderUrl;
}

function Thunderdecode(url) { //地址解密

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