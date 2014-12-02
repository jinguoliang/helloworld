/*
*filename:	array.go
*author: 	Jinux
*create:	2014年11月30日 星期日 02时19分42秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main() {
	var a [5]int
	fmt.Println("array a:", a)

	a[1] = 10
	a[3] = 2014
	fmt.Println("array a:", a)

	fmt.Println("array len:", len(a))

	b := [5]int{1,2,3,4,5}
	fmt.Println("array b:", b)

	var c [2][3]int
	for i := 0; i < 2; i++ {
		for j :=0; j < 3; j++ {
			c[i][j] = i + j
		}
	}
	fmt.Println("2d: ", c)

	//数组的切片
	d := b[2:4]
	fmt.Println(d)
	d = b[:4]
	fmt.Println(d)
	d = b[2:]
	fmt.Println(d)

}
