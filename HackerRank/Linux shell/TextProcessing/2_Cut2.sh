#!/bin/bash
# https://www.hackerrank.com/challenges/text-processing-cut-2/problem
while read line ; do
    echo $line | cut -c2,7
done
