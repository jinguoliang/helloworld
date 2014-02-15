/*
*filename:	[:VIM_TAG:]expand("%:t")[:END_VIM_TAG:]
*author: 	Jinux
*create:	[:VIM_TAG:]strftime('%c')[:END_VIM_TAG:]
*提示:	作为一个头文件,就应该是一个接口,暴露该暴露的,隐藏该隐藏的
*/

#ifndef __[:VIM_TAG:]substitute(toupper(expand("%:t")),"\\.","_","g")[:END_VIM_TAG:]__
#define __[:VIM_TAG:]substitute(toupper(expand("%:t")),"\\.","_","g")[:END_VIM_TAG:]__

#endif


