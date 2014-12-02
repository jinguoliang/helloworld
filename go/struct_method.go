/*
*filename:	struct_method.go
*author: 	Jinux
*create:	2014年11月30日 星期日 18时21分00秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

type rect struct {
	width, height int
}

//!!!!!!!!!没有public什么的，如果想在其他包中访问，大写首字母
//求面积
func (r *rect) area() int {
	return r.width * r.height
}

//求周长
func (r *rect) perimeter() int {
	return 2*(r.width + r.height)
}

func main() {
	r := rect{width: 10, height: 15}

	fmt.Println("面积: ", r.area())
	fmt.Println("周长: ", r.perimeter())

	rp := &r
	fmt.Println("面积: ", rp.area())
	fmt.Println("周长: ", rp.perimeter())
}

