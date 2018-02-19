#!/usr/bin/lua

function f(x)
	print("function")
	return x*2
end

for i=1,f(5),2 do
	print(i)
	end
