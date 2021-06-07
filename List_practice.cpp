#include <iostream>
#include <string>
#include "TW_List.h"


// TODO
// 소멸자 delete
// 0 인덱스에 데이터 삽입  check
// delete, at, find 구현

int main()
{
    TW_List list;
    list.append("마린");
    list.append("메딕");
    list.append("시즈탱크");
    list.append("배틀쿠르져");

    list.add(2, "사이언스베슬");

    list.print();
    

    list.del(0);
    list.del(1);

    list.print();

    Node* tmp =list.at(0);
    tmp->data = "고스트";

    list.print();

    Node* tmp2 = list.find("메딕");
    if ( tmp2 )
    {
        std::cout <<"메딕 있음" << std::endl;
    }
    else
    {
        std::cout <<"메딕 없음" << std::endl;
    }

    Node* tmp3 =list.at(0);
    tmp3->next->data = "벌쳐";

    list.print();

    return 0;
}