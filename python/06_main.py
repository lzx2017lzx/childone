#/usr/bin/python
#coding=utf_8
def leapyear(y):
	if y%400==0 or y%4==0 and y%100!=0:
		return True
	else:
		return False
#leapyear(100);
def main():
	print leapyear(100)
if __name__ =='__main__':
	main()
	print leapyear(100);
