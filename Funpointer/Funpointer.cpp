#include <iostream>

// 함수 포인터 

int main()
{

	typedef int(FUNC_TYPE)(int a, int b); // int a,b를 인자로 갖는 int 반환형의 함수를 (FUNC_TYPE) 이라고 typedef
	using FUNC_TYPE2 = int(int a, int b);

}

