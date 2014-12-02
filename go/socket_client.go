/*
*filename:	socket_client.go
*author: 	Jinux
*create:	2014年11月30日 星期日 22时32分01秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import (
	"fmt"
	"time"
	"net"
)

const RECV_BUF_LEN = 1024

func main() {
	conn,err := net.Dial("tcp", "127.0.0.1:6666")
	if err != nil {
		panic(err.Error())
	}
	defer conn.Close()

	buf := make([]byte, RECV_BUF_LEN)

	for i := 0; i<5; i++{
		msg := fmt.Sprintf("Hello World, %03d", i)
		n, err := conn.Write([]byte(msg))
		if err != nil {
			println("Write Buffer Error:", err.Error())
			break
		}
		println(msg)

		n,err = conn.Read(buf)
		if err != nil {
			println("Read Buffer Error:", err.Error())
			break
		}
		println(string(buf[0:n]))

		time.Sleep(time.Second)
	}

}

