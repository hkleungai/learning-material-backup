#!/bin/sh

N=$1
IFS=$' '
for (( i=1; i<=N; i++ ))
do
	while read num1 num2;
	do
          ./gcd.sh $num1 $num2
	done < file${i}
done
IFS=$'\n'
