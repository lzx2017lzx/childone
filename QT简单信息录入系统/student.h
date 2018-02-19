#pragma once
#include<QString>


class Student
{
public:
    Student(QString name,int age,int score);
    Student();
public:
    QString name;
    int age;
    int score;
};
