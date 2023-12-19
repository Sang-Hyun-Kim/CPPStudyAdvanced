#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// 구버전 코드 알고리즘 라이브러리 활용해서 업그레이드하기
using namespace std;
int main()
{

    // find, find_if
    // count, count_if
    // all_of, any_of, none_of
    // for_each
    // remove, remove_if
    


    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> v;
    for (int i = 0; i < 100; i++)
    {
        int num = rand() % 100;
        v.push_back(num);
    }
    
    // Q1) 임의의 숫자 number 가 벡터 컨테이너 안에 있는지 체크하는 기능
     {
        int number = 50;
        bool found = false; // 찾으면 true
        vector<int>::iterator it;
        it = v.begin();
    
        //TODO
        for (auto value : v)
        {
            if (value == number)
            {
                found = true;
            }
        }
        cout << boolalpha;
        // cout << noboolalpha;
        cout << "값이 있냐 ?" << found << endl;

        // =>
        vector<int>::iterator itFind = find(v.begin(), v.end(), number); // [ ~ )
        // 코드 간결, 가독성 증가
        if (itFind == v.end())
        {
            // 못찾음
            cout << "못찾음" << endl;
        }
        else
        {
            cout << "찾음" << endl;
        }
    }

     //Q2) 11로 나뉘는 숫자가 벡터에 있는지 체크 검증
     {
         bool found = false;
         vector<int>::iterator it;
         //for (it = v.begin(); it != v.end(); ++it)
         //{
         //    if (((*it) % 11) == 0)
         //        found = true;
         //}
         //cout << "값이 있냐 ?" << found << endl;

         // find_if()의 인자 Pred의 구조가 bool 형반환 함수에 인자는 포인터(반복자)를 받는 객체 형태의 조건으로 넣으면 되는 문법으로 되어있음을 확인
         struct CanDivideBy11
         {
             bool operator()(int n)
             {
                 return (n % 11) == 0;
             }
         };

         auto itFind = std::find_if(v.begin(), v.end(), CanDivideBy11());
         // 람다식 사용 std::find_if(v.begin(), v.end(), [](int n){return (n % 11) == 0;});
         if (itFind == v.end())
         {
             // 못찾음
             cout << "못찾음" << endl;
         }
         else
         {
             cout << "찾음" << endl;
         }
     }
     //Q3) 홀수인 숫자의 개수
     {
         int count = 0;
         vector<int>::iterator it;
         for (it = v.begin(); it != v.end(); ++it)
         {
             if (((*it) % 2) != 0)
                 count++;
         }
         cout << "값이 있냐 ?" << count << endl;



         auto itFind = count_if(v.begin(), v.end(), [](int n) {return ( n % 2 ) != 0; });
         cout << itFind << endl;
     }

     // all_of(v.begin(), v.end(), [](int n) {return ( n % 2 ) != 0;); => 모든 데이터가 조건을 만족하는가?
     // any_of(v.begin(), v.end(), [](int n) {return ( n % 2 ) != 0;); => 하나의 데이터이상이 조건을 만족하는가?
     // none_of(v.begin(), v.end(), [](int n) {return ( n % 2 ) != 0;); => 모든 데이터가 조건을 만족않는가?
     
     //Q4) 벡터 내부 모든 숫자에 3을 곱하기
     {
         vector<int>::iterator it;
         //for (it = v.begin(); it != v.end(); ++it)
         //{
         //    (*it) *= 3;
         //    // int& data = v[i];
         //    // data *= 3;
         //}

         for_each(v.begin(), v.end(), [](int& n) {return n= n * 3; });
     }

     // Q5 홀수 데이터 일괄 삭제
     {
         struct IsOdd
         {
             bool operator()(int n)
             {
                 return (n % 2) != 0;
             }
         };


         vector<int>::iterator it1 = remove_if(v.begin(), v.end(), IsOdd()); // 순서를 바꾸고 조건에 맞지 않는 데이터의 위치부터 반환
         v.erase(it1, v.end()); // 이렇게 써줘야함
     
     
     }
    return 0;
}
