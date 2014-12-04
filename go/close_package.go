/*
*filename:	close_package.go
*author: 	Jinux
*create:	2014年11月30日 星期日 03时01分09秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main() {
	nextNumFunc := nextNum()
	for i:=0; i<10; i++ {
		fmt.Println(nextNumFunc())
	}
}

func nextNum() func() int {
	i, j := 1, 1
	return func() int{
		var tmp = i + j
		i, j  = j, tmp
		return tmp
	}
}
