#include <iostream>

using namespace std;

struct node{
    int data;
     node *next,*prev;
     node():data(0),next(NULL),prev(NULL){}
     node(int d,node *n=NULL,node *p=NULL):data(d),next(n),prev(p){}
};

class set{
private:
    node *front,*rear;
    bool exist(int a);
public:
    set(){front=new node;rear=new node;front->next=rear;rear->prev=front;}
    void add(int a);
    void sub(int a);
    void multiple(int a);
    void print();
};

void set::print()
{
    node *p;
    p=front->next;
    while(p!=rear)
    {
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

void set::add(int a)
{
    int b=a,tmp;
    node *p,*q;
    while(b>0)
    {
        cin>>tmp;
        p=front->next;
        while(p!=rear&&p->data<tmp){p=p->next;}
        if(p==rear||p->data>tmp){q=new node(tmp,p,p->prev);p->prev->next=q;p->prev=q;}
        else{b--;continue;}
        b--;
    }
    print();
}

void set::sub(int a)
{
    int b=a,tmp;
    node *p,*q;
    while(b>0)
    {
        cin>>tmp;
        p=front->next;
        while(p!=rear&&p->data<tmp){p=p->next;}
        if(p==rear||p->data>tmp){b--;continue;}
        else{p->prev->next=p->next;p->next->prev=p->prev;}
        delete p;''
        b--;
    }
    print();
}

void set::multiple(int a)
{
    int b=a,tmp;
    node *front1,*rear1;
    front1=new node;rear1=new node;front1->next=rear1;rear1->prev=front1;
    node *p,*q,*r,*s;
    while(b>0)
    {
        cin>>tmp;
        p=front->next;
        while(p!=rear&&p->data<tmp){
            p=p->next;
        }
        if(p==rear||p->data>tmp){b--;continue;}
        else{
            r=front1->next;
            while(r!=rear1&&r->data<p->data){r=r->next;}
            if(r==rear1||r->data>p->data){
                s=new node(p->data,r,r->prev);r->prev->next=s;r->prev=s;
            }
            b--;
        }
    }
    front=front1;
    rear=rear1;
    print();
}

int main()
{
    int num1,num2;
    cin >> num1;
    char ch;
    set s;
    while(num1>0){
        cin >> ch;
        cin >> num2;
        if(ch=='+')s.add(num2);
        if(ch=='-')s.sub(num2);
        if(ch=='*')s.multiple(num2);
        num1--;
    }
    return 0;
}
