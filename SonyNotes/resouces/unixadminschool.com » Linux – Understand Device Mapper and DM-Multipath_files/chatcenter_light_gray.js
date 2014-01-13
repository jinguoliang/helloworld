/*
 * WINDOW STYLE TEMPLATE
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
 *	window_style_template:"window_blue_silver.js",
 * 
 * If you create a decent style template. Please email us the template at 
 * support@fastcatsoftware.com
 */

(function(){
	

FCChatConfig.styles={
	chat_window:{
		frame:{
			logo:"fastcatlogo.gif",
			color:"#666666",
			title_css:"font-size:12px;font-weight:bold;color:white;",
			opacity:.90
		},
		main_panel:{
			height:568,
			background_image:"", //"tc2.gif",
			background_color:"#cccccc",
			border:"1px solid #aaaaaa",
			opacity:1,
			send_to_room_button:{
				default_css:"background-color:#cfcfcf;border:1px solid #bcbcbc; border-bottom:1px solid #a9a9a9;padding:2px 67px; font:10px arial;-moz-border-radius: 2px;-webkit-border-radius: 2px;border-radius:2px;",
				single_button_css:"padding:5px 45px;font:14px arial;font-weight:bold;",
				states:{
					link_css:"color:#163663",
					hover_css:"color:white",
					disabled_css:"color:#aaaaaa;border:1px solid #acacac;background-color:#c3c3c3;"
				}
			},
			send_private_button:{
				default_css:"background-color:#cfcfcf;border:1px solid #bcbcbc; border-bottom:1px solid #a9a9a9;padding:2px 66px; font:10px arial;-moz-border-radius: 2px;-webkit-border-radius: 2px;border-radius:2px;",
				single_button_css:"padding:5px 45px;font:14px arial;font-weight:bold;",
				states:{
					link_css:"color:#163663",
					hover_css:"color:white",
					disabled_css:"color:#a0a0a0;border:1px solid #acacac;background-color:#c3c3c3;"
				}
			},
			other_buttons:{
				default_css:"background-color:#cfcfcf;border:1px solid #bcbcbc; border-bottom:1px solid #a9a9a9;padding:2px 8px; font:12px arial;-moz-border-radius: 2px;-webkit-border-radius: 2px;border-radius:2px;",
				states:{
					link_css:"color:#163663",
					hover_css:"color:white",
					disabled_css:"color:#aaaaaa;border:1px solid #acacac;background-color:#c3c3c3;"
				}
			},
			widgets:{
				border:{
					link_css:"border:1px solid #999999",
					hover_css:"border:1px solid lightblue"
				},
				text_icon_css:"background-color:#aaaaaa",
				more_icon_css:"color:white;font-stretch:wider;font-size:10px;font-weight:bold;text-decoration:none"
			},
			text:{
				font:{
					family:"arial",
					color:"#444444",
					size:12,
					weight:700
				}
			},
			links:{
				css:"font-family:arial;font-size:12px;font-weight:700;color:#448844;text-decoration:none;"
			},
			chat_panels:{
				chat_room_panel:{
					background_image:"chat_window_light_background.jpg",
					background_color:"#ffffff",
					border:"2px solid #a1a1a1",
					css:{opacity:.65,"box-shadow":"inset 5px 5px 10px 0px rgba(0,0,0,0.2)","-webkit-box-shadow": "inset 5px 5px 10px 0px rgba(0,0,0,0.2)"},
					infobox:{
						border:"4px solid silver",
						triangle_color:"silver"
					}
				},
				private_chat_panel:{
					background_image:"private_chat_light_background.jpg",
					msgcenter_background_image:"chat_window_light_background.jpg",
					background_color:"#f6f6f6",
					border:"2px solid #a1a1a1",
					css:{opacity:.65,"box-shadow":"inset 5px 5px 10px 0px rgba(0,0,0,0.2)","-webkit-box-shadow": "inset 5px 5px 10px 0px rgba(0,0,0,0.2)"}
				},
				user_icon:{
					online_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:#44FD64;border:1px solid white",
					offline_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:transparent;border:1px solid #aaaaaa",
					busy_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:yellow;border:1px solid white",
					blocked_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:#FF8380;border:1px solid white"
				},
				font:{
					family:"arial",
					size:9,
					timestamp_size:8,
					weight:500,
					color:{
						default_text_color:"#444444",
						timestamp_color:"green",
						link_color:"#528DC4",
						censored_color:"red",
						offline_css:"color:green"
					},
					screen_name_states:{
						online:{
							link_css:"color:#528DC4;",
							visited_css:"color:purple;",
							hover_css:"color:darkblue;",
							blocked:{
								link_css:"color:red;",
								visited_css:"color:red;",
								hover_css:"color:#FFB6C1;"
							}
						},
						offline:{
							link_css:"color:#528DC4;text-decoration:none;",
							visited_css:"color:purple;text-decoration:none;",
							hover_css:"color:#darkblue;text-decoration:none;",
							blocked:{
								link_css:"color:red;text-decoration:none;",
								visited_css:"color:red;text-decoration:none;",
								hover_css:"color:#FFB6C1;text-decoration:none;"
							}
						}
					}
				}
			},
			side_panels:{
				background_color:"#DaDfE8",
				border:"2px solid #a0a0a0",
				opacity:.7,
				screen_name_dividers:{
					background_color:"transparent",
					hover_color:"#f3f3f3",
					border:"1px solid #cccccc"
				},
				room_display_panel:{
					background_color:"transparent",
					divider:"0px solid gray",
					text_css:"font-family:arial;font-size:8pt;font-weight:500;color:#204096;"
				},
				private_group_panel:{
					selected_user:{
						background_color:"#e6e9f0",
						arrow:{
							color:"green",
							hover_color:"red"
						}
					}
				},
				user_icon:{
					online_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:#54FD74;border:1px solid white",
					offline_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:transparent;border:1px solid#aaaaaa",
					busy_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:yellow;border:1px solid white",
					blocked_css:"-moz-border-radius: 4px;-webkit-border-radius: 4px;border-radius:4px;background-color:#FF8380;border:1px solid white"
				},	
				profile_star:{
					css:"font-size:16px;font-family:courier;font-weight:bold;color:yellow;"
				},
				font:{
					family:"arial",
					size:8,
					weight:500,
					style:{
						user_info_css:"color:#888888",
						mod_css:"color:#777777",
						title_css:"color:#294975"
					},
					screen_name_states:{
						online:{
							link_css:"color:#444444;text-decoration:none;",
							visited_css:"color:#FDF5E6;text-decoration:none;",
							hover_css:"color:lightblue;text-decoration:none;",
							blocked:{
								link_css:"color:#CC0000;text-decoration:none;",
								visited_css:"color:red;text-decoration:none;",
								hover_css:"color:#DF96A1;text-decoration:none;"
							}
						},
						offline:{
							link_css:"color:#444444;text-decoration:none;",
							visited_css:"color:#B0E0E6;text-decoration:none;",
							hover_css:"color:#ADD8E6;text-decoration:none;",
							blocked:{
								link_css:"color:#CC0000;text-decoration:none;",
								visited_css:"color:red;text-decoration:none;",
								hover_css:"color:#DF96A1;text-decoration:none;"
							}
						}
					}
				}
			},
			send_chat_panel:{
				width_offset:-1,
				height:30,
				css:"font-size:9pt;font-family:arial;color:black;background-color:#f3f3f3;border:1px solid #aaaaaa;"
			},
			send_to_panel:{
				css:"background-color:#d3d3d3;padding-top:1px;padding-bottom:0px;border:1px solid gray;box-shadow: 0px 5px 9px #bbbbbb inset;-moz-box-shadow: 0px 5px 9px #bbbbbb inset;-webkit-box-shadow: 0px 5px 9px #bbbbbb inset;",
				text_css:"font:12px arial;color:#444444",
				remove_button_css:"padding:0px 4px 0px 4px;color: red; font-size: 8pt; font-weight: bold; font-stretch:wider;text-decoration: none;text-align:top;text-decoration:none"
			},
			user_pop_up_panel:{
				border:"1px solid silver",
				background_color:"#444444",
				opacity:.8,
				font:{
					screen_name_css:"font-weight:bold;font-size:9pt;color:lightblue;font-style:italic;",
					links_css:"font-family:arial;font-size:9pt;color:white;",
					functions_css:"font-family:arial;color:lightblue;font-size:9pt;",
					smalltext_css:"font-family:arial;color:white;font-size:7pt;"
				},
				dividing_line:"1px solid gray",
				widgets:{
					border:{
						link_css:"border:1px solid #666666",
						hover_css:"border:1px solid lightblue"
					}
				},
				send_chat_panel:{
					css:"font-size:9pt;font-family:arial;color:black;background-color:#aaaaaa;border:1px solid silver;"
				},
				send_private_button:{
					default_css:"border:1px solid silver; padding:2px 12px 2px 11px; font:10px arial;",
					states:{
						link_css:"color:white",
						hover_css:"color:lightblue",
						disabled_css:"color:#bbbbbb;border:1px solid #bbbbbb;"
					}
				}
			},
			options_panel:{
				outer_border:"1px solid #444444",
				inner_border:"1px solid silver",
				background_color:"gray",
				panel_font_css: "color:lightblue;font-family:arial;font-weight:bold;font-style:italic;font-size:12px",
				infobox:{
					font_css:"color:white;font-size:12px;text-decoration:none",
					border:"4px solid silver",
					triangle_color:"silver"
				},
				functions:{
					font_css:"color:white;font-size:12px;text-decoration:none",
					border:"1px solid silver"
				},
				selectors:{
					border:"3px solid silver",
					background_color:"#aaaaaa",
					hover_color:"#b0b0b0",
					selected_color:"#aaaa77",
					font_css:"color:#333333;font-family:arial;font-weight:normal;font-size:10px",
					separator:"1px solid silver"
				},
				//the corresponding language names are in the language template
				translation_selector:{
					css:"margin-left:20px;border:4px solid lightblue;-moz-border-radius:5px;-webkit-border-radius:5px;border-radius:5px;",
					language_codes:["_off","ar","bg","ca","zh-CHS","zh-CHT","cs","da","nl","en","et","fi","fr","de","el","ht","he","hu","id","it","ja","ko","lv","lt","no","pl","pt","ro","ru","sk","sl","es","sv","th","tr","uk","vi"]
				},
				font_size_selector:{
					smallest:6,
					largest:16
				},
				//the corresponding color names are in the language template
				color_selector:{
					color_values:["#444444","black","blue","red","purple","green","yellow","orange","white"]
				},
				remove_block_button:{
					default_css:"border:1px solid silver; padding:2px 12px 2px 11px; font:10px arial;",
					states:{
						link_css:"color:white",
						hover_css:"color:lightblue",
						disabled_css:"color:#bbbbbb;border:1px solid #bbbbbb;"
					}
				}
			},
			tools_panel:{
				border:"1px solid #444444",
				background_color:"gray",
				smileys:{
					width:250,
					height:200
				},
				icons:{
					width:250,
					height:25
				}
			},
			chatrooms_panel:{
				selected_color:"lightblue",
				hover_color:"#dddddd",
				background_color:"transparent",
				horizontal_rule:"font-weight:bold;font-size:16px;border-bottom:2px solid silver;",
				separator:"1px solid silver;",
				room_name_font_css:"font-size:14px;font-weight:bold;color:#444444;",
				font_css:"color:#444444;font-family:arial;font-weight:normal;font-size:12px;",
				count_font_css:"font-size:14px;color:blue;font-weight:bold;",
				disabled_room_name_font_css:"font-size:14px;font-weight:bold;color:#8888aa;",
				exit_room_link_disabled_css:"color:#eeeeee;",
				room_passwords:{
					font:{
						textfield_description_css:"font-family:arial;font-size:12px;color:darkgray;font-style:italic;font-weight:bold;"
					},
					textfield_css:"background-color:white;border:1px solid lightblue;padding:5px;color:#444444"
				}
			},
			info_panel:{
				background_color:"transparent",
				font_css:"color:#444444",
				screen_name_css:"font-family:arial;font-size:10pt;color:green;font-weight:700;text-decoration:none;",
				list_divider_css:"border-bottom:1px solid #dddddd;"
			},
			login_panel:{
				box_shadow:"0px 0px 12px 2px rgba(0,0,0,0.5)",
				background_color:"#eeeeee",
				border:"2px solid #666666",
				font:{
					textfield_description_css:{"font-family":"arial","font-size":"10pt",color:"black","font-style":"italic","font-weight":"bold"},
					smalltext_css:{"margin-right":"10px","font-family":"arial","font-size":"8pt",color:"black"}
				},
				textfield_css:"background-color:#dddddd !important;color:#444444 !important;width:120px !important;height:18px !important;"
			},
			edit_room_panel:{
				font:{
					title_css:"font-style:italic;font-weight:bold;margin-right:10px;font-family:arial;font-size:14px;color:darkblue;",
					textfield_description_css:"font-family:arial;font-size:12px;color:#888888;font-style:italic;font-weight:bold;",
					smalltext_css:"font-style:italic;font-weight:bold;margin-right:10px;font-family:arial;font-size:10px;color:darkgray;"
				},
				textfield_css:"background-color:white;border:1px solid lightblue;padding:5px;color:#444444"
			},
			alert_panel:{
				background_color:"#dddddd",
				border:"1px solid black",
				font:{
					text_css:"margin-right:10px;font-family:arial;font-size:9pt;color:black;"
				}
			}
		}
	},
	split_screen:{
		background_color:"lightgray"
	}
};

function applyQuickStyles(){
	var c = FCChatConfig.quickstyling;
	if(window["fcchat_domain"]&&c[window["fcchat_domain"]]){
			c = c[window["fcchat_domain"]];
	}else{
			c = c.alldomains;
	}
	c=c.application_window;
	var s = "FCChatConfig.styles.chat_window.frame";
	var x = jGo.util.mergeOption;
	if(c.frame_color!="")jGo.util.setOption(s+".color",c.frame_color);
	x(s+".title_css",c.title_css);
	
};
applyQuickStyles();

}());
