#!/bin/bash

read A
read B

if (($A<$B));
then echo "X is less than Y";

elif (($A==$B));
then echo "X is equal to Y";

elif (($A>$B));
then echo "X is greater than Y";
fi
