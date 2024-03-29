#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// detect Loop using map and floyd cycle detection algorithm
bool detectLoop(Node* head)
{
    unordered_map<Node*,int> mp;
    Node* temp;
    temp=head;
    while(temp->next!=NULL)
    {
        if(mp.find(temp)!=mp.end())
            return true;
        mp[temp]++;
        temp=temp->next;
    }
    return false;
}

bool detectLoop(Node* head)
{
    // Floyd Cycle Detection Algorithm:
    if(head==NULL)
        return false;
    Node* slow=head;
    Node* fast=head;
    // here the order matters in while loop - first the node is checked
    while(fast!=NULL &&fast->next!=NULL )
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            return true;
    }
    return false;
}

bool detectLoopBruteForce(Node* head)
{
    set<Node*> s;
    // create a set and if the current node is already present in the set then return true
    while(head->next!=NULL)
    {
        if(s.find(head)!=s.end())
            return true;
        s.insert(head);
        head=head->next;
    }
    return false;
}
