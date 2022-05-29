#!/bin/sh

for entry in "$1"/*.txt
do
  count=0
  while read LINE
  do
    let count++
  done < $entry
  echo "$entry has $count line(s)."
done
