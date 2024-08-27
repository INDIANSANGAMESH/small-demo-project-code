#include<iostream>
using namespace std;
class node
{
public:

    string name,adddress;
    int age,data;
    node*front=NULL;
    node*rear;
    node*next;
    node*prev;
    node(string name1,string address1,int age1)
    {
        name=name1;
        adddress=address1;
        age=age1;
    }
    void enqueue(string name,string address,int age)
    {
        if(front==NULL)
        {
            node*newnode=new node(name,address,age);
            newnode->data=1;
            front=newnode;
            rear=front;
        }
        else
        {
            node*newnode=new node(name,address,age);
            newnode->data=rear->data+1;
            rear->next=newnode;
            rear->prev=rear;
            rear=newnode;
            //rear->next=front;
            //front->prev=rear;
        }
    }
    void dequeue()
    {
        node*temp=front;
        if(rear==front)
        {
            cout<<"Token : "<<temp->data<<"\nName :"<<temp->name<<"\nAddress :"<<temp->adddress<<"\n Age :"<<temp->age<<endl;
            front=NULL;
            rear=front;
            cout<<"queue is empty"<<endl;

        }
        else
        {
            cout<<"Token : "<<temp->data<<"\nName :"<<temp->name<<"\nAddress :"<<temp->adddress<<"\n Age :"<<temp->age<<endl;
            front=front->next;
        }
        delete temp;
    }
    void disp()
    {
        node*temp=front;
        while(temp)
        {
            cout<<"Token : "<<temp->data<<"\nName :"<<temp->name<<"\nAddress :"<<temp->adddress<<"\n Age :"<<temp->age<<endl;
            temp=temp->next;
        }
    }
    void count()
    {
        cout<<" remaining :"<<rear->data-front->data+1<<endl;
    }
};
int main()
{
    node q(" "," ",0);
    char ch;
do{
    // since ch===a loop to encheue
    cout<<"entry or.......";
    cin>>ch;
    switch(ch)
    {
case 'a' :
       {
        string name,address;
        int age;
        cout<<"\nenter name : ";
        cin>>name;
        cout<<"\nenter Address : ";
        cin>>address;
        cout<<"enter age : ";
        cin>>age;
        q.enqueue(name,address,age);
        }break;

    //if ch === s then loop stops to dequeue
    case 's':
    {
        q.dequeue();
    }break;
    case 'c':
    {
        q.count();
    }
    break;
    }
   }while(ch!='Q');
    return  0;
}
