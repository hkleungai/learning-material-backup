#!/bin/sh
year=$2

while [ $year -ge $1 ]
do
        month=12
        while [ $month -ge 1 ]
        do
                day=`date +%A -d "$month/13/$year"`
                if [ $day = "Friday" ]
                then
                        date -d "$month/13/$year" +%b-%Y
                fi
                month=`expr $month - 1`
        done
        year=`expr $year - 1`
done


