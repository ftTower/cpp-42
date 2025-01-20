#!/bin/bash

# Chemin vers votre programme RPN
BTC_PROGRAM="./BitcoinExchange"
LINE="==================================="

make re && clear && echo 

# Tests
echo "Test input :"
valgrind $BTC_PROGRAM "input/input.csv"

LINE="==================================="

echo "Test emptyinput :"
valgrind $BTC_PROGRAM "input/emptyinput.csv"

LINE="==================================="

echo "Test chmodinput :"
chmod -r input/chmodinput.csv
valgrind $BTC_PROGRAM "input/chmodinput.csv"
chmod +r input/chmodinput.csv

make fclean
echo "All tests Done!"
