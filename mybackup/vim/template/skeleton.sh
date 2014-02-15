#!/bin/bash

#filename:	[:VIM_TAG:]expand("%:t")[:END_VIM_TAG:]
#author: 	Jinux
#create:	[:VIM_TAG:]strftime('%c')[:END_VIM_TAG:]
#提示:		脚本是是我们工作便利的工具，短小的脚本，减少重复，让一切自动化

#判断参数个数，提示用法
USAGE=""
if [ $# != "" ] ;then
	echo "usage: $0 $USAGE"
	exit 0
fi


