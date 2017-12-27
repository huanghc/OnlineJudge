#include <iostream>

using namespace std;

struct node{
    int time;
    int number;
    node *next, *prev;
    node():time(-1),number(0),next(NULL),prev(NULL){}
    node(int a,int b=0,node *c=NULL,node *d=NULL):time(a),number(b),next(c),prev(d){}
};

int main()
{
    int num,p=0,beginTime,endTime;
    cin >> num;
    node *front,*cur,*tmp;
    front=new node;
    cur=front->next=new node;
    cur->prev=front;
    while(p<num)
    {
        cur=front->next;
        cin >> beginTime >> endTime;
        while(cur->time<beginTime&&cur->time!=-1){
            cur=cur->next;
        }
        if(cur->time>beginTime||cur->time==-1){
            tmp=new node(beginTime,cur->prev->number+1,cur,cur->prev);
            cur->prev->next=tmp;
            cur->prev=tmp;
        }
        while(cur->time<endTime&&cur->time!=-1){
            cur->number++;cur=cur->next;
        }

        if(cur->time>endTime||cur->time==-1){
            tmp=new node(endTime,cur->prev->number-1,cur,cur->prev);
            cur->prev->next=tmp;
            cur->prev=tmp;
        }
        p++;
    }
    int worktime=0,resttime=0,tmp1=0,tmp2=0;
    cur=front->next;
    while(cur->time!=-1)
    {
        tmp1=cur->time;
        while(cur->number!=0){cur=cur->next;}
        tmp2=cur->time;
        tmp1=cur->time-tmp1;
        if(tmp1>worktime) worktime=tmp1;
        cur=cur->next;
        tmp2=cur->time-tmp2;
        if(tmp2>resttime) resttime=tmp2;
    }
    cout << worktime << " " << resttime;
    return 0;
}
