#!/bin/bash
#echo "hello"
#echo "hello:$1"
cppfile=$1
outfile=${cppfile:0:-4}
flagstd="-std=c++11"
g++ $cppfile $flagstd -o $outfile 
