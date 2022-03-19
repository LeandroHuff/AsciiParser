# makefile for asciiparser

all: main

main: ./obj/main.o ./obj/asciiparser.o
	gcc -o build/main ./obj/main.o ./obj/asciiparser.o

./obj/main.o: main.c ./obj/asciiparser.o asciiparser.h resources/defs.h
	gcc -o ./obj/main.o main.c ./obj/asciiparser.o -c -W -Wall -pedantic

./obj/asciiparser.o: asciiparser.c asciiparser.h resources/defs.h
	gcc -o ./obj/asciiparser.o asciiparser.c -c -W -Wall -pedantic

clean:
	rm -rf ./obj/*.o ./build/main

go:
	./build/main

run:
	./build/main

commit:
	cd resources
	gitacpp . "updates"
	cd ..
	gitacpp . "updates"
