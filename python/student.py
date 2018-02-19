#/usr/bin/python
#coding=UTF_8
class student:
	name=""
	age=0
	score=0
	def print_info(self):
		print self.name,self.age,self.score
	def __init__(self,n,s,e):
		self.name=n
		self.age=s
		self.score=e
		print "called __init__"
class monitor(student):
	task=""
	def print_task(self):
		print self.task
	def __init__(self,n,s,e,tsk):
		#self.task=tsk
		student.__init__(self,n,s,e)
		self.task=tsk
def main():
	xiaoming=student("xiaoming",22,59)
	xiaoming.print_info()
	xiaohong=monitor("xiaohong",19,89,"今天放假")
	xiaohong.print_task()
if __name__ == "__main__":
	main()
