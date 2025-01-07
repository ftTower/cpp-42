#!/bin/bash

# Chemin vers votre programme RPN
PMM_PROGRAM="./PmergeMe"
LINE="==================================="

make re && clear && echo 

# echo "Test 1000 :" && echo 
# $PMM_PROGRAM  `shuf -i 1-100000 -n 1000 | tr "\n" " "`

# echo "Test 2000 :" && echo 
# $PMM_PROGRAM  `shuf -i 1-100000 -n 2000 | tr "\n" " "`

echo "Test 3000 :" && echo 
$PMM_PROGRAM  `shuf -i 1-100000 -n 3000 | tr "\n" " "`

# echo "Test 500000 :" && echo 
# $PMM_PROGRAM  `shuf -i 1-100000 -n 500000 | tr "\n" " "`



make fclean
echo "All tests Done!"
