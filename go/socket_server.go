/*
*filename:	socket_server.go
*author: 	Jinux
*create:	2014年11月30日 星期日 22时23分55秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import (
	"fmt"
	"net"
	"io"
)

const RECV_BUF_LEN = 1024

func main() {
	listener, err := net.Listen("tcp", "0.0.0.0:6666")
	if err != nil {
		panic("error listening:" + err.Error())
	}
	fmt.Println("Starting the server")

	for {
		conn, err  := listener.Accept()
		if err != nil {
			panic("Error accept:" + err.Error())
		}
		fmt.Println("Accepted the Connection :", conn.RemoteAddr())
		go EchoServer(conn)
	}
}

func EchoServer(conn net.Conn) {
	buf := make([]byte, RECV_BUF_LEN)
	defer conn.Close()

	for {
		n, err := conn.Read(buf)
		switch err {
		case nil:
			conn.Write(buf[0:n])
		case io.EOF:
			fmt.Printf("Warning: End of data: %s \n", err)
			return
		default:
			fmt.Printf("Error: Reading data: %s\n",err)
			return
		}
	}
}

