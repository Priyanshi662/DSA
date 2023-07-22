//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// Below approach has Time complexity = O(n*m*n) and space complexity= O(n*m)
Node* merge(Node* a,Node* b)
{
    Node* left=a;
    Node* right=b;
    Node* res=new Node(-1);
    Node* temp=res;
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->bottom=left;
            left=left->bottom;
        }
        else
        {
            temp->bottom=right;
            right=right->bottom;
        }
        temp=temp->bottom;
    }
    while(left!=NULL)
    {
        temp->bottom=left;
        left=left->bottom;
        temp=temp->bottom;
    }
    while(right!=NULL)
    {
        temp->bottom=right;
        right=right->bottom;
        temp=temp->bottom;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
    if(root==NULL ||root->next==NULL)
        return root;
    
    root->next=flatten(root->next);
    root=merge(root,root->next);
    return root;
}
// Using Priortity Queue:

struct compare{
	bool operator()(Node* a,Node* b)
	{
		return a->data>b->data;
	}
};
Node* flattenUsingPq(Node* root)
{
	// push the head of all linked lists connected by next pointers
	Node* temp=root;
	priority_queue<Node*,vector<Node*>,compare> pq;
	while(temp!=NULL)
	{
		pq.push(temp);
		temp=temp->next;
	}
	Node* res=new Node(-1);
	temp=res;
	while(!pq.empty())
	{
		Node* t=pq.top();
		pq.pop();
		temp->bottom=t;
		if(t->bottom)
			pq.push(t->bottom);
		temp=temp->bottom;
	}
	return res->bottom;
}
