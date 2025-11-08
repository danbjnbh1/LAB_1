all: menu_map

build:
	mkdir -p build

build/menu_map.o: menu_map.c | build
	gcc -m32 -g -O0 -Wall -Wextra -c menu_map.c -o build/menu_map.o

menu_map: build/menu_map.o
	gcc -m32 -g -O0 -Wall -Wextra -o menu_map build/menu_map.o

clean:
	rm -f menu_map build/*.o

.PHONY: all clean