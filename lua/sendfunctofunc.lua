#!/usr/bin/lua


myprint =function(param)--匿名函数
	print("这是打印函数 - ##",param);
end

--[[
function functionprint(param)
	return param
]]--

function add(num1,num2,functionprint)
	result=num1+num2
	functionprint(result)
end

myprint(10)

add(3,9,myprint);
