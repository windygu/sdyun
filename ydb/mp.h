(function () {
    setTimeout(function () {
        function a(a) {
            return document.getElementById(a)
        }
        function b(a) {
            return j[a]
        }
        function c(a) {
            return a.replace(/(^\s*)|(\s*$)/g, "")
        }
        function d(a) {
            var b = "";
            try {
                b = decodeURIComponent(decodeURIComponent(a))
            } catch (c) {
                try {
                    b = decodeURIComponent(a)
                } catch (c) {
                    b = a
                }
            }
            return b
        }
        function e(a) {
            return encodeURIComponent(a)
        }
        function f(a) {
            this.fullUrl = a;
            this.noCacheIE = "&noCacheIE=" + (new Date).getTime();
            this.headLoc = document.getElementsByTagName("head").item(0);
            this.scriptId = "JscriptId" + f.scriptCounter++
        }
        function g(a, b, c) {
            var d = a;
            if (b) {
                window[b] = c
            }
            if (d.indexOf("?") != -1) {
                d += "&jsonp=" + b
            } else {
                d += "?jsonp=" + b
            }
            var e = new f(d);
            e.buildScriptTag();
            e.addScriptTag()
        }
        function h(a, b, c) {
            var d = a;
            if (b) {
                window[b] = c
            }
            d += "&callback=" + b;
            var e = new f(d);
            e.buildScriptTag();
            e.addScriptTag();
            return this
        }
        function i(a, b) {
            return a.getAttribute(b)
        }
        var j = {
            isvip: 1,
            userid: 229134597,
            sessionid: null,
            mini: "goovp.com",
            miniuri: "/vod/mini",
            playerconfig: {
                enableShare: true,
                enableFileList: true,
                enableDownload: true,
                enableSet: true,
                enableCaption: true,
                enableOpenWindow: true,
                enableTopBar: true,
                enableFeedback: false
            }
        };
        var k = function (a) {
            return typeof a == "undefined"
        };
        var l = function (a) {
            return typeof a == "object" && !a
        };
        var m = "XL_CLOUD_VOD_PLAYER";
        var n = window.navigator.userAgent.toLowerCase().indexOf("ipad") > 0 || window.navigator.userAgent.toLowerCase().indexOf("iphone") > 0 ? 1 : 0;
        var o = navigator.appVersion.indexOf("MSIE") != -1 ? true : false;
        var p = navigator.userAgent.toUpperCase().indexOf("Firefox") ? true : false;
        var q = "1.22";
        var r = 3e4;
        var s = "http://vod.xunlei.com/";
        var t = "http://dynamic.vod.lixian.xunlei.com/";
        var u = "http://i.vod.xunlei.com/";
        var v = (new Date).getTime();
        var w = a(m);
        if (!w) {
            return false
        }
        f.scriptCounter = 1;
        f.prototype.buildScriptTag = function () {
            this.scriptObj = document.createElement("script");
            this.scriptObj.setAttribute("type", "text/javascript");
            this.scriptObj.setAttribute("src", this.fullUrl)
        };
        f.prototype.removeScriptTag = function () {
            this.headLoc.removeChild(this.scriptObj)
        };
        f.prototype.addScriptTag = function () {
            this.headLoc.appendChild(this.scriptObj)
        };
        var x = w;
        var y = x.getAttribute("from");
        y = y || "unkonwn";
        var z = x.getElementsByTagName("a");
        if (z.length == 0) {
            z = x.getElementsByTagName("span");
            if (z.length == 0) {
                return
            }
            var A = z[0];
            var B = c(i(A, "url"))
        } else {
            var A = z[0];
            var B = c(A.getAttribute("href"))
        }
        var C = i(A, "filesize");
        var D = i(A, "gcid");
        var E = i(A, "cid");
        var F = i(A, "title");
        var G = i(A, "onsuccess");
        var H = i(A, "playother");
        var I = i(A, "onfail");
        if (!x.style.height) {
            x.style.height = "446px"
        }
        if (!x.style.width) {
            x.style.width = "684px"
        }
        x.style.overflow = "hidden";
        var J = i(A, "share_url");
        J = J ? d(J) : d(B);
        var K = i(A, "autoplay");
        if (!K || K != "true") {
            K = false
        } else {
            K = true
        }
        var L = j.playerconfig;
        var M = i(A, "enable_panel");
        if (M && M == "false") {
            L.enableShare = false
        }
        var N = i(A, "enable_download");
        if (N && N == "false") {
            L.enableDownload = false
        }
        var O = i(A, "enable_caption");
        if (O && O == "false") {
            L.enableCaption = false
        }
        var P = i(A, "enable_filelist");
        if (P && P == "false") {
            L.enableFileList = false
        }
        var Q = i(A, "enable_setting");
        if (Q && Q == "false") {
            L.enableSet = false
        }
        var R = i(A, "enable_openwindow");
        if (R && R == "false") {
            L.enableOpenWindow = false
        }
        var S = i(A, "enable_topbar");
        if (S && S == "false") {
            L.enableTopBar = false
        }
        var T = i(A, "enable_kkva");
        if (T && T == "true") {
            T = true
        } else {
            T = false
        }
        var U = parseInt(i(A, "start")) || 0;
        var V = i(A, "format") || "p";
        var W;
        var X = false,
            Y = /xyz/.test(function () {
                xyz
            }) ? /\b_super\b/ : /.*/;
        var Z = function () {};
        Z.extend = function (a) {
            function b() {
                if (!X && this.init) {
                    this.init.apply(this, arguments)
                }
            }
            var c = this.prototype;
            X = true;
            var d = new this;
            X = false;
            for (var e in a) {
                d[e] = typeof a[e] == "function" && typeof c[e] == "function" && Y.test(a[e]) ? function (a, b) {
                    return function () {
                        var d = this._super;
                        this._super = c[a];
                        var e = b.apply(this, arguments);
                        this._super = d;
                        return e
                    }
                }(e, a[e]) : a[e]
            }
            b.prototype = d;
            b.constructor = b;
            b.extend = arguments.callee;
            return b
        };
        var $;
        window.XL_CLOUD_FX_INSTANCE = {
            Class: Z,
            lastFormat: "p",
            cacheData: [],
            curPlay: null,
            curInfohash: "",
            curDlUrl: "",
            curUrl: d(B),
            curName: d(F),
            originalPlay: null,
            fileList: null,
            captionList: [],
            type: "url",
            user: {
                u: 2,
                v: 6,
                s: ""
            },
            init: function (a) {
                $ = a;
                var b = this;
                if (!b.validUrl(b.curUrl)) {
                    b.error("您的点播url非法，无法播放！");
                    return false
                }
                var c = x.getAttribute("id");
                if (!c) {
                    c = "XL_CLOUD_PLAY_BOX";
                    x.setAttribute("id", c)
                }
                x.style.backgroundColor = "#000";
                b.isVod = true;
                b.isXlpan = /.*(xlpan).*/.exec(document.location.host);
                try {
                    b.isThunderBox = window.external.IsInXLpanClient()
                } catch (d) {
                    b.isThunderBox = false
                }
                var e = b.genBtUrl(b.curUrl);
                if (e) {
                    b.type = "bt";
                    J = e
                }
                b.uCheck();
                setTimeout(function () {
                    b.stat({
                        p: "XCVP",
                        f: "pv"
                    })
                }, 25)
            },
            uVipinfo: function () {},
            uCheck: function () {
                var a = this;
                a.query(a.curUrl, a.curName, D, E, C);
                return true
            },
            reportPlayPos: function () {},
            initEvent: function () {
                var a = this;
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onGetFormats", function (a, b, c, d) {});
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onSetFormats", function (b, c, d, e, f, g) {
                    a.setFormats(d, e, f, g)
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onErrorStat", function (b, c, d) {
                    if (a.kkvaUsed) {
                        try {
                            G_PLAYER_INSTANCE.close();
                            G_PLAYER_INSTANCE.closeNetStream();
                            G_PLAYER_INSTANCE.setNoticeMsg("迅雷播放加速服务已经退出，您将无法继续观看视频,请刷新页面重试", 5e3)
                        } catch (e) {}
                        a.kkvaUsed = false
                    }
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onErrorExit", function (b, c, d, e) {
                    a.stat({
                        f: "playerror",
                        e: d,
                        gcid: a.$PU("g", a.curDlUrl)
                    })
                });
                G_PLAYER_INSTANCE.attachEvent(G_PLAYER_INSTANCE, "onplaying", function () {
                    if (a.kkvaValid) {
                        a.kkvaUsed = true;
                        try {
                            G_PLAYER_INSTANCE.setNoticeMsg("<a href=\"javascript:XL_CLOUD_FX_INSTANCE.windowOpenInPlayer('http://dl.xunlei.com/xmp.html')\">迅雷播放加速服务中...</a>", 30)
                        } catch (b) {}
                        a.kkvaValid = false
                    }
                    a.stats_buff()
                })
            },
            initPlayerEvent: function () {
                if (n) {
                    return true
                }
                var a = this;
                G_PLAYER_INIT.attachEvent(G_PLAYER_INIT, "onLoadFlashError", function () {
                    a.error("播放器加载异常，建议您关闭<br/>耗带宽的软件后重试，或联系您的网络运营商。")
                });
                G_PLAYER_INIT.attachEvent(G_PLAYER_INIT, "onFlashError", function () {
                    a.error('检测到您没有安装Flash插件，您可以点这里 <a style=\'color:#1874CA;text-decoration: none;\' href="http://get.adobe.com/cn/flashplayer/" target="_blank">安装插件</a>')
                })
            },
            stat: function (a) {
                var b = this;
                var a = a || {};
                var c = [];
                a.p = "XCVP";
                if (typeof a.u == "undefined") {
                    a.u = b.user.u || 0
                }
                if (typeof a.v == "undefined") {
                    a.v = b.user.v || 0
                }
                if (typeof a.from == "undefined") {
                    a.from = y || "XCVP"
                }
                if (typeof a.d == "undefined") {
                    a.d = v
                }
                for (var d in a) {
                    c.push(d + "=" + encodeURIComponent(a[d]))
                }
            },
            stats_buff_flag: false,
            stats_buff: function () {
                if (document.location.host == ips[0] || document.location.host == ips[2]) {
                    this.uVipinfo()
                }
            },
            query: function (a, b, c, d, e, f) {
                var h = this;
                h.getBtFileLastPos();
                if (b) {
                    var i = "http://i.vod.xunlei.com/req_try_vod?url=" + encodeURIComponent(a) + "&video_name=" + encodeURIComponent(b) + "&platform=" + (n ? "1" : "0") + "&userid=&vip=&sessionid=&from=xlpan_web"
                } else {
                    var i = "http://i.vod.xunlei.com/req_try_vod?url=" + encodeURIComponent(a) + "&platform=" + (n ? "1" : "0") + "&userid=&vip=&sessionid=&from=xlpan_web"
                }
                if (c && d && e) {
                    i = i + "&gcid=" + c + "&cid=" + d + "&filesize=" + e
                }
                i = i + "&cache=" + (new Date).getTime() + "&from=" + y;
                g(i, "XL_CLOUD_FX_INSTANCEqueryBack", function (a) {
                    clearTimeout(k);
                    j = false;
                    var b = setTimeout(function () {
                        if (f) {
                            h.queryOtherBack(a.resp)
                        } else {
                            h.queryBack(a.resp)
                        }
                        clearTimeout(b)
                    }, 25)
                });
                var j = true;
                var k = setTimeout(function () {
                    if (f) {
                        G_PLAYER_INSTANCE.playOtherFail(false)
                    } else {
                        if (j) {
                            h.error("服务器正忙，请稍后再试")
                        }
                    }
                    clearTimeout(k)
                }, r)
            },
            genErrorMsg: function (a, b) {
                var c = this;
                var d = "";
                var e = "";
                var f = c.isXlpan || c.isThunderBox;
                var g = c.$PU("list") == "yincang" ? "?list=" + c.$PU("list") : "?list=recent";
                var h = "";
                var i = "<a href=\"javascript:XL_CLOUD_FX_INSTANCE.windowOpenInPlayer('http://helpbbs.xunlei.com/read.php?tid=578009')\" style='color:#1874CA;'>反馈问题</a>";
                var j = {
                    illegalUrl: "该视频下载链接有误，无法播放",
                    notVideo: "该下载链接不含视频,无法播放",
                    leftTime: "该资源转码还需大约",
                    unkonwTime4Xlpan: "该资源转码需要较长时间，" + i,
                    unkonwTime4Player: "该资源转码需要较长时间",
                    unkonwTime: "该资源转码需要较长时间，" + h,
                    downloading4Xlpan: "该资源云端下载与转码需要较长时间，" + i,
                    downloading4Player: "该资源云端下载与转码需要较长时间",
                    downloading: "该资源云端下载与转码需要较长时间，" + h,
                    transFail: "该文件转码失败，<span style='color:#1874CA;cursor:pointer;' onclick='top.document.location.reload()'>重试</span>",
                    serverError: "服务器正忙，请稍后再试",
                    serverInfo: '<br/>'
                };
                if (a.ret == 6 || a.ret == 7) {
                    d = j.illegalUrl + j.serverInfo
                } else if (a.ret == 403) {
                    d = a.error_msg + '<br/>'
                } else {
                    if (a.ret == 8) {
                        d = j.notVideo + j.serverInfo
                    } else {
                        if (typeof a.status != "undefined" && a.status == 2 && a.trans_wait) {
                            if (a.trans_wait > 0 && a.trans_wait < 60) {
                                e = a.trans_wait + "秒"
                            } else {
                                if (a.trans_wait == -1) {
                                    if (f) {
                                        return j.unkonwTime4Xlpan
                                    } else {
                                        if (b) {
                                            return j.unkonwTime4Player
                                        } else {
                                            return j.unkonwTime
                                        }
                                    }
                                } else {
                                    if (a.trans_wait == -2) {
                                        if (f) {
                                            return j.transFail + " " + i
                                        } else {
                                            return j.transFail + j.serverInfo
                                        }
                                    } else {
                                        var k = parseInt(a.trans_wait / 60);
                                        var l = 0;
                                        var m = k;
                                        var n = 0;
                                        if (k >= 60) {
                                            l = parseInt(k / 60);
                                            m = k - l * 60;
                                            if (l >= 24) {
                                                n = parseInt(l / 24);
                                                l = l - n * 24
                                            }
                                        }
                                        if (n) {
                                            e += n + "天"
                                        }
                                        if (l) {
                                            e += l + "小时"
                                        }
                                        if (m) {
                                            e += m + "分钟"
                                        }
                                    }
                                }
                            }
                            if (f) {
                                d = j.leftTime + e + "," + i
                            } else {
                                if (b) {
                                    d = j.leftTime + e
                                } else {
                                    d = j.leftTime + e + "," + h
                                }
                            }
                        } else {
                            if (typeof a.status != "undefined" && a.status == 1) {
                                if (f) {
                                    d = j.downloading4Xlpan
                                } else {
                                    if (b) {
                                        d = j.downloading4Player
                                    } else {
                                        d = j.downloading
                                    }
                                }
                            } else {
                                d = j.serverError + j.serverInfo
                            }
                        }
                    }
                }
                return d
            },
            queryBack: function (a) {
                var b = this;
                b.curPlay = a;
                b.initPlayerEvent();
                if (typeof a.status == "undefined" || a.status != 0) {
                    if (n || b.type == "url" || b.fileList == null || b.fileList.subfile_list.length <= 1) {
                        b.error(b.genErrorMsg(a))
                    } else {
                        $.attachEvent($, "onload", function (c, d) {
                            b.initEvent();
                            G_PLAYER_INSTANCE.playOtherFail(false, b.genErrorMsg(a, 1));
                            var e = {
                                description: "请选择字幕文件(*.srt、*.ass)",
                                extension: "*.srt;*.ass",
                                limitSize: 6 * 1024 * 1024,
                                uploadURL: t + "interface/upload_file/?cid=" + E,
                                timeOut: "30"
                            };
                            G_PLAYER_INSTANCE.setCaptionParam(e);
                            G_PLAYER_INSTANCE.setToolBarEnable({
                                enableShare: false,
                                enableFileList: L.enableFileList,
                                enableDownload: false,
                                enableSet: false,
                                enableCaption: false,
                                enableOpenWindow: L.enableOpenWindow,
                                enableTopBar: L.enableTopBar,
                                enableFeedback: true
                            });
                            b.setFeeParam(0);
                            b.setShareParam()
                        });
                        var c = x.getAttribute("id");
                        $.printObject(c, false, "100%", "100%");
                        try {
                            window[G].call()
                        } catch (e) {}
                    }
                } else {
                    if (b.type == "url") {
                        b.getLastPos();
                        b.fileList = {
                            userid: b.user.u,
                            info_hash: "",
                            subfile_list: [{
                                name: b.curPlay.src_info.file_name,
                                index: -1,
                                url_hash: b.curPlay.url_hash
                            }]
                        }
                    }
                    if (b.originalPlay == null) {
                        b.originalPlay = a
                    }
                    b.cacheData = b.cacheReqData(b.cacheData, a, b.curPlay.url_hash);
                    var f = a.vodinfo_list;
                    b.vod_info = f;
                    $.attachEvent($, "onload", function (a, c) {
                        b.initEvent();
                        var e = f.length;
                        if (e == 1 && (V == "g" || V == "c") || e == 2 && V == "c") {
                            V = "p"
                        }
                        if (V == "g") {
                            var g = f[1].vod_url
                        } else {
                            if (V == "c") {
                                var g = f[2].vod_url
                            } else {
                                var g = f[0].vod_url
                            }
                        }
                        b.startPlay(g, V, b.lastPos);
                        b.getFormats();
                        G_PLAYER_INSTANCE.playOtherFail(true);
                        b.getCaption(b.curPlay.src_info.gcid, b.curPlay.src_info.cid);
                        b.setShareParam();
                        b.curName = d(b.curPlay.src_info.file_name)
                    });
                    var c = x.getAttribute("id");
                    $.printObject(c, false, "100%", "100%");
                    try {
                        window[G].call()
                    } catch (e) {}
                }
                if (b.curPlay.src_info) {
                    var g = b.curPlay.src_info.gcid
                } else {
                    var g = ""
                }
                try {
                    b.stat({
                        f: "svrresp",
                        ret: b.curPlay.ret,
                        pt: b.curPlay.status,
                        gcid: g
                    })
                } catch (e) {}
            },
            cacheReqData: function (a, b, c) {
                var a = a || [];
                var d = a.length;
                if (d > 0 && d < 6) {
                    var e = [];
                    for (var f = 0; f < d; f++) {
                        if (a[f].url_hash && a[f].url_hash != c) {
                            e.push(a[f])
                        }
                    }
                    a = e
                }
                a.push(b);
                if (a.length == 5) {
                    a.shift()
                }
                return a
            },
            startPlay: function (a, b, c, d) {
                var e = this;
                c = c || 0;
                e.lastFormat = b;
                e.curDlUrl = a;
                if (n) {
                    G_PLAYER_INSTANCE.setUrl(a, c);
                    this.getFormats();
                    return true
                } else {
                    var f = {};
                    f.totalByte = 1;
                    f.totalTime = parseInt(this.curPlay.duration / 1e6);
                    var g = a;
                    f.totalByte = parseInt(this.$PU("s", g));
                    f.sliceType = 0;
                    if (c && c > 0) {
                        f.start = c
                    }
                    G_PLAYER_INSTANCE.stop();
                    G_PLAYER_INSTANCE.setToolBarEnable(L);
                    e.setFeeParam(1);
                    f.format = b;
                    if (T) {
                        this.enableKKVA()
                    }
                    G_PLAYER_INSTANCE.flashopen(g, true, false, K, f, 0)
                }
            },
            playOther: function (a, b, e, f, g, h) {
                var i = this;
                G_PLAYER_INSTANCE.setFormats({
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
                });
                if (!i.validUrl(b)) {
                    G_PLAYER_INSTANCE.playOtherFail(false, "该视频下载链接有误，无法播放");
                    i.setFeeParam(0);
                    G_PLAYER_INSTANCE.setToolBarEnable({
                        enableShare: false,
                        enableFileList: false,
                        enableDownload: false,
                        enableSet: false,
                        enableCaption: false,
                        enableOpenWindow: L.enableOpenWindow,
                        enableTopBar: L.enableTopBar,
                        enableFeedback: true
                    });
                    return false
                }
                i.reportPlayPos();
                b = c(b);
                J = d(b);
                i.type = "url";
                var j = i.genBtUrl(J);
                if (j) {
                    i.type = "bt";
                    J = j
                }
                K = true;
                V = "p";
                U = 0;
                i.captionList = [];
                i.isFromList = false;
                if (!a) {
                    i.isFromList = true;
                    i.curName = d(f);
                    f = "";
                    if (j == i.genBtUrl(B, "", 1)) {
                        f = F
                    }
                    var k = false;
                    if (i.cacheData) {
                        var l = null;
                        var m = i.cacheData.length;
                        for (var n = 0; n < m; n++) {
                            if (e && i.cacheData[n].url_hash == e && i.cacheData[n].status == 0) {
                                k = true;
                                l = i.cacheData[n];
                                break
                            }
                        }
                    }
                    i.getLastPos()
                } else {
                    i.fileList = null
                }
                i.curUrl = b;
                if (k) {
                    var o = setTimeout(function () {
                        i.queryOtherBack(l);
                        clearTimeout(o)
                    }, 30)
                } else {
                    i.query(c(b), f, g, h, "", 1)
                }
            },
            queryOtherBack: function (a) {
                var b = this;
                b.curPlay = a;
                if (a.status != 0) {
                    G_PLAYER_INSTANCE.playOtherFail(false, b.genErrorMsg(a, 1));
                    G_PLAYER_INSTANCE.setToolBarEnable({
                        enableShare: false,
                        enableFileList: L.enableFileList,
                        enableDownload: false,
                        enableSet: false,
                        enableCaption: false,
                        enableOpenWindow: L.enableOpenWindow,
                        enableTopBar: L.enableTopBar,
                        enableFeedback: true
                    });
                    if (!b.isFromList) {
                        if (b.curPlay.src_info) {
                            b.curName = d(b.curPlay.src_info.file_name)
                        } else {
                            b.curName = J
                        }
                    }
                    b.setFeeParam(0)
                } else {
                    if (b.type == "url") {
                        b.getLastPos()
                    }
                    b.cacheData = b.cacheReqData(b.cacheData, a, b.curPlay.url_hash);
                    var c = a.vodinfo_list;
                    b.vod_info = c;
                    if (!b.isFromList) {
                        b.curName = d(b.curPlay.src_info.file_name)
                    }
                    var e = setTimeout(function () {
                        b.startPlay(c[0].vod_url, V, b.lastPos);
                        clearTimeout(e)
                    }, 50);
                    b.getFormats();
                    G_PLAYER_INSTANCE.playOtherFail(true);
                    b.getCaption(a.src_info.gcid, a.src_info.cid);
                    b.setShareParam()
                }
                try {
                    window[H].call()
                } catch (f) {}
                if (a.src_info) {
                    var g = a.src_info.gcid
                } else {
                    var g = ""
                }
                try {
                    b.stat({
                        f: "svrresp",
                        ret: a.ret,
                        pt: a.status,
                        gcid: g
                    })
                } catch (f) {}
            },
            setFeeParam: function (a) {
                var b = this;
                var c = y;
                if (b.isXlpan || b.isThunderBox) {
                    c = "xlpan"
                }
                if (a) {
                    var e = b.curPlay.src_info;
                    var f = e.file_size || "";
                    G_PLAYER_INSTANCE.setFeeParam({
                        sessionid: b.user.s,
                        userid: b.user.u,
                        isvip: b.user.v,
                        gcid: e.gcid,
                        cid: "0000000000000000000000000000000000000000",
                        name: b.curName,
                        url_hash: b.curPlay.url_hash,
                        from: c,
                        url: d(b.curUrl),
                        index: b.curUrl.substr(parseInt(b.curUrl.lastIndexOf("/")) + 1, b.curUrl.length),
                        ygcid: e.gcid,
                        ycid: e.cid,
                        filesize: f,
                        info_hash: b.curInfohash
                    })
                } else {
                    G_PLAYER_INSTANCE.setFeeParam({
                        sessionid: b.user.s,
                        userid: b.user.u,
                        isvip: b.user.v,
                        gcid: "",
                        cid: "0000000000000000000000000000000000000000",
                        name: "",
                        url_hash: b.curPlay.url_hash,
                        from: c,
                        url: d(b.curUrl),
                        index: b.curUrl.substr(parseInt(b.curUrl.lastIndexOf("/")) + 1, b.curUrl.length),
                        ygcid: "",
                        ycid: "",
                        filesize: "",
                        info_hash: b.curInfohash
                    })
                }
            },
            $PU: function (a, b) {
                b = k(b) ? location.href : b;
                var c = b.match(new RegExp("[#|?]([^#]*)[#|?]?"));
                b = "&" + (l(c) ? "" : c[1]);
                c = b.match(new RegExp("&" + a + "=", "i"));
                return l(c) ? undefined : b.substr(c.index + 1).split("&")[0].split("=")[1]
            },
            getFormats: function (a) {
                a = a || this.lastFormat;
                var b = {
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
                b.g.enable = typeof this.vod_info[1] != "undefined";
                b.c.enable = typeof this.vod_info[2] != "undefined";
                b.p.enable = true;
                b[a].checked = true;
                G_PLAYER_INSTANCE.setFormats(b)
            },
            setFormats: function (a, b, c, d) {
                var e = G_PLAYER_INSTANCE.getPlayPosition();
                var a = this;
                K = true;
                if (c == "p") {
                    try {
                        G_PLAYER_INSTANCE.close();
                        G_PLAYER_INSTANCE.closeNetStream()
                    } catch (f) {}
                    G_PLAYER_INSTANCE.setIsChangeQuality(true);
                    this.startPlay(this.vod_info[0].vod_url, "p", e, 1);
                    G_PLAYER_INSTANCE.setIsChangeQuality(false);
                    a.getFormats()
                } else {
                    if (c == "g") {
                        try {
                            G_PLAYER_INSTANCE.close();
                            G_PLAYER_INSTANCE.closeNetStream()
                        } catch (f) {}
                        G_PLAYER_INSTANCE.setIsChangeQuality(true);
                        this.startPlay(this.vod_info[1].vod_url, "g", e, 1);
                        G_PLAYER_INSTANCE.setIsChangeQuality(false);
                        a.getFormats()
                    } else {
                        if (c == "c") {
                            try {
                                G_PLAYER_INSTANCE.close();
                                G_PLAYER_INSTANCE.closeNetStream()
                            } catch (f) {}
                            G_PLAYER_INSTANCE.setIsChangeQuality(true);
                            this.startPlay(this.vod_info[2].vod_url, "c", e, 1);
                            G_PLAYER_INSTANCE.setIsChangeQuality(false);
                            a.getFormats()
                        }
                    }
                }
            },
            error: function (a) {
                x.innerHTML = "<img src='" + s + "img/play_bg.jpg' width='100%' height='100%' /><div style='position:absolute;left:0;top:46%;text-align:center;font-size:14px;color:#FFF;margin: 0;width:100%;height:22px;'>" + a + "</div>";
                try {
                    window[I].call()
                } catch (b) {}
            },
            close: function () {
                try {
                    G_PLAYER_INSTANCE.close();
                    G_PLAYER_INSTANCE.closeNetStream()
                } catch (a) {}
            },
            getCaption: function (a, b) {
                if (n) {
                    return true
                }
                var c = this;
                var d = {
                    description: "请选择字幕文件(*.srt、*.ass)",
                    extension: "*.srt;*.ass",
                    limitSize: 5 * 1024 * 1024,
                    uploadURL: t + "interface/upload_file/?cid=" + b,
                    timeOut: "30"
                };
                G_PLAYER_INSTANCE.setCaptionParam(d);
                h(u + "subtitle/list/gcid/" + a + "/cid/" + b, "XL_CLOUD_FX_INSTANCE.queryCaptionBack", function (a) {
                    c.queryCaptionBack(a, b)
                })
            },
            queryCaptionBack: function (a, b) {
                var c = a.sublist.length;
                if (a.sublist != undefined && a.sublist.length > 0) {
                    var e = a.sublist;
                    for (var f = 0; f < c; f++) {
                        if (this.captionList.length > 3) {
                            break
                        }
                        var g = e[f];
                        if (g.sname == undefined) {
                            continue
                        }
                        var h = g.sname;
                        var i = h.length;
                        if (i > 0) {
                            for (var j = 0; j < i; j++) {
                                var k = d(h[j]);
                                var l = k.lastIndexOf(".");
                                var m = k.length;
                                var o = k.substring(parseInt(l) + 1, m).toLowerCase();
                                if (o == "ass" || o == "srt") {
                                    this.captionList.push({
                                        autoload: g.autoload,
                                        language: g.language[0] || "",
                                        scid: g.scid,
                                        sname: k,
                                        surl: "http://i.vod.xunlei.com/subtitle/data/scid/" + g.scid + ".srt",
                                        svote: g.svote || 0
                                    })
                                }
                            }
                        }
                    }
                    if (!n) {
                        G_PLAYER_INSTANCE.setCaptionList(this.captionList);
                        console.log("line 1156 setCaptionList")
                    }
                }
            },
            addCaptionList: function (a) {
                var b = a.length;
                if (!a || typeof a != "object" || b < 1) {
                    return false
                }
                for (var c = 0; c < b; c++) {
                    if (c == 1) {
                        break
                    }
                    this.captionList.push(a[c])
                }
                if (this.captionList.length > 3) {
                    this.captionList.shift()
                }
                G_PLAYER_INSTANCE.setCaptionList(this.captionList)
            },
            getBtFileLastPos: function () {
                var a = this;
                if (a.type == "url" || a.curInfohash.length != 40) {
                    return false
                }
                if (a.fileList == null) {
                    var b = u + "req_subBT/info_hash/" + a.curInfohash + "/req_num/2/req_offset/0?cache=" + (new Date).getTime();
                    g(b, "XL_CLOUD_FX_INSTANCEqueryFileListBack", function (b) {
                        a.fileList = b.resp;
                        if (a.fileList.ret == 0) {
                            a.getLastPos()
                        }
                    })
                }
            },
            getFileList: function () {
                var a = this;
                if (a.type == "url" || a.curInfohash.length != 40) {
                    return a.fileList = null
                } else {
                    if (a.fileList == null || a.fileList.ret != 0) {
                        var b = null;
                        var c = true;
                        var d = u + "req_subBT/info_hash/" + a.curInfohash + "/req_num/200/req_offset/0?cache=" + (new Date).getTime();
                        g(d, "XL_CLOUD_FX_INSTANCEqueryFileListBack", function (d) {
                            c = false;
                            clearTimeout(b);
                            a.fileList = d.resp;
                            if (a.fileList.ret == 0) {
                                if (a.fileList.subfile_list.length > 199) {
                                    c = true;
                                    g(u + "req_subBT/info_hash/" + a.curInfohash + "/req_num/200/req_offset/200?cache=" + (new Date).getTime(), "XL_CLOUD_FX_INSTANCEqueryFileListBack", function (d) {
                                        c = false;
                                        clearTimeout(b);
                                        var e = d.resp;
                                        if (e.ret == 0) {
                                            a.fileList.subfile_list = a.fileList.subfile_list.concat(e.subfile_list)
                                        }
                                    })
                                }
                                a.getLastPos()
                            }
                        })
                    }
                }
            },
            setShareParam: function () {
                var a = "我正在观看" + d(this.curName);
                G_PLAYER_INSTANCE.setShareParam(a, d(J))
            },
            loginNotice: function () {
                window.open("http://vod.xunlei.com/home.html?xcvp=login");
                this.error("继续<a style='color:#1874CA' href='javascript:;' onclick='XL_CLOUD_FX_INSTANCE.continuePlay();return false;'>播放</a>")
            },
            continuePlay: function () {
                var a = this;
                a.error("请稍候，精彩即将开启...");
                a.uCheck()
            },
            getLastPos: function () {
                var a = this;
                if (U) {
                    a.lastPos = U;
                    return true
                }
                a.lastPos = 0;
                if (a.type == "bt") {
                    var b = a.curUrl.substr(a.curUrl.lastIndexOf("/") + 1, a.curUrl.length);
                    var c = a.fileList.main_task_url_hash
                } else {
                    var c = a.curPlay.url_hash
                }
                var d = null,
                    e = true;
                setTimeout(function () {
                    clearTimeout(d);
                    e = false;
                    if (e) {
                        a.lastPos = 0
                    }
                }, 1e3)
            },
            genBtUrl: function (a, b, c) {
                if (!a && !b) {
                    return false
                }
                var e = "";
                if (b && b.length == 40) {
                    e = b
                } else {
                    if (d(a).substr(0, 5) == "bt://") {
                        e = d(a).substring(5, d(a).lastIndexOf("/"))
                    }
                }
                if (e) {
                    if (!c) {
                        this.curInfohash = e
                    }
                    return "http://bt.box.n0808.com/" + e.substr(0, 2) + "/" + e.substr(38, 40) + "/" + e + ".torrent"
                } else {
                    return false
                }
            },
            validUrl: function (a) {
                if (a == "" || a == "none" || a == "undefined" || document.location.protocol + "//" + document.location.host + "/" == a) {
                    return false
                }
                var b = a.toLowerCase();
                if (b.indexOf("http") == -1 && b.indexOf("https") == -1 && b.indexOf("ftp") == -1 && b.indexOf("thunder") == -1 && b.indexOf("mms") == -1 && b.indexOf("qqdl") == -1 && b.indexOf("rtsp") == -1 && b.indexOf("magnet") == -1 && b.indexOf("flashget") == -1 && b.indexOf("ed2k") == -1 && b.indexOf("bt") == -1 && b.indexOf("xlpan") == -1 || b == "") {
                    return false
                } else {
                    return true
                }
            },
            windowOpenInPlayer: function (a) {
                var b = document;
                _body = document.getElementsByTagName("body")[0];
                var c = null;
                var d = b.getElementById("dapctrl");
                if (d) {
                    try {
                        b.getElementsByTagName("body")[0].removeChild(d)
                    } catch (e) {}
                }
                if (!o && !b.getElementById("dapctrl")) {
                    var f = b.createElement("object");
                    f.setAttribute("type", "application/x-thunder-dapctrl");
                    f.setAttribute("id", "dapctrl");
                    f.setAttribute("width", "0");
                    f.setAttribute("height", "0");
                    f.style.visibility = "hidden";
                    _body.appendChild(f)
                } else {
                    try {
                        c = new ActiveXObject("DapCtrl.DapCtrl")
                    } catch (e) {}
                }
                if (c) {
                    c.Put("iADShowMode", 1);
                    c.Put("sOpenAdUrl", a);
                    c = null
                } else {
                    window.open(a)
                }
            },
            openMini: function (a, b) {
                try {
                    this.reportPlayPos()
                } catch (c) {}
                window.open("http://" + j["mini"] + j.miniuri + "?url=" + parent.Base64.encode(this.curUrl), "miniplayer", "top=10,left=10,height=446,width=684,toolbar=no,menubar=no,resizable=yes,scrollbars=no,location=no,status=no,fullscreen=no")
            },
            enableKKVA: function () {
                var a = this;
                a.kkvaValid = false;
                if (n || !a.isThunderBox && !o) {
                    return true
                }
                var b = document.getElementsByTagName("body")[0];
                var c = document.getElementById("vasensor");
                try {
                    b.removeChild(c)
                } catch (d) {}
                var e = document.createElement("object");
                e.setAttribute("id", "vasensor");
                e.setAttribute("width", "0");
                e.setAttribute("height", "0");
                e.style.visibility = "hidden";
                if (!o) {
                    e.setAttribute("type", "application/x-thunder-kkva")
                } else {
                    e.setAttribute("classid", "CLSID:96CD6DA7-17F2-4576-82B0-BE4526FB7D6B")
                }
                document.getElementsByTagName("body")[0].appendChild(e);
                var f = 0;
                if (XL_CLOUD_FX_INSTANCE.lastFormat == "c") {
                    f = 2
                } else {
                    if (XL_CLOUD_FX_INSTANCE.lastFormat == "g") {
                        f = 1
                    }
                }
                var g = XL_CLOUD_FX_INSTANCE.vod_info[f]["vod_url"];
                var h = this.$PU("g", g);
                if (a.isThunderBox) {
                    try {
                        var i = window.external.GetClientVersion()
                    } catch (d) {
                        var i = "1.6"
                    }
                    if (i < "1.6") {} else {
                        try {
                            if (e.Get("iVersion") != 100007) {
                                e.EnableVA("yvod", h, g, 0);
                                a.kkvaValid = true;
                                e.Put("iXMPIconTray", 0);
                                a.stat({
                                    f: "kkva",
                                    g: h,
                                    client: "thunderBox"
                                })
                            }
                        } catch (d) {}
                    }
                } else {
                    try {
                        var j = document.getElementById("myPlugin");
                        if (!j) {
                            var j = document.createElement("object");
                            j.setAttribute("id", "myPlugin");
                            j.setAttribute("width", "0");
                            j.setAttribute("height", "0");
                            j.style.visibility = "hidden";
                            if (o) {
                                j.setAttribute("classid", "clsid:BD1E9B61-F3B2-4A19-AB69-68E77CA81C42")
                            } else {
                                j.setAttribute("type", "application/x-thunderbox-upload")
                            }
                            document.getElementsByTagName("body")[0].appendChild(j)
                        }
                        if (j.FindThunderbox() && j.GetThunderboxVersion() >= "1.6" && e.Get("iVersion") != 100007) {
                            e.EnableVA("yvod", h, g, 0);
                            a.kkvaValid = true;
                            e.Put("iXMPIconTray", 0);
                            a.stat({
                                f: "kkva",
                                g: h,
                                client: "web"
                            })
                        } else {}
                    } catch (d) {}
                }
                return true
            }
        };
        g(t + "fx?t=" + (new Date).getTime(), "", function (a) {
            return false
        });
        var _ = n ? s + "ipad.js?" + q : "f.h?" + q;
        var bb = new f(_);
        bb.buildScriptTag();
        bb.addScriptTag()
    }, 1)
})()