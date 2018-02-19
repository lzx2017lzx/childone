#include "mywidget.h"
#include"student.h"
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{

    //定义控件
    edit1=new QLineEdit;
    edit1->setPlaceholderText("姓名");

    edit2=new QLineEdit;
    edit2->setPlaceholderText("年龄");

    edit3=new QLineEdit;
    edit3->setPlaceholderText("成绩");

    QPushButton *button1=new QPushButton("录入");
    QPushButton *button2=new QPushButton("退出");

    QLabel *label1=new QLabel("姓名");
    QLabel *label2=new QLabel("年龄");
    QLabel *label3=new QLabel("成绩");

    //对控件进行布局
    // QHBoxLayout*hBoxLayout=new QHBoxLayout(this);
    QGridLayout *mainLayout=new QGridLayout(this);//设置对象，划分空间
    QGridLayout *centerLayout=new QGridLayout;
    mainLayout->setRowStretch(0,1);
    mainLayout->setRowStretch(2,1);
    mainLayout->setColumnStretch(0,1);
    mainLayout->setColumnStretch(2,1);
    mainLayout->addLayout(centerLayout,1,1);//如果不先在centerlayout工作区间的四周添加弹簧，就不能保证显示的窗口在中间

    centerLayout->setRowStretch(4,1);//在新的centerlayout中划分区间
    centerLayout->setColumnStretch(3,1);

    //添加构件
    centerLayout->addWidget(label1,0,0,1,1);
    centerLayout->addWidget(edit1,0,1,1,2);

    centerLayout->addWidget(label2,1,0,1,1);
    centerLayout->addWidget(edit2,1,1,1,2);

    centerLayout->addWidget(label3,2,0,1,1);
    centerLayout->addWidget(edit3,2,1,1,2);


    //用QHBoxLayout对象再次对button1和buttong2进行管理，并放入弹簧
    QHBoxLayout *hbox=new QHBoxLayout;
    hbox->addWidget(button1);
    hbox->addStretch(1);
    hbox->addWidget(button2);
    centerLayout->addLayout(hbox,3,0,1,3);


    //处理退出按钮，按下即退出
    connect(button2,SIGNAL(clicked()),this,SLOT(close()));

    // //将信息读入到文件中
    // QFile file("Student.txt");
    // file.open(QFile::WriteOnly);
    //  QDataStream da(&file);//用序列化读数据

    // Student st;//定义用来写文件的对象；用了匿名对象就不必用本对象
    // QVector<Student>v;//先将所有读入的student对象存入QVector容器中，等容器size大小足够大以后
    //再读入磁盘，为的是减少磁盘读写次数。
    //  v.resize(20);
    //处理录入按钮，按下调试打印所有信息,
    /*
    connect(button1,&QPushButton::clicked,[&]()
    {
        QString name=edit1->text();
        QString age=edit2->text();
        int intage=age.toInt();//QStirng必须转换成string函数，再转换成int类型，才能被Student类对象中的int型数据接收
        QString score=edit3->text();
        int intscore=score.toInt();
        qDebug() << name << intage << intscore;
        Student s1(name,intage,intscore);
        qDebug()<<s1.name<<s1.age<<s1.score;
        // QVector<Student>v;
        //v.push_back(s1);
        //        if(v.size()>20)
        //        {
        //  for(auto it=v.begin();it!=v.end();it++)
        //   {
        QFile file("Student.txt");
        file.open(QFile::WriteOnly);
        QDataStream da(&file);//用序列化读数据
        da<<s1.name<<s1.age<<s1.score;
        //  }
        //v.clear();//输入磁盘以后清理容器对象v的数据
        qDebug()<<"write success!";
        file.close();

        // }

    }
    );

    lamda表达式不能传递datastream的变量，本程序在connect函数外面定义datastream变量ds；但是在connect里面并没有运行通过
*/

    //初始化vfile容器容量
    vfile.reserve(20);
    connect(button1,SIGNAL(clicked()),this,SLOT(writestream()));






    //     gridLayout->setRowStretch(4,1);//第二个参数是比重的意思
    //     gridLayout->setColumnStretch(3,1);//分成三行三列

    //     gridLayout->addWidget(edit1,0,1,1,2);
    //     gridLayout->addWidget(label1,0,0);
    //     gridLayout->addWidget(edit2,1,1,1,2);
    //     gridLayout->addWidget(label2,1,0);
    //     gridLayout->addWidget(edit3,2,1,1,2);
    //     gridLayout->addWidget(label3,2,0);

    //     //只有QHBoxLayout才能用addStretch增加弹簧；先用QHBoxLayout，将所有控件和弹簧组织起来，再用
    //     //gridLayout处理QHBoxLayout对象即可。
    //     QHBoxLayout *hBox=new QHBoxLayout;

    //     hBox->addWidget(button1);
    //     hBox->addStretch(1);
    //     hBox->addWidget(button2);
    //    // gridLayout->addWidget(button1,3,0);
    //  //   gridLayout->addStretch(1);
    //    // gridLayout->addWidget(button1,3,2);
    //     gridLayout->addLayout(hBox,3,0,1,3);

    //    //固定尺寸
    //   // QBoxLayout qb(*this);
    //  // qb.SetSizeConstraint();




}

void MyWidget::readstream()
{
    QFile file("Student.data");
    file.open(QFile::ReadOnly);//指定打开方式(读还是写）

    while(!file.atEnd())
    {
        QDataStream ds(&file);

        Student s1;
        ds>>s1.name>>s1.age>>s1.score;

        qDebug()<<s1.name<<s1.age<<s1.score;
    }
    file.close();

}

void MyWidget::writestream()
{


    QString name=edit1->text();
    QString age=edit2->text();
    int intage=age.toInt();//QStirng必须转换成string函数，再转换成int类型，才能被Student类对象中的int型数据接收
    QString score=edit3->text();
    int intscore=score.toInt();
    qDebug() << name << intage << intscore;
    Student s1(name,intage,intscore);
    qDebug()<<s1.name<<s1.age<<s1.score;


    vfile.push_back(Student(name,intage,intscore));
    if(vfile.size()>20)
    {
        QFile file("Student.data");
        file.open(QFile::WriteOnly);
        QDataStream ds(&file);
        for(auto it=vfile.begin();it!=vfile.end();it++)
        {
            ds<<it->name<<it->age<<it->score;
        }
        file.close();
        vfile.resize(0);
    }
    //QDataStream ds(&file);
    // vfile.push_back();
    // ds<<s1.name<<s1.age<<s1.score;
    //  file.close();

}
