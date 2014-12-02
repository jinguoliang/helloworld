/*
*filename:	Panic_Recover.go
*author: 	Jinux
*create:	2014年11月30日 星期日 19时19分45秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func g(i int) {
	if i > 1 {
		fmt.Println("Panic!")
		panic(fmt.Sprintf("%v", i))
	}
}

func f() {
	defer func() {
		if r := recover(); r != nil {
			fmt.Println("Recovered in f", r)
		}
	}()

	for i := 0; i < 4; i++ {
		fmt.Println("Calling g with ", i)
		g(i)
		fmt.Println("Returned normally from g.")
	}
}
func main() {
	f()
	fmt.Println("Returned normally form f.")

}

