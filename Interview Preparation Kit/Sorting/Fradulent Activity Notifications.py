# Possible fraudulent account activity: If the amount spent by a client on a particular day is greater than or equal to the client's median spending for a trailing number of days,
# Given the number of trailing days and a client's total daily expenditures for a period of days, find and print the number of times the client will receive a notification over all days.

#!/bin/python3

import math
import os
import random
import re
import sys
import bisect

# Bisect and Insort function
def pop_insort(a, x, y):
    # Use bisect_left because item already exists in list, otherwise _right returns index+1
    idx = bisect.bisect_left(a, x)
    # Remove existing item, pop should be faster than remove here
    a.pop(idx)
    # Insort = insort_right, place item into sorted position  ---> much faster than sorting array yourself
    bisect.insort_right(a, y)
    return a

#Median helper function - takes in sorted list of nums
# Using built-in median function is too slow
def find_median(nums):
    n = len(nums)
    if n % 2 == 0:
        median_1 = nums[n//2]
        median_2 = nums[n//2 - 1]
        median = (median_1 + median_2)/2
    else:
        median = nums[n// 2]

    return median

# Complete the activityNotifications function below.
def activityNotifications(expenditure, d):
    nots = 0
    arr = []

    for i in range(d, len(expenditure)):
        if not arr:
            # Array from trailing to one before current,
            # remember slice ends before i here
            # Must be initially sorted once
            arr = expenditure[i-d:i]
            arr.sort()

         # Track trailing and head values as these are the
         # only ones changing per iteration technically
        last_val = expenditure[i - d]
        new_val = expenditure[i]

        # We don't need to do the process if old_val == new_val
        # but there was a bug with implementing an "if !="

        # Find median value
        median_val = find_median(arr)

        # Pop and insort
        arr = pop_insort(arr, last_val, new_val)
        if new_val >= 2 * median_val:
            nots += 1

    return nots

    """ Old Solution
    nots = 0    #Initalize notfication counter
    check_list = expenditure[d:len(expenditure)]    #initalize list for checking fraud from day d

    for i in range(0, len(check_list)):
        #Determine median for the previous d days
        median_list = expenditure[i:i+d]
        median_list.sort()
        med = find_median(median_list)

        if (check_list[i] >= med * 2):
            nots += 1

    return nots
    """

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nd = input().split()

    n = int(nd[0])

    d = int(nd[1])

    expenditure = list(map(int, input().rstrip().split()))

    result = activityNotifications(expenditure, d)

    fptr.write(str(result) + '\n')

    fptr.close()
