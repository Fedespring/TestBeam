#!/bin/sh

LOF=`ls /Users/cibinett/Desktop/BeamTest/data/rec/ `

for file in $LOF
do
   echo $file
   /Users/cibinett/Desktop/BeamTest/analysis/bin/anaSelector $file > $file.log
done

