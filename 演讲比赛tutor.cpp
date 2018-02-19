//ѧУ�ݽ���������
//1��ĳ�о���һ���ݽ������� speech_contest ��������24���˲μӡ����������֣�ǰ����Ϊ��̭����������Ϊ������
//2��������ʽ�����������ÿ��6���ˣ�ѡ��ÿ��Ҫ������飬���б�����
//��һ�ַ�Ϊ4��С�飬ÿ��6���ˡ�����100 - 105Ϊһ�飬106 - 111Ϊ�ڶ��飬�������ƣ�
//ÿ�˷ֱ��ճ�ǩ��draw��˳���ݽ�����С���ݽ������̭����������������ѡ�֣�Ȼ�������һ��С��ı�����
//�ڶ��ַ�Ϊ2��С�飬ÿ��6�ˡ�������ϣ���̭����������������ѡ�֣�Ȼ�������һ��С��ı�����
//������ֻʣ��6���ˣ�����Ϊ������ѡ��ǰ������
//4���������֣�10����ί��֣�ȥ����͡���߷֣���ƽ����
//ÿ��ѡ���ݽ�����10����ί�ֱ��֡���ѡ�ֵ����յ÷���ȥ��һ����߷ֺ�һ����ͷ֣����ʣ�µ�8���ɼ���ƽ���֡�
//ѡ�ֵ����ΰ��÷ֽ������У����÷�һ����������������������
//
//��STL��̣�����������
//1�����ӡ������ѡ�ֵ�����������ţ����Բ����ŵ��������С�
//2����ӡÿһ�ֱ�����С������ɼ���С���������
//3����ӡ����ǰ������ѡ�����ơ��ɼ���
//
//�������
//����ѡ�� �� ABCDEFGHIJKLMNOPQRSTUVWXYZ �� �������÷֣�ѡ�ֱ��
//��1��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴������� 
//��2��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������
//��3��	ѡ�ֳ�ǩ ѡ�ֱ��� �鿴�������

//����ѡ����Ϣ��
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
		p.mName = "ѡ��";
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
	cout << "��" << round << "�ֱ���������������:" << endl;

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