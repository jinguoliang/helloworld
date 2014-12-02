/*
*filename:	concurrency.go
*author: 	Jinux
*create:	2014年11月30日 星期日 21时42分41秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"
import "time"
import "math/rand"
import "runtime"
import "sync"

var total_tickets int32 = 10
var mutex = &sync.Mutex{}

func sell_tickets(i int){
	for{
		mutex.Lock()
		if total_tickets > 0 {
			time.Sleep(time.Duration(rand.Intn(5)) * time.Millisecond)
			total_tickets--
			fmt.Println("id:", i, " ticket:", total_tickets)
		}
		mutex.Unlock()
	}
}


func main() {

	runtime.GOMAXPROCS(4)
	rand.Seed(time.Now().Unix())

	for i := 0; i<5; i++ {
		go sell_tickets(i)
	}

	var input string
	fmt.Scanln(&input)
	fmt.Println(total_tickets, "done")

}

