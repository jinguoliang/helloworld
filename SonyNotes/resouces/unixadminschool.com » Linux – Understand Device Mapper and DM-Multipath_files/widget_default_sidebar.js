/*
 * WIDGET STYLE TEMPLATE
 *
 * This file controls aspects of FCChat's layout and appearance.
 * 
 * In this file comments are preceded by double slashes ie.
 *      //THIS IS A COMMENT
 *      
 * Refer to the product manual for info regarding how to effectively make changes to the
 * style template:
 * 
 * http://www.fastcatsoftware.com/chat/manual.htmk
 * 
 * To use this template, edit FCChat/config/config.js as follows:
 * 
 *  //STYLE
 *	widget_style_template:"widget_default_sidebar.js",
 * 
 * If you create a decent style template. Please email us the template at 
 * support@fastcatsoftware.com
 */
(function(){

var widget_base_font = "font-family:arial;font-size:12px;color:#444444;";
var toolbar_base_font = jGo.fcchat_toolbar.style.text;

FCChatConfig.styles.widget={
	control:{
		top:0, //for absolute positioning
		left:310, //"     "
		width:190,
		height:180,
		align_dialogs:true,
		css:"background-color:#eeeeee;-moz-border-radius: 5px;-webkit-border-radius: 5px;border-radius:5px;",
		logo:{
			top:10,
			left:10,
			css:""
		},
		title_box:{
			top:7,
			left:30,
			width:160,
			height:27,
			css:"background-color:transparent;",
			text:{
				css:widget_base_font+";font-weight:bold;font-size:13px;color:#777777;"
			}
		},
		status:{
			css:""
		},
		buttons:{
			top:35,
			left:10,
			width:180,
			height:30,
			default_css:widget_base_font+";text-decoration:none;",
			states:{
				link_css:"color:rgb(22, 125, 200);",
				hover_css:"color:darkblue;",
				disabled_css:"color:#aaaaaa;"
			},
			full_page_button:{
				css:""
			},
			on_off_button:{
				css:"margin-left:40px;"
			}
		},
		info_box:{
			top:65,
			left:10,
			width:180,
			height:120,
			css:"background-color:transparent;",
			linebreak:"<br>",
			text:{
				css:widget_base_font,
				alert_css:widget_base_font+"font-weight:bold;color:green;",
				info_css:widget_base_font+"color:#444444;"
			}
		}	
    },
	toolbar_item:{
		text:{
			css:toolbar_base_font+"color:white;",
			alert_css:toolbar_base_font+"color:pink;",
			link_css:toolbar_base_font+"color:white;",
			info_css:toolbar_base_font+"color:#BFEFFF;"
		},
		buttons:{
			default_css:toolbar_base_font+"text-decoration:none;",
			states:{
				link_css:"color:white;",
				hover_css:"color:yellow;",
				disabled_css:"color:lightgray;"
			}
		},
		chatcenter_layout:{
			width:610,
			info_box:{
				width:420,
				css:"height:35px;left:10px;top:0px;",
				padding_top:11
			},
			open_chat_button:{
				top:10,
				left:465
			},
			off_button:{
				top:10,
				left:560
			},
			status:{
				top:15,
				left:438,
				css:""
			},
			divider:{
				top:0,
				left:455,
				css:"width:1px;height:35px;background-color:#aaaaaa;"
			}
		},
		msgcenter_layout:{
			width:490,
			info_box:{
				width:300,
				css:"height:30px;left:10px;top:0px;",
				padding_top:11
			},
			open_chat_button:{
				top:10,
				left:345
			},
			off_button:{
				top:10,
				left:440
			},
			status:{
				top:15,
				left:318,
				css:""
			},
			divider:{
				top:0,
				left:335,
				css:"width:1px;height:30px;background-color:#aaaaaa;"
			}
		}
	},
	online_box:{
		top:0,
		left:0,
		toolbar_offset:3,
		width:230,
		height:343,
		css:jGo.fcchat_toolbar.style.dialog_box.css,
		title_box_css:jGo.fcchat_toolbar.style.dialog_box.title_box_css,
		greeting_box_css:"top:40px;left:0px;height:53px;background-color:#dddddd;",
		greeting_box_link:jGo.fcchat_toolbar.style.dialog_box.text.secondary_link_css,
		list_box_css:"top:93px;left:0px;height:180px;",
		list_divider_css:jGo.fcchat_toolbar.style.dialog_box.list_divider_css,
		info_box_css:"top:273px;left:0px;height:70px;background-color:#dddddd;",
		text:jGo.fcchat_toolbar.style.dialog_box.text
	},
	new_messages_box:{
		top:0,
		left:0,
		toolbar_offset:3,
		width:300,
		height:343,
		css:jGo.fcchat_toolbar.style.dialog_box.css,
		title_box_css:jGo.fcchat_toolbar.style.dialog_box.title_box_css,
		greeting_box_css:"top:40px;left:0px;height:53px;background-color:#dddddd;",
		greeting_box_link:jGo.fcchat_toolbar.style.dialog_box.text.secondary_link_css,
		view_msg_box_css:"top:93px;left:0px;height:180px;",
		send_msg_box_css:"top:273px;left:0px;height:70px;background-color:#dddddd;",
		input_css:"height:18px !important;background-color:white !important;border:1px solid silver !important;margin-left:2px !important;color:#44444 !important;",
		text:jGo.fcchat_toolbar.style.dialog_box.text
	},
	friends_box:{
		top:0,
		left:0,
		toolbar_offset:3,
		width:230,
		height:343,
		css:jGo.fcchat_toolbar.style.dialog_box.css,
		title_box_css:jGo.fcchat_toolbar.style.dialog_box.title_box_css,
		list_box_css:"top:40px;left:0px;height:233px;",
		list_divider_css:jGo.fcchat_toolbar.style.dialog_box.list_divider_css,
		info_box_css:"top:273px;left:0px;height:70px;background-color:#dddddd;",
		text:jGo.fcchat_toolbar.style.dialog_box.text
	},
	chatrooms_box:{
		top:0,
		left:0,
		width:400,
		height:343,
		css:jGo.fcchat_toolbar.style.dialog_box.css,
		title_box_css:jGo.fcchat_toolbar.style.dialog_box.title_box_css,
		list_box_css:"top:93px;left:0px;height:180px;",
		text:jGo.fcchat_toolbar.style.dialog_box.text,
		selected_color:"lightblue",
		hover_color:"#dddddd",
		background_color:"transparent",
		separator:"1px solid #dddddd",
		room_name_font_css:"font-size:14px;font-weight:bold;color:#444444;",
		font_css:"color:#444444;font-family:arial;font-weight:normal;font-size:12px;",
		count_font_css:"font-size:14px;color:blue;font-weight:bold;",
		disabled_room_name_font_css:"font-size:14px;font-weight:bold;color:#8888aa;",
		room_passwords:{
			font:{
				textfield_description_css:"font-family:arial;font-size:12px;color:#darkgray;font-style:italic;font-weight:bold;"
			},
			textfield_css:"background-color:white;border:1px solid #444444;padding:5px;color:#444444"
		}
	},
	login_panel:{
		top:0,
		left:0,
		box_shadow:"0px 0px 12px 2px rgba(0,0,0,0.5)",
		background_color:"#eeeeee",
		border:"2px solid gray",
		font:{
			textfield_description_css:{"font-family":"arial","font-size":"10pt",color:"black","font-style":"italic","font-weight":"bold"},
			smalltext_css:{"margin-right":"10px","font-family":"arial","font-size":"8pt",color:"black"}
		},
		textfield_css:"background-color:#dddddd !important;color:#444444 !important;width:120px !important;height:18px !important;"
	}
};

function applyQuickStyles(){
	var d = FCChatConfig.quickstyling;
	var c;
	var s = "FCChatConfig.styles.widget.control";
	var x = jGo.util.mergeOption;
	if(!window["fcchat_domain"]){
		c=d.alldomains.widget;
		var h = c.height_prop_offsets.split(':');
		h[0]-=0;
		h[1]-=0;
		h[2]-=0;
		x(s+".css",c.background_css);
		x(s+".width",c.width_offset);
		x(s+".height",h[0]+h[1]+h[2]);
		x(s+".logo.top",c.logo_top_offset);
		x(s+".logo.left",c.logo_left_offset);
		x(s+".logo.css",c.logo_css);
		x(s+".title_box.width",c.width_offset);
		x(s+".title_box.height",h[0]);
		x(s+".title_box.css",c.title_css);
		x(s+".title_box.text.css",c.base_font_css+c.title_font_css);
		x(s+".buttons.top",h[0]);
		x(s+".buttons.width",c.width_offset);
		x(s+".buttons.height",h[1]);
		x(s+".buttons.default_css",c.base_font_css);
		x(s+".buttons.states.link_css",c.link_css);
		x(s+".buttons.states.hover_css",c.link_hover_css);
		x(s+".buttons.states.disabled_css",c.link_disabled_css);
		x(s+".buttons.full_page_button.css",c.full_page_button_css);
		x(s+".buttons.on_off_button.css",c.off_button_css);
		x(s+".info_box.top",h[0]+h[1]);
		x(s+".info_box.width",c.width_offset);
		x(s+".info_box.height",h[2]);
		x(s+".info_box.css",c.infobox_css);
		x(s+".info_box.text.css",c.base_font_css);
		x(s+".info_box.text.alert_css",c.base_font_css+c.alert_css);
		x(s+".info_box.text.link_css",c.base_font_css+c.link_css);
		x(s+".info_box.text.info_css",c.base_font_css+c.info_css);
	}
	if(window["fcchat_domain"]&&d[window["fcchat_domain"]]){
		c = d[window["fcchat_domain"]];
	}else{
		c = d.alldomains;
	}
	c = c.toolbar;
	s = "FCChatConfig.styles.widget.toolbar_item";
	var w = c.width_prop_offsets.split(':');
	
	w[0]-=0;
	w[1]-=0;
	w[2]-=0;
	x(s+".text.css",c.base_font_css);
	x(s+".text.link_css",c.base_font_css+c.link_css);
	x(s+".text.alert_css",c.base_font_css+c.alert_css);
	x(s+".text.info_css",c.base_font_css+c.info_css);
	x(s+".buttons.default_css",c.base_font_css);
	x(s+".buttons.states.link_css",c.link_css);
	x(s+".buttons.states.hover_css",c.link_hover_css);
	x(s+".buttons.states.disabled_css",c.link_disabled_css);
	x(s+".chatcenter_layout.info_box.padding_top",c.text_top_offset);
	x(s+".chatcenter_layout.open_chat_button.top",c.text_top_offset);
	x(s+".chatcenter_layout.off_button.top",c.text_top_offset);
	x(s+".msgcenter_layout.info_box.padding_top",c.text_top_offset);
	x(s+".msgcenter_layout.open_chat_button.top",c.text_top_offset);
	x(s+".msgcenter_layout.off_button.top",c.text_top_offset);
	x(s+".chatcenter_layout.width",w[0]+w[1]);
	x(s+".msgcenter_layout.width",w[0]+w[1]);
	x(s+".chatcenter_layout.info_box.width",w[0]);
	x(s+".msgcenter_layout.info_box.width",w[0]);
	x(s+".chatcenter_layout.open_chat_button.left",w[0]);
	x(s+".msgcenter_layout.open_chat_button.left",w[0]);
	x(s+".chatcenter_layout.off_button.left",w[0]+(c.off_button_left_offset||0));
	x(s+".msgcenter_layout.off_button.left",w[0]+(c.off_button_left_offset||0));
	x(s+".chatcenter_layout.status.left",w[0]);
	x(s+".msgcenter_layout.status.left",w[0]);
	x(s+".chatcenter_layout.divider.left",w[0]);
	x(s+".msgcenter_layout.divider.left",w[0]);
	x(s+".chatcenter_layout.divider.css",c.divider_css);
	x(s+".msgcenter_layout.divider.css",c.divider_css);
	
}
		
applyQuickStyles();	

})();
