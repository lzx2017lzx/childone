#!/usr/bin/lua

a="hello"
b="world"
print("before exchange:" .. "a、" .. a .. ";b、" .. b)
a,b=b,a--会先计算赋值号右边的变量，再计算左边的变量
print("after exchange:" .. "a、" .. a .. ";b、" .. b)

