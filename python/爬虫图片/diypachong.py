#coding=utf-8
import urllib,urllib2
from bs4 import BeautifulSoup
import re
import html5lib
#import bs4.builder._lxml
#import bs4.builder.htmlparser
#import bs4.builder._htmltlib

def main():
    #入口代码
    home = 'http://www.meizitu.com'
    base = 'http://www.meizitu.com/a/sifang.html'
    #下载该位置的html网页   分析出每个明星所在的入口网页 
    
    #构建请求的头  这个案例主要使用User-Agent  
    request = urllib2.Request(base);
    request.add_header('User-Agent','Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11')
    
    #请求链接  数据 得到相应
    reponse = urllib2.urlopen(request)
    html    = reponse.read()
   # print html   
 #html就是得到的请求的数据 (网页  图片  xml json)
    soup = BeautifulSoup(html,'lxml')
    alist = soup.find_all('a',href=re.compile("http://www.meizitu.com/a/5450.html"))
    #find_all在查找不到数据时  就会返回一个空的列表
    count = 0
    print "alist work"
#    print alist[1]
#    print "%s" alist
    for a in alist:
        url = a['href'] 
        print 'cd url',url        
	print "1"
        while True:
        #开始爬取每个明星
            request = urllib2.Request(url)
            request.add_header('User-Agent','Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11')
            try:
                mhtml = urllib2.urlopen(request).read()
            except  urllib2.URLError as e:
                if hasattr(e,'reason'):
                    print 'We failed to reach a server. reason: ',e.reason
                elif hasattr(e,'code'):
                    print 'error code',e.code
                break
            else:
               # msoup = BeautifulSoup(mhtml,'lxml')
               # aa = msoup.find('p',href=re.compile("^[_\d]+.html"                

        #fin#d函数在找不到需要的数据时  返回None   
                #if aa == None:
                 #   break
                print 'getting ',mhtml.img['src']
                picreq = urllib2.Request(mhtml.img['src'])
                picreq.add_header('User-Agent','Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11')
                try:
                    picdata = urllib2.urlopen(picreq).read()
                except :
                    break
                f = open(str(count)+'.jpg',"wb")
                f.write(picdata)
                f.close()

               # url = base + aa['href']
            finally:
                count += 1
                print '已经完成第%d个网页'%(count)
if __name__ == '__main__':
    main()
