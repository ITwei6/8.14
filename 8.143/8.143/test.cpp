#include <iostream>
#include <set>
#include <map>
#include<vector>
using namespace std;
void test1()
{
	/*int a[] = { 0,1,2,2,2,3,3,3,4,4,5,6 };
	int size = sizeof(a) / sizeof(a[0]);
	set<int> s(a,a+size);*/
	//�ײ�������keyģ��
	//����+ȥ��
	//set<int> s;
	//s.insert(3);
	//s.insert(1);
	//s.insert(4);
	//s.insert(0);
	//s.insert(4);
	////�����find�ǳ�Ա������Ч��Ҫ���㷨find�ҵĿ졣�㷨find�Ǳ�������

	//if (s.find(4) != s.end())
	//{
	//	cout << "�ҵ���\n";
	//}
	////set����count�Ĺ��ܣ��������������������ֵĸ����ģ�������set��˵��û���õ�
	////��Ϊset��ȥ�غ�ģ������ܳ����ظ��ģ�����count�Ľ��ֻ��1��0���ֻ���û�г��֡�
	////����count�ֿ�����������find����ĳ�����Ƿ����
	////count��Ҫ����������mutilset������������ظ����ֵ�
	//if (s.count(4))
	//{
	//	cout << "�ҵ���\n";
	//}
	//for (auto& e : s)
	//{
	//	cout << e<<" ";
 //   }
	//cout << endl;

	set<int> myset;
	set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++)
	{
		myset.insert(10 * i);
	}
	//10 20 30 40 50 60 70 80 90

	for (auto& e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
	//ɾ��[30 60]
	//itlow = myset.lower_bound(30);//�ҵ��ı߽��Ǵ��ڵ���30�Ǹ� ��30λ���ϵĵ�����
	//itup = myset.upper_bound(60);//���صı߽��Ǵ���60�Ǹ�����ģ���70
	//cout << *itlow << endl;;
	//cout << *itup << endl;;
	//myset.erase(itlow, itup);
	//for (auto& e : myset)
	//{
	//	cout << e << " ";
	//}

	auto ret = myset.equal_range(30);
	itlow = ret.first;
	itup = ret.second;
	cout << *itlow << endl;
	cout << *itup << endl;
	//[30 40)                 
}
void test2()
{
	multiset<int> s;
	//��set���������mutiset���Բ����ظ���ֵ���������򲻻�ȥ��
	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(30);
	s.insert(30);
	s.insert(30);
	s.insert(40);
	s.insert(50);
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//�����ظ���ֵ�����ʹ��find���һ᷵���ĸ�ֵ�أ�
	auto pos = s.find(30);
	//���ص��������һ��
	while (pos != s.end())
	{
		cout << *pos<<" ";
		++pos;
	}
	cout << endl;
	//��multiset��count���������ˡ���Ϊ���Լ�����ظ��ĳ����˸�����
	cout << s.count(30) << endl;

	multiset<int>::iterator itlow, itup;
	auto ret = s.equal_range(30);
	//���ص�����������30������
	itlow = ret.first;
	itup = ret.second;
	/*cout << *itlow << endl;
	cout << *itup << endl;
	while (itlow != itup)
	{
		cout << *itlow << " ";
		++itlow;
	}*/
	cout << endl;
	s.erase(itlow, itup);
	for (auto& e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	test2();
}