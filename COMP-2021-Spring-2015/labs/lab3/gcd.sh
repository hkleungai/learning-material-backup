#!/bin/sh
#GCD
a=$1
b=$2
m=$a
if [ $b -lt $m ]
then
   m=$b
fi
while [ $m -ne 0 ]
do
   x=`expr $a % $m`
   y=`expr $b % $m`
   if [ $x -eq 0 -a $y -eq 0 ]
   then
      echo gcd of $a and $b is $m
      break
   fi
m=`expr $m - 1`
done
