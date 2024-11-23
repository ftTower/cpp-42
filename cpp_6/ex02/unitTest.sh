#!/bin/bash

make re || { echo "Build Failed." ; exit 1;}
clear

for i in {1..10}; do
	echo "Running test $i.."
	./Base
	if [ $? -ne 0 ];then
		echo "test $i failed."
		exit 1
	fi
	sleep 1
done

echo "All tests completed. Please check the output for correctness."
make fclean