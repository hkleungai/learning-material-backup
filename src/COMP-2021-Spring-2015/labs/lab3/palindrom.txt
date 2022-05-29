#!/bin/sh

str=$1
len=`echo $str | wc -c`
len=`expr $len - 1`
i=1
j=`expr $len / 2`
while [ $i -le $j ]
do
k=`echo $str | cut -c $i`
l=`echo $str | cut -c $len`
if [ $k != $l ]
then
echo "String is not palindrome"
exit
fi
i=`expr $i + 1`
len=`expr $len - 1`
done
echo "String is palindrome"
