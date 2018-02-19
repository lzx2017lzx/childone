#/usr/bin/python
#coding=utf_8
def myadd(a,b):
	print "%f"%a,"+","%f"%b,"=","%f"%(a+b)
def mymin(a,b):
	print "%f"%a,"-","%f"%b,"=","%f"%(a-b)
def mymulti(a,b):
	print "%f"%a,"*","%f"%b,"=","%f"%(a*b)
def mydiv(a,b):
	print "%f"%a,"/","%f"%b,"=","%f"%(a/b)
def main():
	myadd(a,b)
	mymin(a,b)
	mymulti(a,b)
	mydiv(a,b)
if __name__ =="__main__":
	main()
	
