
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=gb2312" />
<title>松达电脑科技－CNTV直播</title>
<style type="text/css"> 
<!-- 
body{margin:0px;} body{background-color: #000000 repeat-y left top;}
* {padding:0;margin:0; font-size:12px;font-family: Verdana, Arial, Helvetica, sans-serif;} 
body {SCROLLBAR-FACE-COLOR: #444; SCROLLBAR-HIGHliGHT-COLOR: #999; SCROLLBAR-SHADOW-COLOR: #222; SCROLLBAR-3DliGHT-COLOR: #000; SCROLLBAR-ARROW-COLOR: #ccc; SCROLLBAR-TRACK-COLOR: #666; SCROLLBAR-DARKSHADOW-COLOR: #111; background-color: #000000; } 
body,td,th { font-family: Verdana, Arial, Helvetica, sans-serif; color: #FFFFFF; } h1{display:none;} 
img{border:none;} ul{padding:0;margin:0;list-style-type:none;}
/* 直播频道列表导航菜单 */ 
#menu {width:188px; margin-left:2px;} 
#menu li {list-style-type:none; display:block; width:188px;line-height:23px; background:url(img/menu_listbk.gif)  no-repeat;} 
#menu li a { display:block; text-decoration:none;  width:100%;  padding:1px 3px 0 3px; line-height:23px; } 
#menu li a.list_name{ float:left;display:block; width:100%; padding-left:18px;line-height:21px;   } 
#menu li a.list_play{ float:left;display:block; width:32px; line-height:21px;color:#888;  } 
#menu li.ft {list-style-type:none; display:block;  width:188px; line-height:24px; background:urlmenu_listbk2.gif)  no-repeat left 2px;} 
#menu h1 { display:block;font-size:12px;line-height:24px; font-weight:normal; margin-top:1px;} 
#menu h1.ft_1{display:block; width:100%; text-align: left; padding-left:18px; border-bottom:#000 2px solid;} 
#menu h2.ft_2{display:block; width:100%; text-align: left; padding-left:12px; font-size:12px;font-weight:normal;text-decoration:none; margin-top:5px; } 
#menu h2.lm_2 a{display: block; BACKGROUND: url(tv.gif) #363636 no-repeat 8px 3px; 
MARGIN-BOTTOM: 1px; WIDTH: 100%; COLOR: #d7d7d7; TEXT-INDENT: 25px; LINE-HEIGHT: 25px; BORDER-BOTTOM: #333333 1px solid; HEIGHT: 25px; TEXT-DECORATION: none}
#menu h2.lm_2 a:hover{FONT-WEIGHT: bold; font-size:14px; BACKGROUND: url(lb/tv/tv.gif) #555555 no-repeat 8px 3px; color:#ececec;}
#menu h1.lm_1{display:block; width:188px; color:#333;text-align:left; padding-left:5px;line-height:21px; } 
#menu h2.lm_2{display:block; width:188px; color:#333; text-align: left;font-size:12px;font-weight:normal;text-decoration:none; margin-top:3px; } 
#menu h1 a,#menu h1.ft_1 a{color:#ccc;} 
#menu h1 a:hover,#menu h1.ft_1 a:hover,#menu h2.ft_2 a:hover{color:#ff6600;}
#menu li a:hover span {cursor:hand;} 
#menu li img{ float:left;display: block;} #menu li.end{border-bottom-width:1px; } 
COLOR: #ff6600;TEXT-INDENT: 2px; padding-top:5px; LINE-HEIGHT: 22px; HEIGHT: 22px; TEXT-ALIGN: left;}
.mlt a{COLOR: #ff6600;text-decoration: none;}
.mlt a:hover{COLOR: #ff6600;text-decoration: none;}
 --> 
</style> 
<script language="javascript">
<!--
if(parent.frames.length==0){top.location.href="http://wpa.qq.com/msgrd?v=3&uin=1160038650&site=qq&menu=yes";}
-->
</script>          
<SCRIPT language="VBScript" type="text/VBScript">
Function bytes2BSTR(vIn)
strReturn = ""
For i = 1 To LenB(vIn)
ThisCharCode = AscB(MidB(vIn,i,1))
If ThisCharCode < &H80 Then
strReturn = strReturn & Chr(ThisCharCode)
Else
NextCharCode = AscB(MidB(vIn,i+1,1))
strReturn = strReturn & Chr(CLng(ThisCharCode) * &H100 + CInt(NextCharCode))
i = i + 1
End If
Next
bytes2BSTR = strReturn
End Function
</script>
<script language="javascript" type="text/javascript">
function GetData(str) 
{ 
if(str!=""){
var str2="/search/so.asp?k="+str.replace(/(\/|\\|\||\(|\)|\.|\*|\$|\&|\?|\+|\{|\}|\^|\[|\]|\-)/ig,'');
		document.getElementById("halist").style.display="none";
		document.getElementById("solist").style.display="block";
		document.getElementById("solist").innerHTML=getDatal(str2);
		}
		else{
		document.getElementById("solist").style.display="none";
		document.getElementById("halist").style.display="block";
	}
}

function getDatal(url){  
    var xmlhttp = new ActiveXObject("MSXML2.XMLHTTP.3.0");
    xmlhttp.open("post",url,false);   
    xmlhttp.send();              
    return bytes2BSTR(xmlhttp.responsebody);       
    xmlhttp=nothing
}  
document.oncontextmenu=new Function("event.returnValue=false;"); 
document.onselectstart=new Function("event.returnValue=false;");
</script>           
<base target="playpp">
</head>
<body  ondragstart="return false" onselectstart="return false">
<div class="mlt">

</div>
<div id="halist" style="display:block;">
<ul id="menu">

 <li class="ft">
<hr width=95% size=1 color=#A9C8E4 style="FILTER: alpha(opacity=100,finishopacity=0,style=3)"> 
      <h1 class="ft_1"><a target="_blank" title="CNTV直播" href="http://wpa.qq.com/msgrd?v=3&uin=1160038650&site=qq&menu=yes">松达影视盒－CNTV直播</a><hr width=95% size=1 color=#A9C8E4 style="FILTER: alpha(opacity=100,finishopacity=0,style=3)"> 
</h1></li>



<li><h1 class="lm_1"> <a href="javascript:OpenChanel(1);" class="list_name" target="_self">央视直播HD</a></h1>
<h2 class="lm_2" id="CHT_1" style="display: none;">
 <a href="/svn/cntv/c/?id=pa://cctv_p2p_hdcctv1">CCTV-1</a>
 <a href="c/?id=pa://cctv_p2p_hdcctv2">CCTV-2</a>
 <a href="/svn/cntv/c/?id=pl://cctv_p2p_hdcctv3">CCTV-3</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv4">CCTV-4</a>
 <a href="c/?id=pa://cctv_p2p_hdcctv5">CCTV-5</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv6">CCTV-6</a>
 <a href="c/?id=pa://cctv_p2p_hdcctv7">CCTV-7</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv8">CCTV-8</a>
 <a href="c/?id=pb://cctv_p2p_hdcctvjilu">CCTV-9</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv10">CCTV-10</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv11">CCTV-11</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv12">CCTV-12</a>
 <a href="c/?id=pa://cctv_p2p_hdcctvnews">CCTV-13</a>
 <a href="c/?id=pl://cctv_p2p_hdcctvkids">CCTV-14</a>
 <a href="c/?id=pl://cctv_p2p_hdcctvmusic">CCTV-15</a>
 <a href="c/?id=pb://cctv_p2p_hdcctvdoc">CCTV-9英文</a>
 <a href="c/?id=pl://cctv_p2p_cctv9">CCTV-NEWS</a>
 <a href="c/?id=pl://cctv_p2p_hdcctvxiyu">CCTV-E</a>
 <a href="c/?id=pl://cctv_p2p_hdcctvfayu">CCTV-F</a>
 <a href="c/?id=pl://cctv_p2p_cctvrussian">CCTV-R</a>
 <a href="c/?id=pl://cctv_p2p_cctvarabic">CCTV-A</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv4america">CCTV-4美洲</a>
 <a href="c/?id=pl://cctv_p2p_hdcctv4euro">CCTV-4欧洲</a>
 <a href="c/?id=pa://cctv_p2p_hdcctvgaoqing">CCTV-高清</a>
 <a href="c/?id=pa://cctv_p2p_hdcctvfyzq">风云足球</a>
 <a href="c/?id=pa://cctv_p2p_hdcctvgaowang">高尔夫网球</a>
 <a href="c/?id=pl://cctv_p2p_gouwu">中视购物</a>
 <a href="c/?id=pb://cctv_p2p_hddianshizhinan">电视指南</a>
 <a href="c/?id=pb://cctv_p2p_v15">中学生</a>
</h2></li>

<li><h1 class="lm_1"> <a href="javascript:OpenChanel(2);" class="list_name" target="_self">城市直播a-f</a></h1>
<h2 class="lm_2" id="CHT_2" style="display: none;">
 <a href="c/?id=pl://cctv_p2p_hdanhui">安徽卫视</a>
 <a href="c/?id=pb://cctv_p2p_anqin">安庆综合</a>
 <a href="c/?id=pl://cctv_p2p_hdbtv5">北京卫视</a>
 <a href="c/?id=pb://cctv_p2p_hdbtvwenyi">北京财经</a>
 <a href="c/?id=pb://cctv_p2p_hdbtvkejiao">北京科教</a>
 <a href="c/?id=pb://cctv_p2p_hdbtvyingshi">北京影视</a>
 <a href="c/?id=pb://cctv_p2p_hdbtvshenghuo">北京生活</a>
 <a href="c/?id=pb://cctv_p2p_hdbtvqingshao">北京青少</a>
 <a href="c/?id=pa://cctv_p2p_hdbtvtiyu">北京体育</a>
 <a href="c/?id=pb://cctv_p2p_hdbtvgongong">北京公共</a>
 <a href="c/?id=pl://cctv_p2p_hdchongqing">重庆卫视</a>
 <a href="c/?id=pl://cctv_p2p_hddongnan">东南卫视</a>
 <a href="c/?id=pl://cctv_p2p_xiamenweishi">厦门卫视</a>
 <a href="c/?id=pl://cctv_p2p_xiamen1">厦门一套</a>
 <a href="c/?id=pl://cctv_p2p_xiamen2">厦门二套</a>
 <a href="c/?id=pl://cctv_p2p_xiamen3">厦门三套</a>
 <a href="c/?id=pl://cctv_p2p_xiamen4">厦门四套</a>
</h2></li>

<li><h1 class="lm_1"> <a href="javascript:OpenChanel(3);" class="list_name" target="_self">城市直播g</a></h1>
<h2 class="lm_2" id="CHT_3" style="display: none;">
 <a href="c/?id=pl://cctv_p2p_hdguangdong">广东卫视</a>
 <a href="c/?id=pb://cctv_p2p_shaoguangonggong">韶关公共</a>
 <a href="c/?id=pb://cctv_p2p_shaoguanzonghe">韶关综合</a>
 <a href="c/?id=pa://cctv_p2p_shenzhencaijing">深圳财经</a>
 <a href="c/?id=pb://cctv_p2p_foshan">佛山综合</a>
 <a href="c/?id=pa://cctv_p2p_hdgzzonghe">广州综合</a>
 <a href="c/?id=pa://cctv_p2p_zhuhai">珠海一套</a>
 <a href="c/?id=pa://cctv_p2p_zhuhai2">珠海二套</a>
 <a href="c/?id=pa://cctv_p2p_hdgzecon">广州经济</a>
 <a href="c/?id=pa://cctv_p2p_hdgznews">广州新闻</a>
 <a href="c/?id=pa://cctv_p2p_hdgzkids">广州少儿</a>
 <a href="c/?id=pa://cctv_p2p_hdgzenglish">广州英语</a>
 <a href="c/?id=pa://cctv_p2p_cztv1">潮州综合</a>
 <a href="c/?id=pa://cctv_p2p_cztv2">潮州公共</a>
 <a href="c/?id=pl://cctv_p2p_hdguangxi">广西卫视</a>
 <a href="c/?id=pb://cctv_p2p_guangxizy">广西综艺</a>
 <a href="c/?id=pl://cctv_p2p_hdgansu">甘肃卫视</a>
 <a href="c/?id=pb://cctv_p2p_jingcailanzhou">睛彩兰州</a>
 <a href="c/?id=pl://cctv_p2p_hdguizhou">贵州卫视</a>
</h2></li>

<li><h1 class="lm_1"> <a href="javascript:OpenChanel(4);" class="list_name" target="_self">城市直播h</a></h1>
<h2 class="lm_2" id="CHT_4" style="display: none;">
 <a href="c/?id=pl://cctv_p2p_hdhebei">河北卫视</a>
 <a href="c/?id=pb://cctv_p2p_hebeinongmin">河北农民</a>
 <a href="c/?id=pa://cctv_p2p_hebeijingji">河北经济</a>
 <a href="c/?id=pb://cctv_p2p_sjz1">石家庄一套</a>
 <a href="c/?id=pb://cctv_p2p_sjz2">石家庄二套</a>
 <a href="c/?id=pb://cctv_p2p_sjz3">石家庄三套</a>
 <a href="c/?id=pb://cctv_p2p_sjz4">石家庄四套</a>
 <a href="c/?id=pb://cctv_p2p_xingtaishenghuo">邢台生活</a>
 <a href="c/?id=pb://cctv_p2p_xingtaiyule">邢台娱乐</a>
 <a href="c/?id=pb://cctv_p2p_xingtaizonghe">邢台综合</a>
 <a href="c/?id=pl://cctv_p2p_hdheilongjiang">黑龙江卫视</a>
 <a href="c/?id=pa://cctv_p2p_haerbin1">哈尔滨新闻</a>
 <a href="c/?id=pa://cctv_p2p_hdhubei">湖北卫视</a>
 <a href="c/?id=pa://cctv_p2p_wuhanjiaoyu">武汉教育</a>
 <a href="c/?id=pb://cctv_p2p_jinzhouxw">荆州新闻</a>
 <a href="c/?id=pb://cctv_p2p_hubeidianshitai">湖北综合</a>
 <a href="c/?id=pb://cctv_p2p_hubeigonggong">湖北公共</a>
 <a href="c/?id=pb://cctv_p2p_hubeijiaoyu">湖北教育</a>
 <a href="c/?id=pb://cctv_p2p_hubeitiyu">湖北体育</a>
 <a href="c/?id=pb://cctv_p2p_hubeiyingshi">湖北影视</a>
 <a href="c/?id=pb://cctv_p2p_hubeijingshi">湖北经视</a>
 <a href="c/?id=pb://cctv_p2p_hubeigouwu">湖北购物</a>
 <a href="c/?id=pa://cctv_p2p_hdhunan">湖南卫视</a>
 <a href="c/?id=pl://cctv_p2p_hdhenan">河南卫视</a>
 <a href="c/?id=pl://cctv_p2p_hdlvyou">旅游卫视</a>
</h2></li>

<li><h1 class="lm_1"> <a href="javascript:OpenChanel(5);" class="list_name" target="_self">城市直播j-q</a></h1>
<h2 class="lm_2" id="CHT_5" style="display: none;">
 <a href="c/?id=pl://cctv_p2p_hdjilin">吉林卫视</a>
 <a href="c/?id=pa://cctv_p2p_hdyanbian">延边卫视</a>
 <a href="c/?id=pl://cctv_p2p_jiangsu">江苏卫视</a>
 <a href="c/?id=pa://cctv_p2p_wxtv1">无锡新闻综合</a>
 <a href="c/?id=pa://cctv_p2p_wxtv2">无锡都市资讯</a>
 <a href="c/?id=pa://cctv_p2p_wxtv3">无锡娱乐</a>
 <a href="c/?id=pa://cctv_p2p_wxtv4">无锡生活</a>
 <a href="c/?id=pa://cctv_p2p_wxtv5">无锡经济</a>
 <a href="c/?id=pa://cctv_p2p_wxtv6">无锡移动</a>
 <a href="c/?id=pa://cctv_p2p_nanjing1">南京新闻</a>
 <a href="c/?id=pb://cctv_p2p_nantongshenghuo">南通生活</a>
 <a href="c/?id=pb://cctv_p2p_nantongkejiao">南通科教</a>
 <a href="c/?id=pb://cctv_p2p_nantongxinwen">南通新闻</a>
 <a href="c/?id=pl://cctv_p2p_hdjiangxi">江西卫视</a>
 <a href="c/?id=pa://cctv_p2p_nanchangxinwen">南昌新闻</a>
 <a href="c/?id=pl://cctv_p2p_hdliaoning">辽宁卫视</a>
 <a href="c/?id=pb://cctv_p2p_hubeigonggong">辽宁都市</a>
 <a href="c/?id=pa://cctv_p2p_liaoningdushi">大连新闻</a>
 <a href="c/?id=pb://cctv_p2p_hubeitiyu">内蒙古卫视</a>
 <a href="c/?id=pa://cctv_p2p_mengyu">内蒙古蒙语</a>
 <a href="c/?id=pb://cctv_p2p_hubeijingshi">宁夏卫视</a>
 <a href="c/?id=pb://cctv_p2p_hdqinghai">青海卫视</a>
</h2></li>

<li><h1 class="lm_1"> <a href="javascript:OpenChanel(6);" class="list_name" target="_self">城市直播s-t</a></h1>
<h2 class="lm_2" id="CHT_6" style="display: none;">
 <a href="c/?id=pl://cctv_p2p_dongfang">东方卫视</a>
 <a href="c/?id=pl://cctv_p2p_hdshanghaikatong">炫动卡通</a>
 <a href="c/?id=pa://cctv_p2p_shanghaixinwen">上海新闻</a>
 <a href="c/?id=pl://cctv_p2p_hdshan-xi">山西卫视</a>
 <a href="c/?id=pb://cctv_p2p_lvliang1">吕梁广播</a>
 <a href="c/?id=pl://cctv_p2p_hdshandong">山东卫视</a>
 <a href="c/?id=pa://cctv_p2p_jinan1">济南新闻</a>
 <a href="c/?id=pa://cctv_p2p_qtv1">青岛新闻</a>
 <a href="c/?id=pb://cctv_p2p_shandongjiaoyu380">山东教育</a>
 <a href="c/?id=pb://cctv_p2p_sdtv1">烟台新闻综合</a>
 <a href="c/?id=pb://cctv_p2p_sdtv2">烟台经济生活</a>
 <a href="c/?id=pb://cctv_p2p_sdtv4">烟台公共</a>
 <a href="c/?id=pl://cctv_p2p_hdsichuan">四川卫视</a>
 <a href="c/?id=pa://cctv_p2p_hdcdtv1">成都新闻</a>
 <a href="c/?id=pa://cctv_p2p_hdcdtv5">成都公共</a>
 <a href="c/?id=pb://cctv_p2p_kangbaweishi">康巴卫视</a>
 <a href="c/?id=pb://cctv_p2p_hdshanvxi">陕西卫视</a>
 <a href="c/?id=pa://cctv_p2p_xianyang">西安综合</a>
 <a href="c/?id=pl://cctv_p2p_hdtianjin">天津卫视</a>
 <a href="c/?id=pb://cctv_p2p_bhtv1">滨海一套</a>
 <a href="c/?id=pb://cctv_p2p_bhtv2">滨海二套</a>
</h2></li>

<li><h1 class="lm_1"> <a href="javascript:OpenChanel(7);" class="list_name" target="_self">城市直播x-z</a></h1>
<h2 class="lm_2" id="CHT_7" style="display: none;">
 <a href="c/?id=pb://cctv_p2p_hktv">香港卫视</a>
 <a href="c/?id=pb://cctv_p2p_jktv">健康卫视</a>
 <a href="c/?id=pl://cctv_p2p_hdxinjiang">新疆卫视</a>
 <a href="c/?id=pa://cctv_p2p_weiyu">新疆维语</a>
 <a href="c/?id=pa://cctv_p2p_weiyuzongyi">新疆维语综艺</a>
 <a href="c/?id=pa://cctv_p2p_weiyujingji">新疆维语经济</a>
 <a href="c/?id=pa://cctv_p2p_hayu">新疆哈语</a>
 <a href="c/?id=pa://cctv_p2p_hayuzongyi">新疆哈语综艺</a>
 <a href="c/?id=pl://cctv_p2p_hdxizang2">西藏卫视</a>
 <a href="c/?id=pa://cctv_p2p_zangyu">西藏藏语</a>
 <a href="c/?id=pl://cctv_p2p_hdyunnan">云南卫视</a>
 <a href="c/?id=pb://cctv_p2p_lijiang_zhonghe">丽江综合</a>
 <a href="c/?id=pb://cctv_p2p_lijiang_gg">丽江公共</a>
 <a href="c/?id=pl://cctv_p2p_hdzhejiang">浙江卫视</a>
 <a href="c/?id=pb://cctv_p2p_hdningbo1">宁波一套</a>
 <a href="c/?id=pb://cctv_p2p_hdningbo2">宁波二套</a>
 <a href="c/?id=pb://cctv_p2p_hdningbo3">宁波三套</a>
</h2></li>

 <li class="ft">
<hr width=95% size=1 color=#A9C8E4 style="FILTER: alpha(opacity=100,finishopacity=0,style=3)"> 
      <h1 class="ft_1"><a target="_blank" title="松达电脑科技－小松维护" href="http://wpa.qq.com/msgrd?v=3&uin=1160038650&site=qq&menu=yes">松达电脑科技－小松维护</a><hr width=95% size=1 color=#A9C8E4 style="FILTER: alpha(opacity=100,finishopacity=0,style=3)"> 
</h1></li>

<!-- 频道列表导航结束 -->
<script language="javascript" type="text/javascript">
var crrCn=1;
function OpenChanel(id) { 
if (crrCn == id) { 
if (document.getElementById("CHT_" + crrCn).style.display == "none") {document.getElementById("CHT_" + crrCn).style.display = "block";} 
else {document.getElementById("CHT_" + crrCn).style.display = "none";} } 
else {document.getElementById("CHT_" + crrCn).style.display = "none"; 
var o2 = document.getElementById("CHT_" + id); o2.style.display = "block"; crrCn = id; } } 
OpenChanel(crrCn); 
document.getElementById("CHT_" + crrCn).style.display = "block"; 
</script>
<div id="solist" style="display:block"> </div>
<div style="display:none">
</div>
</body>
</html>
<script>
if(top==self){top.location='/'}
</script>
<td width="0%"></script><script LANGUAGE="JavaScript"> 
function click() { if (event.button==2) 
{alert('欢迎使用就要看电视); } } document.onmousedown=click
</script>

