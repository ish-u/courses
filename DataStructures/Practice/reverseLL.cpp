#include <iostream>
#include <iomanip>
using namespace std;

#include "sll.h"

template <typename T>
void reverseList(Node<T> *node)
{
    if(node  == 0)
    {
        return;
    }
    reverseList(node->nextNode);
    cout<<node->data<<" ";
}

int main()
{
    SinglyLinkedList<int> *S = new SinglyLinkedList<int>();
    int n = 0; cin>>n;
    for(int i = 0; i < n; i++)
    {
        S->insertAtEnd();
    }
    S->traverse();
    reverseList<int>(S->returnHead());
    return 0;
}