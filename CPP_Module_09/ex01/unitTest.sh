#!/bin/bash

# Chemin vers votre programme RPN
RPN_PROGRAM="./RPN"
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
$RPN_PROGRAM "(1 + 1)" && echo $LINE

# echo "Test 5 :"
# $RPN_PROGRAM "6 3 / 4 * 2 +" && echo $LINE

make fclean
echo "All tests Done!"
