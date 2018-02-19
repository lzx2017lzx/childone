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
#include<iostream>
using namespace std;
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<ctime>
#include<deque>
#include<numeric>
#include<functional>


class Player
{
public:
	string mName;
	int mScore[3];
};

void CreatePlayerList(map<int, Player>&mList, vector<int>&vFirst)
{
	string nameSeend = "ABCDEFGHIJKLMNOPQSTUVWXYZ";
	for (int i = 0; i < 24; i++)
	{
		Player p;
		p.mName = "选手";
		p.mName += nameSeend[i];

		for (int j = 0; j < 3; j++)
		{
			p.mScore[j] = 0;
		}

		int joinID = 100 + i;

		mList.insert(make_pair(joinID, p));
		vFirst.push_back(joinID);
	}
}

void ChouQian(vector<int>&vJoinList)
{
	srand((unsigned int)time(NULL));

	random_shuffle(vJoinList.begin(), vJoinList.end());
}

void Match(int round, vector<int>&vJoinList, map<int, Player>&mPlayerList, vector<int>&mLeverList)
{
	srand((unsigned int)time(NULL));

	multimap<int, int, greater<int>>mGroups;

	for (vector<int>::iterator it = vJoinList.begin(); it != vJoinList.end(); ++it)
	{
		deque<int>dScores;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 50 + 50;
			dScores.push_back(score);
		}

		sort(dScores.begin(), dScores.end());

		dScores.pop_back();
		dScores.pop_front();

		int avg = accumulate(dScores.begin(), dScores.end(), 0) / dScores.size();

		mPlayerList[*it].mScore[round - 1] = avg;

		mGroups.insert(make_pair(avg, *it));

		if (mGroups.size() == 6)
		{
			multimap<int, int, greater<int>>::iterator mit = mGroups.begin();
			for (int j = 0; j < 3; j++)
			{
				mLeverList.push_back(mit->second);
				++mit;
			}
			mGroups.clear();
		}
	}
}

void Show(int round, vector<int>&vLevelLIst, map<int, Player>&mPlayersList)
{
	cout << "第" << round << "轮比赛晋级名单如下:" << endl;

	for (auto id : vLevelLIst)
	{
		cout << "Score" << mPlayersList[id].mScore[round - 1] << "Name:" << mPlayersList[id].mName << endl;
	}

	cout << endl;

}
int main(void)
{
	map<int, Player>mPlayersList;
	vector<int>vFirstRound;
	CreatePlayerList(mPlayersList, vFirstRound);

	vector<int>vLevelList1;
	vector<int>vLevelList2;
	vector<int>vLevelList3;

	ChouQian(vFirstRound);

	Match(1, vFirstRound, mPlayersList, vLevelList1);

	Show(1, vLevelList1, mPlayersList);

	ChouQian(vLevelList1);

	Match(2, vLevelList1, mPlayersList, vLevelList2);

	Show(2, vLevelList2, mPlayersList);

	ChouQian(vLevelList2);

	Match(3, vLevelList2, mPlayersList, vLevelList3);
	Show(3, vLevelList3, mPlayersList);
	system("pause");
	return 0;
}