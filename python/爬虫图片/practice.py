#coding=utf-8
import urllib,urllib2
from bs4 import BeautifulSoup
import re
import html5lib
#import bs4.builder._lxml
#import bs4.builder.htmlparser
#import bs4.builder._htmltlib
import os
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
    alist = soup.find_all('a',href=re.compile("http://www.meizitu.com/a/\d+.html"))
    count=0
    #find_all在查找不到数据时  就会返回一个空的列表
    for a1 in alist:
        print a1
        m2=a1['href']
        print "-------------"
        print "m2%s"%(m2)
        request = urllib2.Request(m2)
        request.add_header('User-Agent','Mozilla/5.0 (Macintosh; Intel M ac OS X 10_7_0) AppleWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Sa fari/535.11')	
        try: 
            mhtml = urllib2.urlopen(request).read()
        except urllib2.URLError as e:
            if hasattr(e,'reason'):
                print 'We failed to reach a server. reason: ',e.reason
            elif hasattr(e,'code'):
                print 'error code',e.code
            continue
        else:
            msoup = BeautifulSoup(mhtml,'lxml')
            aa = msoup.find_all('img')
           # print "aa=%s"%(aa)
            print "1"
            if aa == None:
                break
            print "aa=%s"%(aa)
            #if aa == None:
            for bb in aa:
                aa1=bb['src']
                if aa1 == None:
                    continue
                print "aa1works"
                print "aa1",aa1
                picreq = urllib2.Request(aa1)
                picreq.add_header('User-Agent','Mozilla/5.0 (Macintosh; Intel Mac OS X 10_7_0) Appl eWebKit/535.11 (KHTML, like Gecko) Chrome/17.0.963.56 Safari/535.11')
				
                picdata = urllib2.urlopen(picreq).read()
				#global f
                f = open(str(count)+'.jpg',"wb")
                f.write(picdata)
                f.close()
                count+=1
                if count>100:
                    os._exit(1)
if __name__ == '__main__':
    main()
