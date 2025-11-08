all: count-words addresses

build:
	mkdir -p build

build/count-words.o: count-words.c | build
	gcc -m32 -g -O0 -Wall -Wextra -c count-words.c -o build/count-words.o

build/addresses.o: addresses.c | build
	gcc -m32 -g -O0 -Wall -Wextra -c addresses.c -o build/addresses.o

count-words: build/count-words.o
	gcc -m32 -g -O0 -Wall -Wextra -o count-words build/count-words.o

addresses: build/addresses.o
	gcc -m32 -g -O0 -Wall -Wextra -o addresses build/addresses.o

clean:
	rm -f count-words addresses build/*.o

.PHONY: all clean