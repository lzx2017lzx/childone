#/usr/bin/python
#coding=utf_8
menu={0:"鱼香肉丝",1:"红烧鱼",2:"炒肉块"}
list=[0,0,0]
flag=0
i=0
file_obj=open("点菜信息.dat","wb+")
while 1:
	a=raw_input("请输入你要点的菜:")
	if a=='3' and flag==0:
		print "您未点任何菜。"
	if a=='0':
		list[0]+=1
		file_obj.write(list)
		flag=1
	elif a=='1':
		list[1]+=1;
		file_obj.write(list)
		flag=1
	elif a=='2':
		list[2]+=1
		file_obj.write(list)
		flag=1
	elif a=='3' and flag==1:
		break;
while i<3:
	print "dict[%d]"%(i),dict[i]
	i+=1
list1=file_obj.read(len(list))
print list1
		
