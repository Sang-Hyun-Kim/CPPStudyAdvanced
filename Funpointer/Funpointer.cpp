#include <iostream>

using namespace std;



// 함수포인터 2: 멤버함수 포인터

// typedef의 진실
// typedef 왼쪽 오른쪽 -> 오른쪽 커스텀 타입 정의
// 정확히는 왼/오 기준이 아닌 [선언 문법]에서 typedef을 앞에 붙이는 쪽

class Knight
{
public:
	static void HelloKnight()
	{

	}

	int GetHp()
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp = 100;
};
// 
class Dog // 멤버함수 포인터 지정시 한 클래스에 대해서 지정하였으니 Dog.*mfn은 오류가 발생함
{
public:
	static void HelloKnight()
	{

	}

	int GetHp()
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp = 100;
};
typedef int INTEGER;
typedef int* POINTER;
typedef int FUNC(int, int); // 이렇게선언된 함수 자체는 정의 없이 사용될 경우 메모리에도 올라가지않는다. 이 상태로 호출되면 오류가 발생. 따라서 꼭 정의를 구현해줘야한다. => 즉, 함주 타입자체는 다른 자료형들과 다르게 메모리에 올라가지 않는다는 차이점을 알아라
typedef int ARRAY[20];
// 한번에 함수 포인터 선언하기
typedef int(*PFUNC)(int, int); // 함수이름앞에 단순히 *만 붙여주면 반환형이 포인터 타입인 함수로 오인될 수 있으니 반드시 문법적으로 괄호안에들어간 형태를 취해야함

// 멤버함수 호출을 위한 함수포인터 선언법
typedef int(Knight::*PMEMFUNC)(); // Knight의 멤버함수를 담으며 인자를 int,int를 갖는 반환형이 int인 멤버함수 를 담는 함수 포인터 선언법



int main()
{
	
	PFUNC fn;
	// 기존 함수포인터 문법으로는 [전역/정적 함수]만 담을 수 있다.(호출 규약이 동일한 녀석들)

	// fn = &Knight::GetHp; // 오류 발생, 멤버함수 불가능
	Knight k1;
	k1.GetHp(); // k1이란 객체를 레지스터에 등록 후 멤버 함수를 실행하는 구조
	PMEMFUNC mfn;

	mfn = &Knight::GetHp; // & 안붙이면 비표준 구문 오류 발생
	// 여기서 끝이아님 항상 객체의 멤버함수를 대상으로 호출해야함
	(k1.*mfn)(); // 까다로움 (객체.*멤버함수포인터)(인자);  
	// k1.mfn: k1객체의 멤버인가? 라는 컴파일러 오류 발생

	// 클래스 포인터의 경우
	Knight* k2 = new Knight;
	((*k2).*mfn)();
	(k2->*mfn)();

	delete k2;
}
/* 함수 포인터1 기초
* 
// 함수 포인터 
int Add(int a, int b)
{
	return a + b;
}

int main()
{

	typedef int(FUNC_TYPE)(int a, int b); // int a,b를 인자로 갖는 int 반환형의 함수를 (FUNC_TYPE) 이라고 typedef
	using FUNC_TYPE2 = int(int a, int b);
	// 사용법
	FUNC_TYPE* fn;

	// 시그니처가 완전히 동일한 함수를 넣어 줄 수 있음
	// 시그니처: 반환형과 인자의 타입등이 일치하는가?
	fn = Add;
	int result = fn(1, 2);
	// 디스 어셈블리로 확인하면 함수 호출시 함수의 주소값이 실행되는 것을 볼 수 있음
	// 배열처럼 함수의 이름은 함수의 시작 주소를 담고있다.
	// 즉 함수 포인터에 Add란 함수의 시작 주소를 옮겨 담은 형태이다
	cout << result << endl;
	// 기존 포인터와 다르게 함수포인터는 (*)를 붙여서 호출해도 문제가 없다
	// (*fn)도 똑같이 작동함( 함수포인터를 사용한다고 명시하는 의미로 사용 가능)
}

// 내용을 좀더 축약하면 이런식으로도 가능 Typedef 반환형(이름)(인자 타입 인자 이름...);
typedef bool(IntOperator)(int* integer);
// 어떤 함수의 인자에 경우데 따라 다른 이름의 함수가 다른 기능을 수행해야하는 상황으로 특정 함수의 인자로 들어가야 할 경우
typedef int Item;
Item* FindItem(Item item[], int itemCount, IntOperator* optr)
{
	return 0;
 }
 // 예시: 아이템 획득후 정렬 순서에 따라 또는 특정 기능에따라 다른 함수가 들어가야 할 경우를 구현
 
 */

