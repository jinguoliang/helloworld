/*
*filename:	args.go
*author: 	Jinux
*create:	2014年11月30日 星期日 02时56分50秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main() {
	sum(2, 3, 5)
	sum(2, 3, 5, 8)
}

func sum(nums ...int) {
	total := 0
	for _, num := range nums {
		total += num
	}
	fmt.Printf("the sum is %d\n", total)
}
