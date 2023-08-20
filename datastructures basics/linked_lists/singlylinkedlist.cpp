#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
    //constructor
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
    //destructor   
    ~Node()
    {
        if(this->next!=NULL)
        {
            this->next=NULL;
            delete next;
        }
    }
};

void print(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//insert at head
void insertAtHead(Node* &head,int data)
{
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

//insert at tail
void insertAtTail(Node* &tail,int data)
{
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

//insert at position
void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    Node* nodeToInsert=new Node(data);
    if(position==1)
    {
        insertAtHead(head,data);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,data);
        return;
    }
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

//delete at any position
void deleteAtPosition(Node* &head,Node* &tail,int position)
{
    //get prev and curr node for the position.
    Node*  prev=NULL;
    Node* curr=head;
    int cnt=1;
    if(position==1)
    {
        head=curr->next;
        curr->next=NULL;
        delete curr;
        return;
    }
    while(cnt<position)
    {
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    if(curr->next==NULL)
    {
        tail=prev;
        prev->next=NULL;
        delete curr;
        return;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
int main()
{
    Node* n1=new Node(10);
    Node* head=n1;
    Node* tail=n1;
    print(head);
    cout<<endl;
    //insert at head;
    insertAtHead(head,15);
    print(head);
    cout<<endl;
    // insert at tail;
    insertAtTail(tail,20);
    print(head);
    cout<<endl;

    //insert at any position
    insertAtPosition(head,tail,3,22);
    print(head);
    cout<<endl;
    insertAtPosition(head,tail,1,25);
    print(head);
    cout<<endl;
    insertAtPosition(head,tail,6,28);
    print(head);
    cout<<endl;

    //print tail after inserting at last
    cout<<tail->data<<endl;

    //delete at any position.
    deleteAtPosition(head,tail,1);
    print(head);
    cout<<endl;
    deleteAtPosition(head,tail,2);
    print(head);
    cout<<endl;
    deleteAtPosition(head,tail,4);
    print(head);
    cout<<endl;
    deleteAtPosition(head,tail,1);
    print(head);
    cout<<endl;
    
    
}