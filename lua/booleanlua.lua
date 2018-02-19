#!/usr/bin/lua

print(type(true))
print(type(false))
print(type(nil))

if false or nil then
	print("至少有一个是true")
else
	print("false 和nil 都为false!")
end
