$(function() {
    $("#myBt").hide();
    var str = getParameterByName("url");
    if (str && str != "") {
        SetSelect(str);
        $("#url").val(str)
    };
    $("#url_play_button").click(function() {
        $("#myBt").hide();
        if ($("#url").val() == "" || $("#url").val() == '在这里添加视频地址，支持http、ftp、ed2k、thunder、magnet开头的链接') {
            alert("请先输入有效的资源地址")
        } else {
            SetSelect($("#url").val())
        }
    });
    $("select").change(function() {
        SetSelect($("select").val())
    });
    var button = $('#button1'),
    interval;
    new AjaxUpload(button, {
        action: 'uptorrent.aspx',
        name: 'myfile',
        onSubmit: function(file, ext) {
            if (ext && /^(torrent)$/.test(ext)) {
                button.text('解析中');
                this.disable();
                interval = window.setInterval(function() {
                    var text = button.text();
                    if (text.length < 13) {
                        button.text(text + '.')
                    } else {
                        button.text('解析中')
                    }
                },
                200)
            } else {
                return false
            }
        },
        onComplete: function(file, response) {
            button.text('播放BT种子');
            window.clearInterval(interval);
            var data = HTMLDeCode(HTMLDecode(response));
            if (data != "0" && data != "0|") {
                $("#myBt").html(data);
                $("#myBt").show();
                SetSelect($("select").val())
            } else {
                alert("种子解析失败！！！")
            };
            this.enable()
        }
    })
});
function getParameterByName(name) {
    name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
    var regexS = "[\\?&]" + name + "=([^&#]*)";
    var regex = new RegExp(regexS);
    var results = regex.exec(window.location.search);
    if (results == null) return "";
    else return decodeURIComponent(results[1].replace(/\+/g, " "))
};
function uploadReturn(str) {
    if (str != "0" && str != "0|") {
        $("#myBt").html(str);
        SetSelect($("select").val())
    } else {
        alert("BT种子解析失败！！！")
    }
};
function clear1() {
    document.getElementById("url").value = "";
    var aa1 = window.clipboardData.getData('text');
    document.getElementById("url").value = aa1
};
function SetSelect(str) {
    var html = '<iframe id="play_frame" frameborder="0" scrolling="no" src="/svn/vod/vip.html?url=' + ThunderEncode(encodeURIComponent(str)) + '" width="100%" height="100%" ></iframe>';
    $("#play_html").attr("width", "100%");
    $("#play_html").attr("height", "100%");
    $("#play_html").html(html)
};
function HTMLDecode(input) {
    var converter = document.createElement("DIV");
    converter.innerHTML = input;
    var output = converter.innerText;
    converter = null;
    return output
};
function HTMLDeCode(str) {
    var s = "";
    if (str.length == 0) return "";
    s = str.replace(/&lt;/g, "<");
    s = s.replace(/&gt;/g, ">");
    s = s.replace(/&nbsp;/g, "    ");
    s = s.replace(/"/g, "\"");
    s = s.replace(/&quot;/g, "\"");
    s = s.replace(/<br>/g, "\n");
    return s
};
var widthSpace = 480;
window.onload = function() {
    var nav = document.getElementById("url");
    nav.style.width = document.documentElement.clientWidth - widthSpace + "px";
    document.getElementById("play_html").style.height = document.documentElement.clientHeight - 50 + "px"
};
window.onresize = function() {
    var nav = document.getElementById("url");
    nav.style.width = document.documentElement.clientWidth - widthSpace + "px";
    document.getElementById("play_html").style.height = document.documentElement.clientHeight - 50 + "px"
};
document.writeln("<script type=\"text/javascript\">/*云点播官网*/ var cpro_id = \'u898166\';</script><script src=\"http://cpro.baidu.com/cpro/ui/f.js\" type=\"text/javascript\"></script>");