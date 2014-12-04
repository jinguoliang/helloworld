/*
*filename:	web-app.go
*author: 	Jinux
*create:	2014年11月30日 星期日 22时49分09秒
*提示:		Go, 解释,编译,都可以,垃圾回收,并发,快,新语言,我要用它来做网站
*/

package main

import (
	"fmt"
	"net/http"
	"io/ioutil"
	"os"
	"path/filepath"
)

const http_root = "/var/www/"


func main() {
	http.HandleFunc("/", rootHandler)
	http.HandleFunc("/view/", viewHandler)
	http.HandleFunc("/html/", htmlHandler)

	http.ListenAndServe(":8080", nil)
}

func rootHandler(w http.ResponseWriter, r *http.Request){
	fmt.Fprintf(w, "rootHandler: %s\n", r.URL.Path)
	fmt.Fprintf(w, "URL: %s\n", r.URL)
	fmt.Fprintf(w, "Method: %s\n", r.Method)
	fmt.Fprintf(w, "RequestURI: %s\n", r.RequestURI)
	fmt.Fprintf(w, "HOST: %s\n", r.Host)
}

func viewHandler(w http.ResponseWriter, r *http.Request){
	fmt.Fprintf(w, "viewHandler: %s", r.URL.Path)
}

func htmlHandler(w http.ResponseWriter, r *http.Request){
	fmt.Printf("htmlHandler: %s\n", r.URL.Path)

	filename := http_root + r.URL.Path
	fileext := filepath.Ext(filename)
	fmt.Printf(filename)

	file,err := os.Lstat(filename)
	if err != nil{
		fmt.Fprintf(w," 404 Not Found!\n")
		w.WriteHeader(http.StatusNotFound)
		return
	}

	if file.IsDir() {
		println("this is a dir")
		w.Header().Set("Content-Type", "text/html")
		files, _ := ioutil.ReadDir(filename)
		fmt.Fprintf(w, "<html><head><title>hello world</title></head><body>")
		for _, f := range files {

			fmt.Fprintf(w, "<a href=\""+r.URL.Path+"/" + f.Name()+"\">"+f.Name()+"</a><br/>")
		}
		fmt.Fprintf(w, "</body>")
		return
	}

	content, err := ioutil.ReadFile(filename)
	if err != nil{
		fmt.Fprintf(w," 404 Not Found!\n")
		w.WriteHeader(http.StatusNotFound)
		return
	}

	var contype string
	switch fileext {
	case ".html", "htm":
		contype = "text/html"
	case ".css":
		contype = "text/css"
	case ".js":
		contype = "application/javascript"
	case ".png":
		contype = "image/png"
	case ".jpg",".jpeg":
		contype = "image/jpeg"
	case ".gif":
		contype = "image/gif"
	default:
		contype = "text/plain"
	}
	fmt.Printf("ext %s, ct = %s\n", fileext, contype)

	w.Header().Set("Content-Type", contype)
	fmt.Fprintf(w, "%s", content)
}

