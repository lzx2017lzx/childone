#!/usr/bin/lua

a=21
b=10

if(a==b)
then
	print("Line 1 - a 等于 b")
else
	print("Line 1 - a 不等于 b")
end


if(a ~= b)
then
	print("Line2 - a 不等于 b")
else 	
	print("Line2 - a等于 b")
end

if(a < b)
then
	print("Line3 - a小于b")
else 
	print("Line3 -a 大于等于 b")
end

if( a> b)
then
	print("Line4 -a 大于 b")
else
	print("Line5 -a 小于等于 b")
end
