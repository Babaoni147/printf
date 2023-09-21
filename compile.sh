#!/bin/bash

# Define text formatting codes
bold_green="\e[1;92m"
bold_yellow="\e[1;93m"
bold_red="\e[1;91m"
reset="\e[0m"

echo -e "${bold_yellow}Compiling Program...${reset}"

# Compile all .c files with GCC
gcc -Wall -Werror -Wextra -pedantic -Wno-format -std=gnu89 *.c

# Check if the compilation was successful
if [[ $? -eq 0 ]]; then
    echo -e "${bold_green}Compilation DONE${reset}"
    echo -e "${bold_yellow}Running Program...${reset}"
    
    # Determine the platform and execute the appropriate binary
    if [[ "$OS" == "Windows_NT" ]]; then
        "./a.exe"
    else
        "./a.out"
    fi
else
    echo -e "${bold_red}Compilation failed${reset}"
fi
