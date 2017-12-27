#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
    node():data(0),next(NULL){}
    node(int a,node *n=NULL):data(a),next(n){}
};

void sort(node *p)
{
    int min;
    if(p->next==NULL||p->next->next==NULL)return;
    node *order,*pos,*minp,*tmp;
    for(order=p;order->next!=NULL;order=order->next)
    {
        minp=order;
        min=order->next->data;
        for(pos=order->next;pos->next!=NULL;pos=pos->next)
        {
            if(pos->next->data<min){minp=pos;min=pos->next->data;}
        }
        if(minp==order){continue;}
        tmp=minp->next;
        minp->next=tmp->next;
        tmp->next=order->next;
        order->next=tmp;
    }
}

void print(node *p)
{
    if(p->next==NULL)return;
    node *pos;
    pos=p->next;
    while(pos!=NULL){cout << pos->data << " ";pos=pos->next;}
}

int main()
{
    int num,a=0;
    cin >> num;
    int tmp;
    node *front,*p;
    p=front=new node;
    while(a<num)
    {
        cin >> tmp;
        p->next=new node(tmp);
        p=p->next;
        a++;
    }
    sort(front);
    print(front);
    return 0;
}

