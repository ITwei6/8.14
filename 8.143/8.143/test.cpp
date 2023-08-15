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
	//底层是搜索key模型
	//排序+去重
	//set<int> s;
	//s.insert(3);
	//s.insert(1);
	//s.insert(4);
	//s.insert(0);
	//s.insert(4);
	////这里的find是成员函数，效率要比算法find找的快。算法find是暴力查找

	//if (s.find(4) != s.end())
	//{
	//	cout << "找到了\n";
	//}
	////set还有count的功能，这个功能是用来计算出现的个数的，但对于set来说是没有用的
	////因为set是去重后的，不可能出现重复的，所以count的结果只有1或0出现或者没有出现。
	////所以count又可以用来当作find查找某个数是否存在
	////count主要用来适用于mutilset，这个是运行重复出现的
	//if (s.count(4))
	//{
	//	cout << "找到了\n";
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
	//删除[30 60]
	//itlow = myset.lower_bound(30);//找到的边界是大于等于30那个 即30位置上的迭代器
	//itup = myset.upper_bound(60);//返回的边界是大于60那个最近的，即70
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
	//与set的区别就是mutiset可以插入重复的值，并且排序不会去重
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

	//存在重复的值，如果使用find查找会返回哪个值呢？
	auto pos = s.find(30);
	//返回的是中序第一个
	while (pos != s.end())
	{
		cout << *pos<<" ";
		++pos;
	}
	cout << endl;
	//在multiset中count就有作用了。因为可以计算出重复的出现了个数了
	cout << s.count(30) << endl;

	multiset<int>::iterator itlow, itup;
	auto ret = s.equal_range(30);
	//返回的是连续的是30的区间
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