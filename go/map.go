/*
*filename:	map.go
*author: 	Jinux
*create:	2014年11月30日 星期日 02时32分32秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main() {
	m := make(map[string]int)

	m["one"] = 1
	m["two"] = 2
	m["three"] = 3

	fmt.Println(m)
	fmt.Println(len(m))

	v := m["two"]
	fmt.Println(v)

	delete(m, "two")
	fmt.Println(m)

	m1 := map[string]int{"one": 1, "two": 2, "three": 3}
	fmt.Println(m1)

	for key, val := range m1 {
		fmt.Printf("%s => %d \n", key, val)
	}
}

