#!/bin/bash
# https://www.hackerrank.com/challenges/text-processing-cut-1/problem
finish=false
until $finish ; do
    read || finish=true
    echo $REPLY | cut -c3
done
# Another way
# cut -c3
# Another way
# while read line; do
#     echo $line | cut -c 3
# done
