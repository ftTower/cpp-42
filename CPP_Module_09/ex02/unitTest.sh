#!/bin/bash

# Chemin vers votre programme RPN
PMM_PROGRAM="./PmergeMe"
LINE="==================================="

make re && clear && echo 

echo "Test 1 :" && echo 
$PMM_PROGRAM  `shuf -i 1-100000 -n 10 | tr "\n" " "`



make fclean
echo "All tests Done!"
