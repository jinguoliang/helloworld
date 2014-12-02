/*
*filename:	timer.go
*author: 	Jinux
*create:	2014年11月30日 星期日 22时20分08秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"
import "time"

func main() {

	ticker := time.NewTicker(time.Second)

	go func() {
		for t := range ticker.C {
			fmt.Println(t)
		}
	}()

	time := time.NewTimer(5*time.Second)
	<-time.C

	ticker.Stop()

	fmt.Println("timer expired!")

}

