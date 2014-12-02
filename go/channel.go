/*
*filename:	channel.go
*author: 	Jinux
*create:	2014年11月30日 星期日 21时56分45秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

func main() {
	//创建一个string类型的channel
	channel := make(chan string)
	channel1 := make(chan int)

	//在goroutine向channel里发一个字符串
	go func() { 
		channel <- "hello" 
		channel <- "hello" 
	}()
	go func() { channel1 <- 1 }()

	msg := <- channel
	msg = msg + <- channel
	fmt.Println(msg,<-channel1)
}

