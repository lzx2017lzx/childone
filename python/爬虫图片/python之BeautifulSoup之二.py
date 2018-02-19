#usr/bin/python
#coding=utf_8
import urllib2
from bs4 import BeautifulSoup
del getlmg(url):
	html=urllib2.urlopen(url)
	page=html.read()
	soup=BeautifulSoup(page,"html.parser")
	for s in soup.find_all("cc"):
		if "img" not in str(s):
			continue
		d=s.find_all("img",attrs={"class":"BDE_image"})
		lenth=len(d)
		for i in range(lenth):
		print d[i].attrs["src"]
getlmg(url)
