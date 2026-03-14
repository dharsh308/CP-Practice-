#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;
        Node *c = head;
        while (c != nullptr)
        {
            Node *newNode = new Node(c->val);
            newNode->next = c->next;
            c->next = newNode;
            c = newNode->next;
        }
        Node *o = head;
        c = head->next;
        while (o != nullptr)
        {
            if (o->random != nullptr)
                o->next->random = o->random->next;
            o = o->next->next;
        }

        o = head;
        Node *t = head->next;
        c = t;
        while (o != nullptr)
        {
            o->next = o->next->next;
            if (c->next != nullptr)
                c->next = c->next->next;
            o = o->next;
            c = c->next;
        }
        return t;
    }
};