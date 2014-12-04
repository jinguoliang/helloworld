/*
*filename:	channel_block.go
*author: 	Jinux
*create:	2014年11月30日 星期日 22时05分05秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"
import "time"

func main() {
	channel := make(chan string)

	go func() {
		channel <- "hello"
		fmt.Println("write \"hello\" done")

		channel <- "world"
		fmt.Println("write \"world\" done")

		fmt.Println("write go sleep...")
		time.Sleep(3*time.Second)

		channel <- "channel"
		fmt.Println("write \"channel\" done")
	}()

	time.Sleep(2*time.Second)
	fmt.Println("Reader Wake up...")

	msg := <-channel
	fmt.Println("Reader: ", msg)
	msg = <-channel
	fmt.Println("Reader: ", msg)
	msg = <-channel
	fmt.Println("Reader: ", msg)
}

