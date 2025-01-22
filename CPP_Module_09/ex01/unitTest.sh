#!/bin/bash

# Chemin vers votre programme RPN
RPN_PROGRAM="valgrind ./RPN"
LINE="==================================="

make re && clear && echo 

# Tests
echo "Test 1 :"
$RPN_PROGRAM "8 9 * 9 - 9 - 9 - 4 - 1 +" && echo $LINE

echo "Test 2 :"
$RPN_PROGRAM "7 7 * 7 -" && echo $LINE

echo "Test 3 :"
$RPN_PROGRAM  "1 2 * 2 / 2 * 2 4 - +" && echo $LINE

echo "Test 4 :"
$RPN_PROGRAM "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" && echo $LINE

echo "Test 5 :"
$RPN_PROGRAM "(1 + 1)" && echo $LINE

echo "Test 6 :"
$RPN_PROGRAM "1 + 1" && echo $LINE

echo "Test 7 :"
$RPN_PROGRAM "1 + " && echo $LINE

echo "Test 8 :"
$RPN_PROGRAM "1 1 " && echo $LINE

echo "Test 9 :"
$RPN_PROGRAM " " && echo $LINE

echo "Test 10 :"
$RPN_PROGRAM "1 " && echo $LINE

make fclean
echo "All tests Done!"
