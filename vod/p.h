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
        var ad = function(e) {
            return typeof e == "undefined"
        };
        var X = function(e) {
            return typeof e == "object" && !e
        };
        var x = "XL_CLOUD_VOD_PLAYER";
        var c = (window.navigator.userAgent.toLowerCase().indexOf("ipad") > 0 || window.navigator.userAgent.toLowerCase().indexOf("iphone") > 0) ? 1: 0;
        var u = (navigator.appVersion.indexOf("MSIE") != -1) ? true: false;
        var q = navigator.userAgent.toUpperCase().indexOf("Firefox") ? true: false;
        var af = "2.8231";
        var D = 30000;
        var ai = "http://vod.xunlei.com/";
        var aa = "http://dynamic.vod.lixian.xunlei.com/";
        var G = "http://i.vod.xunlei.com/";
        var L = new Date().getTime();
        function O(e) {
            return document.getElementById(e)
        }
        var C = O(x);
        if (!C) {
            return false
        }
        function k(e) {
            return (document.cookie.match(new RegExp("(^" + e + "| " + e + ")=([^;]*)")) == null) ? "": RegExp.$2
        }
        function b(e) {
            return e.replace(/(^\s*)|(\s*$)/g, "")
        }
        function h(am) {
            var ak = "";
            try {
                ak = decodeURIComponent(decodeURIComponent(am))
            } catch(al) {
                try {
                    ak = decodeURIComponent(am)
                } catch(al) {
                    ak = am
                }
            }
            return ak
        }
        function i(e) {
            return encodeURIComponent(e)
        }
        function Q(e) {
            this.fullUrl = e;
            this.noCacheIE = "&noCacheIE=" + (new Date()).getTime();
            this.headLoc = document.getElementsByTagName("head").item(0);
            this.scriptId = "JscriptId" + Q.scriptCounter++
        }
        Q.scriptCounter = 1;
        Q.prototype.buildScriptTag = function() {
            this.scriptObj = document.createElement("script");
            this.scriptObj.setAttribute("type", "text/javascript");
            this.scriptObj.setAttribute("src", this.fullUrl)
        };
        Q.prototype.removeScriptTag = function() {
            this.headLoc.removeChild(this.scriptObj)
        };
        Q.prototype.addScriptTag = function() {
            this.headLoc.appendChild(this.scriptObj)
        };
        function K(e, al, an) {
            var ak = e;
            if (al) {
                window[al] = an
            }
            if (ak.indexOf("?") != -1) {
                ak += "&jsonp=" + al
            } else {
                ak += "?jsonp=" + al
            }
            var am = new Q(ak);
            am.buildScriptTag();
            am.addScriptTag()
        }
        function l(e, al, an) {
            var ak = e;
            if (al) {
                window[al] = an
            }
            ak += "&callback=" + al;
            var am = new Q(ak);
            am.buildScriptTag();
            am.addScriptTag();
            return this
        }
        function Z(ak, e) {
            return ak.getAttribute(e)
        }
        function v(al, an, ak, am) {
            if (arguments.length > 2) {
                var e = new Date(new Date().getTime() + ak * 3600000);
                document.cookie = al + "=" + encodeURIComponent(an) + "; domain=xunlei.com; expires=" + e.toGMTString()
            } else {
                document.cookie = al + "=" + encodeURIComponent(an) + "; path=/; domain=xunlei.com"
            }
        }
        function ab(al, ak) {
            ak = ad(ak) ? location.href: ak;
            var e = ak.match(new RegExp("[#|?]([^#]*)[#|?]?"));
            ak = "&" + (X(e) ? "": e[1]);
            e = ak.match(new RegExp("&" + al + "=", "i"));
            return X(e) ? undefined: ak.substr(e.index + 1).split("&")[0].split("=")[1]
        }
        var H = false;
        try {
            if (ab("from")) {
                var H = (ab("from").indexOf("xl_scene") != -1) ? true: false
            } else {
                H = false
            }
        } catch(aj) {
            H = false
        }
        try {
            if (window.G_PAGE && window.G_PAGE == "vodplay" && H) {
                H = true
            } else {
                H = false
            }
        } catch(aj) {
            H = false
        }
        var z = 6;
        var ae = (ab("flux") == 1) ? true: false;
        window.isClientVodScene = false;
        if (H && z == 0 && !ae) {
            window.isClientVodScene = true
        }
        var U = C;
        var y = U.getAttribute("from");
        y = y || "unknown";
        var Y = U.getElementsByTagName("a");
        if (Y.length == 0) {
            Y = U.getElementsByTagName("span");
            if (Y.length == 0) {
                return
            }
            var g = Y[0];
            var j = b(Z(g, "url"))
        } else {
            var g = Y[0];
            var j = b(g.getAttribute("href"))
        }
        var J = Z(g, "filesize");
        var I = Z(g, "gcid");
        var r = Z(g, "cid");
        var P = Z(g, "title");
        var V = Z(g, "onsuccess");
        var ah = Z(g, "playother");
        var t = Z(g, "onfail");
        if (!U.style.height) {
            U.style.height = "446px"
        }
        if (!U.style.width) {
            U.style.width = "684px"
        }
        U.style.overflow = "hidden";
        var R = Z(g, "share_url");
        R = R ? h(R) : h(j);
        var ag = Z(g, "autoplay");
        if (!ag || ag != "true") {
            ag = false
        } else {
            ag = true
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
        var B = Z(g, "enable_panel");
        if (B && B == "false") {
            d.enableShare = false
        }
        var N = Z(g, "enable_download");
        if (N && N == "false") {
            d.enableDownload = false
        }
        var F = Z(g, "enable_caption");
        if (F && F == "false") {
            d.enableCaption = false
        }
        var m = Z(g, "enable_filelist");
        if (m && m == "false") {
            d.enableFileList = false
        }
        var ac = Z(g, "enable_setting");
        if (ac && ac == "false") {
            d.enableSet = false
        }
        var E = Z(g, "enable_openwindow");
        if (E && E == "false") {
            d.enableOpenWindow = false
        }
        var n = Z(g, "enable_topbar");
        if (n && n == "false") {
            d.enableTopBar = false
        }
        var A = Z(g, "enable_kkva");
        if (A && A == "true") {
            A = true
        } else {
            A = false
        }
        var S = parseInt(Z(g, "start")) || 0;
        var p = Z(g, "format");
        var W;
        var s = false,
        M = /xyz/.test(function() {
            xyz
        }) ? /\b_super\b/: /.*/;
        var f = function() {};
        f.extend = function(an) {
            var am = this.prototype;
            s = true;
            var al = new this();
            s = false;
            for (var ak in an) {
                al[ak] = typeof an[ak] == "function" && typeof am[ak] == "function" && M.test(an[ak]) ? (function(ao, ap) {
                    return function() {
                        var ar = this._super;
                        this._super = am[ao];
                        var aq = ap.apply(this, arguments);
                        this._super = ar;
                        return aq
                    }
                })(ak, an[ak]) : an[ak]
            }
            function e() {
                if (!s && this.init) {
                    this.init.apply(this, arguments)
                }
            }
            e.prototype = al;
            e.constructor = e;
            e.extend = arguments.callee;
            return e
        };
        var w;
        window.XL_CLOUD_FX_INSTANCE = {
            Class: f,
            lastFormat: "p",
            cacheData: [],
            curPlay: null,
            curInfohash: "",
            curDlUrl: "",
            curUrl: h(j),
            curName: h(P),
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
            init: function(ak) {
                w = ak;
                var am = this;
                am.platform = am.getPlatForm();
                if (!am.validUrl(am.curUrl)) {
                    am.error("您的点播url非法，无法播放！");
                    return false
                }
                var ap = U.getAttribute("id");
                if (!ap) {
                    ap = "XL_CLOUD_PLAY_BOX";
                    U.setAttribute("id", ap)
                }
                U.style.backgroundColor = "#000";
                var an = ["61.147.76.6", "61.147.76.6", "222.141.53.5", "222.141.53.5"];
                goip = an[0];
                K(aa + "interface/getip?t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryIpBack", 
                function(aq) {
                    try {
                        goip = an[aq]
                    } catch(ar) {
                        try {
                            goip = an[aq.result]
                        } catch(ar) {
                            goip = an[0]
                        }
                    }
                });
                am.isVod = (document.location.host == an[0] || document.location.host == an[2]);
                am.isXlpan = /.*((xlpan)|(f\.xunlei\.com)).*/.exec(document.location.host);
                try {
                    am.isThunderBox = window.external.IsInXLpanClient()
                } catch(ao) {
                    am.isThunderBox = false
                }
                var al = am.genBtUrl(am.curUrl);
                if (al) {
                    am.type = "bt";
                    R = al
                }
                am.uCheck();
                window.onunload = function(aq) {
                    am.reportPlayPos();
                    if (am.curPlay) {
                        try {
                            var av = G_PLAYER_INSTANCE.getTimePlayed();
                            var ar = av.playedtime;
                            var az = av.playedbyte;
                            var aw = av.downloadbyte
                        } catch(ax) {
                            var ar = 0;
                            var az = 0;
                            var aw = 0
                        }
                        try {
                            var aC = G_PLAYER_INSTANCE.getPlayPosition()
                        } catch(ax) {
                            var aC = 0
                        }
                        var ay = am.curPlay.src_info;
                        if (ay) {
                            var at = ay.gcid || ""
                        } else {
                            var at = ""
                        }
                        var aB = am.$PU("g", am.curDlUrl) || "";
                        var aA = am.curPlay.duration / 1000000 || 0;
                        var au = new Image();
                        au.src = "http://i.vod.xunlei.com/stat/s.gif?f=playtime&p=XCVP&totaltime=" + aA + "&du=" + ar + "&by=" + az + "&downby=" + aw + "&t=" + aC + "&gcid=" + aB + "&ygcid=" + at + "&u=" + am.user.u + "&v=" + am.user.v + "&from=" + y + "&d=" + L
                    }
                    am.close()
                };
                setTimeout(function() {
                    am.stat({
                        p: "XCVP",
                        f: "pv"
                    })
                },
                25)
            },
            uVipinfo: function() {
                l(aa + "interface/getuservipinfo?t=" + L, "XL_CLOUD_FX_INSTANCEqueryVipinfoBack", 
                function(al) {
                    if (al.result == "0" && al.vipinfo.payid) {
                        var ap = al.vipinfo;
                        if (ap.payid - 1000 > 0) {
                            var ak = ap.expiredate.split("-");
                            var e = al.svrtime.split("-");
                            var an = ak[0] - e[0];
                            var aq = ak[1] - e[1];
                            var am = ak[2] - e[2];
                            var ao = "";
                            if (am < 0) {
                                var ar = new Date();
                                ar = new Date(ar.getFullYear(), ar.getMonth() + 3, 0);
                                if (aq > 0) {
                                    aq = aq - 1
                                } else {
                                    an -= 1;
                                    aq = 11
                                }
                                am = ar.getDate() + am
                            }
                            if (an > 0) {
                                ao += an + "年"
                            }
                            if (aq > 0) {
                                ao += aq + "月"
                            }
                            if (am > 8 || an > 0 || aq > 0) {
                                return false
                            }
                            ao += am + "天";
                            ao = "您的体验会员将在" + ao + "后到期，建议您开通正式会员";
                            G_PLAYER_INSTANCE.setNoticeMsg(ao, 1500)
                        }
                    }
                })
            },
            uCheck: function() {
                var e = this;
                if (e.isXlpan || e.isThunderBox || e.isVod || isClientVodScene) {
                    if (!e.isVod) {
                        d.enableOpenWindow = false
                    }
                    e.user.u = k("userid");
                    e.user.v = "6";
                    e.user.s = k("sessionid");
                    e.query(e.curUrl, e.curName, I, r, J);
                    return true
                }
                var ak = null;
                isTimeout = true;
                K(aa + "interface/getXlCookie?t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryXlCookieBack", 
                function(al) {
                    if (al && al.sessionid && al.userid) {
                        e.user.u = al.userid;
                        e.user.v = "6";
                        e.user.s = al.sessionid;
                        if (!k("userid") && !k("isvip") && !k("sessionid")) {
                            v("userid");
                            v("isvip");
                            v("sessionid")
                        }
                        e.query(e.curUrl, e.curName, I, r, J)
                    } else {
                        e.query(e.curUrl, e.curName, I, r, J)
                    }
                    isTimeout = false;
                    clearTimeout(ak)
                });
                ak = setTimeout(function() {
                    if (isTimeout) {
                        e.error("暂时无法验证您的登录状态，请稍后<a style='color:#1874CA;' href='javascript:;' onclick='XL_CLOUD_FX_INSTANCE.uCheck();return false;'>重试</a>")
                    }
                    isTimeout = false;
                    clearTimeout(ak)
                },
                D)
            },
            uUpdate: function() {
                var e = this;
                K(aa + "interface/getXlCookie?t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryXlCookieBack", 
                function(ak) {
                    if (ak && ak.sessionid && ak.isvip && ak.userid) {
                        e.user.u = ak.userid;
                        e.user.v = "6";
                        e.user.s = ak.sessionid;
                        if (!k("userid") && !k("isvip") && !k("sessionid")) {
                            v("userid");
                            v("isvip");
                            v("sessionid")
                        }
                    }
                })
            },
            reportPlayPos: function() {
                var am = this;
                if (am.curPlay && am.curPlay.ret == 0) {
                    var al = "";
                    if (am.type == "bt" && am.fileList && am.fileList.main_task_url_hash) {
                        al = am.fileList.main_task_url_hash
                    } else {
                        if (am.curPlay && am.curPlay.url_hash) {
                            al = am.curPlay.url_hash
                        } else {
                            return false
                        }
                    }
                    try {
                        var ao = 0;
                        if (am.playPosition != -1) {
                            ao = am.playPosition
                        } else {
                            ao = G_PLAYER_INSTANCE.getPlayPosition();
                            ao = Math.ceil(ao)
                        }
                        if (!ao || ao < 0) {
                            ao = 0
                        }
                        al = al + "_" + ao
                    } catch(an) {
                        return false
                    }
                    var ak = 0;
                    if (am.type == "bt") {
                        al = al + "_1";
                        ak = am.curUrl.substr(parseInt(am.curUrl.lastIndexOf("/")) + 1, am.curUrl.length)
                    } else {
                        al = al + "_0"
                    }
                    try {
                        K(G + "req_report_play_pos?userid=" + am.user.u + "&report_data=" + al + "_" + ak + "&t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEreportPosBack", 
                        function(e) {
                            return false
                        })
                    } catch(an) {}
                }
            },
            initEvent: function() {
                var e = this;
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onGetFormats", 
                function(al, ak, am, an) {});
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onSetFormats", 
                function(al, ak, am, ap, an, ao) {
                    e.setFormats(am, ap, an, ao)
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onErrorStat", 
                function(al, ak, am) {
                    if (e.kkvaUsed) {
                        try {
                            e.close();
                            G_PLAYER_INSTANCE.setNoticeMsg("迅雷播放加速服务已经退出，您将无法继续观看视频,请刷新页面重试", 5000)
                        } catch(an) {}
                        e.kkvaUsed = false
                    }
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onErrorExit", 
                function(al, ak, am, an) {
                    e.stat({
                        f: "playerror",
                        e: am,
                        gcid: e.$PU("g", e.curDlUrl)
                    })
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onplaying", 
                function() {
                    if (e.kkvaValid) {
                        e.kkvaUsed = true;
                        try {
                            G_PLAYER_INSTANCE.setNoticeMsg("<a href=\"javascript:XL_CLOUD_FX_INSTANCE.windowOpenInPlayer('http://dl.xunlei.com/xmp.html')\">迅雷播放加速服务中...</a>", 30)
                        } catch(ak) {}
                        e.kkvaValid = false
                    }
                    e.stats_buff()
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onStop", 
                function() {
                    var ak = G_PLAYER_INSTANCE.getPlayPosition();
                    ak = Math.ceil(ak);
                    e.playPosition = ak
                })
            },
            initPlayerEvent: function() {
                if (c) {
                    return true
                }
                var e = this;
                G_PLAYER_INIT.attachEvent(G_PLAYER_INIT, "onLoadFlashError", 
                function() {
                    e.error("播放器加载异常，建议您关闭<br/>耗带宽的软件后重试，或联系您的网络运营商。");
                    e.stat({
                        f: "loadflasherror",
                        ua: window.navigator.userAgent
                    })
                });
                G_PLAYER_INIT.attachEvent(G_PLAYER_INIT, "onFlashError", 
                function() {
                    e.error('检测到您没有安装Flash插件，您可以点这里 <a style=\'color:#1874CA;text-decoration: none;\' href="http://get.adobe.com/cn/flashplayer/" target="_blank">安装插件</a>');
                    e.stat({
                        f: "noflash"
                    })
                })
            },
            stat: function(ao) {
                var al = this;
                var ao = ao || {};
                var an = [];
                ao.p = "XCVP";
                if (typeof ao.u == "undefined") {
                    ao.u = al.user.u || 0
                }
                if (typeof ao.v == "undefined") {
                    ao.v = al.user.v || 0
                }
                if (typeof ao.from == "undefined") {
                    ao.from = y || "XCVP"
                }
                if (typeof ao.d == "undefined") {
                    ao.d = L
                }
                for (var ak in ao) {
                    an.push(ak + "=" + encodeURIComponent(ao[ak]))
                }
                try {
                    setTimeout(function() {
                        var e = new Image(0, 0);
                        e.src = G + "stat/s.gif?" + an.join("&")
                    },
                    5)
                } catch(am) {}
            },
            stats_buff_flag: false,
            stats_buff: function() {
                if (document.location.host == ips[0] || document.location.host == ips[2]) {
                    this.uVipinfo()
                }
            },
            query: function(ak, e, at, ap, au, am) {
                var an = this;
                an.getBtFileLastPos();
                var ar,
                aq;
                if (e) {
                    aq = "url=" + encodeURIComponent(ak) + "&video_name=" + encodeURIComponent(e) + "&platform=" + (c ? "1": "0") + "&userid=" + an.user.u + "&vip=" + an.user.v + "&sessionid=" + an.user.s
                } else {
                    aq = "url=" + encodeURIComponent(ak) + "&platform=" + (c ? "1": "0") + "&userid=" + an.user.u + "&vip=" + an.user.v + "&sessionid=" + an.user.s
                }
                if (at && ap && au) {
                    aq = aq + "&gcid=" + at + "&cid=" + ap + "&filesize=" + au
                }
                ar = "http://127.0.0.1:1218/chydbreq_get_method_vod?" + aq;
                if (isClientVodScene) {
                    d.enableTopBar = false;
                    d.enableOpenWindow = false;
                    d.enableFileList = false;
                    if (! (at && ap && au) && at) {
                        aq = aq + "&gcid=" + at
                    }
                    ar = G + "req_try_vod?" + aq + "&peerid=" + an.$PU("peerid") + "&playallow=" + an.$PU("playallow")
                }
                ar = ar + "&cache=" + new Date().getTime() + "&from=" + y;
                K(ar, "XL_CLOUD_FX_INSTANCEqueryBack", 
                function(aw) {
                    if (aw.resp.vod_permit && typeof(aw.resp.vod_permit.ret) != "undefined") {
                        an.userType = 1
                    } else {
                        an.userType = 1
                    }
                    clearTimeout(al);
                    ao = false;
                    var av = setTimeout(function() {
                        if (am) {
                            an.queryOtherBack(aw.resp)
                        } else {
                            an.queryBack(aw.resp)
                        }
                        clearTimeout(av)
                    },
                    25)
                });
                var ao = true;
                var al = setTimeout(function() {
                    if (am) {
                        G_PLAYER_INSTANCE.playOtherFail(false)
                    } else {
                        if (ao) {
                            an.error("服务器正忙，请稍后再试")
                        }
                    }
                    clearTimeout(al)
                },
                D)
            },
            genErrorMsg: function(at, av) {
                var ar = this;
                var aq = "";
                var ap = "";
                var ak = ar.isXlpan || ar.isThunderBox;
                var ay = ar.$PU("list") == "yincang" ? ("#list=" + ar.$PU("list") + "&p=" + ar.$PU("p")) : "#list=recent";
                var al = "<a href='http://vod.xunlei.com/list.html" + ay + "' target='_blank' style='color:#1874CA;'>查看进度</a>";
                if (ar.platform == "client") {
                    al = "<a href='http://vod.xunlei.com/client/clist.html" + ay + "' target='_self' style='color:#1874CA;'>查看进度</a>"
                }
                var ao = "<a href=\"javascript:XL_CLOUD_FX_INSTANCE.windowOpenInPlayer('http://helpbbs.xunlei.com/read.php?tid=578009')\" style='color:#1874CA;'>反馈问题</a>";
                var am = {
                    illegalUrl: "该视频下载链接有误，无法播放",
                    notVideo: "该下载链接不含视频,无法播放",
                    leftTime: "该资源转码还需大约",
                    unkonwTime4Xlpan: "该资源转码需要较长时间，" + ao,
                    unkonwTime4Player: "该资源转码需要较长时间",
                    unkonwTime: "该资源转码需要较长时间，" + al,
                    downloading4Xlpan: "该资源云端下载与转码需要较长时间，" + ao,
                    downloading4Player: "该资源云端下载与转码需要较长时间",
                    downloading: "该资源云端下载与转码需要较长时间，" + al,
                    transFail: "该文件转码失败，请<span style='color:#1874CA;cursor:pointer;' onclick='top.document.location.reload()'>重试</span>",
                    serverError: "服务器正忙，请稍后再试",
                    sessionidExpired: "检测到您未登录或登录异常，请重新登录后从列表页点播",
                    IPTooMuchUsed: "您的帐号因登录IP过多已被限制为不能播放，请于1天后重试，建议您尽快修改密码",
                    noPermit: "点播权限存在问题"
                };
                if (at.ret == 6) {
                    aq = am.illegalUrl
                } else {
                    if (at.ret == 8) {
                        aq = am.notVideo
                    } else {
                        if (at.ret == 11) {
                            var aw = 1;
                            if (aw == 3) {
                                aq = am.IPTooMuchUsed
                            } else {
                                if (aw == 4 || aw == 5) {
                                    aq = am.sessionidExpired
                                } else {
                                    if (aw != 0 && aw != 1) {
                                        aq = am.noPermit
                                    } else {
                                        aq = am.serverError
                                    }
                                }
                            }
                        } else {
                            if (at.ret == 14 || at.ret == 15) {
                                aq = 15
                            } else {
                                if (typeof at.status != "undefined" && at.status == 2 && at.trans_wait) {
                                    if (at.trans_wait > 0 && at.trans_wait < 60) {
                                        ap = at.trans_wait + "秒"
                                    } else {
                                        if (at.trans_wait == -1) {
                                            if (ak) {
                                                return am.unkonwTime4Xlpan
                                            } else {
                                                if (av) {
                                                    return am.unkonwTime4Player
                                                } else {
                                                    return am.unkonwTime
                                                }
                                            }
                                        } else {
                                            if (at.trans_wait == -2) {
                                                if (ak) {
                                                    return am.transFail + "，还不能解决" + ao
                                                } else {
                                                    return am.transFail
                                                }
                                            } else {
                                                var e = parseInt(at.trans_wait / 60);
                                                var ax = 0;
                                                var an = e;
                                                var au = 0;
                                                if (e >= 60) {
                                                    ax = parseInt(e / 60);
                                                    an = e - ax * 60;
                                                    if (ax >= 24) {
                                                        au = parseInt(ax / 24);
                                                        ax = ax - au * 24
                                                    }
                                                }
                                                if (au) {
                                                    ap += au + "天"
                                                }
                                                if (ax) {
                                                    ap += ax + "小时"
                                                }
                                                if (an) {
                                                    ap += an + "分钟"
                                                }
                                            }
                                        }
                                    }
                                    if (ak) {
                                        aq = am.leftTime + ap + "," + ao
                                    } else {
                                        if (av) {
                                            aq = am.leftTime + ap
                                        } else {
                                            aq = am.leftTime + ap + "," + al
                                        }
                                    }
                                } else {
                                    if (typeof at.status != "undefined" && at.status == 1) {
                                        if (ak) {
                                            aq = am.downloading4Xlpan
                                        } else {
                                            if (av) {
                                                aq = am.downloading4Player
                                            } else {
                                                aq = am.downloading
                                            }
                                        }
                                    } else {
                                        aq = am.serverError
                                    }
                                }
                            }
                        }
                    }
                }
                return aq
            },
            queryBack: function(au) {
                var ar = this;
                ar.curPlay = au;
                ar.initPlayerEvent();
                var am = ar.getPlatForm();
                var ap = "platform=" + am;
                var ao = function() {
                    w.attachEvent(w, "onload", 
                    function(ax, e) {
                        if (a) {
                            G_PLAYER_INSTANCE.showDebug()
                        }
                        ar.initEvent();
                        G_PLAYER_INSTANCE.playOtherFail(false, ar.genErrorMsg(au, 1));
                        var ay = {
                            description: "请选择字幕文件(*.srt、*.ass)",
                            extension: "*.srt;*.ass",
                            limitSize: 6 * 1024 * 1024,
                            uploadURL: aa + "interface/upload_file/?cid=" + r,
                            timeOut: "30"
                        };
                        G_PLAYER_INSTANCE.setCaptionParam(ay);
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
                        ar.setFeeParam(0);
                        ar.setShareParam()
                    });
                    var aw = U.getAttribute("id");
                    w.printObject(aw, false, "100%", "100%", "", ap);
                    try {
                        window[V].call()
                    } catch(av) {}
                };
                if (typeof au.status == "undefined" || au.status != 0) {
                    try {
                        if (isClientVodScene && au.ret == 0) {
                            var al = "";
                            al = I;
                            if (ar.type == "bt") {
                                al = R
                            }
                            ar.stat({
                                f: "trialPlayAtOnceFail",
                                id: al,
                                status: au.status,
                                transWait: au.trans_wait
                            })
                        }
                    } catch(at) {}
                    if (isClientVodScene && (au.ret == 14 || au.ret == 15)) {
                        ao()
                    } else {
                        if (au.ret == 11) {
                            ar.error(ar.genErrorMsg(au))
                        } else {
                            if (c || ar.type == "url" || ar.fileList == null || ar.fileList.subfile_list.length <= 1) {
                                ar.error(ar.genErrorMsg(au))
                            } else {
                                ao()
                            }
                        }
                    }
                } else {
                    if (ar.type == "url") {
                        ar.getLastPos();
                        ar.fileList = {
                            userid: ar.user.u,
                            info_hash: "",
                            subfile_list: [{
                                name: ar.curPlay.src_info.file_name,
                                index: -1,
                                url_hash: ar.curPlay.url_hash
                            }]
                        }
                    }
                    if (ar.originalPlay == null) {
                        ar.originalPlay = au
                    }
                    ar.cacheData = ar.cacheReqData(ar.cacheData, au, ar.curPlay.url_hash);
                    var an = au.vodinfo_list;
                    ar.vod_info = an;
                    w.attachEvent(w, "onload", 
                    function(av, e) {
                        if (a) {
                            G_PLAYER_INSTANCE.showDebug()
                        }
                        if (!p) {
                            p = G_PLAYER_INSTANCE.getDefaultFormat() || "p"
                        }
                        ar.initEvent();
                        var aw = an.length;
                        if ((aw == 1 && (p == "g" || p == "c"))) {
                            p = "p"
                        } else {
                            if ((aw == 2 && p == "c")) {
                                p = "g"
                            }
                        }
                        if (p == "g") {
                            var ax = an[1].vod_url
                        } else {
                            if (p == "c") {
                                var ax = an[2].vod_url
                            } else {
                                var ax = an[0].vod_url
                            }
                        }
                        if (!ar.curName) {
                            ar.curName = h(ar.curPlay.src_info.file_name)
                        }
                        ar.startPlay(ax, p, ar.lastPos);
                        ar.getFormats();
                        G_PLAYER_INSTANCE.playOtherFail(true);
                        ar.getCaption(ar.curPlay.src_info.gcid, ar.curPlay.src_info.cid);
                        ar.setShareParam();
                        ar.curName = h(ar.curPlay.src_info.file_name)
                    });
                    var ak = U.getAttribute("id");
                    w.printObject(ak, false, "100%", "100%", "", ap);
                    try {
                        window[V].call()
                    } catch(at) {}
                }
                if (ar.curPlay.src_info) {
                    var aq = ar.curPlay.src_info.gcid
                } else {
                    var aq = ""
                }
                try {
                    ar.stat({
                        f: "svrresp",
                        ret: ar.curPlay.ret,
                        pt: ar.curPlay.status,
                        gcid: aq
                    })
                } catch(at) {}
            },
            cacheReqData: function(ak, e, am) {
                var ak = ak || [];
                var ao = ak.length;
                if (ao > 0 && ao < 6) {
                    var an = [];
                    for (var al = 0; al < ao; al++) {
                        if (ak[al].url_hash && ak[al].url_hash != am) {
                            an.push(ak[al])
                        }
                    }
                    ak = an
                }
                ak.push(e);
                if (ak.length == 5) {
                    ak.shift()
                }
                return ak
            },
            startPlay: function(ak, ao, ar, aq) {
                var am = this;
                ar = ar || 0;
                am.lastFormat = ao;
                am.curDlUrl = ak;
                if (c) {
                    G_PLAYER_INSTANCE.setUrl(ak, ar);
                    this.getFormats();
                    return true
                } else {
                    var ap = {};
                    ap.totalByte = 1;
                    ap.totalTime = parseInt(this.curPlay.duration / 1000000);
                    var al = ak;
                    ap.totalByte = parseInt(this.$PU("s", al));
                    ap.sliceType = 0;
                    if (ar && ar > 0) {
                        ap.start = ar
                    }
                    G_PLAYER_INSTANCE.stop();
                    try {
                        G_PLAYER_INSTANCE.close()
                    } catch(an) {}
                    G_PLAYER_INSTANCE.setToolBarEnable(d);
                    am.setFeeParam(1);
                    ap.format = ao;
                    if (A) {
                        this.enableKKVA()
                    }
                    G_PLAYER_INSTANCE.flashopen(al, true, false, ag, ap, 0)
                }
            },
            playOther: function(ar, am, ao, e, av, au) {
                var at = this;
                if (!at.validUrl(am)) {
                    G_PLAYER_INSTANCE.playOtherFail(false, "该视频下载链接有误，无法播放");
                    at.setFeeParam(0);
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
                at.reportPlayPos();
                am = b(am);
                R = h(am);
                at.type = "url";
                var an = at.genBtUrl(R);
                if (an) {
                    at.type = "bt";
                    R = an
                }
                ag = true;
                p = G_PLAYER_INSTANCE.getDefaultFormat() || "p";
                S = 0;
                at.captionList = [];
                at.isFromList = false;
                at.curUrl = am;
                if (!ar) {
                    at.isFromList = true;
                    at.curName = h(e);
                    e = "";
                    if (an == at.genBtUrl(j, "", 1)) {
                        e = P
                    }
                    var al = false;
                    if (at.cacheData) {
                        var aq = null;
                        var aw = at.cacheData.length;
                        for (var ap = 0; ap < aw; ap++) {
                            if (ao && at.cacheData[ap].url_hash == ao && at.cacheData[ap].status == 0) {
                                al = true;
                                aq = at.cacheData[ap];
                                break
                            }
                        }
                    }
                    at.getLastPos()
                } else {
                    at.fileList = null
                }
                if (al) {
                    var ak = setTimeout(function() {
                        at.queryOtherBack(aq);
                        clearTimeout(ak)
                    },
                    30)
                } else {
                    at.query(b(am), e, av, au, "", 1)
                }
            },
            queryOtherBack: function(an) {
                var am = this;
                am.curPlay = an;
                if (an.status != 0) {
                    G_PLAYER_INSTANCE.playOtherFail(false, am.genErrorMsg(an, 1));
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
                    if (!am.isFromList) {
                        if (am.curPlay.src_info) {
                            am.curName = h(am.curPlay.src_info.file_name)
                        } else {
                            am.curName = R
                        }
                    }
                    am.setFeeParam(0)
                } else {
                    if (am.type == "url") {
                        am.getLastPos()
                    }
                    am.cacheData = am.cacheReqData(am.cacheData, an, am.curPlay.url_hash);
                    var ap = an.vodinfo_list;
                    am.vod_info = ap;
                    if (!am.isFromList) {
                        am.curName = h(am.curPlay.src_info.file_name)
                    }
                    var ak = setTimeout(function() {
                        var e = ap.length;
                        if ((e == 1 && (p == "g" || p == "c"))) {
                            p = "p"
                        } else {
                            if ((e == 2 && p == "c")) {
                                p = "g"
                            }
                        }
                        if (p == "g") {
                            var aq = ap[1].vod_url
                        } else {
                            if (p == "c") {
                                var aq = ap[2].vod_url
                            } else {
                                var aq = ap[0].vod_url
                            }
                        }
                        am.startPlay(aq, p, am.lastPos);
                        clearTimeout(ak);
                        am.getFormats()
                    },
                    50);
                    G_PLAYER_INSTANCE.playOtherFail(true);
                    am.getCaption(an.src_info.gcid, an.src_info.cid);
                    am.setShareParam()
                }
                try {
                    window[ah].call()
                } catch(ao) {}
                if (an.src_info) {
                    var al = an.src_info.gcid
                } else {
                    var al = ""
                }
                try {
                    am.stat({
                        f: "svrresp",
                        ret: an.ret,
                        pt: an.status,
                        gcid: al
                    })
                } catch(ao) {}
            },
            getPlatForm: function() {
                var ak = "webpage";
                try {
                    ak = (window.external.getVodClientVer()) ? "client": "webpage"
                } catch(al) {}
                return ak
            },
            setFeeParam: function(e) {
                var am = this;
                var al = y;
                if (am.isXlpan || am.isThunderBox) {
                    al = "xlpan"
                }
                if (e) {
                    var an = am.curPlay.src_info;
                    var ak = an.file_size || "";
                    G_PLAYER_INSTANCE.setFeeParam({
                        sessionid: am.user.s,
                        userid: am.user.u,
                        userType: am.userType,
                        isvip: 6,
                        gcid: an.gcid,
                        cid: "0000000000000000000000000000000000000000",
                        name: am.curName,
                        url_hash: am.curPlay.url_hash,
                        from: al,
                        url: h(am.curUrl),
                        index: (am.curUrl.substr(parseInt(am.curUrl.lastIndexOf("/")) + 1, am.curUrl.length)),
                        ygcid: an.gcid,
                        ycid: an.cid,
                        filesize: ak,
                        info_hash: am.curInfohash
                    })
                } else {
                    G_PLAYER_INSTANCE.setFeeParam({
                        sessionid: am.user.s,
                        userid: am.user.u,
                        userType: am.userType,
                        isvip: 6,
                        gcid: "",
                        cid: "0000000000000000000000000000000000000000",
                        name: "",
                        url_hash: am.curPlay.url_hash,
                        from: al,
                        url: h(am.curUrl),
                        index: (am.curUrl.substr(parseInt(am.curUrl.lastIndexOf("/")) + 1, am.curUrl.length)),
                        ygcid: "",
                        ycid: "",
                        filesize: "",
                        info_hash: am.curInfohash
                    })
                }
            },
            $PU: function(al, ak) {
                ak = ad(ak) ? location.href: ak;
                var e = ak.match(new RegExp("[#|?]([^#]*)[#|?]?"));
                ak = "&" + (X(e) ? "": e[1]);
                e = ak.match(new RegExp("&" + al + "=", "i"));
                return X(e) ? undefined: ak.substr(e.index + 1).split("&")[0].split("=")[1]
            },
            getFormats: function(ak) {
                ak = ak || this.lastFormat;
                var e = {
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
                e.g.enable = typeof(this.vod_info[1]) != "undefined";
                e.c.enable = typeof(this.vod_info[2]) != "undefined";
                e.p.enable = true;
                e[ak].checked = true;
                G_PLAYER_INSTANCE.setFormats(e)
            },
            setFormats: function(e, an, ak, al) {
                var am = G_PLAYER_INSTANCE.getPlayPosition();
                var e = this;
                ag = true;
                if (ak == "p") {
                    e.close();
                    G_PLAYER_INSTANCE.setIsChangeQuality(true);
                    this.startPlay(this.vod_info[0].vod_url, "p", am, 1);
                    e.getFormats()
                } else {
                    if (ak == "g") {
                        e.close();
                        G_PLAYER_INSTANCE.setIsChangeQuality(true);
                        this.startPlay(this.vod_info[1].vod_url, "g", am, 1);
                        e.getFormats()
                    } else {
                        if (ak == "c") {
                            e.close();
                            G_PLAYER_INSTANCE.setIsChangeQuality(true);
                            this.startPlay(this.vod_info[2].vod_url, "c", am, 1);
                            e.getFormats()
                        }
                    }
                }
            },
            error: function(al) {
                U.innerHTML = "<img src='" + ai + "img/play_bg.jpg' width='100%' height='100%' /><div style='position:absolute;left:0;top:46%;text-align:center;font-size:14px;color:#FFF;margin: 0;width:100%;height:22px;'>" + al + "</div>";
                try {
                    window[t].call()
                } catch(ak) {}
            },
            close: function() {
                try {
                    G_PLAYER_INSTANCE.close();
                    G_PLAYER_INSTANCE.closeNetStream()
                } catch(ak) {}
            },
            getCaption: function(al, am) {
                if (c) {
                    return true
                }
                var e = this;
                var ak = {
                    description: "请选择字幕文件(*.srt、*.ass)",
                    extension: "*.srt;*.ass",
                    limitSize: 5 * 1024 * 1024,
                    uploadURL: aa + "interface/upload_file/?cid=" + am,
                    timeOut: "30"
                };
                G_PLAYER_INSTANCE.setCaptionParam(ak);
                l(G + "subtitle/list/gcid/" + al + "/cid/" + am, "XL_CLOUD_FX_INSTANCEqueryCaptionBack", 
                function(an) {
                    e.queryCaptionBack(an, am)
                })
            },
            queryCaptionBack: function(e, at) {
                var ar = e.sublist.length;
                if (e.sublist != undefined && e.sublist.length > 0) {
                    var aq = e.sublist;
                    for (var ap = 0; ap < ar; ap++) {
                        if (this.captionList.length > 3) {
                            break
                        }
                        var aw = aq[ap];
                        if (aw.sname == undefined) {
                            continue
                        }
                        var au = aw.sname;
                        var av = au.length;
                        if (av > 0) {
                            for (var ao = 0; ao < av; ao++) {
                                var ak = h(au[ao]);
                                var am = ak.lastIndexOf(".");
                                var an = ak.length;
                                var al = ak.substring(parseInt(am) + 1, an).toLowerCase();
                                if (al == "ass" || al == "srt") {
                                    this.captionList.push({
                                        autoload: aw.autoload,
                                        language: aw.language[0] || "",
                                        scid: aw.scid,
                                        sname: ak,
                                        surl: "http://i.vod.xunlei.com/subtitle/data/scid/" + aw.scid + ".srt",
                                        svote: aw.svote || 0
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
            addCaptionList: function(am) {
                var e = am.length;
                if (!am || typeof(am) != "object" || e < 1) {
                    return false
                }
                var al = 1;
                if (this.captionList.length == 0) {
                    al = 3
                } else {
                    if (this.captionList.length == 1) {
                        al = 2
                    }
                }
                for (var ak = 0; ak < e; ak++) {
                    if (ak == al) {
                        break
                    }
                    this.captionList.push(am[ak])
                }
                if (this.captionList.length > 3) {
                    this.captionList.shift()
                }
                G_PLAYER_INSTANCE.setCaptionList(this.captionList)
            },
            getBtFileLastPos: function() {
                var ak = this;
                if (ak.type == "url" || ak.curInfohash.length != 40) {
                    return false
                }
                if (ak.fileList == null) {
                    var e = G + "req_subBT/info_hash/" + ak.curInfohash + "/req_num/2/req_offset/0?cache=" + new Date().getTime();
                    K(e, "XL_CLOUD_FX_INSTANCEqueryFileListBack", 
                    function(al) {
                        ak.fileList = al.resp;
                        if (ak.fileList.ret == 0) {
                            ak.getLastPos()
                        }
                    })
                }
            },
            setShareParam: function() {
                var e = "我正在观看" + h(this.curName);
                G_PLAYER_INSTANCE.setShareParam(e, h(R))
            },
            loginNotice: function() {
                window.open("http://vod.xunlei.com/home.html?xcvp=login");
                this.error("继续<a style='color:#1874CA' href='javascript:;' onclick='XL_CLOUD_FX_INSTANCE.continuePlay();return false;'>播放</a>")
            },
            continuePlay: function() {
                var e = this;
                e.error("请稍候，精彩即将开启...");
                e.uCheck()
            },
            getLastPos: function() {
                var am = this;
                if (S) {
                    am.lastPos = S;
                    return true
                }
                am.lastPos = 0;
                if (am.type == "bt") {
                    var ak = am.curUrl.substr(am.curUrl.lastIndexOf("/") + 1, am.curUrl.length);
                    var al = am.fileList.main_task_url_hash
                } else {
                    var al = am.curPlay.url_hash
                }
                var an = null,
                e = true;
                K(G + "req_last_play_pos?userid=" + am.user.u + "&query_list=" + al + "_" + ((am.type == "bt") ? 1: 0) + "&t=" + new Date().getTime(), "XL_CLOUD_FX_INSTANCEqueryLastPosBack", 
                function(aq) {
                    clearTimeout(an);
                    e = false;
                    if (aq.resp && aq.resp.ret == 0) {
                        var ap = aq.resp.res_list;
                        if (ap && ap[0]) {
                            if (ap[0].is_bt_play == 0) {
                                am.lastPos = ap[0].last_play_pos
                            } else {
                                if (ap[0].sub_list && ap[0].sub_list.length > 0) {
                                    var at = ap[0].sub_list;
                                    var ao = ap[0].sub_list.length;
                                    for (var ar = 0; ar < ao; ar++) {
                                        if (at[ar].idx == ak) {
                                            am.lastPos = at[ar].last_play_pos;
                                            break
                                        }
                                    }
                                }
                            }
                        }
                    }
                });
                setTimeout(function() {
                    clearTimeout(an);
                    e = false;
                    if (e) {
                        am.lastPos = 0
                    }
                },
                1000)
            },
            genBtUrl: function(al, am, ak) {
                if (!al && !am) {
                    return false
                }
                var e = "";
                if (am && am.length == 40) {
                    e = am
                } else {
                    if (h(al).substr(0, 5) == "bt://") {
                        e = h(al).substring(5, h(al).lastIndexOf("/"))
                    }
                }
                if (e) {
                    if (!ak) {
                        this.curInfohash = e
                    }
                    return "http://bt.box.n0808.com/" + e.substr(0, 2) + "/" + e.substr(38, 40) + "/" + e + ".torrent"
                } else {
                    return false
                }
            },
            validUrl: function(e) {
                if (e == "" || e == "none" || e == "undefined" || (document.location.protocol + "//" + document.location.host + "/") == e) {
                    return false
                }
                var ak = e.toLowerCase();
                if (((ak.indexOf("http") == -1) && (ak.indexOf("https") == -1) && (ak.indexOf("ftp") == -1) && (ak.indexOf("thunder") == -1) && (ak.indexOf("mms") == -1) && (ak.indexOf("qqdl") == -1) && (ak.indexOf("rtsp") == -1) && (ak.indexOf("magnet") == -1) && (ak.indexOf("flashget") == -1) && (ak.indexOf("ed2k") == -1) && (ak.indexOf("bt") == -1) && (ak.indexOf("xlpan") == -1)) || ak == "") {
                    return false
                } else {
                    return true
                }
            },
            windowOpenInPlayer: function(al) {
                var ap = document;
                _body = document.getElementsByTagName("body")[0];
                var ao = null;
                var ak = ap.getElementById("dapctrl");
                if (ak) {
                    try {
                        ap.getElementsByTagName("body")[0].removeChild(ak)
                    } catch(an) {}
                }
                if (!u && !ap.getElementById("dapctrl")) {
                    var am = ap.createElement("object");
                    am.setAttribute("type", "application/x-thunder-dapctrl");
                    am.setAttribute("id", "dapctrl");
                    am.setAttribute("width", "0");
                    am.setAttribute("height", "0");
                    am.style.visibility = "hidden";
                    _body.appendChild(am)
                } else {
                    try {
                        ao = new ActiveXObject("DapCtrl.DapCtrl")
                    } catch(an) {}
                }
                if (ao) {
                    ao.Put("iADShowMode", 1);
                    ao.Put("sOpenAdUrl", al);
                    ao = null
                } else {
                    window.open(al)
                }
            },
            openMini: function(ak, al) {
                try {
                    this.reportPlayPos()
                } catch(am) {}
                window.open("http://" + goip + "/mini.html?" + ak, "miniplayer", "top=10,left=10,height=446,width=684,toolbar=no,menubar=no,resizable=yes,scrollbars=no,location=no,status=no,fullscreen=no")
            },
            enableKKVA: function() {
                var am = this;
                am.kkvaValid = false;
                if (c || (!am.isThunderBox && !u)) {
                    return true
                }
                var al = document.getElementsByTagName("body")[0];
                var aq = document.getElementById("vasensor");
                try {
                    al.removeChild(aq)
                } catch(an) {}
                var ao = document.createElement("object");
                ao.setAttribute("id", "vasensor");
                ao.setAttribute("width", "0");
                ao.setAttribute("height", "0");
                ao.style.visibility = "hidden";
                if (!u) {
                    ao.setAttribute("type", "application/x-thunder-kkva")
                } else {
                    ao.setAttribute("classid", "CLSID:96CD6DA7-17F2-4576-82B0-BE4526FB7D6B")
                }
                document.getElementsByTagName("body")[0].appendChild(ao);
                var at = 0;
                if (XL_CLOUD_FX_INSTANCE.lastFormat == "c") {
                    at = 2
                } else {
                    if (XL_CLOUD_FX_INSTANCE.lastFormat == "g") {
                        at = 1
                    }
                }
                var au = XL_CLOUD_FX_INSTANCE.vod_info[at]["vod_url"];
                var ap = this.$PU("g", au);
                if (am.isThunderBox) {
                    try {
                        var ar = window.external.GetClientVersion()
                    } catch(an) {
                        var ar = "1.6"
                    }
                    if (ar < "1.6") {} else {
                        try {
                            if (ao.Get("iVersion") != 100007) {
                                ao.EnableVA("yvod", ap, au, 0);
                                am.kkvaValid = true;
                                ao.Put("iXMPIconTray", 0);
                                am.stat({
                                    f: "kkva",
                                    g: ap,
                                    client: "thunderBox"
                                })
                            }
                        } catch(an) {}
                    }
                } else {
                    try {
                        var ak = document.getElementById("myPlugin");
                        if (!ak) {
                            var ak = document.createElement("object");
                            ak.setAttribute("id", "myPlugin");
                            ak.setAttribute("width", "0");
                            ak.setAttribute("height", "0");
                            ak.style.visibility = "hidden";
                            if (u) {
                                ak.setAttribute("classid", "clsid:BD1E9B61-F3B2-4A19-AB69-68E77CA81C42")
                            } else {
                                ak.setAttribute("type", "application/x-thunderbox-upload")
                            }
                            document.getElementsByTagName("body")[0].appendChild(ak)
                        }
                        if (ak.FindThunderbox() && ak.GetThunderboxVersion() >= "1.6" && ao.Get("iVersion") != 100007) {
                            ao.EnableVA("yvod", ap, au, 0);
                            am.kkvaValid = true;
                            ao.Put("iXMPIconTray", 0);
                            am.stat({
                                f: "kkva",
                                g: ap,
                                client: "web"
                            })
                        } else {}
                    } catch(an) {}
                }
                return true
            }
        };
        K(aa + "fx?t=" + new Date().getTime(), "", 
        function(e) {
            return false
        });
        var o = c ? (ai + "fx/js/ipad.js?" + af) : ("/svn/vod/f.h" + af);
        var T = new Q(o);
        T.buildScriptTag();
        T.addScriptTag()
    },
    1)
})();