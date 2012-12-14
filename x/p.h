(function() {
    var a = false;
    if (!window.console && !a) {
        window.console = {
            log: function() {},
            warn: function() {},
            error: function() {},
            fatal: function() {},
            debug: function() {},
            dir: function() {}
        }
    }
    setTimeout(function() {
        var ac = function(ah) {
            return typeof ah == "undefined"
        };
        var W = function(ah) {
            return typeof ah == "object" && !ah
        };
        var w = "XL_CLOUD_VOD_PLAYER";
        var c = (window.navigator.userAgent.toLowerCase().indexOf("ipad") > 0 || window.navigator.userAgent.toLowerCase().indexOf("iphone") > 0) ? 1: 0;
        var t = (navigator.appVersion.indexOf("MSIE") != -1) ? true: false;
        var p = navigator.userAgent.toUpperCase().indexOf("Firefox") ? true: false;
        var ad = "2.825";
        var C = 3E4;
        var ag = "http://vod.xunlei.com/";
        var Z = "http://dynamic.vod.lixian.xunlei.com/";
        var F = "http://i.vod.xunlei.com/";
        var K = new Date().getTime();
        function N(ah) {
            return document.getElementById(ah)
        }
        var B = N(w);
        if (!B) {
            return false
        }
        function j(ah) {
            return (document.cookie.match(new RegExp("(^" + ah + "| " + ah + ")=([^;]*)")) == null) ? "": RegExp.$2
        }
        function b(ah) {
            return ah.replace(/(^\s*)|(\s*$)/g, "")
        }
        function g(aj) {
            var ah = "";
            try {
                ah = decodeURIComponent(decodeURIComponent(aj))
            } catch(ai) {
                try {
                    ah = decodeURIComponent(aj)
                } catch(ai) {
                    ah = aj
                }
            }
            return ah
        }
        function h(ah) {
            return encodeURIComponent(ah)
        }
        function P(ah) {
            this.fullUrl = ah;
            this.noCacheIE = "&noCacheIE=" + (new Date()).getTime();
            this.headLoc = document.getElementsByTagName("head").item(0);
            this.scriptId = "JscriptId" + P.scriptCounter++
        }
        P.scriptCounter = 1;
        P.prototype.buildScriptTag = function() {
            this.scriptObj = document.createElement("script");
            this.scriptObj.setAttribute("type", "text/javascript");
            this.scriptObj.setAttribute("src", this.fullUrl)
        };
        P.prototype.removeScriptTag = function() {
            this.headLoc.removeChild(this.scriptObj)
        };
        P.prototype.addScriptTag = function() {
            this.headLoc.appendChild(this.scriptObj)
        };
        function J(ah, aj, al) {
            var ai = ah;
            if (aj) {
                window[aj] = al
            }
            if (ai.indexOf("?") != -1) {
                ai += "&jsonp=" + aj
            } else {
                ai += "?jsonp=" + aj
            }
            var ak = new P(ai);
            ak.buildScriptTag();
            ak.addScriptTag()
        }
        function k(ah, aj, al) {
            var ai = ah;
            if (aj) {
                window[aj] = al
            }
            ai += "&callback=" + aj;
            var ak = new P(ai);
            ak.buildScriptTag();
            ak.addScriptTag();
            return this
        }
        function Y(ai, ah) {
            return ai.getAttribute(ah)
        }
        function u(aj, al, ai, ak) {
            if (arguments.length > 2) {
                var ah = new Date(new Date().getTime() + ai * 3600000);
                document.cookie = aj + "=" + encodeURIComponent(al) + "; path=/; domain=xunlei.com; expires=" + ah.toGMTString()
            } else {
                document.cookie = aj + "=" + encodeURIComponent(al) + "; path=/; domain=xunlei.com"
            }
        }
        function aa(aj, ai) {
            ai = ac(ai) ? location.href: ai;
            var ah = ai.match(new RegExp("[#|?]([^#]*)[#|?]?"));
            ai = "&" + (W(ah) ? "": ah[1]);
            ah = ai.match(new RegExp("&" + aj + "=", "i"));
            return W(ah) ? undefined: ai.substr(ah.index + 1).split("&")[0].split("=")[1]
        }
        window.isClientVodScene = false;
        var G = aa("tryplay");
        if (G == 1) {
            window.isClientVodScene = true
        }
        var z = aa("debug");
        if (z == 1) {
            a = true
        }
        var T = B;
        var x = "vlist";
        x = x || "unknown";
        var X = T.getElementsByTagName("a");
        if (X.length == 0) {
            X = T.getElementsByTagName("span");
            if (X.length == 0) {
                return
            }
            var f = X[0];
            var i = b(Y(f, "url"))
        } else {
            var f = X[0];
            var i = b(f.getAttribute("href"))
        }
        var I = Y(f, "filesize");
        var H = Y(f, "gcid");
        var q = Y(f, "cid");
        var O = Y(f, "title");
        var U = Y(f, "onsuccess");
        var af = Y(f, "playother");
        var s = Y(f, "onfail");
        if (!T.style.height) {
            T.style.height = "446px"
        }
        if (!T.style.width) {
            T.style.width = "684px"
        }
        T.style.overflow = "hidden";
        var Q = Y(f, "share_url");
        Q = Q ? g(Q) : g(i);
        var ae = Y(f, "autoplay");
        if (!ae || ae != "true") {
            ae = false
        } else {
            ae = true
        }
        var d = {
            enableShare: true,
            enableFileList: true,
            enableDownload: true,
            enableSet: true,
            enableCaption: true,
            enableOpenWindow: true,
            enableTopBar: true,
            enableFeedback: true
        };
        var A = Y(f, "enable_panel");
        if (A && A == "false") {
            d.enableShare = false
        }
        var M = Y(f, "enable_download");
        if (M && M == "true") {
            d.enableDownload = true
        }
        var E = Y(f, "enable_caption");
        if (E && E == "false") {
            d.enableCaption = false
        }
        var l = Y(f, "enable_filelist");
        if (l && l == "false") {
            d.enableFileList = false
        }
        var ab = Y(f, "enable_setting");
        if (ab && ab == "false") {
            d.enableSet = false
        }
        var D = Y(f, "enable_openwindow");
        if (D && D == "true") {
            d.enableOpenWindow = true
        }
        var m = Y(f, "enable_topbar");
        if (m && m == "false") {
            d.enableTopBar = false
        }
        var y = Y(f, "enable_kkva");
        if (y && y == "true") {
            y = false
        } else {
            y = false
        }
        var R = parseInt(Y(f, "start")) || 0;
        var o = Y(f, "format");
        var V;
        var r = false,
        L = /xyz/.test(function() {
            xyz
        }) ? /\b_super\b/: /.*/;
        var e = function() {};
        e.extend = function(al) {
            var ak = this.prototype;
            r = true;
            var aj = new this();
            r = false;
            for (var ai in al) {
                aj[ai] = typeof al[ai] == "function" && typeof ak[ai] == "function" && L.test(al[ai]) ? (function(am, an) {
                    return function() {
                        var ap = this._super;
                        this._super = ak[am];
                        var ao = an.apply(this, arguments);
                        this._super = ap;
                        return ao
                    }
                })(ai, al[ai]) : al[ai]
            }
            function ah() {
                if (!r && this.init) {
                    this.init.apply(this, arguments)
                }
            }
            ah.prototype = aj;
            ah.constructor = ah;
            ah.extend = arguments.callee;
            return ah
        };
        var v;
        window.XL_CLOUD_FX_INSTANCE = {
            Class: e,
            lastFormat: "p",
            cacheData: [],
            curPlay: null,
            curInfohash: "",
            curDlUrl: "",
            curUrl: g(i),
            curName: g(O),
            originalPlay: null,
            fileList: null,
            captionList: [],
            type: "url",
            user: {
                u: "",
                v: 6,
                s: ""
            },
            platform: "webpage",
            playPosition: -1,
            userType: 1,
            init: function(ah) {
                v = ah;
                var aj = this;
                aj.platform = aj.getPlatForm();
                if (!aj.validUrl(aj.curUrl)) {
                    aj.error("您的点播无法播放，无法播放！请更换视频！");
                    return false
                }
                var am = T.getAttribute("id");
                if (!am) {
                    am = "XL_CLOUD_PLAY_BOX";
                    T.setAttribute("id", am)
                }
                T.style.backgroundColor = "#000";
                var ak = ["61.147.76.6", "61.147.76.6", "222.141.53.5", "222.141.53.5"];
                goip = ak[0];
                J(Z + "interface/getip?t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryIpBack", 
                function(an) {
                    try {
                        goip = ak[an]
                    } catch(ao) {
                        try {
                            goip = ak[an.result]
                        } catch(ao) {
                            goip = ak[0]
                        }
                    }
                });
                aj.isVod = (document.location.host == ak[0] || document.location.host == ak[2]);
                aj.isXlpan = /.*((xlpan)|(f\.xunlei\.com)).*/.exec(document.location.host);
                try {
                    aj.isThunderBox = window.external.IsInXLpanClient()
                } catch(al) {
                    aj.isThunderBox = false
                }
                var ai = aj.genBtUrl(aj.curUrl);
                if (ai) {
                    aj.type = "bt";
                    Q = ai
                }
                aj.uCheck();
                window.onunload = function(an) {
                    aj.reportPlayPos();
                    if (aj.curPlay) {
                        try {
                            var ar = G_PLAYER_INSTANCE.getTimePlayed();
                            var ao = ar.playedtime;
                            var aw = ar.playedbyte;
                            var at = ar.downloadbyte
                        } catch(au) {
                            var ao = 0;
                            var aw = 0;
                            var at = 0
                        }
                        try {
                            var az = G_PLAYER_INSTANCE.getPlayPosition()
                        } catch(au) {
                            var az = 0
                        }
                        var av = aj.curPlay.src_info;
                        if (av) {
                            var ap = av.gcid || ""
                        } else {
                            var ap = ""
                        }
                        var ay = aj.$PU("g", aj.curDlUrl) || "";
                        var ax = aj.curPlay.duration / 1000000 || 0;
                        var aq = new Image();
                        aq.src = "http://i.vod.xunlei.com/stat/s.gif?f=playtime&p=XCVP&totaltime=" + ax + "&du=" + ao + "&by=" + aw + "&downby=" + at + "&t=" + az + "&gcid=" + ay + "&ygcid=" + ap + "&u=" + aj.user.u + "&v=" + aj.user.v + "&from=xlpan&d=" + K
                    }
                    aj.close()
                };
                setTimeout(function() {
                    aj.stat({
                        p: "XCVP",
                        f: "pv"
                    })
                },
                25)
            },
            uVipinfo: function() {
                k(Z + "interface/getuservipinfo?t=" + K, "XL_CLOUD_FX_INSTANCEqueryVipinfoBack", 
                function(aj) {
                    if (aj.result == "0" && aj.vipinfo.payid) {
                        var an = aj.vipinfo;
                        if (an.payid - 1000 > 0) {
                            var ai = an.expiredate.split("-");
                            var ah = aj.svrtime.split("-");
                            var al = ai[0] - ah[0];
                            var ao = ai[1] - ah[1];
                            var ak = ai[2] - ah[2];
                            var am = "";
                            if (ak < 0) {
                                var ap = new Date();
                                ap = new Date(ap.getFullYear(), ap.getMonth() + 3, 0);
                                if (ao > 0) {
                                    ao = ao - 1
                                } else {
                                    al -= 1;
                                    ao = 11
                                }
                                ak = ap.getDate() + ak
                            }
                            if (al > 0) {
                                am += al + "年"
                            }
                            if (ao > 0) {
                                am += ao + "月"
                            }
                            if (ak > 8 || al > 0 || ao > 0) {
                                return false
                            }
                            am += ak + "天";
                            am = "您的体验会员将在" + am + "后到期，建议您开通正式会员";
                            G_PLAYER_INSTANCE.setNoticeMsg(am, 1500)
                        }
                    }
                })
            },
            uCheck: function() {
                var ah = this;
                if (ah.isXlpan || ah.isThunderBox || ah.isVod || isClientVodScene) {
                    if (!ah.isVod) {
                        d.enableOpenWindow = false
                    }
                    ah.user.u = j("userid");
                    ah.user.v = 6;
                    ah.user.s = j("sessionid");
                    ah.query(ah.curUrl, ah.curName, H, q, I);
                    return true
                }
                var ai = null;
                isTimeout = true;
                J(Z + "interface/getXlCookie?t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryXlCookieBack", 
                function(aj) {
                    if (aj && aj.sessionid && aj.userid) {
                        ah.user.u = aj.userid;
                        ah.user.v = 6;
                        ah.user.s = aj.sessionid;
                        if (!j("userid") && !j("isvip") && !j("sessionid")) {
                            u("userid");
                            u("isvip");
                            u("sessionid")
                        }
                        ah.query(ah.curUrl, ah.curName, H, q, I)
                    } else {
                        ah.query(ah.curUrl, ah.curName, H, q, I)
                    }
                    isTimeout = false;
                    clearTimeout(ai)
                });
                ai = setTimeout(function() {
                    if (isTimeout) {
                        ah.error("暂时无法验证您的登录状态，请稍后<a style='color:#1874CA;' href='javascript:;' onclick='XL_CLOUD_FX_INSTANCE.uCheck();return false;'>重试</a>")
                    }
                    isTimeout = false;
                    clearTimeout(ai)
                },
                C)
            },
            uUpdate: function() {
                var ah = this;
                J(Z + "interface/getXlCookie?t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryXlCookieBack", 
                function(ai) {
                    if (ai && ai.sessionid && ai.isvip && ai.userid) {
                        ah.user.u = ai.userid;
                        ah.user.v = 6;
                        ah.user.s = ai.sessionid;
                        if (!j("userid") && !j("isvip") && !j("sessionid")) {
                            u("userid");
                            u("isvip");
                            u("sessionid")
                        }
                    }
                })
            },
            reportPlayPos: function() {
                var aj = this;
                if (aj.curPlay && aj.curPlay.ret == 0) {
                    var ai = "";
                    if (aj.type == "bt" && aj.fileList && aj.fileList.main_task_url_hash) {
                        ai = aj.fileList.main_task_url_hash
                    } else {
                        if (aj.curPlay && aj.curPlay.url_hash) {
                            ai = aj.curPlay.url_hash
                        } else {
                            return false
                        }
                    }
                    try {
                        var al = 0;
                        if (aj.playPosition != -1) {
                            al = aj.playPosition
                        } else {
                            al = G_PLAYER_INSTANCE.getPlayPosition();
                            al = Math.ceil(al)
                        }
                        if (!al || al < 0) {
                            al = 0
                        }
                        ai = ai + "_" + al
                    } catch(ak) {
                        return false
                    }
                    var ah = 0;
                    if (aj.type == "bt") {
                        ai = ai + "_1";
                        ah = aj.curUrl.substr(parseInt(aj.curUrl.lastIndexOf("/")) + 1, aj.curUrl.length)
                    } else {
                        ai = ai + "_0"
                    }
                    try {
                        J(F + "req_report_play_pos?userid=" + aj.user.u + "&report_data=" + ai + "_" + ah + "&t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEreportPosBack", 
                        function(am) {
                            return false
                        })
                    } catch(ak) {}
                }
            },
            initEvent: function() {
                var ah = this;
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onGetFormats", 
                function(aj, ai, ak, al) {});
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onSetFormats", 
                function(aj, ai, ak, an, al, am) {
                    ah.setFormats(ak, an, al, am)
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onErrorStat", 
                function(aj, ai, ak) {
                    if (ah.kkvaUsed) {
                        try {
                            ah.close();
                            G_PLAYER_INSTANCE.setNoticeMsg("迅雷播放加速服务已经退出，您将无法继续观看视频,请刷新页面重试", 5000)
                        } catch(al) {}
                        ah.kkvaUsed = false
                    }
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onErrorExit", 
                function(aj, ai, ak, al) {
                    ah.stat({
                        f: "playerror",
                        e: ak,
                        gcid: ah.$PU("g", ah.curDlUrl)
                    })
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onplaying", 
                function() {
                    if (ah.kkvaValid) {
                        ah.kkvaUsed = true;
                        try {
                            G_PLAYER_INSTANCE.setNoticeMsg("<a href=\"javascript:XL_CLOUD_FX_INSTANCE.windowOpenInPlayer('http://dl.xunlei.com/xmp.html')\">迅雷播放加速服务中...</a>", 30)
                        } catch(ai) {}
                        ah.kkvaValid = false
                    }
                    ah.stats_buff()
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onStop", 
                function() {
                    var ai = G_PLAYER_INSTANCE.getPlayPosition();
                    ai = Math.ceil(ai);
                    ah.playPosition = ai
                })
            },
            initPlayerEvent: function() {
                if (c) {
                    return true
                }
                var ah = this;
                G_PLAYER_INIT.attachEvent(G_PLAYER_INIT, "onLoadFlashError", 
                function() {
                    ah.error("播放器加载异常！<br>请尝试以下办法：<br>1,清理IE缓存！<br>2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>");
                    ah.stat({
                        f: "loadflasherror",
                        ua: window.navigator.userAgent
                    })
                });
                G_PLAYER_INIT.attachEvent(G_PLAYER_INIT, "onFlashError", 
                function() {
                    ah.error('检测到您没有安装Flash插件，您可以点这里 <a style=\'color:#1874CA;text-decoration: none;\' href="http://get.adobe.com/cn/flashplayer/" target="_blank">安装插件</a>');
                    ah.stat({
                        f: "noflash"
                    })
                })
            },
            stat: function(al) {
                var ai = this;
                var al = al || {};
                var ak = [];
                al.p = "XCVP";
                if (typeof al.u == "undefined") {
                    al.u = ai.user.u || 0
                }
                if (typeof al.v == "undefined") {
                    al.v = ai.user.v || 0
                }
                if (typeof al.from == "undefined") {
                    al.from = x || "XCVP"
                }
                if (typeof al.d == "undefined") {
                    al.d = K
                }
                for (var ah in al) {
                    ak.push(ah + "=" + encodeURIComponent(al[ah]))
                }
                try {
                    setTimeout(function() {
                        var am = new Image(0, 0);
                        am.src = F + "stat/s.gif?" + ak.join("&")
                    },
                    5)
                } catch(aj) {}
            },
            stats_buff_flag: false,
            stats_buff: function() {
                if (document.location.host == ips[0] || document.location.host == ips[2]) {
                    this.uVipinfo()
                }
            },
            query: function(ai, ah, ar, ao, at, al) {
                var am = this;
                am.getBtFileLastPos();
                var aq,
                ap;
                ai = b(ai);
                if (ah) {
                    ap = "url=" + encodeURIComponent(ai) + "&video_name=" + encodeURIComponent(ah) + "&platform=" + (c ? "1": "0")
                } else {
                    ap = "url=" + encodeURIComponent(ai) + "&platform=" + (c ? "1": "0")
                }
                if (ar && ao && at) {
                    ap = ap + "&gcid=" + ar + "&cid=" + ao + "&filesize=" + at
                }
                aq = "http://127.0.0.1:1218/chydbreq_get_method_vod?" + ap;
                if (isClientVodScene) {
                    d.enableTopBar = false;
                    d.enableOpenWindow = false;
                    d.enableFileList = false;
                    if (! (ar && ao && at) && ar) {
                        ap = ap + "&gcid=" + ar
                    }
                    aq = F + "req_try_vod?" + ap;
                    var ak = am.$PU("peerid");
                    var au = am.$PU("playallow");
                    if (ak) {
                        aq += "&peerid=" + ak
                    }
                    if (au) {
                        aq += "&playallow=" + au
                    }
                }
                aq = aq + "&cache=" + new Date().getTime() + "&from=" + x;
                J(aq, "XL_CLOUD_FX_INSTANCEqueryBack", 
                function(aw) {
                    if (aw.resp.vod_permit && typeof(aw.resp.vod_permit.ret) != "undefined") {
                        am.userType = 1
                    } else {
                        am.userType = 1
                    }
                    clearTimeout(aj);
                    an = false;
                    var av = setTimeout(function() {
                        if (al) {
                            am.queryOtherBack(aw.resp)
                        } else {
                            am.queryBack(aw.resp)
                        }
                        clearTimeout(av)
                    },
                    25)
                });
                var an = true;
                var aj = setTimeout(function() {
                    if (al) {
                        G_PLAYER_INSTANCE.playOtherFail(false)
                    } else {
                        if (an) {
                            am.error("您的点播无法播放！请更换视频！忙<br>请尝试以下办法：<br>1,更换其他播放地址！<br>2,重新登录迅雷帐号！<br>3,重新打开软件！<br>4,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>")
                        }
                    }
                    clearTimeout(aj)
                },
                C)
            },
            genErrorMsg: function(aq, at) {
                var ap = this;
                var ao = "";
                var an = "";
                var ai = ap.isXlpan || ap.isThunderBox;
                var aw = ap.$PU("list") == "yincang" ? ("#list=" + ap.$PU("list") + "&p=" + ap.$PU("p")) : "#list=recent";
                var aj = "<a href='http://vod.xunlei.com/list.html" + aw + "' target='_blank' style='color:#1874CA;'>查看进度</a>";
                if (ap.platform == "client") {
                    aj = "<a href='http://vod.xunlei.com/client/clist.html" + aw + "' target='_self' style='color:#1874CA;'>查看进度</a>"
                }
                var am = "<a href=\"javascript:XL_CLOUD_FX_INSTANCE.windowOpenInPlayer('http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes')\" style='color:#1874CA;'>反馈问题</a>";
                var ak = {
                    illegalUrl: "该视频下载链接有误，无法播放<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    notVideo: "该下载链接不含视频,无法播放<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    leftTime: "您的点播无法播放！请更换视频！",
                    unkonwTime4Xlpan: "您的点播无法播放！请更换视频！转码<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    unkonwTime4Player: "您的点播无法播放！请更换视频！转码<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    unkonwTime: "您的点播无法播放！请更换视频！转码<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    downloading4Xlpan: "您的点播无法播放！请更换视频！转码<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    downloading4Player: "您的点播无法播放！请更换视频！转码<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    downloading: "您的点播无法播放！请更换视频！转码<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    transFail: "<br>1,请更换其他播放地址！2,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    serverError: "您的点播无法播放！请更换视频！转码<br>请尝试以下办法：<br>1,更换其他播放地址！<br>2,重新登录迅雷帐号！<br>3,重新打开软件！<br>4,联系QQ：<a href='http://wpa.qq.com/msgrd?V=1&Uin=706258852&Exe=QQ&Site=7tbw.com&Menu=yes' target='_blank' style='color:#1874CA;'>706258852</a>  官网：<a href='http://yun.7tbw.com/' target='_blank' style='color:#1874CA;'>http://yun.7tbw.com/</a>",
                    sessionidExpired: "检测到您未登录或登录异常，请重新登录后从列表页点播",
                    IPTooMuchUsed: "您的帐号因登录IP过多已被限制为不能播放，请于1天后重试，建议您尽快修改密码",
                    noPermit: "点播权限存在问题"
                };
                if (aq.ret == 6) {
                    ao = ak.illegalUrl
                } else {
                    if (aq.ret == 8) {
                        ao = ak.notVideo
                    } else {
                        if (aq.ret == 11) {
                            var au = 1;
                            if (au == 3) {
                                ao = ak.IPTooMuchUsed
                            } else {
                                if (au == 4 || au == 5) {
                                    ao = ak.sessionidExpired
                                } else {
                                    if (au != 0 && au != 1) {
                                        ao = ak.noPermit
                                    } else {
                                        ao = ak.serverError
                                    }
                                }
                            }
                        } else {
                            if (aq.ret == 14 || aq.ret == 15) {
                                ao = 15
                            } else {
                                if (typeof aq.status != "undefined" && aq.status == 2 && aq.trans_wait) {
                                    if (aq.trans_wait > 0 && aq.trans_wait < 60) {
                                        an = aq.trans_wait + "秒"
                                    } else {
                                        if (aq.trans_wait == -1) {
                                            if (ai) {
                                                return ak.unkonwTime4Xlpan
                                            } else {
                                                if (at) {
                                                    return ak.unkonwTime4Player
                                                } else {
                                                    return ak.unkonwTime
                                                }
                                            }
                                        } else {
                                            if (aq.trans_wait == -2) {
                                                if (ai) {
                                                    return ak.transFail + "，还不能解决" + am
                                                } else {
                                                    return ak.transFail
                                                }
                                            } else {
                                                var ah = parseInt(aq.trans_wait / 60);
                                                var av = 0;
                                                var al = ah;
                                                var ar = 0;
                                                if (ah >= 60) {
                                                    av = parseInt(ah / 60);
                                                    al = ah - av * 60;
                                                    if (av >= 24) {
                                                        ar = parseInt(av / 24);
                                                        av = av - ar * 24
                                                    }
                                                }
                                                if (ar) {
                                                    an += ar + "天"
                                                }
                                                if (av) {
                                                    an += av + "小时"
                                                }
                                                if (al) {
                                                    an += al + "分钟"
                                                }
                                            }
                                        }
                                    }
                                    if (ai) {
                                        ao = ak.leftTime + an + "," + am
                                    } else {
                                        if (at) {
                                            ao = ak.leftTime + an
                                        } else {
                                            ao = ak.leftTime + an + "," + aj
                                        }
                                    }
                                } else {
                                    if (typeof aq.status != "undefined" && aq.status == 1) {
                                        if (ai) {
                                            ao = ak.downloading4Xlpan
                                        } else {
                                            if (at) {
                                                ao = ak.downloading4Player
                                            } else {
                                                ao = ak.downloading
                                            }
                                        }
                                    } else {
                                        ao = ak.serverError
                                    }
                                }
                            }
                        }
                    }
                }
                return ao
            },
            queryBack: function(aq) {
                var ao = this;
                ao.curPlay = aq;
                ao.initPlayerEvent();
                var aj = ao.getPlatForm();
                var am = {
                    platform: aj
                };
                var al = function() {
                    v.attachEvent(v, "onload", 
                    function(av, au) {
                        if (a) {
                            G_PLAYER_INSTANCE.showDebug()
                        }
                        ao.initEvent();
                        G_PLAYER_INSTANCE.playOtherFail(false, ao.genErrorMsg(aq, 1));
                        var aw = {
                            description: "请选择字幕文件(*.srt、*.ass)",
                            extension: "*.srt;*.ass",
                            limitSize: 6 * 1024 * 1024,
                            uploadURL: Z + "interface/upload_file/?cid=" + q,
                            timeOut: "30"
                        };
                        G_PLAYER_INSTANCE.setCaptionParam(aw);
                        G_PLAYER_INSTANCE.setToolBarEnable({
                            enableShare: false,
                            enableFileList: d.enableFileList,
                            enableDownload: false,
                            enableSet: false,
                            enableCaption: false,
                            enableOpenWindow: d.enableOpenWindow,
                            enableTopBar: d.enableTopBar,
                            enableFeedback: true
                        });
                        ao.setFeeParam(0);
                        ao.setShareParam()
                    });
                    var at = T.getAttribute("id");
                    v.printObject(at, false, "100%", "100%", "", am);
                    try {
                        window[U].call()
                    } catch(ar) {}
                };
                if (typeof aq.status == "undefined" || aq.status != 0) {
                    try {
                        if (isClientVodScene && aq.ret == 0) {
                            var ai = "";
                            ai = H;
                            if (ao.type == "bt") {
                                ai = Q
                            }
                            ao.stat({
                                f: "trialPlayAtOnceFail",
                                id: ai,
                                status: aq.status,
                                transWait: aq.trans_wait
                            })
                        }
                    } catch(ap) {}
                    if (isClientVodScene && (aq.ret == 14 || aq.ret == 15)) {
                        al()
                    } else {
                        if (aq.ret == 11) {
                            ao.error(ao.genErrorMsg(aq))
                        } else {
                            if (c || ao.type == "url" || ao.fileList == null || ao.fileList.subfile_list.length <= 1) {
                                ao.error(ao.genErrorMsg(aq))
                            } else {
                                al()
                            }
                        }
                    }
                } else {
                    if (ao.type == "url") {
                        ao.getLastPos();
                        ao.fileList = {
                            userid: ao.user.u,
                            info_hash: "",
                            subfile_list: [{
                                name: ao.curPlay.src_info.file_name,
                                index: -1,
                                url_hash: ao.curPlay.url_hash
                            }]
                        }
                    }
                    if (ao.originalPlay == null) {
                        ao.originalPlay = aq
                    }
                    ao.cacheData = ao.cacheReqData(ao.cacheData, aq, ao.curPlay.url_hash);
                    var ak = aq.vodinfo_list;
                    ao.vod_info = ak;
                    v.attachEvent(v, "onload", 
                    function(at, ar) {
                        if (a) {
                            G_PLAYER_INSTANCE.showDebug()
                        }
                        if (!o) {
                            o = G_PLAYER_INSTANCE.getDefaultFormat() || "p"
                        }
                        ao.initEvent();
                        var au = ak.length;
                        if ((au == 1 && (o == "g" || o == "c"))) {
                            o = "p"
                        } else {
                            if ((au == 2 && o == "c")) {
                                o = "g"
                            }
                        }
                        if (o == "g") {
                            var av = ak[1].vod_url
                        } else {
                            if (o == "c") {
                                var av = ak[2].vod_url
                            } else {
                                var av = ak[0].vod_url
                            }
                        }
                        if (!ao.curName) {
                            ao.curName = g(ao.curPlay.src_info.file_name)
                        }
                        ao.startPlay(av, o, ao.lastPos);
                        ao.getFormats();
                        G_PLAYER_INSTANCE.playOtherFail(true);
                        ao.getCaption(ao.curPlay.src_info.gcid, ao.curPlay.src_info.cid);
                        ao.setShareParam();
                        ao.curName = g(ao.curPlay.src_info.file_name)
                    });
                    var ah = T.getAttribute("id");
                    v.printObject(ah, false, "100%", "100%", "", am);
                    try {
                        window[U].call()
                    } catch(ap) {}
                }
                if (ao.curPlay.src_info) {
                    var an = ao.curPlay.src_info.gcid
                } else {
                    var an = ""
                }
                try {
                    ao.stat({
                        f: "svrresp",
                        ret: ao.curPlay.ret,
                        pt: ao.curPlay.status,
                        gcid: an
                    })
                } catch(ap) {}
            },
            cacheReqData: function(ai, ah, ak) {
                var ai = ai || [];
                var am = ai.length;
                if (am > 0 && am < 6) {
                    var al = [];
                    for (var aj = 0; aj < am; aj++) {
                        if (ai[aj].url_hash && ai[aj].url_hash != ak) {
                            al.push(ai[aj])
                        }
                    }
                    ai = al
                }
                ai.push(ah);
                if (ai.length == 5) {
                    ai.shift()
                }
                return ai
            },
            startPlay: function(ah, al, ao, an) {
                var aj = this;
                ao = ao || 0;
                aj.lastFormat = al;
                aj.curDlUrl = ah;
                if (c) {
                    G_PLAYER_INSTANCE.setUrl(ah, ao);
                    this.getFormats();
                    return true
                } else {
                    var am = {};
                    am.totalByte = 1;
                    am.totalTime = parseInt(this.curPlay.duration / 1000000);
                    var ai = ah;
                    am.totalByte = parseInt(this.$PU("s", ai));
                    am.sliceType = 0;
                    if (ao && ao > 0) {
                        am.start = ao
                    }
                    G_PLAYER_INSTANCE.stop();
                    try {
                        G_PLAYER_INSTANCE.close()
                    } catch(ak) {}
                    G_PLAYER_INSTANCE.setToolBarEnable(d);
                    aj.setFeeParam(1);
                    am.format = al;
                    if (y) {
                        this.enableKKVA()
                    }
                    G_PLAYER_INSTANCE.flashopen(ai, true, false, ae, am, 0)
                }
            },
            playOther: function(ap, ak, am, ah, at, ar) {
                var aq = this;
                if (!aq.validUrl(ak)) {
                    G_PLAYER_INSTANCE.playOtherFail(false, "该视频下载链接有误，无法播放");
                    aq.setFeeParam(0);
                    G_PLAYER_INSTANCE.setToolBarEnable({
                        enableShare: false,
                        enableFileList: false,
                        enableDownload: false,
                        enableSet: false,
                        enableCaption: false,
                        enableOpenWindow: d.enableOpenWindow,
                        enableTopBar: d.enableTopBar,
                        enableFeedback: true
                    });
                    return false
                }
                aq.reportPlayPos();
                ak = b(ak);
                Q = g(ak);
                aq.type = "url";
                var al = aq.genBtUrl(Q);
                if (al) {
                    aq.type = "bt";
                    Q = al
                }
                ae = true;
                o = G_PLAYER_INSTANCE.getDefaultFormat() || "p";
                R = 0;
                aq.captionList = [];
                aq.isFromList = false;
                aq.curUrl = ak;
                if (!ap) {
                    aq.isFromList = true;
                    aq.curName = g(ah);
                    ah = "";
                    if (al == aq.genBtUrl(i, "", 1)) {
                        ah = O
                    }
                    var aj = false;
                    if (aq.cacheData) {
                        var ao = null;
                        var au = aq.cacheData.length;
                        for (var an = 0; an < au; an++) {
                            if (am && aq.cacheData[an].url_hash == am && aq.cacheData[an].status == 0) {
                                aj = true;
                                ao = aq.cacheData[an];
                                break
                            }
                        }
                    }
                    aq.getLastPos()
                } else {
                    aq.fileList = null
                }
                if (aj) {
                    var ai = setTimeout(function() {
                        aq.queryOtherBack(ao);
                        clearTimeout(ai)
                    },
                    30)
                } else {
                    aq.query(b(ak), ah, at, ar, "", 1)
                }
            },
            queryOtherBack: function(ak) {
                var aj = this;
                aj.curPlay = ak;
                if (ak.status != 0) {
                    G_PLAYER_INSTANCE.playOtherFail(false, aj.genErrorMsg(ak, 1));
                    G_PLAYER_INSTANCE.setToolBarEnable({
                        enableShare: false,
                        enableFileList: d.enableFileList,
                        enableDownload: false,
                        enableSet: false,
                        enableCaption: false,
                        enableOpenWindow: d.enableOpenWindow,
                        enableTopBar: d.enableTopBar,
                        enableFeedback: true
                    });
                    if (!aj.isFromList) {
                        if (aj.curPlay.src_info) {
                            aj.curName = g(aj.curPlay.src_info.file_name)
                        } else {
                            aj.curName = Q
                        }
                    }
                    aj.setFeeParam(0)
                } else {
                    if (aj.type == "url") {
                        aj.getLastPos()
                    }
                    aj.cacheData = aj.cacheReqData(aj.cacheData, ak, aj.curPlay.url_hash);
                    var am = ak.vodinfo_list;
                    aj.vod_info = am;
                    if (!aj.isFromList) {
                        aj.curName = g(aj.curPlay.src_info.file_name)
                    }
                    var ah = setTimeout(function() {
                        var an = am.length;
                        if ((an == 1 && (o == "g" || o == "c"))) {
                            o = "p"
                        } else {
                            if ((an == 2 && o == "c")) {
                                o = "g"
                            }
                        }
                        if (o == "g") {
                            var ao = am[1].vod_url
                        } else {
                            if (o == "c") {
                                var ao = am[2].vod_url
                            } else {
                                var ao = am[0].vod_url
                            }
                        }
                        aj.startPlay(ao, o, aj.lastPos);
                        clearTimeout(ah);
                        aj.getFormats()
                    },
                    50);
                    G_PLAYER_INSTANCE.playOtherFail(true);
                    aj.getCaption(ak.src_info.gcid, ak.src_info.cid);
                    aj.setShareParam()
                }
                try {
                    window[af].call()
                } catch(al) {}
                if (ak.src_info) {
                    var ai = ak.src_info.gcid
                } else {
                    var ai = ""
                }
                try {
                    aj.stat({
                        f: "svrresp",
                        ret: ak.ret,
                        pt: ak.status,
                        gcid: ai
                    })
                } catch(al) {}
            },
            getPlatForm: function() {
                var ah = "webpage";
                try {
                    ah = (window.external.getVodClientVer()) ? "client": "webpage"
                } catch(ai) {}
                return ah
            },
            setFeeParam: function(ah) {
                var ak = this;
                var aj = x;
                if (ak.isXlpan || ak.isThunderBox) {
                    aj = "xlpan"
                }
                if (ah) {
                    var al = ak.curPlay.src_info;
                    var ai = al.file_size || "";
                    G_PLAYER_INSTANCE.setFeeParam({
                        sessionid: ak.user.s,
                        userid: ak.user.u,
                        userType: 1,
                        isvip: 6,
                        gcid: ak.$PU("g", ak.curDlUrl),
                        cid: "0000000000000000000000000000000000000000",
                        name: ak.curName,
                        url_hash: ak.curPlay.url_hash,
                        from: aj,
                        url: g(ak.curUrl),
                        index: (ak.curUrl.substr(parseInt(ak.curUrl.lastIndexOf("/")) + 1, ak.curUrl.length)),
                        ygcid: al.gcid,
                        ycid: al.cid,
                        filesize: ai,
                        info_hash: ak.curInfohash
                    })
                } else {
                    G_PLAYER_INSTANCE.setFeeParam({
                        sessionid: ak.user.s,
                        userid: ak.user.u,
                        userType: 1,
                        isvip: 6,
                        gcid: "",
                        cid: "0000000000000000000000000000000000000000",
                        name: "",
                        url_hash: ak.curPlay.url_hash,
                        from: aj,
                        url: g(ak.curUrl),
                        index: (ak.curUrl.substr(parseInt(ak.curUrl.lastIndexOf("/")) + 1, ak.curUrl.length)),
                        ygcid: "",
                        ycid: "",
                        filesize: "",
                        info_hash: ak.curInfohash
                    })
                }
            },
            $PU: function(aj, ai) {
                ai = ac(ai) ? location.href: ai;
                var ah = ai.match(new RegExp("[#|?]([^#]*)[#|?]?"));
                ai = "&" + (W(ah) ? "": ah[1]);
                ah = ai.match(new RegExp("&" + aj + "=", "i"));
                return W(ah) ? undefined: ai.substr(ah.index + 1).split("&")[0].split("=")[1]
            },
            getFormats: function(ai) {
                ai = ai || this.lastFormat;
                var ah = {
                    c: {
                        checked: false,
                        enable: false
                    },
                    g: {
                        checked: false,
                        enable: false
                    },
                    p: {
                        checked: false,
                        enable: false
                    },
                    y: {
                        checked: false,
                        enable: false
                    }
                };
                ah.g.enable = typeof(this.vod_info[1]) != "undefined";
                ah.c.enable = typeof(this.vod_info[2]) != "undefined";
                ah.p.enable = true;
                ah[ai].checked = true;
                G_PLAYER_INSTANCE.setFormats(ah)
            },
            setFormats: function(ah, al, ai, aj) {
                var ak = G_PLAYER_INSTANCE.getPlayPosition();
                var ah = this;
                ae = true;
                if (ai == "p") {
                    ah.close();
                    G_PLAYER_INSTANCE.setIsChangeQuality(true);
                    this.startPlay(this.vod_info[0].vod_url, "p", ak, 1);
                    ah.getFormats()
                } else {
                    if (ai == "g") {
                        ah.close();
                        G_PLAYER_INSTANCE.setIsChangeQuality(true);
                        this.startPlay(this.vod_info[1].vod_url, "g", ak, 1);
                        ah.getFormats()
                    } else {
                        if (ai == "c") {
                            ah.close();
                            G_PLAYER_INSTANCE.setIsChangeQuality(true);
                            this.startPlay(this.vod_info[2].vod_url, "c", ak, 1);
                            ah.getFormats()
                        }
                    }
                }
            },
            error: function(ai) {
                T.innerHTML = "<img src='" + ag + "img/play_bg.jpg' width='100%' height='100%' /><div style='position:absolute;left:0;top:46%;text-align:center;font-size:14px;color:#FFF;margin: 0;width:100%;height:22px;'>" + ai + "</div>";
                try {
                    window[s].call()
                } catch(ah) {}
            },
            close: function() {
                try {
                    G_PLAYER_INSTANCE.close();
                    G_PLAYER_INSTANCE.closeNetStream()
                } catch(ah) {}
            },
            getCaption: function(aj, ak) {
                if (c) {
                    return true
                }
                var ah = this;
                var ai = {
                    description: "请选择字幕文件(*.srt、*.ass)",
                    extension: "*.srt;*.ass",
                    limitSize: 5 * 1024 * 1024,
                    uploadURL: Z + "interface/upload_file/?cid=" + ak,
                    timeOut: "30"
                };
                G_PLAYER_INSTANCE.setCaptionParam(ai);
                k(F + "subtitle/list/gcid/" + aj + "/cid/" + ak, "XL_CLOUD_FX_INSTANCEqueryCaptionBack", 
                function(al) {
                    ah.queryCaptionBack(al, ak)
                })
            },
            queryCaptionBack: function(ah, aq) {
                var ap = ah.sublist.length;
                if (ah.sublist != undefined && ah.sublist.length > 0) {
                    var ao = ah.sublist;
                    for (var an = 0; an < ap; an++) {
                        if (this.captionList.length > 3) {
                            break
                        }
                        var au = ao[an];
                        if (au.sname == undefined) {
                            continue
                        }
                        var ar = au.sname;
                        var at = ar.length;
                        if (at > 0) {
                            for (var am = 0; am < at; am++) {
                                var ai = g(ar[am]);
                                var ak = ai.lastIndexOf(".");
                                var al = ai.length;
                                var aj = ai.substring(parseInt(ak) + 1, al).toLowerCase();
                                if (aj == "ass" || aj == "srt") {
                                    this.captionList.push({
                                        autoload: au.autoload,
                                        language: au.language[0] || "",
                                        scid: au.scid,
                                        sname: ai,
                                        surl: "http://i.vod.xunlei.com/subtitle/data/scid/" + au.scid + ".srt",
                                        svote: au.svote || 0
                                    })
                                }
                            }
                        }
                    }
                    if (!c) {
                        G_PLAYER_INSTANCE.setCaptionList(this.captionList)
                    }
                }
            },
            addCaptionList: function(ak) {
                var ah = ak.length;
                if (!ak || typeof(ak) != "object" || ah < 1) {
                    return false
                }
                var aj = 1;
                if (this.captionList.length == 0) {
                    aj = 3
                } else {
                    if (this.captionList.length == 1) {
                        aj = 2
                    }
                }
                for (var ai = 0; ai < ah; ai++) {
                    if (ai == aj) {
                        break
                    }
                    this.captionList.push(ak[ai])
                }
                if (this.captionList.length > 3) {
                    this.captionList.shift()
                }
                G_PLAYER_INSTANCE.setCaptionList(this.captionList)
            },
            getBtFileLastPos: function() {
                var ai = this;
                if (ai.type == "url" || ai.curInfohash.length != 40) {
                    return false
                }
                if (ai.fileList == null) {
                    var ah = F + "req_subBT/info_hash/" + ai.curInfohash + "/req_num/2/req_offset/0?cache=" + new Date().getTime();
                    J(ah, "XL_CLOUD_FX_INSTANCEqueryFileListBack", 
                    function(aj) {
                        ai.fileList = aj.resp;
                        if (ai.fileList.ret == 0) {
                            ai.getLastPos()
                        }
                    })
                }
            },
            setShareParam: function() {
                var ah = "我正在观看" + g(this.curName);
                G_PLAYER_INSTANCE.setShareParam(ah, g(Q))
            },
            loginNotice: function() {
                window.open("http://vod.xunlei.com/home.html?xcvp=login");
                this.error("继续<a style='color:#1874CA' href='javascript:;' onclick='XL_CLOUD_FX_INSTANCE.continuePlay();return false;'>播放</a>")
            },
            continuePlay: function() {
                var ah = this;
                ah.error("请稍候，精彩即将开启...");
                ah.uCheck()
            },
            getLastPos: function() {
                var ak = this;
                if (R) {
                    ak.lastPos = R;
                    return true
                }
                ak.lastPos = 0;
                if (ak.type == "bt") {
                    var ai = ak.curUrl.substr(ak.curUrl.lastIndexOf("/") + 1, ak.curUrl.length);
                    var aj = ak.fileList.main_task_url_hash
                } else {
                    var aj = ak.curPlay.url_hash
                }
                var al = null,
                ah = true;
                J(F + "req_last_play_pos?userid=" + ak.user.u + "&query_list=" + aj + "_" + ((ak.type == "bt") ? 1: 0) + "&t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryLastPosBack", 
                function(ao) {
                    clearTimeout(al);
                    ah = false;
                    if (ao.resp && ao.resp.ret == 0) {
                        var an = ao.resp.res_list;
                        if (an && an[0]) {
                            if (an[0].is_bt_play == 0) {
                                ak.lastPos = an[0].last_play_pos
                            } else {
                                if (an[0].sub_list && an[0].sub_list.length > 0) {
                                    var aq = an[0].sub_list;
                                    var am = an[0].sub_list.length;
                                    for (var ap = 0; ap < am; ap++) {
                                        if (aq[ap].idx == ai) {
                                            ak.lastPos = aq[ap].last_play_pos;
                                            break
                                        }
                                    }
                                }
                            }
                        }
                    }
                });
                setTimeout(function() {
                    clearTimeout(al);
                    ah = false;
                    if (ah) {
                        ak.lastPos = 0
                    }
                },
                1000)
            },
            genBtUrl: function(aj, ak, ai) {
                if (!aj && !ak) {
                    return false
                }
                var ah = "";
                if (ak && ak.length == 40) {
                    ah = ak
                } else {
                    if (g(aj).substr(0, 5) == "bt://") {
                        ah = g(aj).substring(5, g(aj).lastIndexOf("/"))
                    }
                }
                if (ah) {
                    if (!ai) {
                        this.curInfohash = ah
                    }
                    return "http://bt.box.n0808.com/" + ah.substr(0, 2) + "/" + ah.substr(38, 40) + "/" + ah + ".torrent"
                } else {
                    return false
                }
            },
            validUrl: function(ah) {
                if (ah == "" || ah == "none" || ah == "undefined" || (document.location.protocol + "//" + document.location.host + "/") == ah) {
                    return false
                }
                var ai = ah.toLowerCase();
                if (((ai.indexOf("http") == -1) && (ai.indexOf("https") == -1) && (ai.indexOf("ftp") == -1) && (ai.indexOf("thunder") == -1) && (ai.indexOf("mms") == -1) && (ai.indexOf("qqdl") == -1) && (ai.indexOf("rtsp") == -1) && (ai.indexOf("magnet") == -1) && (ai.indexOf("flashget") == -1) && (ai.indexOf("ed2k") == -1) && (ai.indexOf("bt") == -1) && (ai.indexOf("xlpan") == -1)) || ai == "") {
                    return false
                } else {
                    return true
                }
            },
            windowOpenInPlayer: function(ai) {
                var am = document;
                _body = document.getElementsByTagName("body")[0];
                var al = null;
                var ah = am.getElementById("dapctrl");
                if (ah) {
                    try {
                        am.getElementsByTagName("body")[0].removeChild(ah)
                    } catch(ak) {}
                }
                if (!t && !am.getElementById("dapctrl")) {
                    var aj = am.createElement("object");
                    aj.setAttribute("type", "application/x-thunder-dapctrl");
                    aj.setAttribute("id", "dapctrl");
                    aj.setAttribute("width", "0");
                    aj.setAttribute("height", "0");
                    aj.style.visibility = "hidden";
                    _body.appendChild(aj)
                } else {
                    try {
                        al = new ActiveXObject("DapCtrl.DapCtrl")
                    } catch(ak) {}
                }
                if (al) {
                    al.Put("iADShowMode", 1);
                    al.Put("sOpenAdUrl", ai);
                    al = null
                } else {
                    window.open(ai)
                }
            },
            openMini: function(ah, ai) {
                try {
                    this.reportPlayPos()
                } catch(aj) {}
                window.open("http://yun.7tbw.com/vip.html?url=" + ThunderEncode(encodeURIComponent(i)), "miniplayer", "top=10,left=10,height=446,width=684,toolbar=no,menubar=no,resizable=yes,scrollbars=no,location=no,status=no,fullscreen=no")
            },
            enableKKVA: function() {
                var aj = this;
                aj.kkvaValid = false;
                if (c || (!aj.isThunderBox && !t)) {
                    return true
                }
                var ai = document.getElementsByTagName("body")[0];
                var an = document.getElementById("vasensor");
                try {
                    ai.removeChild(an)
                } catch(ak) {}
                var al = document.createElement("object");
                al.setAttribute("id", "vasensor");
                al.setAttribute("width", "0");
                al.setAttribute("height", "0");
                al.style.visibility = "hidden";
                if (!t) {
                    al.setAttribute("type", "application/x-thunder-kkva")
                } else {
                    al.setAttribute("classid", "CLSID:96CD6DA7-17F2-4576-82B0-BE4526FB7D6B")
                }
                document.getElementsByTagName("body")[0].appendChild(al);
                var ap = 0;
                if (XL_CLOUD_FX_INSTANCE.lastFormat == "c") {
                    ap = 2
                } else {
                    if (XL_CLOUD_FX_INSTANCE.lastFormat == "g") {
                        ap = 1
                    }
                }
                var aq = XL_CLOUD_FX_INSTANCE.vod_info[ap]["vod_url"];
                var am = this.$PU("g", aq);
                if (aj.isThunderBox) {
                    try {
                        var ao = window.external.GetClientVersion()
                    } catch(ak) {
                        var ao = "1.6"
                    }
                    if (ao < "1.6") {} else {
                        try {
                            if (al.Get("iVersion") != 100007) {
                                al.EnableVA("yvod", am, aq, 0);
                                aj.kkvaValid = true;
                                al.Put("iXMPIconTray", 0);
                                aj.stat({
                                    f: "kkva",
                                    g: am,
                                    client: "thunderBox"
                                })
                            }
                        } catch(ak) {}
                    }
                } else {
                    try {
                        var ah = document.getElementById("myPlugin");
                        if (!ah) {
                            var ah = document.createElement("object");
                            ah.setAttribute("id", "myPlugin");
                            ah.setAttribute("width", "0");
                            ah.setAttribute("height", "0");
                            ah.style.visibility = "hidden";
                            if (t) {
                                ah.setAttribute("classid", "clsid:BD1E9B61-F3B2-4A19-AB69-68E77CA81C42")
                            } else {
                                ah.setAttribute("type", "application/x-thunderbox-upload")
                            }
                            document.getElementsByTagName("body")[0].appendChild(ah)
                        }
                        if (ah.FindThunderbox() && ah.GetThunderboxVersion() >= "1.6" && al.Get("iVersion") != 100007) {
                            al.EnableVA("yvod", am, aq, 0);
                            aj.kkvaValid = true;
                            al.Put("iXMPIconTray", 0);
                            aj.stat({
                                f: "kkva",
                                g: am,
                                client: "web"
                            })
                        } else {}
                    } catch(ak) {}
                }
                return true
            }
        };
        J(Z + "fx?t=" + new Date().getTime(), "", 
        function(ah) {
            return false
        });
        var n = c ? (ag + "fx/js/ipad.js?" + ad) : ("/svn/x/f.h?" + ad);
        var S = new P(n);
        S.buildScriptTag();
        S.addScriptTag()
    },
    1)
})();