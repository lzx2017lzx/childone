//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T,typename U>
//void BubbleSort(T *arr, int n, U compare)
//{
//	for (int i = 0; i < n - 1; ++i)
//	{
//		for (int j = 0; j < n - 1 - i; ++j)
//		{
//			if (compare(arr[j], arr[j + 1]))
//			{
//				T temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//
//bool CompareInt(int a, int b)
//{
//	return a > b;
//}
//
//class Person
//{
//public:
//	string name;
//	int age;
//	Person(string name, int age) :name(name), age(age)
//	{
//
//	}
//};
//
//class ComparePerson
//{
//public:
//	bool operator()(Person &p1, Person &p2)
//	{
//		return p1.age < p2.age;
//	}
//};
//
//int main0()
//{
//	int arr[] = { 3,6,2,1,7,8,4,9,0,5 };
//	BubbleSort(arr, 10, CompareInt);
//	for (int i = 0; i < 10; ++i)
//	{
//		cout << arr[i] << endl;
//	}
//	Person pArr[] = { Person("zhangsan",18),Person("lisi",19),Person("wangwu",20) };
//	BubbleSort(pArr, 3, ComparePerson());
//	for (int i = 0; i < 3; ++i)
//	{
//		cout << pArr[i].name << ","<< pArr[i].age << endl;
//	}
//	return 0;
//}