#!/usr/bin/env bash
# https://www.hackerrank.com/challenges/bash-tutorials---getting-started-with-conditionals/problem
read input


if [[ $input == "y" ]]; then
    echo "YES"
elif [[ $input == "Y" ]]; then
    echo "YES"
else
    echo "NO"
fi

# Another way
# read I
# if [ "$I" = "y" -o "$I" = "Y" ]; then
#     echo "YES"
# else
#     echo "NO"
# fi
