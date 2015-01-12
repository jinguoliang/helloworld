/*
*filename:	html-template.go
*author: 	Jinux
*create:	2014年12月04日 星期四 00时06分01秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/
package main

import (
	    "html/template"
		    "os"
		)
type Info struct{
		Username string
		MainPage string
}
func main() {
	t, _ := template.New("demo").Parse(
		`{{define "T"}}Hello, {{.Username}}! Main Page: [{{.MainPage}}]{{end}}`)
	args2 := Info{Username: "Hypermind", MainPage: "http://hypermind.com.cn/go"}
	_ = t.ExecuteTemplate(os.Stdout, "T", args2)
}
