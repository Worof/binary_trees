#!/bin/bash

# Define the README file path
README_PATH="./README.md"

# Check if the README already exists
if [ -f "$README_PATH" ]; then
    echo "$README_PATH already exists."
else
    # Create and edit README.md using Vim
    vim "$README_PATH" <<EOF
i# Binary Trees Project

This repository contains the implementation and tasks for the binary trees project.

## Description

This project is focused on learning about binary trees, including binary search trees (BST), AVL trees, and Max Binary Heaps. It covers creating, inserting, deleting, and performing various operations on these types of trees.

## Installation

Clone this repository:
\`\`\`bash
git clone https://github.com/yourusername/binary_trees.git
\`\`\`

## Usage

Compile the files using gcc with the following flags:
\`\`\`bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 *.c -o binary_trees
\`\`\`

Run the program:
\`\`\`bash
./binary_trees
\`\`\`
