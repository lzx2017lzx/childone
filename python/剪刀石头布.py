#usr/bin/python
#coding=utf_8
import random
num1=1
num2=2
num3=3
flag=0
string=raw_input("你出什么。")
if string=="剪刀":
	flag=1
elif string=="石头":
	flag=2
elif string=="布":
	flag=3
while 1:
	num4=random.choice(range(1,4))
	if flag==num4:
		continue
	elif flag==1 and num4==2:
		print "剪刀小于石头,你输了"
		break
	elif flag==1 and num4==3:
		print "剪刀大于布，你赢了"
		break
	elif flag==2 and num4==1:
		print "石头小于剪刀，你输了"
		break
	elif flag==3 and num4==2:
		print "布大于石头,你赢了"
		break
	elif flag==2 and num4==3:
		print "石头小于布，你输了"
		break
	elif flag==3 and num4==1:
		print "布小于剪刀，你输了"
		break
print flag,num4
	
