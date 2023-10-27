#include <iostream>
#include <vector>
using namespace std;
// 중괄호 초기화
// curly brace

class Test
{
public:

};

int main()
{
	Test t1;
	Test t2 = t1;// 복사 연산자, 대입 X
	Test t3;
	t3 = t1; // 대입 연산자
	Test t4{ t1 };//  중괄호 초기화

	vector<int> v2(10, 1);
	vector<int> v3{ 1,2,3,4 };
	// 1. STL 컨테이너들과 잘 활용됨
	// 2. 축소 변환 방지

	int x = 0;
	double y(x); // 오류x
	// double y{x}; // 오류 O, 어떻게든 손실이나는 축소변환을 사전에 컴파일러가 방지해줌
	// 참고
	// Test t5;// 기본생성자 호출
	// Test t5() //오류발생: 이 문법은 기본생성자 호출이 아닌 Test 반환하는 함수 t5를 호출한 것이다.
	// Test t5{}; // 중괄호 초기화를 이용한 기본생성자 호출

	// 주의할점 
	// 객체 생성시 중괄호 사용시 initializer_list 라는 인자로 생성됨
	// 이때 생성자 중에 비슷한 방법으로 인자를 받는 개수가 있는 경우 initializer_list가 우선권이있기때문에 문제가 생김
	// 벡터의 경우 초기화(size, value) 대신 {value,value, ...} 내용물을 가지는 벡터가 생성된다는 거임
	// 생성한 객체의 초기화 방법에 initializer_list<T> 방법이 있을경우 해당
	// 전통적인 괄호 초기화를 따라가는 것도 좋다

}
