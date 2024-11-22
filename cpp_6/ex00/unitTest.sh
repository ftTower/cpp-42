#!/bin/bash

EXECNAME="./ScalarConverter"

# Rebuild the project
make re

# Basic integer tests
$EXECNAME 0
$EXECNAME -0
$EXECNAME 10
$EXECNAME -10
$EXECNAME 100000000000
$EXECNAME -10000000000

# Float tests
$EXECNAME 42.0f
$EXECNAME -42.0f
$EXECNAME 3.141592f
$EXECNAME -3.141592f
$EXECNAME 1e10f
$EXECNAME -1e10f
$EXECNAME nanf
$EXECNAME -nanf
$EXECNAME inff
$EXECNAME -inff

# Double tests
$EXECNAME 42.0
$EXECNAME -42.0
$EXECNAME 3.141592
$EXECNAME -3.141592
$EXECNAME 1e10
$EXECNAME -1e10
$EXECNAME nan
$EXECNAME -nan
$EXECNAME inf
$EXECNAME -inf

# Edge cases
$EXECNAME a
$EXECNAME 'a'
$EXECNAME ""
$EXECNAME "123abc"
$EXECNAME "abc123"
$EXECNAME "42.0fabc"
$EXECNAME "abc42.0f"
$EXECNAME "4.2e10f"
$EXECNAME "10.5.6"
$EXECNAME "   42.0f" # Leading spaces
$EXECNAME "42.0f   " # Trailing spaces

# Overflow and underflow cases
$EXECNAME 1e308
$EXECNAME -1e308
$EXECNAME 1e-308
$EXECNAME -1e-308
$EXECNAME 1e400
$EXECNAME -1e400

# Extreme cases
$EXECNAME 2147483647    # Max int
$EXECNAME -2147483648   # Min int
$EXECNAME 9223372036854775807  # Max long
$EXECNAME -9223372036854775808 # Min long
$EXECNAME 0.0000000000000001f # Very small float
$EXECNAME -0.0000000000000001f # Negative very small float

# Invalid inputs
$EXECNAME "---"
$EXECNAME "++123"
$EXECNAME "42.0f.."
$EXECNAME "inf42"
$EXECNAME "--nan"

# Optional: Add a summary of tests
echo "All tests completed. Please check output for correctness."
