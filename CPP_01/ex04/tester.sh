#!/bin/bash

PROGRAM="./replace"

GREEN='\033[0;32m'
RED='\033[0;31m'
RESET='\033[0m'

run_test() {
    local input_file="$1"
    local input_content="$2"
    local s1="$3"
    local s2="$4"
    local expected_content="$5"
    local output_file="${input_file}.replace"

    # Input file
    echo -e "$input_content" > "$input_file"

    # Generate expected if not provided
    if [ -z "$expected_content" ]; then
        expected_content=$(echo -e "$input_content" | sed "s/$s1/$s2/g")
    fi

    # Expected output file
    echo -e "$expected_content" > expected.txt

    # Run
    valgrind $PROGRAM "$input_file" "$s1" "$s2"

    # Check
    if diff -q "$output_file" expected.txt; then
        echo -e "${GREEN}PASS:${RESET} $input_file with '$s1' -> '$s2'"
    else
        echo -e "${RED}FAIL:${RESET} $input_file with '$s1' -> '$s2'"
    fi

    # Cleanup
    rm -f "$input_file" "$output_file" expected.txt
}

run_test test1.txt "hello world\nthis is a test\nhello test" "hello" "hi"
run_test test2.txt "foo bar\nbar foo\nfoobar" "foo" "boo"
run_test test3.txt "123456789\n12345\n6789" "12345" "abc"
run_test test4.txt "www
aaa
hhh
aaa" "a
h" "test" "www
aatesthh
aaa"
run_test test5.txt "test 123 te123st" "test" "nice"
run_test test6.txt "test 123 te123st" "no" "nice"
run_test test7.txt "hi ih iihii
hhiihi" "h" ""
