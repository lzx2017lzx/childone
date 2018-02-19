#/usr/bin/python
#coding=utf_8
#food={"0":"鱼香肉丝","1":"水煮鱼","2":"红烧肉"}

num0=0
num1=0
num2=0
while 1:
	string=raw_input("请输入你想点的菜:")
	if string=="0":
		num0+=1
	elif string=="1":
		num1+=1
	elif string=="2":
		num2+=1
	elif string=="3":
		break;
print "鱼香肉丝:%d份"%(num0)
print "水煮鱼:%d份"%(num1)
print "红烧肉:%d份"%(num2)
