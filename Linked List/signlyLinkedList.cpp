#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

    //Destructor
    ~Node()
    {
        int val=this->data;
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free from node with data: "<<val<<endl;
    }
};

void insertAtHead(Node* &head,int d);
void insertAtTail(Node* &tail,int d);
void insertAtMiddle(Node* &head,Node* &tail,int position,int d);
void deleteNode(Node* &head,Node* &tail,int position);
void print(Node* &head);
void reverse(Node* &head);
int getMiddle(Node* &head);
void findMiddle(Node* &head);
Node* floydDetectLoop(Node* &head);
void removeLoop(Node* &head,Node* &tail);
int main()
{   
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
  
    print(head);
    insertAtTail(tail,30);
    print(head);
    
    insertAtMiddle(head,tail,3,22);
    print(head);
    insertAtMiddle(head,tail,3,25);
    print(head);
    insertAtMiddle(head,tail,3,30);
    print(head);
    insertAtMiddle(head,tail,3,28);
    print(head);
    insertAtMiddle(head,tail,3,33);
    print(head);
    insertAtMiddle(head,tail,3,35);
    print(head);
    deleteNode(head,tail,3);
    print(head);
    reverse(head);
    print(head);
    reverse(head);
    print(head);
    findMiddle(head);

    cout<<"\nHead: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
    tail->next=head->next->next->next;
    Node *abc=floydDetectLoop(head);
    abc==NULL?cout<<"\nNo loop found":cout<<"\nLoop found at: "<<abc->data;
    removeLoop(head,tail);
    
    cout<<"\nFinal: "<<endl;
    print(head);
    return 0;
}

void insertAtHead(Node* &head,int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d)
{
    Node* temp= new Node(d);
    tail->next=temp;
    tail=temp;
}
void print(Node* &head)
{
    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
    cout<<endl;
}
void insertAtMiddle(Node* &head,Node* &tail,int position,int d)
{
    if(position==1)
    {
        insertAtHead(head,d);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
    return;
}
void deleteNode(Node* &head,Node* &tail,int position)
{
    //delete first node
    if(position==1)
    {
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node* curr=head;  
        Node* prev=NULL;
        int count=1;
        while(count<position)
        {
            prev=curr;
            curr=curr->next;
            count++;
        }

        prev->next=curr->next;
        if(curr->next==NULL)
        {
            tail=prev;
        }
        else curr->next=NULL;
        delete curr;
    }
}
void reverse(Node* &head)
{
    if(head==NULL)
    {
        cout<<"List is empty!"<<endl;
    }
    Node* prev=NULL;
    Node* current=head;
    Node* further=NULL;
    
    while(current!=NULL)
    {
    further=current->next;
    current->next=prev;
    prev=current;
    current=further;
    }
    head=prev;
}
int getLength(Node* head)
{
    int length=0;
    while(head!=NULL)
    {
        length++;
        head=head->next;
    }
    return length;
}
/*int getMiddle(Node* &head)
{
   // none or one node available
    if(head==NULL||head->next==NULL)
    {
        cout<<"\nInside if cond 1 loop "<<endl;
        return head->data;
    }
    //for 2nd node
    if(head->next->next=NULL)
    {
        cout<<"\nInside if cond 1 loop "<<endl;
        return head->data;
    }
    Node* slow=head;
    Node* fast=head;
    
    if(head!=NULL){
    while(fast->next!=NULL&&fast!=NULL)
    {
       fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
    }
     else return head->data;   
    
}*/
void findMiddle(Node* &head) {
    
    /*cout<<"Middle element: "<<getMiddle(head);
    return;
     Method1: 
    int l=getLength(head);
    Node*temp=head;
    int ans=(l/2);
    int count=0;
    while(count<ans)
    {
        temp=temp->next;
        count++;
    }
    return temp;*/
   Node* slow=head;
    if(head==NULL)
    return;
   Node* fast=head->next;
   int val;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        
        if(fast->next!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;
        
    }
    cout<<"\nMiddle: "<<slow->data;
    return;
    
}
Node* floydDetectLoop(Node*&head)
{
    if(head==NULL)
    return NULL;
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL&& slow!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast)
        {
            slow=head;
            while(slow==fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            return fast;
        }
    }
        return NULL;
}
void removeLoop(Node* &head,Node* &tail)
{
    Node* poi=floydDetectLoop(head);
   if (poi==NULL)
   {
    cout<<"Loop not found! "<<endl;
    return;
   }
    Node* temp=poi;
    while(temp->next!=poi)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    tail=temp;
    cout<<"\nLoop removed by pointing "<<temp->data<<" to NULL"<<endl;
    return;
}