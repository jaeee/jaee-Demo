#.PHONY:all
#all:semtest sem
	
semtest:semtest.c sem.c sem.h
	gcc -o $@ $^

#sem:sem.c
#	gcc -o $@ $^
	
.PHONY:clean
clean:
	rm -f sem semtest
