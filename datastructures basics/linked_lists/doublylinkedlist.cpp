#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    //contructor
    Node(int data)
    {
        this->data=data;
        this->prev=NULL;
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

//print
void print(Node* &head)
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
    head->prev=temp;
    head=temp;
}
//insert at tail
void insertAtTail(Node* &tail,int data)
{
    Node* temp=new Node(data);
    temp->prev=tail;
    tail->next=temp;
    tail=temp;
}
//insert at any position
void insertAtPosition(Node* &head,Node* &tail,int position,int data)
{
    Node* nodeToInsert=new Node(data);
    Node* temp=head;
    if(position==1)
    {
        insertAtHead(head,data);
        return;
    }
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
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}
// delete at position
void deleteAtPosition(Node* &head,Node* &tail,int position)
{
    Node* prev=NULL;
    Node* curr=head;
    int cnt=1;
    if(position==1)
    {
        head=head->next;
        head->prev=NULL;
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
        prev->next=NULL;
        curr->prev=NULL;
        tail=prev;
        delete curr;
        return;
    }
    prev->next=curr->next;
    curr->next->prev=prev;
    curr->next=NULL;
    curr->prev=NULL;
    delete curr;


}
int main()
{
    Node* n1=new Node(10);
    Node* head=n1;
    Node* tail=n1;

    // print
    print(head);
    cout<<endl;

    //insert at head;
    insertAtHead(head,15);
    print(head);
    cout<<endl;
    // insert at tail;
    insertAtTail(tail,22);
    print(head);
    cout<<endl;
    //insert at any position;
    insertAtPosition(head,tail,2,35);
    print(head);
    cout<<endl;
    insertAtPosition(head,tail,1,26);
    print(head);
    cout<<endl;
    insertAtPosition(head,tail,2,35);
    insertAtPosition(head,tail,2,35);
    print(head);
    cout<<endl;

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


    return 0;
}