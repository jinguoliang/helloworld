/*
*filename:	Defer.go
*author: 	Jinux
*create:	2014年11月30日 星期日 18时57分53秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "os"
import "io"
import "fmt"


func CopyFile(dstName, srcName string) (written int64, err error) {
	src, err := os.Open(srcName)
	if err != nil {
		fmt.Println("src error")
		return -1, err
	}
	defer src.Close()

	dst, err := os.Create(dstName)
	if err != nil {
		fmt.Println("dst error")
		return -1, err
	}
	defer dst.Close()

	return io.Copy(dst, src)
}

func main() {
	written,err := CopyFile("/tmp/Defer.go", "/home/jinux/Learning/go/Defer.go")
	fmt.Println("written ", written)
	if err != nil {
		fmt.Println("err ", err)
	}

	for i := 0; i < 5; i++ {
		defer fmt.Printf("%d \n", i)
	}
}

