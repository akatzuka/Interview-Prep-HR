#!/bin/bash

read A
read B
read C

if (($A==$B)) && (($A==$C));
    then echo "EQUILATERAL"
elif (($A!=$B)) && (($A!=$C)) && (($B!=$C));
    then echo "SCALENE"
else
    echo "ISOSCELES"
fi

#Alternative Solution
#read A;
#read B;
#read C;
#if [ $A -eq $B ] && [ $B -eq $C ]
#   then echo "EQUILATERAL";
#elif [ $A -ne $B ] && [ $A -ne $C ] && [ $B -ne $C ]
#   then echo "SCALENE";
#else
    #echo "ISOSCELES";
#fi
