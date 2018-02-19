#if 1
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>
#include<map>
#include<deque>
#include<ctime>
#include<numeric>
#include<string>
//学校演讲比赛介绍
//1）某市举行一场演讲比赛（ speech_contest ），共有24个人参加。比赛共三轮，前两轮为淘汰赛，第三轮为决赛。
//2）比赛方式：分组比赛，每组6个人；选手每次要随机分组，进行比赛；
//第一轮分为4个小组，每组6个人。比如100 - 105为一组，106 - 111为第二组，依次类推，
//每人分别按照抽签（draw）顺序演讲。当小组演讲完后，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。
//第二轮分为2个小组，每组6人。比赛完毕，淘汰组内排名最后的三个选手，然后继续下一个小组的比赛。
//第三轮只剩下6个人，本轮为决赛，选出前三名。
//4）比赛评分：10个评委打分，去除最低、最高分，求平均分
//每个选手演讲完由10个评委分别打分。该选手的最终得分是去掉一个最高分和一个最低分，求得剩下的8个成绩的平均分。
//选手的名次按得分降序排列，若得分一样，按参赛号升序排名。
//
//用STL编程，求解这个问题
//1）请打印出所有选手的名字与参赛号，并以参赛号的升序排列。
//2）打印每一轮比赛后，小组比赛成绩和小组晋级名单
//3）打印决赛前三名，选手名称、成绩。
//
//需求分析
//产生选手 （ ABCDEFGHIJKLMNOPQRSTUVWXYZ ） 姓名、得分；选手编号
//第1轮	选手抽签 选手比赛 查看比赛结果 
//第2轮	选手抽签 选手比赛 查看比赛结果
//第3轮	选手抽签 选手比赛 查看比赛结果

//定义选手信息。
class Competitor
{
public:
	string Name;
	int Score[3];
};


//抽签分组

void PickUp(vector<int>&v1)
{
	random_shuffle(v1.begin(), v1.end());
	return;
}

//创建初始数据，选手的编号从100开始
void CreateCompetitor(map<int, Competitor>&MulCom, vector<int>&vNumber)//MulCom中开始元素是编号，然后是选手
{

	//为vNumber赋值，存入选手的编号
	for (int i = 0; i < 24; i++)
	{
		vNumber.push_back(i + 100);
	}

	char *temp = "ABCDEFGHIJKLMNOPQISTUVWXYZ";
	for (vector<int>::iterator it = vNumber.begin(); it != vNumber.end(); it++)
	{
		Competitor cp;
		cp.Name = "选手";
		cp.Name += temp[*it - 100];
		MulCom.insert(make_pair(*it, cp));
	}
	return;
}//MulCom数据形成后就不会改动。

//First中存放的是要进行比赛的人员编号，MulCop容器对象中存放的是最开始数据，但是Competitor中的Score数据未填好分数信息,ResultMat中存放的是比赛结果编号
//比赛过程是先将First内的数据打乱，每隔六个作为一个组，从mulcop开始用迭代器进行迭代，边迭代边打分，然后将编号和分数形成新的multimap，并按分数排序，可以在插入
//数据的时候指定按分数降序的方式插入。打分的方式要借助一个双端数组，(虽然queue容器由于没有迭代器，不方便操作）

void MatchBegin(int Round, vector<int>&First, map<int, Competitor>&MulCop, vector<int>&ResultMat)
{
	PickUp(First);
	multimap<int, int, greater<int>>mp;//指定greater<>（）是为了按照降序排列，然后取开始的三个元素

	for (vector<int>::iterator it = First.begin(); it!= First.end(); it++)
	{
		deque<int>Pscore;
	
		for (int i = 0; i < 10; i++)
		{
			Pscore.push_back(rand() % 100 + 50);
		}

		sort(Pscore.begin(), Pscore.end());//对双端数组排序

		Pscore.pop_back();//弹出开头元素
		Pscore.pop_front();//弹出尾元素

		//求和一种方法是遍历求和，另一种是通过算法求和
		//第一种方法
		int sum=accumulate(Pscore.begin(), Pscore.end(), 0);

		int ave = sum / Pscore.size();
		map<int, Competitor>::iterator mit =MulCop.find(*it);
		(*mit).second.Score[Round - 1] = ave;
		//MulCop[*it].Score[Round-1]=ave;
		
		mp.insert(make_pair(ave, *it));


		if (((it - First.begin()+1) % 6 == 0)&&(it-First.begin())!=0)
		{
			map<int, int, greater<int>>::iterator mait = mp.begin();
			for(int i=0;i<3;i++)
			{
				ResultMat.push_back(mait->second);
				mait++;
			}
			//memset(&mp, 0, sizeof(mp));
			mp.clear();
		}

		

	}
	return;

}

void ShowResult(int Round,vector<int>&ResultMat, map<int, Competitor>&MulCop)
{
	cout << "第" <<Round << "轮比赛结果" << endl;
	for (vector<int>::iterator it = ResultMat.begin(); it != ResultMat.end(); it++)
	{
		cout << "Score:" << MulCop.find(*it)->second.Score[Round - 1] << " 编号:" << MulCop.find(*it)->first <<" name:"<< (MulCop.find(*it))->second.Name<< endl;
	}
	cout << "----------------------------------" << endl;
}
int main(void)
{
	//srand((unsigned int)time(NULL));

	map<int, Competitor>mpCompetitor;
	vector<int>vNumber;
	CreateCompetitor(mpCompetitor, vNumber);
	//void CreateCompetitor(map<int, Competitor>&MulCom, vector<int>&vNumber)
	//MatchBegin(int Round, vector<int>&First, map<int, Competitor>&MulCop, vector<int>&ResultMat)
	vector<int>vResult1;
	vector<int>vResult2;
	vector<int>vResult3;
	MatchBegin(1, vNumber, mpCompetitor, vResult1);
	ShowResult(1, vResult1, mpCompetitor);

	MatchBegin(2, vResult1, mpCompetitor, vResult2);
	ShowResult(2, vResult2, mpCompetitor);

	MatchBegin(3, vResult2, mpCompetitor, vResult3);
	ShowResult(3, vResult3, mpCompetitor);

	system("pause");
	return 0;
}
#endif

#if 0
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<map>
int main(void)
{
	map<int, int>a;
	//a.push
	a.insert(make_pair(2,3));
	a.insert(make_pair(10,4));
	a.insert(make_pair(3,6));

	cout << a[0] << endl;
	system("pause");
	return 0;
}
#endif




