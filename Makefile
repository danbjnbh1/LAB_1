all: count-words addresses base

build:
	mkdir -p build

build/count-words.o: count-words.c | build
	gcc -m32 -g -O0 -Wall -Wextra -c count-words.c -o build/count-words.o

build/addresses.o: addresses.c | build
	gcc -m32 -g -O0 -Wall -Wextra -c addresses.c -o build/addresses.o

build/base.o: base.c | build
	gcc -m32 -g -O0 -Wall -Wextra -c base.c -o build/base.o

count-words: build/count-words.o
	gcc -m32 -g -O0 -Wall -Wextra -o count-words build/count-words.o

addresses: build/addresses.o
	gcc -m32 -g -O0 -Wall -Wextra -o addresses build/addresses.o

base: build/base.o
	gcc -m32 -g -O0 -Wall -Wextra -o base build/base.o

clean:
	rm -f base count-words addresses build/*.o 

.PHONY: all clean