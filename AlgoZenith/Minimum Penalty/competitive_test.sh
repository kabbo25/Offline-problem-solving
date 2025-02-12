#!/bin/bash

# Colors for output (Windows compatible)
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Windows specific settings
EXECUTABLE="solution.exe"

# Compilation flags
CPP_FLAGS="-std=c++17 -Wall -Wextra -O2"

# Function to create input file if it doesn't exist
create_input_file() {
    if [ ! -f "input.txt" ]; then
        echo -e "${YELLOW}Input file not found. Creating input.txt...${NC}"
        echo -e "${BLUE}Enter your test cases (Press Ctrl+Z and Enter when finished):${NC}"
        cat > input.txt
    fi
}

# Function to compile and run the program
compile_and_run() {
    local cpp_file=$1
    echo -e "${BLUE}Compiling ${cpp_file}...${NC}"
    
    # Compile the C++ program
    g++ $CPP_FLAGS "$cpp_file" -o "$EXECUTABLE"

    # Check if compilation was successful
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation Error!${NC}"
        exit 1
    fi

    echo -e "${GREEN}Compilation successful!${NC}"
    echo "Running program..."

    # Time the execution (Windows compatible)
    SECONDS=0
    
    # Run the program and capture both output and runtime errors
    ./"$EXECUTABLE" < input.txt > output.txt 2>error.txt
    
    duration=$SECONDS
    
    # Check for runtime errors
    if [ -s error.txt ]; then
        echo -e "${RED}Runtime Error:${NC}"
        cat error.txt
        rm -f error.txt
        exit 1
    fi
    rm -f error.txt

    echo -e "${GREEN}Program executed successfully!${NC}"
    echo -e "${BLUE}Output:${NC}"
    cat output.txt
    echo -e "\n${BLUE}Execution time: ${NC}$duration seconds"
}

# Function to run test cases and verify output
run_tests() {
    local cpp_file=$1
    
    # Check if expected output file exists
    if [ -f "expected.txt" ]; then
        echo -e "\n${BLUE}Comparing with expected output...${NC}"
        if diff -w output.txt expected.txt > /dev/null; then
            echo -e "${GREEN}All test cases passed! ✅${NC}"
        else
            echo -e "${RED}Test Failed! ❌${NC}"
            echo -e "${BLUE}Expected Output:${NC}"
            cat expected.txt
            echo -e "\n${BLUE}Your Output:${NC}"
            cat output.txt
            echo -e "\n${BLUE}Differences:${NC}"
            diff -y output.txt expected.txt
        fi
    fi
}

# Function to create template C++ file if it doesn't exist
create_cpp_template() {
    if [ ! -f "main.cpp" ]; then
        echo -e "${YELLOW}Creating C++ template file...${NC}"
        cat > main.cpp << 'EOL'
#include <bits/stdc++.h>
using namespace std;

void solve() {
    // Your solution here
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;  // Comment this line if there's only one test case
    
    while(t--) {
        solve();
    }
    return 0;
}
EOL
        echo -e "${GREEN}Created main.cpp template${NC}"
    fi
}

# Function to set up the environment
setup_environment() {
    # Create bin directory in user's home if it doesn't exist
    mkdir -p "$HOME/bin"
    
    # Add to PATH if not already added
    if [[ ":$PATH:" != *":$HOME/bin:"* ]]; then
        echo 'export PATH="$HOME/bin:$PATH"' >> "$HOME/.bashrc"
        export PATH="$HOME/bin:$PATH"
    fi
}

# Main script
main() {
    # Check if this is the first run
    if [ ! -f "$HOME/bin/competitive_test" ]; then
        setup_environment
    fi

    # Check if a C++ file is provided
    if [ $# -eq 0 ]; then
        # If no file is provided, look for main.cpp in current directory
        if [ ! -f "main.cpp" ]; then
            create_cpp_template
        fi
        cpp_file="main.cpp"
    else
        cpp_file=$1
        # Check if the file exists
        if [ ! -f "$cpp_file" ]; then
            echo -e "${RED}Error: File $cpp_file not found${NC}"
            exit 1
        fi
    fi

    create_input_file
    compile_and_run "$cpp_file"
    run_tests "$cpp_file"

    # Clean up
    echo -e "\n${BLUE}Cleaning up...${NC}"
    rm -f "$EXECUTABLE" error.txt
}

# Run the main function
main "$@" 