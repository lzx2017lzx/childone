#!/usr/bin/lua

a="hello" .. "world"

print(a)

x=5

a,b = 20, 2*x--赋值号右边的值会依次被赋给左边的变量

print('a' .. a)
print('b' .. b)
