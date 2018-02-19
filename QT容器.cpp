#include<QApplication>
#include<QVector>
#include<QDebug>
//给出用QVector容器插入数据的三种方法？给出QVector容器遍历的三种方法？给出从起始位置和删除3个元素的方法?
//给出删除容器中所有值为10元素的方法？给出删除第一个元素的方法?给出删除最后一个元素的方法？
//给出删除第一个值为10元素的方法?给出删除所有元素的方法?删除尾元素？删除头元素?给出修改第0个数为100的函数的两种方法？
//使用方法二时，要注意什么？答必须保证容器下标引用的内存空间合法(即有空间存在)


//给出QMap容器增加元素的两种方法？
//给出QMap容器修改元素值的三种方法(键不修改)？
//给出QMap容器删除键值对的两种方法？
//给出清空QMap容器的方法？
//给出遍历QMap容器的两种方法？并指出那种方法适合于即遍历又删除？
int main(int argc,char**argv)
{
    QCoreApplication app(argc,argv);
    QMap<QString,int>m;
    //增加元素
    m.insert("tom",10);//方法一
    m["alice"]=20;//方法二

    //修改元素
    m["tom"]=18;//一
    m["alice"]++;//二
    m["tom"]+=2;//三

    //删除
    m.erase(m.find("alice"));
    m.remove("tom");

    //遍历
    foreach(QString key,m.keys())
    {
        qDebug()<<key<<m[key];
    }

    for(auto it=m.begin();it!=m.end();it++)
    {
        it.key();
        it.value();
    }

    return app.exec();
}








int main01(int argc,char **argv)
{
    QApplication app(argc,argv);
    QVector<int>v;
    v.push_back(3);//前插方法一
    v.push_front(4);//后插效率低方法二

    v.insert(v.begin()+1,50);//中间插方法三

    #if 1
    foreach(int d,v)
    {
        qDebug()<<d;
    }
    #endif

#if 1
    //这种最常用
    for(auto it=v.begin();it!=v.end();++it)
    {
        qDebug()<<*it;
    }
#endif

#if 1
    int index=0;
    int endindex=v.size();
    for(int i=0;i<endindex;i++)
    {
        qDebug()<<v[i];
    }
#endif

    //删除
    v.erase(v.begin());//方法一
    v.remove(0,2);//方法二起始位置和删除个数；给出从起始位置和删除3个元素的方法
    v.removeAll(10);//方法三给出删除容器中所有值为10元素的方法。
    v.removeFirst();//给出删除第一个元素的方法
    v.removeLast();//给出删除最后一个元素的方法
    v.removeOne(10);//给出删除第一个值为10元素的方法
    v.clear();//给出删除所有元素的方法
    v.pop_back();//删除尾元素
    v.pop_front();//删除头元素

    //修改
    //给出修改第0个数为100的函数的两种方法
    v.replace(0,100);//方法一
    v[0]=100;//方法二
    //使用方法二时，要注意什么？答必须保证容器下标引用的内存空间合法(即有空间存在)
    return app.exec();
}
