#!/usr/bin/lua

tab1={ key1="val1",key2="val2","val3"}
for k,v in pairs(tab1) do
	print(k .. "-" .. v)--只能字母或下划线为变量的开始，..的作用是字符串连接
end

print("----------")

tab1.key1=nil--nil值会删除变量
for k,v in pairs(tab1) do
	print(k .. "-" .. v)
end
