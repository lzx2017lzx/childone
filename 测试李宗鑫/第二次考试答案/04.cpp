#include <iostream>
#include <string>
using namespace std;

template<typename T,typename U>
void InsertSort(T *arr, int n,U compare)
{
	for (int i = 1; i < n; ++i)
	{
		T temp = arr[i];
		int j = i - 1;
		while (j >= 0 && compare(temp , arr[j]))
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = temp;
	}
}

bool CompareInt(int a, int b)
{
	return a < b;
}
class Person
{
public:
	string name;
	int age;
	Person(string name, int age) :name(name), age(age)
	{

	}
};
class ComparePerson
{
public:
	bool operator()(Person& p1, Person& p2)
	{
		return p1.age < p2.age;
	}
};

int main()
{
	int arr[] = { 3,5,6,8,2,7,9,0,1,4 };
	InsertSort(arr, 10,CompareInt);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << endl;
	}
	Person p[3] = { Person("zhangsan",20),Person("lisi",23),Person("wangwu",18) };
	InsertSort(p, 3, ComparePerson());
	for (int i = 0; i < 3; ++i)
	{
		cout << p[i].name << "," << p[i].age << endl;
	}
	return 0;
}