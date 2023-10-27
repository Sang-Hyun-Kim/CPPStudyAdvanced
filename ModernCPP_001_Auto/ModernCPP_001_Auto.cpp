#include <iostream>
#include <vector>
#include <map>
// auto
// TypeDeduction 형식 연역
// 컴파일러에 의한 타입 추론
// 기본 auto는 const나 &(참조) 추론을 무시하는 규칙을 주의
using namespace std;
int main()
{
	auto a = 3; // int
	int& reference = a;
	const int cst = a;

	auto test1 = reference;
	auto test2 = cst;
	// 둘다 그냥 int로 추론이 되어버림

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		int& data = v[i]; // auto 붙이면 data가 그냥 int가 되어버림 v내부 값들이 바뀌지 않게 됨
		// auto&로 해결
		data = 100;
	}

	// 용도 2: 너무 긴 타입 대체
	map<int, int> m;
	auto ok = m.insert(make_pair(1, 100));
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}
	return 0;
}
