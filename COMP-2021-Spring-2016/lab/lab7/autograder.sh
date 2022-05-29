#!/bin/sh
# autograder of simple calculator

dir="hw1" #directory with all submitted script
grade="grade.csv"
cp /dev/null $grade #clear content of grade file
test="test.txt" #testing cases
answer="answer.txt" #answer of testing cases
output="output.txt" #script output

count=1
for script in "$dir"/*.sh
do 
  stuid=`basename $script .sh`
  echo "------------------"
  echo "marking $stuid hw1"
  echo "------------------"
 
 # run the student script on testing cases
  $script $test >  $stuid.output
 
  echo "$stuid hw1 grading report" > $stuid.report

  # correct 
  echo "Correct: " >> $stuid.report
  num_correct=`grep -f $stuid.output answer.txt | tee -a $stuid.report | wc -l`

  # wrong
  echo "Wrong: " >> $stuid.report
  num_wrong=`diff $stuid.output answer.txt | grep "<" | sed 's/< //g' |tee -a $stuid.report | wc -l`
 
  # summary and write score file
  score=$num_correct
  echo "Correct: $num_correct, Wrong: $num_wrong, Score: $score" | tee -a $stuid.report
  echo "$stuid,$score" >> $grade
done

# write score file
echo -e "\nCheck $grade for grading summary\n"
