#include <iostream>

using namespace std;

struct node{
    int data;
     node *next;
     node():data(0),next(NULL){}
     node(int d,node *n=NULL):data(d),next(n){}
};

int main()
{
    int num_list,tmp;
    node *front;
    node *p;
    p=front=new node;
    cin >> num_list;
    while(num_list>0){
        cin >> tmp;
        p->next=new node(tmp);
        p=p->next;
        num_list--;
    }
    int num_search;
    cin >> num_search;
    node *q;
    while(num_search>0){
        cin >> tmp;
        p=front;
        while(p->next!=NULL&&p->next->data!=tmp){p=p->next;}
        if(p->next==NULL){cout << "N" << endl;}
        else{
            cout << "Y" << endl;
            q=p->next;
            p->next=q->next;
            q->next=front->next;
            front->next=q;
        }
        num_search--;
    }
    return 0;
}

