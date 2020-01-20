#!/bin/python3

#Print a single integer denoting the number of letter a's in the first letters of the infinite string created by repeating infinitely many times.

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    counter = s.count("a")
    return counter * (n // len(s)) + s[:n % len(s)].count("a")

#counter is the number of times "a" appears in the base string
#total number of a's is counter * number of string repeats +
#"a" count of the last string

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
