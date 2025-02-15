#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Compilation flags
CPP_FLAGS="-std=c++17 -Wall -Wextra -O2"

echo -e "${BLUE}Compiling main.cpp...${NC}"

# Compile the C++ program with all warnings and optimizations
g++ $CPP_FLAGS main.cpp -o solution

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation Error!${NC}"
    exit 1
fi

echo -e "${GREEN}Compilation successful!${NC}"
echo "Running tests..."

# Time the execution
time_start=$(date +%s.%N)

# Run the program with input and store output
./solution < input1.in > my_output.txt

time_end=$(date +%s.%N)
execution_time=$(echo "$time_end - $time_start" | bc)

# Compare output with expected output
if diff -w my_output.txt output.in > /dev/null; then
    echo -e "${GREEN}All test cases passed! ✅${NC}"
else
    echo -e "${RED}Test Failed! ❌${NC}"
    echo -e "${BLUE}Expected Output:${NC}"
    cat output.in
    echo -e "\n${BLUE}Your Output:${NC}"
    cat my_output.txt
    echo -e "\n${BLUE}Differences:${NC}"
    diff -y my_output.txt output.in
fi

echo -e "\n${BLUE}Execution time: ${NC}$execution_time seconds"

# Clean up
rm -f solution my_output.txt

echo -e "${BLUE}Cleanup completed${NC}"