var $f181=function(){var $v749={P$0:!1};var hmTagsNotHonoringDNT={};var ieHonorDNT=!1;var otherHonorDNT=!1;var $v908=[];var $v733={"[":1,"]":1,".":1,"'":1,'"':1};var $v468={"+":1,"-":1,"/":1,"!":1,"*":1,"%":1,"^":1,"&":1,"|":1,"<":1,">":1," ":1,"\t":1};var $f169={getPageIdentifier:function(){return($f181.$v181("J","WebAnalytics.Page.PageIdentifier")===null)?eval("WebAnalytics.Page.PageIdentifier"):""+$f181.$v181("J","WebAnalytics.Page.PageIdentifier")},$v29:function($v382){return $v749["P$"+$v382]},isTagSyndicationAllowed:function($v382,tagId){if(hmTagsNotHonoringDNT[tagId]){return !0}if(CM_DDX.privacy.isDoNotTrackEnabled($v382)){return !1}if(navigator.msDoNotTrack&&navigator.msDoNotTrack==1&&ieHonorDNT){return !1}if(navigator.doNotTrack&&(navigator.doNotTrack=="yes"||navigator.doNotTrack=="1")&&otherHonorDNT){return !1}return !0},doesParameterExist:function($v857){var sa=$v857.split("\x01");return(sa.length===3)?$f169.$v181(sa[0],sa[2])===null:$f169.$v181(sa[0],sa[2],sa[3])===null},$v904:function($v857){var sa=$v857.split("\x01");return(sa.length===3)?$f169.$v181(sa[0],sa[2]):$f169.$v181(sa[0],sa[2],sa[3])},getParameterValue:function($v857){var sa=$v857.split("\x01");if(sa[0]==="H"){return(sa[2].charAt(0)==="#")?(sa.length===3?$f169.$v232(sa[2].substring(1)):$f169.$v232(sa[2].substring(1),sa[3])):(sa.length===3?$f169.$v442(sa[2]):$f169.$v442(sa[2],sa[3]))}else{if(sa[0]==="U"){return CM_DDX.gup(sa[2])}else{if(sa[0]==="J"||sa[0]==="1"){try{return $f169.$v162(sa[2])}catch(sErr){$f180.$f124(sErr);return null}}else{if(sa[0]==="C"){return sa[2]}else{if(sa[0]==="K"){return cI(sa[2])}else{if(sa[0]==="L"){return localStorage[sa[2]]}else{if(sa[0]==="S"){return sessionStorage[sa[2]]}else{if(sa[0]==="M"||sa[0]==="2"){return $f169.$v539(sa[2])}else{return null}}}}}}}}},$v63:function($v6,$v225,$v131){if($v6!==null){return $v6}if(!$v131){return $v225}var $v530=$v131.replace(/@/g,$v225+"");try{return eval($v530)}catch($v95){return"\x01"+$v95}},$v181:function($v132,$v686,$v311){if($v132==="H"){if($v686!==null&&$v686.length>0){var $v213=($v686.charAt(0)==="#");var o=$v213?$f169.$v246($v686.substring(1)):document.getElementById($v686);if(!o&&!$v213){var sa=document.getElementsByName($v686);if(sa.length>0){o=sa[0]}}if(o===null){return $v213?"\x01NO_SUCH_XPATH_ELEMENT":"\x01NO_SUCH_DOM_ELEMENT"}if($v311!==null&&typeof($v311)!=="undefined"&&!$f169.hasAttribute(o,$v311)&&$v311!=="innerHTML"){return"\x01NO_SUCH_DOM_ATTRIBUTE"}}else{return"\x01INVALID_DOM_ELEM_SPECIFIER"}}else{if($v132==="J"||$v132==="1"){try{if($f169.$v162($v686)===undefined){return"\x01NO_SUCH_JS_VARIABLE"}}catch(e){return"\x01NO_SUCH_JS_VARIABLE"}}else{if($v132==="K"&&!cI($v686)){return"\x01NO_SUCH_JS_VARIABLE"}else{if($v132==="L"){if(CM_DDX.localStorage===!1){return"\x01LS_NOT_SUPPORTED"}else{if(CM_DDX.localStorage===undefined){try{localStorage.setItem("!@#$%","!@#$%");localStorage.removeItem("!@#$%");CM_DDX.localStorage=!0}catch(sErr){CM_DDX.localStorage=!1;return"\x01LS_NOT_SUPPORTED"}}}if(!localStorage[$v686]){return"\x01NO_SUCH_LS_VARIABLE"}}else{if($v132==="S"){if(CM_DDX.sessionStorage===!1){return"\x01SS_NOT_SUPPORTED"}else{if(CM_DDX.sessionStorage===undefined){try{sessionStorage.setItem("!@#$%","!@#$%");sessionStorage.removeItem("!@#$%");CM_DDX.sessionStorage=!0}catch(sErr){CM_DDX.sessionStorage=!1;return"\x01SS_NOT_SUPPORTED"}}}if(!sessionStorage[$v686]){return"\x01NO_SUCH_SS_VARIABLE"}}else{if(($v132==="M"||$v132==="2")&&$f169.$v539($v686)===null){return"\x01NO_SUCH_META_TAG"}else{if($v132==="U"){if(CM_DDX.gup($v686)===null){return"\x01NO_SUCH_URL_PARAMETER"}}}}}}}}return null},$v539:function(sName){var $v889=document.getElementsByTagName("meta");if($v889==null||$v889.length===0){return null}if(sName.indexOf("?")===-1){for(var m=0;m<$v889.length;m++){if($f169.getAttribute($v889[m],"name")===cmUtils.string.trim(sName)){return $f169.getAttribute($v889[m],"content")}}}else{oaTokens=sName.split("?");if(oaTokens.length===2){for(var m=0;m<$v889.length;m++){var sVal=$f169.getAttribute($v889[m],cmUtils.string.trim(oaTokens[1]));if(sVal!=null){return sVal}}}else{if(oaTokens.length===3){var oaAttrVal=cmUtils.string.trim(oaTokens[1]).split("=");for(var m=0;m<$v889.length;m++){var sVal=$f169.getAttribute($v889[m],oaAttrVal[0]);if(sVal!=null){if(sVal===cmUtils.string.trim(oaAttrVal[1])){return $f169.getAttribute($v889[m],oaTokens[2])}}}}}}return null},hasAttribute:function(o,$v362){if(!$v362){return !1}if(o.hasAttribute){return o.hasAttribute($v362.toLowerCase())}else{return(o.attributes[$v362]||o.attributes[$v362.toLowerCase()])}},$v972:function(oValue){if(typeof(oValue)==="string"){oValue=oValue.toLowerCase();if(oValue==="true"||oValue==="yes"||oValue==="1"){return !0}else{if(oValue==="false"||oValue==="no"||oValue==="0"){return !1}}}else{if(typeof(oValue)==="boolean"){return oValue}else{if(typeof(oValue)==="number"){if(oValue===1){return !0}else{if(oValue===0){return !1}}}}}return undefined},$v936:function(oValue){return $f169.$v972(oValue)!=undefined},$v811:function(oValue){return(parseInt(oValue)===oValue*1)?oValue*1:undefined},$v992:function(oValue){return(!isNaN(oValue)&&typeof(oValue)!="boolean")?oValue*1:undefined},$v442:function($v431,$v362){if($v431!==null&&$v431.length>0){var o=document.getElementById($v431);if(!o){var oa=document.getElementsByName($v431);if(oa.length>0){o=oa[0]}}return $f169.getAttribute(o,$v362)}return null},$v232:function($v911,$v362){if($v911!==null&&$v911.length>0){return $f169.getAttribute($f169.$v246($v911),$v362)}return null},$v246:function($v911){var xh=null;try{xh=new XMLHttpRequest()}catch(ex1){try{xh=new ActiveXObject("Microsoft.XMLHTTP")}catch(ex2){}}if(xh===null){return null}try{var o=document.evaluate?document.evaluate($v911,document,null,XPathResult.FIRST_ORDERED_NODE_TYPE,null):null;if(o===null){return null}try{return o.getSingleNodeValue?o.getSingleNodeValue():o.singleNodeValue}catch(exWebKit){try{return o.iterateNext()}catch(exUnknown){return null}}}catch(ex2){var sErr=ex2.message;return null}},getAttribute:function($v354,$v311){if($v354!==null){if(!$v311||$v311==="innerHTML"){return $v354.innerHTML}else{if($v354.getAttribute){return $v354.getAttribute($v311.toLowerCase())}else{return($v354.attributes[$v311])?$v354.attributes[$v311]:$v354.attributes[$v311.toLowerCase()]}}}return null},$v162:function($v530){var $v155=$f169.$v667($v530);if($v155.length===0){return undefined}var o=window;for(var i=0;i<$v155.length;i++){o=o[$v155[i].replace(/\\\"/g,'"').replace(/\\\'/g,"'")];if(o===null||o===undefined){return o}}return o},$v667:function(sValue){if($v908[sValue]!==undefined){return $v908[sValue]}var $v155=[];var ch,$v478,$v742="",$v388=!1,$v757=!0,$v991=null,$v425=null,$v687=null;for(var i=0;i<sValue.length;i++){ch=sValue.charAt(i);$v388=($v425==="\\");$v165=!1;if(ch==='"'||ch==="'"){if($v687===null){$v687=ch;$v165=!0}else{if($v687===ch){$v687=null;$v165=!0}}}$v478=$f169.$v669(ch,$v388,$v991,$v165,$v687);if($v478!=null){if(!$v388){if($v478==="S"){$v991=ch}if($v478==="E"||$v742.length>0){if($v742.length>0){$v155[$v155.length]=$v742}$v742="";$v991=$v757?ch:null;$v757=!1}}}else{if(!$v165){$v742+=ch}}$v425=ch}$v742=$v742.replace(/\"/g,'\\"').replace(/\\/g,"\\\\");if($v742.length>0){$v155[$v155.length]=$v742}$v908[sValue]=$v155;return $v155},$v963:function(sExpr){if($v908["@F:"+sExpr]!==undefined){return $v908["@F:"+sExpr]}var $v218=new $f165();if(!sExpr){$v908["@F:"+sExpr]=$v218;return $v218}var $v901=!0,$v278=!1;var $v742="",ch,$v425,$v30=null;for(var i=0;i<sExpr.length;i++){ch=sExpr.charAt(i);$v278=$v425==="\\";if(!$v278&&(ch==='"'||ch==="'")){if($v30===null){$v30=ch}else{if($v30===ch){$v30=null}}}$v901=($v468[ch]!==undefined&&$v30===null);if(ch==="("&&$v30===null){if(!$v218.contains($v742)&&isNaN($v742)&&$v742.length>0&&$v742.charAt(0)!=='"'&&$v742.charAt(0)!=="'"&&$v742.indexOf(")")===-1){$v218.add($v742)}$v901=!0}if(!$v901){$v742+=ch}else{$v742=""}$v425=ch}$v908["@F:"+sExpr]=$v218;return $v218},$v669:function(ch,$v388,$v991,$v165,$v687){if($v733[ch]){if($v687!==null){return null}if(!$v388&&((($v991===null&&ch!=="]")||ch==="[")&&ch!=="]")){return"S"}if((($v991==='"'&&ch==='"')||($v991==="'"&&ch==="'")||(($v991===null||$v991==="[")&&ch==="]")||(ch==="."))&&!$v388){return"E"}}return null}};return $f169}();var $f180=new function(){var $f112=[],$v835=[],loUtcInMillis;var $v724={$v976:-1};var $f169={$v879:function(s,t){if(s.length>0&&s.charAt(0)==="\x02"){s=s.substring(1);var sa=s.split("\x01");var $v629=(sa.length===3)?$f181.$v181(sa[0],sa[2]):$f181.$v181(sa[0],sa[2],sa[3]);if($v629){return $v629}else{$v629=$f181.getParameterValue(s);if(t===$f166.BOOLEAN){$v629=$f181.$v972($v629)}else{if(t===$f166.NUMERIC){$v629=$f181.$v992($v629)}else{if($v629){$v629=""+$v629}}}return $v629}}else{return s}},$v482:function(s){return(s&&typeof(s)==="string"&&s.length>0&&s.charAt(0)==="\x01")},$v18:function(oa,o){for(var i=0;i<oa.length;i++){if((oa[i]+"").toLowerCase()===(o+"").toLowerCase()){return !0}}return !1},recordPartnerFromVCPIVendor:function(){var vcpi="";try{vcpi=_cmPartnerUtils.parseVCPI(document.URL);if(vcpi===""){vcpi=_cmPartnerUtils.parseVCPI(document.referrer)}if(vcpi!==""&&vcpi.length>1){var $v601=$v724[vcpi[1].toLowerCase()];if(typeof($v601)!=="undefined"){CM_DDX.setSubCookie("CM_DDX","pla"+$v601,new Date().getTime(),365)}}}catch(sErr){$f180.$f124(sErr)}},$v808:function($v601){var $v393=24*60*60*1000;var idt=cI("CM_DDX","pla"+$v601);if(idt===null){return -1}try{return(new Date().getTime()-parseInt(idt))/$v393}catch(e){return -1}},hasPartnerBeenAccessedIn:function($v601,numDays){var days=$f169.$v808($v601);return(days!=-1&&days<numDays)},$f124:function(sErr){$f112[$f112.length]=sErr},$f113:function(){return $f112},$v778:function($v635,$v310){if(!$v835[$v635]){$v835[$v635]=$v310}},$v946:function($v39){if($v39.length===0){return !0}var dt=new Date(),sDoesntExist;loUtcInMillis=Date.UTC(dt.getFullYear(),dt.getMonth(),dt.getDate(),dt.getHours(),dt.getMinutes(),dt.getSeconds(),dt.getMilliseconds());for(var i=0;i<$v39.length;i++){if($v835[$v39[i]]===!1){return !1}else{sDoesntExist=eval($v835[$v39[i]]);if(typeof(sDoesntExist)==="string"){return sDoesntExist}else{if(sDoesntExist===!1){return !1}}}}return !0},$v301:function(ia1,ia2){var len1=ia1.length;var len2=ia2.length;for(var i=0;i<len2;i++){ia1[len1+i]=ia2[i]}},$v809:function($v131,fe){fe.modifier=$v131;var $v221=$f181.$v963($v131);for(var $v832 in $v221.elements()){if($v221.$f128($v832)){if(typeof(window[$v832])==="function"){fe.found.add($v832)}else{fe.$v482.add($v832)}}}},$v895:function(sUrl,fnCallback){var l=document.createElement("link");l.setAttribute("rel","stylesheet");l.setAttribute("type","text/css");l.setAttribute("href",sUrl);document.getElementsByTagName("head")[0].appendChild(l);if(fnCallback){if(l.readyState){l.onreadystatechange=function(){fnCallback()}}else{l.onload=function(){fnCallback()}}}},$f121:function(){var dt=new Date();var $f122=dt.getFullYear();var fnPad2=function(v){return(v<10)?"0"+v:""+v};var fnPad3=function(v){return(v<10)?"00"+v:((v<100)?"0"+v:""+v)};$f122+=fnPad2(dt.getMonth()+1);$f122+=fnPad2(dt.getDate());$f122+=fnPad2(dt.getHours());$f122+=fnPad2(dt.getMinutes());$f122+=fnPad2(dt.getSeconds());$f122+=fnPad3(dt.getMilliseconds());return $f122},$v613:function($v62){return $v62?encodeURIComponent($v62)+"="+(+new Date()):+new Date()},$v358:function(hm){var oa=[];for(var k in hm){if(hm.hasOwnProperty(k)){oa[oa.length]=hm[k]}}return oa},$v453:function(fe){var sa=[];var hs=fe.found;for(var k in hs.elements()){if(hs.$f128(k)){sa[sa.length]=k+"=1"}}hs=fe.$v482;for(var k in hs.elements()){if(hs.$f128(k)){sa[sa.length]=k+"=0"}}return sa}};return $f169}();var $f166=function(){var a={IBM_COREMETRICS:1,IBM_UNICA:2,IBM_TEALEAF:3,CHANGO:100,SEEWHY:101,CLICKTALE:102,FORESEE:103,ACCENTURE_ADO:104,EVIDON:106,THIRTY_THREE_ACROSS:108,AGGREGATE_KNOWLEDGE:109,REEVOO:110,BIZO:111,TRADE_DESK:112,ADROLL:114,PUBMATIC:115,BLUEKAI:116,DIGILANT:117,GOOGLE_ADWORDS:118,DOUBLE_CLICK_FLOODLIGHT:119,OPINION_LAB:120,BAZAAR_VOICE_ROI_BEACON_V1:121,BAZAAR_VOICE_ROI_BEACON_V2:122,X_PLUS_1:123,TURN:124,EXTENDED_PARTNER_ID_START:1000,IDLE:0,INITIALIZED:1,IN_HEAD:2,BODY_STARTED:3,BODY_ENDED:4,DOM_READY:5,BODY_STATE_CHECK_FREQUENCY:100,PARAMETER_LIST_BREAK_COUNT:5000,IMMEDIATELY:0,AFTER:"AFTER",BEFORE:"BEFORE",CHILD:"CHILD",TEXT:1,NUMERIC:2,BOOLEAN:4,NOT_YET:"\x01NOT_YET"};return a}();function $f165(){this.$f129=[];this.count=0}$f165.prototype.contains=function(a){return this.$f129[a]===!0};$f165.prototype.add=function(a){if(this.$f129[a]===!0){return !1}this.$f129[a]=!0;this.count++;return !0};$f165.prototype.$v141=function(b){for(var a in b.elements()){if(b.$f128(a)){this.add(a)}}};$f165.prototype.remove=function(a){if(typeof(this.$f129[a])==="undefined"){return !1}this.count--;delete this.$f129[a];return !0};$f165.prototype.clear=function(){this.$f129=[];this.count=0};$f165.prototype.isEmpty=function(){return this.count===0};$f165.prototype.elements=function(){return this.$f129};$f165.prototype.$f130=function(){var b=[];for(var a in this.$f129){if(this.$f128(a)){b[b.length]=a}}return b};$f165.prototype.size=function(){return this.count};$f165.prototype.$f128=function(a){return this.$f129.hasOwnProperty(a)};function $f172(){this.$f129=[];this.count=0}$f172.prototype.contains=function(a){return this.$f129[a]!==undefined};$f172.prototype.add=function(b){var a=this.$f129[b];if(a===undefined){this.$f129[b]=1;this.count++}else{this.$f129[b]=a+1}};$f172.prototype.remove=function(b){var a=this.$f129[b];if(a!==undefined){if(a>1){this.$f129[b]=a-1}else{this.count--;delete this.$f129[b]}}};$f172.prototype.$f179=function(b){var a=this.$f129[b];if(a!==undefined){this.count--;delete this.$f129[b]}};$f172.prototype.clear=function(){this.$f129=[];this.count=0};$f172.prototype.isEmpty=function(){return this.count===0};$f172.prototype.$f174=function(){var b=[];for(var a in this.$f129){if(this.$f129.hasOwnProperty(a)){b[b.length]=a}}for(var e=0;e<b.length-e;e++){for(var d=e+1;d<b.length;d++){if(this.$f129[b[e]]<this.$f129[b[d]]){var c=b[e];b[e]=b[d];b[d]=c}}}return b};function $f173(a,c,b){this.$f176=a;this.$f177=c;this.$f178=b}$f173.prototype.$f175=function(){var a=this.$f176;this.$f176*=this.$f177;if(this.$f176>this.$f178){this.$f176=this.$f178}return a};var __$partnerHead=new function(){var a={$v579:function(){},$v344:function(){var b=$f183.$v475()},$v976:{}};return a}();var hmNameToIds=[];var $v926=new function(){var a={register:function(){hmNameToIds["IBM Global Code"]=548;hmNameToIds["Generate Marketing Attributes"]=475},run:function(b){if(hmNameToIds[b]){window["$v926"]["$"+hmNameToIds[b]](!0)}else{throw"Unable to find runtime code snippet ["+b+"]\nThis could've happened either because your code snippet wasn't included in any of the deployed page groups."}},invoke:function(b){for(var c=0;c<b.length;c++){window["$v926"]["$"+b[c]](!1)}},$548:function(b){window.pageViewAttributes=new String();window.IBMPageCategory=new String();function c(){if(typeof(window.digitalData)=="undefined"){window.digitalData=new Object()}if(typeof(window.digitalData.page)=="undefined"){window.digitalData.page=new Object()}if(typeof(window.digitalData.page.category)=="undefined"){window.digitalData.page.category=new Object()}if(typeof(window.digitalData.page.onsiteSearchTerm)=="undefined"){window.digitalData.page.onsiteSearchTerm=null}if(typeof(window.digitalData.page.onsiteSearchResult)=="undefined"){window.digitalData.page.onsiteSearchResult=null}if(typeof(window.digitalData.page.attributes)=="undefined"){window.digitalData.page.attributes=new Object()}if(typeof(window.digitalData.page.pageID)=="undefined"){window.digitalData.page.pageID=location.host+location.pathname+location.hash}if(digitalData.page.category.categoryID){window.IBMPageCategory=digitalData.page.category.categoryID}else{window.IBMPageCategory=d("IBM.WTMCategory")+""}var e=new Array();if(String(document.cookie).match(/(^| )(w3ibmProfile|w3_sauid|PD-W3-SSO-|OSCw3Session|IBM_W3SSO_ACCESS)=/)){if(typeof NTPT_IBMer=="undefined"||NTPT_IBMer==null){NTPT_IBMer=1}}else{if(typeof NTPT_IBMer=="undefined"||NTPT_IBMer==null){NTPT_IBMer=0}}if(typeof(window.digitalData.page.attributes.NTPT_IBMer)=="undefined"){window.digitalData.page.attributes.NTPT_IBMer=e[0]=NTPT_IBMer+""}else{e[0]=window.digitalData.page.attributes.NTPT_IBMer+""}if(digitalData.page.attributes.IBM_Country){e[1]=digitalData.page.attributes.IBM_Country}else{digitalData.page.attributes.IBM_Country=e[1]=d("IBM.Country")+""}if(digitalData.page.attributes.DC_Language){e[2]=digitalData.page.attributes.DC_Language}else{digitalData.page.attributes.DC_Language=e[2]=d("DC.Language")+""}if(digitalData.page.attributes.IBM_Effective){e[3]=digitalData.page.attributes.IBM_Effective}else{digitalData.page.attributes.IBM_Effective=e[3]=d("IBM.Effective")+""}if(digitalData.page.attributes.DC_Subject){e[4]=digitalData.page.attributes.DC_Subject}else{digitalData.page.attributes.DC_Subject=e[4]=d("DC.Subject")+""}if(digitalData.page.attributes.DC_Type){e[5]=digitalData.page.attributes.DC_Type}else{digitalData.page.attributes.DC_Type=e[5]=d("DC.Type")+""}if(digitalData.page.attributes.Source){e[6]=digitalData.page.attributes.Source}else{digitalData.page.attributes.Source=e[6]=d("Source")+""}if(digitalData.page.attributes.Owner||digitalData.page.attributes.Author){if(digitalData.page.attributes.Owner){e[7]=digitalData.page.attributes.Owner}else{e[7]=digitalData.page.attributes.Author}}else{if(digitalData.page.attributes.Owner){digitalData.page.attributes.Owner=e[7]=d("Owner")+""}else{digitalData.page.attributes.Author=e[7]=d("Author")+""}}if(digitalData.page.attributes.Description){e[8]=digitalData.page.attributes.Description}else{digitalData.page.attributes.Description=e[8]=d("Description")+""}if(digitalData.page.attributes.Title){e[9]=digitalData.page.attributes.Title}else{digitalData.page.attributes.Title=e[9]=document.title}if(digitalData.page.attributes.IBM_Industry){e[10]=digitalData.page.attributes.IBM_Industry}else{digitalData.page.attributes.IBM_Industry=e[10]=d("IBM.Industry")+""}if(digitalData.page.attributes.IBM_SpecialPurpose){e[11]=digitalData.page.attributes.IBM_SpecialPurpose}else{digitalData.page.attributes.IBM_SpecialPurpose=e[11]=d("IBM.SpecialPurpose")+""}if(digitalData.page.attributes.Keywords){e[12]=digitalData.page.attributes.Keywords}else{digitalData.page.attributes.Keywords=e[12]=d("Keywords")+""}if(digitalData.page.attributes.DC_Date){e[13]=digitalData.page.attributes.DC_Date}else{digitalData.page.attributes.DC_Date=e[13]=d("DC.Date")+""}for(i=0;i<e.length;i++){pageViewAttributes+=e[i]+"-_-"}return pageViewAttributes,IBMPageCategory;function d(f){var h=document.getElementsByTagName("meta");for(i=0;i<h.length;i++){var g=h[i].getAttribute("name")+"";if(h[i].getAttribute("name")!=null){if(f.toUpperCase()==g.toUpperCase()){return h[i].getAttribute("content")+""}}}return null}}c()},$475:function(e){var f="",b="NA",h="NA",g="NA",d="NA";if(typeof(window.QueryString.cmp)!="undefined"){f=f+"cm_mmca1="+window.QueryString.cmp+"&";b=window.QueryString.cmp}if(typeof(window.QueryString.ct)!="undefined"){f=f+"cm_mmca2="+window.QueryString.ct+"&";h=window.QueryString.ct}if(typeof(window.QueryString.cr)!="undefined"){f=f+"cm_mmca3="+window.QueryString.cr+"&";g=window.QueryString.cr}if(typeof(window.QueryString.cm)!="undefined"){f=f+"cm_mmca4="+window.QueryString.cm+"&";d=window.QueryString.cm}if(typeof(window.QueryString.csr)!="undefined"){f=f+"cm_mmca5="+window.QueryString.csr+"&"}if(typeof(window.QueryString.co)!="undefined"){f=f+"cm_mmca6="+window.QueryString.co+"&"}if(typeof(window.QueryString.ck)!="undefined"){f=f+"cm_mmca7="+window.QueryString.ck+"&"}if(typeof(window.QueryString.mkwid)!="undefined"){f=f+"cm_mmca8="+window.QueryString.mkwid+"&"}if(typeof(window.QueryString.cs)!="undefined"){f=f+"cm_mmca9="+window.QueryString.cs+"&"}if(typeof(window.QueryString.ccy)!="undefined"){f=f+"cm_mmca10="+window.QueryString.ccy+"&"}if(typeof(window.QueryString.cot)!="undefined"){f=f+"cm_mmca11="+window.QueryString.cot+"&"}if(typeof(window.QueryString.csot)!="undefined"){f=f+"cm_mmca12="+window.QueryString.csot+"&"}if(typeof(window.QueryString.cd)!="undefined"){f=f+"cm_mmca13="+window.QueryString.cd+"&"}if(typeof(window.QueryString.cpg)!="undefined"){f=f+"cm_mmca14="+window.QueryString.cpg+"&"}if(typeof(window.QueryString.cpb)!="undefined"){f=f+"cm_mmca15="+window.QueryString.cpb+"&"}if(typeof(window.QueryString.cn)!="undefined"){f=f+"cm_mmca16="+window.QueryString.cn+"&"}if(typeof(window.QueryString.csz)!="undefined"){f=f+"cm_mmca17="+window.QueryString.csz+"&"}if(typeof(window.QueryString.ce)!="undefined"){f=f+"cm_mmca18="+window.QueryString.ce+"&"}if(typeof(window.QueryString.pid)!="undefined"){f=f+"cm_mmca19="+window.QueryString.pid+"&"}if(typeof(window.QueryString.cm_mmc)!="undefined"){f="cm_mmc="+window.QueryString.cm_mmc+"&"+f}else{if(f.length>0){f="cm_mmc="+b+"-_-"+h+"-_-"+g+"-_-"+d+"&"+f}}if(f.lastIndexOf("&")==f.length-1){f=f.substring(0,f.length-1)}if(f.length!=0){f="&"+f}cmCreateManualPageviewTag(digitalData.page.pageID,window.IBMPageCategory,document.URL+f,document.referrer,window.pageViewAttributes,digitalData.page.onsiteSearchTerm,digitalData.page.onsiteSearchResult)}};return a}();var __$helper=function(){var $f169={prefix:function(sPrefix,sValue){return sPrefix+sValue},suffix:function(sValue,sSuffix){return sValue+sSuffix},isStaging:function(){return !1},loadJS:function(url,callbackFunctionNameOrReference){var fn=callbackFunctionNameOrReference;if(typeof fn==="string"){fn=eval(fn);if(typeof fn!=="function"){alert(callbackFunctionNameOrReference+" is not a function");return}}__$dispatcher.load(url,fn)},invokeFunction:function(functionNameOrReference){var fn=functionNameOrReference;if(typeof fn==="string"){fn=eval(fn);if(typeof fn!=="function"){alert(functionNameOrReference+" is not a function");return}}var fargs=[];for(var i=1;i<arguments.length;i++){fargs[fargs.length]=arguments[i]}fn.apply(this,fargs)},pixel:function(baseURL,type){type=type.toLowerCase();var sURL=baseURL;sURL+=((sURL.indexOf("?")==-1)?"?":"&");sURL+=$f171.$v613("che");var bToggle=!1;var paramName,paramValue;for(var i=2;i<arguments.length;i++){if(!bToggle){paramName=arguments[i]}else{paramValue=arguments[i];sURL=sURL+"&"+paramName+"="+cE(paramValue)}bToggle=!bToggle}if(type=="iframe"){var ifrm=document.createElement("IFRAME");ifrm.src=sURL;ifrm.style.width=0+"px";ifrm.style.height=0+"px";ifrm.marginWidth="0";ifrm.marginHeight="0";ifrm.hspace="0";ifrm.vspace="0";ifrm.scrolling="no";ifrm.frameBorder="0";ifrm.style.borderColor="#000000";document.body.appendChild(ifrm)}else{var img=new Image();img.src=sURL;img.width="1";img.height="1";img.border="0"}},replaceContent:function(idOrXpathOrName,htmlContent){var o=document.getElementById(idOrXpathOrName);if(!o){o=$f181.$v246(idOrXpathOrName);if(!o){var oa=document.getElementsByName(idOrXpathOrName);if(oa.length>0){o=oa[0]}}}if(o){o.innerHTML=htmlContent}}};return $f169}();var $f183=new function(){var b=null,c=new $f165(),a=new $f165(),g=[],d=null;var e=[[]];var f={setup:function(){b=[];d=new $f165();var j=document.referrer,l=document.URL,h="";try{h=_cmPartnerUtils.parseVCPI(document.URL);if(h===""){h=_cmPartnerUtils.parseVCPI(j)}if(h.length>4){h=h[1]+"-_-"+h[2]+"-_-"+h[3]+"-_-"+h[4]}}catch(k){$f180.$f124(k)}f.register({id:0,global:!0,head:!0},[548,475]);f.initialize(j,l,h)},initialize:function(j,l,h){var k=$f181.getPageIdentifier();if(k===null){}else{if(k.length>0&&k.charAt(0)==="\x01"){k=null}}__$partnerHead.$v579();if(typeof($v926)!=="undefined"){$v926.register()}if(typeof($f187)!=="undefined"){$f187.initialize()}__$partnerHead.$v344();$f183.$v767();$f183.$v970()},register:function(k,h){b[k.id]=k;for(var j=0;j<e[k.id].length;j++){d.add((e[k.id])[j])}g[k.id]=h},$v475:function(){return d},$v224:function(j){var h='<script type="text/javascript" src="'+j+'"><\/script>';document.write(h)},$v767:function(){var h;if(b[0]){$v926.invoke(g[0])}},$v970:function(){var u,n,p,o,j,r,m,k,t,l,q,v,s,h;if(b[0]){}}};return f}();$f183.setup();