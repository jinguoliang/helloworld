/*
*filename:	interface.go
*author: 	Jinux
*create:	2014年11月30日 星期日 18时31分44秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"
import "math"

//--------------- 借口 ---------------//
type shape interface {
	area() float64
	perimeter() float64
}

//--------------- 长方形 -------------//
type rect struct {
	width, height float64
}

func (r *rect) area() float64 {
	return r.width * r.height
}

func (r *rect) perimeter() float64 {
	return 2*(r.width + r.height)
}

//--------------- 圆形 --------------//
type circle struct {
	radius float64
}

func (c *circle) area() float64 {
	return math.Pi * c.radius * c.radius
}

func (c *circle) perimeter() float64{
	return  2*math.Pi * c.radius
}

//--------------- 接口使用 --------------//
func interface_test() {
	r := rect{width:2.9, height:4.9}
	c := circle{radius:4.3}

	s := []shape{&r, &c}

	for _, sh := range s {
		fmt.Println(sh)
		fmt.Println(sh.area())
		fmt.Println(sh.perimeter())
	}
}


func main() {
	interface_test()
}

