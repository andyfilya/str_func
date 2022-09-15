CC = g++
CFLAGS = -c -Wall

all: strfunc

strfunc: main.o test.o func.o
	$(CC) main.o test.o func.o -o strfunc

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

func.o: func.cpp
	$(CC) $(CFLAGS) func.cpp
	
clean:
	rm -rf *.o strfunc