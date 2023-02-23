#!/bin/bash

echo "
#include <string.h>
int main() {
    char str[] = \"\";
    return strlen(str);
    }" > main.c
gcc main.c -o main
./main
ret_value=$?

export LD_LIBRARY_PATH=`pwd`

cd ../ && make re > /dev/null && cd tests
gcc main.c -o main
LD_PRELOAD=../libasm.so ./main
myret_value=$?
if [ $ret_value == $myret_value ]; then
    echo "Success got $myret_value"
else
    echo "Failure"
    echo "Expected: $ret_value but got $myret_value"
    exit 84;
fi

sleep 2
# ----------------------------

echo "
#include <string.h>
int main() {
    char str[12] = \"Hello World!\";
    return strlen(str);
    }" > main.c
gcc main.c -o main
./main
ret_value=$?

export LD_LIBRARY_PATH=`pwd`
cd ../ && make re > /dev/null && cd tests
gcc main.c -o main
LD_PRELOAD=../libasm.so ./main
myret_value=$?
if [ $ret_value == $myret_value ]; then
    echo "Success got $myret_value"
else
    echo "Failure"
    echo "Expected: $ret_value but got $myret_value"
    exit 84;
fi

sleep 2
# ----------------------------

echo "
#include <string.h>
#include <stdio.h>
int main() {
    char *str = NULL;
    return strlen(str);
    }" > main.c
gcc main.c -o main
./main
ret_value=$?

export LD_LIBRARY_PATH=`pwd`
cd ../ && make re > /dev/null && cd tests
gcc main.c -o main
LD_PRELOAD=../libasm.so ./main
myret_value=$?
if [ $ret_value == $myret_value ]; then
    echo "Success got $myret_value"
else
    echo "Failure"
    echo "Expected: $ret_value but got $myret_value"
    exit 84;
fi

sleep 2
# ----------------------------

echo "
#include <string.h>
#include <stdio.h>
int main() {
    char str[12] = \"Hello World!\";
    printf(\"%s\n\", strchr(str, 'o'));
    return 0;
    }" > main.c
gcc main.c -o main
./main
ret_value=$?

export LD_LIBRARY_PATH=`pwd`
cd ../ && make re > /dev/null && cd tests
gcc main.c -o main
LD_PRELOAD=../libasm.so ./main
myret_value=$?
if [ $ret_value == $myret_value ]; then
    echo "Success got $myret_value"
else
    echo "Failure"
    echo "Expected: $ret_value but got $myret_value"
    exit 84;
fi