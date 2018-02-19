#usr/bin/python
#coding=utf_8
xiaozhang=[]
xiaoli=[]
xiaohua=[]
import random
pai=['A','A','A','A','2','2','2','2','3','3','3','3','4','4','4','4','5','5','5','5','6','6','6','6','7','7','7','7','8','8','8','8','9','9','9','9','10','10','10','10','J','J','J','J','Q','Q','Q','Q','K','K','K','K','S','s']
i=0
k=0
while i<54:
	k=random.choice(range(54-i))
	xiaozhang.append(pai[k])
	pai.pop(k)
	i+=1
	k=random.choice(range(54-i))
	xiaoli.append(pai[k])
	pai.pop(k)
	i+=1
	k=random.choice(range(54-i))
	xiaohua.append(pai[k])
	pai.pop(k)
	i+=1
print "xiaohua=%s"%(xiaohua)
print "xiaoli=%s"%(xiaoli)
print "xiaozhang=%s"%(xiaozhang)
