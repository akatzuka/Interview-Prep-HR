#!/bin/bash

read num_int
sum=0

for i in $(seq 1 $num_int)
do
    read temp
    sum=$(($sum+$temp))
done


printf "%.3f\n" `echo "$sum / $num_int" | bc -l`
