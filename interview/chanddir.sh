#!/bin/bash

path=`pwd`
echo $path
substr=$1
echo $substr

let pos=`echo "$path" | awk -F ''$substr'' '{printf "%d", length($0)-length($NF)}'`
echo "pos:" $pos
mypth=${path:0:$pos}
cd $mypth 

#echo ${path##$substr}
#echo ----------------

#src="hello world"
#sub="wor"
#str="abbc,def,ghi,abcjkl"
#temp="a*c"
#echo ${str##$temp}
#echo ${src##wor}

#echo ${path%/*}
#strarray=("hello","world")
#echo ${strarray[@]}
#cd /root/
#echo $1

