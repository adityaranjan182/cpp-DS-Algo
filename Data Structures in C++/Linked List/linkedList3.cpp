#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
Node *head=nullptr;

void createNode(int arr[], int n) //array data to link list data
{
    int i;
    Node *t,*last;
    head=new Node;
    head->value=arr[0];
    head->next=nullptr;
    last=head;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->value=arr[i];
        t->next=nullptr;
        last->next=t;
        last=t;
    }

}

void Display(struct Node *p) // front to end
{   cout<<"Displaying LinkedList:"<<endl;
    while(p!=0)
    {
        cout<<p->value<<" ";
        p=p->next;
    }
}

void Display_Recursive(struct Node *p) // end to front
{
    if(p!=0)
    {
        Display_Recursive(p->next);
        cout<<p->value<<" ";
    }
}

int count_node(struct Node *p) //counting number of nodes in LinkList
{
    if(p==0)
        return 0;
    else
        return (count_node(p->next)+1);
}

int add_nodesValue(struct Node *p) //sum of all nodes value
{
    if(p==0)
        return 0;
    else
        return add_nodesValue(p->next)+p->value;
}

int maximum_node(struct Node *p) //maximum node value
{
    int maxi=INT_MIN;
    while(p!=nullptr)
    {
        if((p->value)>maxi)
            maxi=p->value;
        p=p->next;
    }
    return(maxi);
}

string search_node(struct Node *p, int key) //linear search
{
    while(p!=0)
    {
        if(p->value==key)
            return "Found";
        p=p->next;
    }
    return "Not found";
}

void insert_node(int pos, int data) //inserting a node at a given position
{
    Node *t=new Node,*p;
    t->value=data;
    if(pos==0){
        t->next=head;
        head=t;
    }
    if(p>0)
    {
        p=head;
        for(int i=0;i<pos-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}

void delete_node(struct Node *p,int pos)
{
    Node *q=nullptr;
    if(pos==1)
    {
        q=head;
        head=head->next;
        delete q;
    }
    if(pos>1)
    {
        for(int i=0;i<pos-1;i++){
            q=p;
            p=p->next;
            }
        q->next=p->next;
        delete p;
    }
}

string isSorted(struct Node *p)
{
    while(p!=0)
    {
        if(p->value>p->next->value)
            return "Unsorted LL";
        p=p->next;
    }
    return "Sorted LL";

}

void removeDuplicates(struct Node *p)
{
    Node *q,*dup;
    while(p!=0 && p->next!=0)
    {
        q=p;
        while(q->next!=0){

        if(p->value==q->next->value){
            dup = q->next;
            q->next = q->next->next;
            delete(dup);
        }
        else{
            q=q->next;
        }
    }
    p=p->next;
}
}

void reverse_LL(struct Node *p)
{
    Node *q=nullptr,*r=nullptr;
    while(p!=0)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}

void reverse_recursive(struct Node *q, struct Node *p)
{
    if(p!=0)
    {
        reverse_recursive(p,p->next);
        p->next=q;
    }
    else{
        head=q;
    }
}

void reverse_K_nodes(int index)
{
    Node *q=nullptr,*r=nullptr,*p=head,*temp=head,*join;
    for(int i=0;i<index-1;i++)
        temp=temp->next;
    join=temp->next;
    temp->next=nullptr;
    while(p!=0)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }head=q;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=join;
}

void right_shift(int k)
{
    while(k>0)
    {
        static Node *q=head,*r=nullptr;
        while(q->next!=0)
    {
        r=q;
        q=q->next;
    }
        q->next=head;
        r->next=nullptr;
        head=q;
        k--;
    }
}

int main()
{
    int a[]={1,2,1,3,4,5};
    createNode(a,6);
    Display(head);
    cout<<endl;
    Display_Recursive(head);
    cout<<endl<<"No. of nodes = "<<count_node(head);
    cout<<endl<<"Sum of data of all nodes = "<<add_nodesValue(head);
    cout<<endl<<"Maximum node value is = "<<maximum_node(head);
    cout<<endl<<"key search status: "<<search_node(head,4);
    insert_node(2,3);
    cout<<endl<<"After Insertion"<<endl;
    Display(head);
    cout<<endl;
    cout<<"After deletion"<<endl;
    delete_node(head,3);
    Display(head);
    cout<<endl<<isSorted(head);
    cout<<endl;
    cout<<"After removing duplicates"<<endl;
    removeDuplicates(head);
    Display(head);
    reverse_LL(head);
    cout<<endl<<"After reversing SLL"<<endl;
    Display(head);
    reverse_recursive(nullptr,head);
    cout<<endl<<"After recursive reversing SLL"<<endl;
    Display(head);
    cout<<endl;
    reverse_K_nodes(3);
    Display(head);
    cout<<endl;
    right_shift(3);
    Display(head);
}
