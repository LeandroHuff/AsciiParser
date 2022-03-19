#/bin/bash

clear

rm -rf obj
rm -rf build

[ ! -d ./obj/ ] && mkdir -p obj
[ ! -d ./build ] && mkdir -p build

gcc -o ./obj/asciiparser.o asciiparser.c -c -W -Wall -pedantic
gcc -o ./obj/main.o main.c ./obj/asciiparser.o -c -W -Wall -pedantic
gcc -o ./build/main ./obj/main.o ./obj/asciiparser.o

if [ -f ./build/main ] 
then
  echo "build successful!"
else
  echo "build failure!"
fi

