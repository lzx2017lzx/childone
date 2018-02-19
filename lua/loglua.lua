#!/usr/bin/lua

a=true
b=true

if(a and b)
then
	print("a and b - 条件为true")
end

if ( a or b)
then
	print("a or b - 条件为true")
end

print("-------分割线------")

a=false
b=true

if(a and b)
then
	print("a and b - 条件为 true")
else
	print("a and b - 条件为false")
end

if(not(a and b))
then
	print("not(a and b) - 条件为 true")
else
	print("not(a and b) -条件为false")
end
