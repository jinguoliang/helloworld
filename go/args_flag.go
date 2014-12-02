/*
*filename:	args_flag.go
*author: 	Jinux
*create:	2014年11月30日 星期日 22时45分06秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"
import "flag"

func main() {

	host := flag.String("host", "coolshell.cn", "a host name")
	port := flag.Int("port", 80, "a port number")
	debug := flag.Bool("d", false, "enable/disable debug mode")

	flag.Parse()

	fmt.Println("host:", *host)
	fmt.Println("port:", *port)
	fmt.Println("debug:", *debug)

}

