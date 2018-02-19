#usr/bin/python
#coding=utf_8
string=raw_input("请输入字符串")
for ch in string:
	if  ch=='x'or ch=='o':
		continue
	else:
		print "%-1s"%(ch),

