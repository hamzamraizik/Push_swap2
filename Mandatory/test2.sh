#!/bin/bash

# Run push_swap program and capture its output
output=$(./push_swap "$@")

# Check if push_swap execution failed
if [ $? -ne 0 ]; then
    echo "Error: push_swap program failed"
    exit 1
fi

# Pass each line of the output to checker_bonus
echo "$output" | while IFS= read -r line; do
    echo "$line" | ./checker_bonus "$@"
    # Check the return value of checker_bonus
    if [ $? -ne 0 ]; then
        echo "Error: checker_bonus program failed on input: $line"
        exit 1
    fi
done

echo "All checks passed successfully"
