#include <iostream>
#include "TW_List.h"

using namespace std;

TW_List::TW_List()
{
    head = nullptr;
    tail = nullptr;
}

TW_List::~TW_List()
{
    delete head;
    delete tail;
    
}

bool TW_List::append(std::string data)
{
    // 링크드 리스트 데이터 추가 과정
    // 1. 새로운 노드 삽입
    // 2. 기존 노드 연결

    if (head == nullptr || tail == nullptr ) // 데이터가 없는 경우
    {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;
        head = new_node;
        tail = new_node;
    }
    else // 데이터가 있는 경우
    {
        Node * new_node = new Node;
        new_node->data = data;
        new_node->next = nullptr;

        tail->next = new_node;
        tail = new_node;
    }

    return true;
}

bool TW_List::add(int index, std::string data)
{
    if ( index < -1 )
        return false;

    Node* cur_node = head;
    if ( cur_node == nullptr )
    {
        append(data);
        return true;
    }

    if ( index == -1 )
    {
        Node* new_node = new Node;
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }

    int count = 0;
    while ( cur_node != nullptr )
    {
        if (cur_node == tail)
        {
            append(data);
            return true;
        }

        if ( index == count )
        {
            Node* new_node = new Node;
            new_node->data = data;
            new_node->next = cur_node->next;
            cur_node->next = new_node;
            
            return true;
        }

        count++;
        cur_node = cur_node->next;
    } 


    return false;

}

bool TW_List::del(int index)
{
    if ( index < 0 )
        return false;

    //지우려는 노드 전 노드랑 지우는 노드 다음 노드 연결
    // 해당 노드 지우기.
    Node *before_node = new Node;
    Node *cur_node = new Node;
    cur_node = cur_node->next;

    int count = 1;
    while ( cur_node != nullptr )
    {
        if ( index == 0 )
        {
            cur_node->next = head;
            delete cur_node;
            return true;
        }
        if ( index == count )
        {
            before_node->next = cur_node->next;
            delete cur_node;
            return true;
        }
       /* if ( (index )
        {

        }*/
        count++;
        before_node = before_node->next;
        cur_node = cur_node->next;
    }
   
    return false;
}

Node *TW_List::at(int index)
{
    if ( index < 0 )
        return nullptr;

    Node *cur_node = new Node;

    int count = 0;
    while ( index == count);
    {
        return cur_node;
    }
    count++;
    cur_node = cur_node->next;
}

Node *TW_List::find(std::string data)
{
    Node *cur_node = new Node;
    int count = 0;
    std::string find_what;

    while ( cur_node != nullptr )
    {
        if ( cur_node->data == data )
        {
            return cur_node;
        }
        count++;
        cur_node = cur_node->next;
    }
}

bool TW_List::print() const
{
    Node* cur_node = head;
    while ( cur_node != nullptr )
    {
        cout << cur_node->data << " ";
        cur_node = cur_node->next;
    }
    cout << endl;

    return true;
}