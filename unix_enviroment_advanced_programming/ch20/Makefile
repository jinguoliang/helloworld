FLAGS=-I./include/ -Wall -g#-fPIC
CC=gcc

test: testdb
	./testdb

testdb: test_db.o libourhdr_db.a
	${CC} -o $@ $^

test_db.o: test_db.c
	${CC} -o $@ -c $< ${FLAGS} 


#static lib
libourhdr_db.a: db.o stderr.o filelock.o
	ar rsv $@ $^

#shared lib
libourhdr_db.so.1: db.o
	${CC} -shared -Wl,-soname,libourhdr_db.so.1 -o libourhdr_db.so.1 db.o 



db.o: db.c include/ourhdr.h include/ourhdr_db.h
	${CC} -o $@ -c $< ${FLAGS} 

stderr.o: stderr.c include/ourhdr.h
	${CC} -o $@ -c $< ${FLAGS} 

filelock.o: filelock.c include/ourhdr.h
	${CC} -o $@ -c $< ${FLAGS} 

clean:
	rm *.o *.a *.so.* 
