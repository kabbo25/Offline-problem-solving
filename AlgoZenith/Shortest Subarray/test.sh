#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Compilation flags
CPP_FLAGS="-std=c++17 -Wall -Wextra -O2"

echo -e "Compiling main.cpp..."

# Compile the C++ program with all warnings and optimizations
g++  main.cpp -o solution

# Check if compilation was successful
if [ 0 -ne 0 ]; then
    echo -e "Compilation Error!"
    exit 1
fi

echo -e "Compilation successful!"
echo "Running tests..."

# Time the execution
# shellcheck disable=SC2034
time_start=1739483295.876431800

# Run the program with input and store output
./solution < input1.in > my_output.txt

# shellcheck disable=SC2034
time_end=1739483295.892360200
# shellcheck disable=SC2034
execution_time=

# Compare output with expected output
if diff -w my_output.txt output.in > /dev/null; then
    echo -e "All test cases passed! ✅"
else
    echo -e "Test Failed! ❌"
    echo -e "Expected Output:"
    cat output.in
    echo -e "\nYour Output:"
    cat my_output.txt
    echo -e "\nDifferences:"
    diff -y my_output.txt output.in
fi

echo -e "\nExecution time:  seconds"

# Clean up
rm -f solution my_output.txt

echo -e "Cleanup completed" 

