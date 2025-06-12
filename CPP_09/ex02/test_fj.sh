#!/bin/bash

# Number of test runs
tests=1000

debug=0
if [ "$1" = "-d" ]; then
    debug=1
    shift
fi

for i in $(seq 1 $tests); do
    # Run PmergeMe with n random numbers in range -i
    seq=$(shuf -i 1-100000 -n 3000 | tr "\n" " ")
    output=$(./PmergeMe -c $seq)
    # Extract the two relevant numbers from the output
    used=$(echo "$output" | grep 'Comparisons used:' | awk '{print $3}')
    target=$(echo "$output" | grep 'Comparison target for' | awk '{print $6}')
    after_line=$(echo "$output" | grep '^After:')
    # Remove 'After: ' and quotes, then split into array
    sorted_seq=$(echo "$after_line" | sed 's/^After: //' | tr -d '"')
    prev=0
    first=1
    for num in $sorted_seq; do
        if [ $first -eq 1 ]; then
            prev=$num
            first=0
            continue
        fi
        if [ $num -lt $prev ]; then
            echo "failed (not sorted)"
            echo "Sequence:" $seq
            echo "Output After: $after_line"
            if [ $debug -eq 1 ]; then
                echo "Original:"
                for o in ${orig[@]}; do printf '"%s", ' "$o"; done; echo
            fi
            exit 1
        fi
        prev=$num
    done
    if [ -z "$used" ] || [ -z "$target" ]; then
        echo "failed (output parse error)"
        exit 1
    fi
    if [ "$used" -gt "$target" ]; then
        echo "failed. Comparisons used:" $used "vs. targeted: " $target
        echo "Sequence:"
        echo $seq
        if [ $debug -eq 1 ]; then
            echo "Original:"
            for o in ${orig[@]}; do printf '"%s", ' "$o"; done; echo
        fi
        exit 1
    fi
done
echo "passed"
