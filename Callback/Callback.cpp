#include <iostream>

using namespace std;

class Item
{
public:

public:
    int _itemId = 0;
    int _rarity = 0;
    int _ownerId = 0;
};

// ID에 따라 찾는 Functor
class FindByOwnerId
{
public:
    bool operator()(const Item* item)
    {
        return (item->_ownerId == _ownerId);
    }

public:
    int _ownerId;
};

// 레어도에 따라 찾는 함수
// 레어도가 높은걸로
class FindByRarity
{
public:
    bool operator()(const Item* item)
    {
       return (item->_rarity >= _rarity);
    }

public:
    int _rarity;
};

// 아이템을 찾을때 특정 기능의 함수에 따라 다른 기능을 수행함
// => 인자로 여러함수를 넘겨줄 수 있게 함수포인터로 구현
// 그자리에 Functor(함수객체)로 넘겨주기
// 근데 이제 함수 여러개를 넣기위해 템플릿을 사용

template<class T>
Item* Finditem(Item items[], int itemCount,/* bool(*func)(const Item*)*/ T selector)
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];

        if (selector(item))
            return item;
    }
    return nullptr;
}
// 콜백 함수 사용 예시
// 특정 상황이 일어나면, 해당 기능을 호출해줘
// ex) 버튼을 누르면-> 특정 이벤트가 발생하는 함수 실행
int main()
{

    Item items[10];
    items[3]._ownerId = 100;
    items[8]._rarity = 2;
    FindByOwnerId functor1;
    functor1._ownerId = 100;
    FindByRarity functor2;
    functor2._rarity = 1;
    // 추후 진짜 기능 구현시, 레어도에 따른 Functor를 여럿 구현해서 사용

   Item* item1 = Finditem(items, 10, functor1);
   Item* item2 =  Finditem(items, 10, functor2);

    // 추후 람다 사용시 functor 없이도 구현가능
    return 0;

}
