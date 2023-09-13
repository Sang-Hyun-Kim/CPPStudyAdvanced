#include <iostream>

using namespace std;
// 템플릿 기초
// 템플릿: 함수나 클래스를 찍어내는 틀

template<class T, class Y>
void Print(T a,Y b)
{
	cout << a << b << endl;
}
template<class T>
void Print(T a)
{
	cout << a << endl;
}

class Knight
{
public:

public:
	int _hp = 10;
};


// 변수 하나 출력하기보단 특정 경우에 따라 다른 연산이 나오도록 하고 싶음
// => 템플릿 특수화 

template<>
void Print(Knight a)
{
	cout << "Knight!" << endl;
	cout << a._hp << endl;
}
// 템플릿 특수화
// 커스텀 클래스 대입시 오류 발생
// => 연산자가 없어서 연산자 오버로딩을 해줘야함

// 특수화가 없을때에는 오퍼레이터 오버로딩이 필요함
ostream& operator<<(ostream& os, const Knight& K)
{
	os <<K._hp;
	return os;
}
// 새로 만들어진 클래스에 대한 ostream cout 연산자 오버로딩

// 클래스도 템플릿 형식으로 제작 가능하다.
// 기본 설정되야하는 인자도 추가 할 수 있으며, 기본값(=)도 설정 가능하다.	  
template<class T, int SIZE>
class RandomBox
{
public:
	T GetRandomData()
	{
		int idx = rand() % SIZE;
		return _data[idx];
	}
public:
	T _data[SIZE];
};

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	RandomBox<int, 10> rb1;
	for (int i = 0; i < 10; i++)
	{
		rb1._data[i] = i;
	}
	int value1 = rb1.GetRandomData();
	cout << value1 << endl;


	RandomBox<float, 10> rb2;
	for (int i = 0; i < 10; i++)
	{
		rb2._data[i] = i;
	}
	float value2 = rb2.GetRandomData();
	cout << value2 << endl;



	//Knight K1;
	//Print(K1);
}
 