#!/usr/bin/env bash
# https://www.hackerrank.com/challenges/bash-tutorials---the-world-of-numbers/problem
read a
read b
# Sum
echo $(expr $a + $b)
# Difference
echo $(expr $a - $b)
# Product
echo $(expr $a \* $b)
# Quotient
echo $(expr $a / $b)
