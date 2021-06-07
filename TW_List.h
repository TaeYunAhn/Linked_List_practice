#pragma once
#include <string>


struct Node
{
    std::string data;
    Node *next;
};

class TW_List
{
public:

    TW_List();
    ~TW_List();

   
    bool append(std::string data);
    bool add(int index, std::string data);
    bool del(int index);
    Node *at(int index);

    Node *find(std::string data);
    bool print() const;

private:

    Node *head;
    Node *tail;
};

//Node* at(int index)
//{
//    Node a;
//    return a;
//}
//
//bool b = a.at(0);