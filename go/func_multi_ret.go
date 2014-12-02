/*
*filename:	func_multi_ret.go
*author: 	Jinux
*create:	2014年11月30日 星期日 02时53分34秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main() {
	var key, len = multi_ret("hello world")

	fmt.Println(key,len)

}

func multi_ret(key string) (string, int) {
	return key, len(key)
}
