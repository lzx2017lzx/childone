#/usr/bin/python
#coding=UTF_8
import random
import time
i=0
class zoombie:
	blood_volume=0
	speed=0
	def __init__(self,blood_volume,speed=60):
		self.blood_volume=blood_volume
		self.speed=speed
		print "zoombie出生了"
	def get_blood(self,_blood):
		self.blood_volume=_blood
	def eat(self):
		self.blood_volume+=random.randint(10,50)
	def beated(self):
		self.blood_volume-=random.randint(10,70)
	def running(self):
		self.blood_volume+=random.randint(1,10)
def main():
	print "请输入初始血量:"
	a=input()
	izoombie=zoombie(a,60)
	while(1):
		i=random.randint(0,2)
		if i==0:
			izoombie.eat()
			print "吃了东西,血量增加了 "
			print "血量:%d\n"%(izoombie.blood_volume)
			time.sleep(2)
		elif i==1:
			izoombie.beated()
			if izoombie.blood_volume<=0:
				print "被攻击了,僵尸挂了"
				break
			else:
				print "被攻击了，血量减少了"
				print "血量:%d\n"%(izoombie.blood_volume)
				time.sleep(2)
		elif i==2:
			izoombie.running()
			print "running,血量增加了"
			print "血量:%d\n"%(izoombie.blood_volume)
			time.sleep(2)
if __name__ == "__main__":
	main()
	
		
