/*
*filename:	recursivce.go
*author: 	Jinux
*create:	2014年11月30日 星期日 18时12分35秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main() {
	fmt.Println(fact(7))
}

func fact(n int) int {
	if n == 0 {
		return 1
	}
	return n * fact(n-1)
}
