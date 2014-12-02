/*
*filename:	pointer.go
*author: 	Jinux
*create:	2014年11月30日 星期日 02时42分18秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main(){
	var i int = 1
	var pInt *int = &i
	fmt.Printf("i=%d\tpInt=%p\t*pInt=%d\n",i,pInt,*pInt)
	*pInt = 2
	fmt.Printf("i=%d\tpInt=%p\t*pInt=%d\n",i,pInt,*pInt)
	i = 3
	fmt.Printf("i=%d\tpInt=%p\t*pInt=%d\n",i,pInt,*pInt)
}

