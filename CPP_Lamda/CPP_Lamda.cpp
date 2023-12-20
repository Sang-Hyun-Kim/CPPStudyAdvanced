// CPP_Lamda.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
enum class ItemType
{
    None,
    Armor,
    Weapon,
    Jewerly,
    Consumable
    
};


enum class Rarity
{
    Common,
    Rare,
    Unique,
};

class Item
{
public:
    Item() {}
    Item(int itemId, Rarity rarity, ItemType type)
        : _itemId(itemId), _rarity(rarity), _type(type)
    {

    }
public: 
    int _itemId = 0;
    Rarity _rarity = Rarity::Common;
    ItemType _type = ItemType::None;

};

int main()
{
    vector<Item> v;
    v.push_back(Item(1,Rarity::Common,ItemType::Weapon));
    v.push_back(Item(2, Rarity::Rare, ItemType::Armor));
    v.push_back(Item(3, Rarity::Common, ItemType::Weapon));
    v.push_back(Item(4, Rarity::Unique, ItemType::Jewerly));

    // 람다: 함수 객체를손쉽게 만드는 문법

    {
        struct IsUniqueItem
        {
            bool operator() (Item& item)
            {
                return item._rarity == Rarity::Unique;
            }
        };
        struct FindItemByItemId
        {
            FindItemByItemId(int itemId) : _itemId(itemId)
            {

            }
            bool operator()(Item& item)
            {
                return item._itemId == _itemId;
            }
            int _itemId;
        };
        
        auto Find = [](Item& item) {return item._rarity == Rarity::Unique; };
        // auto Find = [](Item& item) -> int {return item._rarity == Rarity::Unique; };
        auto findit =std::find_if(v.begin(), v.end(), Find);
        // 반환타입 수동지정
        if (findit != v.end())
        {
            cout << "아이템 ID: "<< findit->_itemId << endl;
        }
        // auto findit = std::find_if(v.begin(), v.end(), [](Item& item) {return item._rarity == Rarity::Unique;  });
        
        // [] :캡처(capture) : 함수 객체 내부에 변수를 저장하는 개념과 유사
        // 외부변수를 람다식에 넣을 수 있음
        // 캡처방식: 값 복사(=), 참조(&)
        int itemid = 3;
        auto FindById = [=](Item& item) {return item._itemId == itemid; };
        // 외부에서 변수를 복사해서 사용 
        itemid = 10;
        // 참조 방식일경우 바뀜
        auto findid = std::find_if(v.begin(), v.end(), FindById);
        if (findid != v.end())
        {
            cout << "아이템 ID: " << findid->_itemId << endl;
        }

    }

    class Knight
    {
    public:
        auto ResetHpJob()
        {
            auto f = [=]()
                {
                    _hp = 200;
                };
            return f;
        }
    public:
        int _hp = 100;
    };

    Knight* k = new Knight();
    auto job = k->ResetHpJob();
    delete k;
    job();
}

// 클로저(closure) = 람다에 의해 만들어진 실행시점 객체
