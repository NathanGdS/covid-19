covid19: covid19.o index.o
	gcc covid19.o index.o -o covid19

covid19.o: covid19.c covid19.h
	gcc -c covid19.c

index.o: index.c
	gcc -c index.c

clean:
	rm *.o covid19