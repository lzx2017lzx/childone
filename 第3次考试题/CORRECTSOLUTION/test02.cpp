//#pragma warning(disable:4996)
//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//using namespace std;
//
//class Person
//{
//public:
//	char name[64];
//	int age;
//	Person(char *name, int age)
//	{
//		strcpy(this->name, name);
//		this->age = age;
//	}
//};
//
//void ReadFile(vector<Person> &v, const char *path)
//{
//	ifstream ifs(path);
//	char buf[1024] = { 0 };
//	while (ifs >> buf)
//	{
//		char *name = strtok(buf, "#");
//		int age = atoi(strtok(NULL, "#"));
//		v.push_back(Person(name, age));
//	}
//}
//
//void SelectionSort(vector<Person> &v)
//{
//	for (int i = 0; i < v.size() - 1; ++i)
//	{
//		int min = i;
//		for (int j = i + 1; j < v.size(); ++j)
//		{
//			if (v[min].age > v[j].age)
//			{
//				min = j;
//			}
//		}
//		if (min != i)
//		{
//			Person temp = v[i];
//			v[i] = v[min];
//			v[min] = temp;
//		}
//	}
//}
//
//void WriteFile(vector<Person> &v, const char *path)
//{
//	ofstream ofs(path);
//	for (int i = 0; i < v.size(); ++i)
//	{
//		ofs << v[i].name << "#" << v[i].age << endl;
//	}
//}
//
//int main1()
//{
//	vector<Person> v;
//	ReadFile(v, "C:/Users/Administrator/Desktop/第3次考试题/a.txt");
//	SelectionSort(v);
//	WriteFile(v, "C:/Users/Administrator/Desktop/第3次考试题/b.txt");
//	return 0;
//}