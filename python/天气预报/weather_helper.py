# coding=utf-8

import urllib
import urllib2
from StringIO import StringIO
import gzip

import json
import sys
reload(sys)
sys.setdefaultencoding( "utf-8" )

try:
        import xml.etree.cElementTree as ET
except ImportError:
        import xml.etree.ElementTree as ET


'''
如果有城市编码  就直接使用 

response = urllib2.urlopen("http://wthrcdn.etouch.cn/WeatherApi?citykey=101010100");

否则就使用
http://wthrcdn.etouch.cn/WeatherApi?city=会宁
print response.read()

file_html = open("index.html",'w')
file_html.write(response.read())
file_html.close()
'''
def getXMLFromNet(no,xml_name):
    #request = urllib2.Request('http://wthrcdn.etouch.cn/WeatherApi?citykey=101010100')
    request = urllib2.Request('http://wthrcdn.etouch.cn/WeatherApi?citykey='+no)
    request.add_header('Accept-encoding','gzip')
    response = urllib2.urlopen(request)

    if response.info().get('Content-Encoding') == 'gzip':
        buf = StringIO(response.read())
        f   = gzip.GzipFile(fileobj = buf)
        data = f.read()
        #print data

        file_html = open(xml_name,'wb')
        file_html.write(data)
        file_html.close()
        print '数据接收成功'

def getWeatherInfoFromXML(xml_name):

    print '正在解析数据'
    tree = ET.ElementTree(file=xml_name)
    root = tree.getroot()
    print '城市:'+ root.find('city').text
    print root.find('wendu').text + '°C'
    print '风力:' +root.find('fengli').text
    
    if root.find('environment'):
        print 'PM2.5:' + root.find('environment').find('pm25').text
        print '空气质量:' + root.find('environment').find('quality').text

    day = root.find('forecast')
    print day[0].find('date').text + ':'
    
    print ' 最' + day[0].find('high').text
    print ' 最' + day[0].find('low').text
    print ' 白天' + day[0].find('day').find('type').text
    print ' 夜间' + day[0].find('night').find('type').text
    

    print day[1].find('date').text + ':'
    
    print ' 最' + day[1].find('high').text
    print ' 最' + day[1].find('low').text
    print ' 白天' + day[1].find('day').find('type').text
    print ' 夜间' + day[1].find('night').find('type').text
    
    index = root.find('zhishus')
    #index[2].find('name').text
    print '穿衣指数...'  +  index[2].find('detail').text
    print '运动指数...'  +  index[8].find('detail').text

def getNoFromJSON(file):

    #1  先遍历文件能把省市全部遍历出来 --练习-> 按照显示省 下的市自动右移 
    #2  通过输入省份和市名进行比较之后 获取对应的no 

    fp = open(file,"rb")
    jsondata = fp.read()
    jsonobj  = json.loads(jsondata)
    
    #inpro  = raw_input('省份:城市格式输入 不加省直辖市市自治区/市区县:')
    inpro  = raw_input('省份 不加省直辖市自治区:')
    incity = raw_input('城市 不加市区县:')
    
    print inpro +  incity
    #print jsonobj.keys()
    province_list    = jsonobj['cityno'] 

    proflag = False
    ctflag  = False

    destno = ""
    for province in province_list:
        #print province['province']
        if province['province']  == inpro:
            proflag = True          
            city_list = province['city']
            for city in city_list:
                #print city['city_name']
    
                if city['city_name'] == incity:
                    ctflag = True
                    print "查询到城市信息,请稍后"
                    destno = city['no']
                    return destno
            if ctflag == False:
                break
    if proflag == False:
        print "你所输入的信息在本地信息中没有找到,正在联网查询...." 
        return incity;
    fp.close()
    
if __name__ == '__main__':                              #既可以独立运行，也可以当做模块导入到其他文件
    
    no = ""
    while  len(no) == 0 :
        no = getNoFromJSON('get_no_from_address.json')

    getXMLFromNet(no,'index.xml')
    getWeatherInfoFromXML('index.xml')