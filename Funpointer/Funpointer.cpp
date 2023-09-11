#include <iostream>

using namespace std;
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
