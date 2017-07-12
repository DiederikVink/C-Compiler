#!/bin/bash

bin/c_compiler: c_parser.tab.o lex.yy.o
	g++ -std=c++11 -o bin/c_compiler c_parser.tab.o lex.yy.o
	
lex.yy.o: lex.yy.c c_parser.tab.h
	g++ -std=c++11 -c lex.yy.c
	
c_parser.tab.o: c_parser.tab.c c_parser.tab.h
	g++ -std=c++11 -c c_parser.tab.c

c_parser.tab.h: src/c_parser.y
	bison -d src/c_parser.y

c_parser.tab.c: src/c_parser.y
	bison -d src/c_parser.y
	
lex.yy.c: src/c_parser.l
	flex src/c_parser.l 
	
test: bin/c_compiler
	cat test/deetz_test_$(num).c | ./bin/c_codegen 1> test/test.s 2> test/output.txt
	less test/test.s

test_out: bin/c_compiler
	./tests.sh

clear: c_parser.tab.o lex.yy.o
	clear
	clear
	g++ -o bin/c_parser c_parser.tab.o lex.yy.o
	clear
	cat test/test11.c | ./bin/c_parser > test/output.txt
	vim test/output.txt

clean:
	rm -f lex.yy.c c_parser.tab.h c_parser.tab.c *.o bin/c_parser

cleanup:
	rm -f lex.yy.c c_parser.tab.h c_parser.tab.c *.o
