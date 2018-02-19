#usr/bin/python
#coding=utf_8
import random

quanto = 0
jiandao = 1
bu = 2
while True:
	compu=random.choice(range(3))
	number=input("请输入整数 0拳头 1剪刀 2布:")
	print compu
	if number not in range(3):
		print "输入非法"
		continue
	if compu==number:
		print "平局"
	elif compu==1 and number==0 or compu==2 and number ==1 or compu==0 and number==2:
		print "你赢了"
	else:
		print "你输了"
