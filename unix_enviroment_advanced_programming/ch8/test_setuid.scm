#! /usr/bin/guile
-s
!#

(define (show str) (begin (display str) (newline)))

(show (getuid))
(show (getuid))

