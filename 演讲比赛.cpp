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
class Competitor
{
public:
	string Name;
	int Score[3];
};


//��ǩ����

void PickUp(vector<int>&v1)
{
	random_shuffle(v1.begin(), v1.end());
	return;
}

//������ʼ���ݣ�ѡ�ֵı�Ŵ�100��ʼ
void CreateCompetitor(map<int, Competitor>&MulCom, vector<int>&vNumber)//MulCom�п�ʼԪ���Ǳ�ţ�Ȼ����ѡ��
{

	//ΪvNumber��ֵ������ѡ�ֵı��
	for (int i = 0; i < 24; i++)
	{
		vNumber.push_back(i + 100);
	}

	char *temp = "ABCDEFGHIJKLMNOPQISTUVWXYZ";
	for (vector<int>::iterator it = vNumber.begin(); it != vNumber.end(); it++)
	{
		Competitor cp;
		cp.Name = "ѡ��";
		cp.Name += temp[*it - 100];
		MulCom.insert(make_pair(*it, cp));
	}
	return;
}//MulCom�����γɺ�Ͳ���Ķ���

//First�д�ŵ���Ҫ���б�������Ա��ţ�MulCop���������д�ŵ����ʼ���ݣ�����Competitor�е�Score����δ��÷�����Ϣ,ResultMat�д�ŵ��Ǳ���������
//�����������Ƚ�First�ڵ����ݴ��ң�ÿ��������Ϊһ���飬��mulcop��ʼ�õ��������е������ߵ����ߴ�֣�Ȼ�󽫱�źͷ����γ��µ�multimap�������������򣬿����ڲ���
//���ݵ�ʱ��ָ������������ķ�ʽ���롣��ֵķ�ʽҪ����һ��˫�����飬(��Ȼqueue��������û�е������������������

void MatchBegin(int Round, vector<int>&First, map<int, Competitor>&MulCop, vector<int>&ResultMat)
{
	PickUp(First);
	multimap<int, int, greater<int>>mp;//ָ��greater<>������Ϊ�˰��ս������У�Ȼ��ȡ��ʼ������Ԫ��

	for (vector<int>::iterator it = First.begin(); it!= First.end(); it++)
	{
		deque<int>Pscore;
	
		for (int i = 0; i < 10; i++)
		{
			Pscore.push_back(rand() % 100 + 50);
		}

		sort(Pscore.begin(), Pscore.end());//��˫����������

		Pscore.pop_back();//������ͷԪ��
		Pscore.pop_front();//����βԪ��

		//���һ�ַ����Ǳ�����ͣ���һ����ͨ���㷨���
		//��һ�ַ���
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
	cout << "��" <<Round << "�ֱ������" << endl;
	for (vector<int>::iterator it = ResultMat.begin(); it != ResultMat.end(); it++)
	{
		cout << "Score:" << MulCop.find(*it)->second.Score[Round - 1] << " ���:" << MulCop.find(*it)->first <<" name:"<< (MulCop.find(*it))->second.Name<< endl;
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




