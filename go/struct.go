/*
*filename:	struct.go
*author: 	Jinux
*create:	2014年11月30日 星期日 18时16分51秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import "fmt"

type Person struct {
	name string
	age int
	email string
}

func main() {
	person := Person{"Tom", 30, "tom@gmail.com"}
	person = Person{name:"Tom", age: 30, email:"tom@gmail.com"}

	fmt.Println(person)

	pPerson := &person

	fmt.Println(pPerson)

	pPerson.age = 40
	person.name = "Jerrry"
	fmt.Println(person)

}

