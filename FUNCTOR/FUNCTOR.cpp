#include <iostream>

using namespace std;

// 함수 객체(FunctionPointer, FUNCTOR) : 함수 처럼 동작하는 객체

class Functor
{
public:

	// 함수 객체 사용법
	void operator() ()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}
	bool operator()(int num)
	{
		cout << "Functor Text" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}
private:
	int _value = 0;
};

class MoveTask
{
public:
	void operator()()
	{
		//TODO
		cout << "해당 좌표로 플레이어 이동" << endl;
	}
public:
	int _playerid;
	int _posX;
	int _posY;
};

int main()
{

	Functor functor;
	functor();
	bool ret = functor(3);

	// 함수 객체 선언
	MoveTask task;
	task._playerid = 100;
	task._posX = 5;
	task._posY = 0;


	// 나중에 여유 될 때 일감을 실행한다.
	task();

	return 0;
}

// 함수포인터: 동작을 넘겨줄 때 유용하다
// 다만 단점이 있음
// 1. 시그니처가 안 맞으면 사용 불가, 매 포인터마다 알맞은 시그니처 사용이 필수
// 2. 상태를 가질 수 없음=> 함수에서 저장되는 값
// => 클래스는 동작(메서드)와 상태(변수값)을 동시에 사용 가능함
// 함수 객체로 극복 가능한 단점 들

// 함수 객체 : 함수처럼 동작하는 객체/
// () 연산자 오버로딩으로 구현

// 장점=> 함수객체가 선언되는 시기와 함수가 실행되는 시기를 분리 할 수 있으며 한번에 여러 요청이 들어왔을때 요청을 저장하는 방식에 용이