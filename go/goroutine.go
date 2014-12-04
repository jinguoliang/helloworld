/*
*filename:	goroutine.go
*author: 	Jinux
*create:	2014年11月30日 星期日 21时08分54秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"
import "time"
import "runtime"
import "math/rand"

func routine(name string, delay time.Duration){
	t0 := time.Now()
	fmt.Println(name, " start at ", t0)

	time.Sleep(delay)

	t1 := time.Now()
	fmt.Println(name, " end at ", t1)

	fmt.Println(name, " lasted ", t1.Sub(t0))
}

func main() {

	runtime.GOMAXPROCS(4)

	rand.Seed(time.Now().Unix())

	var name string
	for i := 0; i<3; i++ {
		name = fmt.Sprintf("go %02d", i)
		go routine(name, time.Duration(rand.Intn(5)) * time.Second)
	}

	//让主进程暂停
	var input string
	fmt.Scanln(&input)
	fmt.Println("done")

}

