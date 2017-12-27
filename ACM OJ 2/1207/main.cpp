#include <iostream>
#include <cstdio>

using namespace std;

template<class T>
class linkQueue
{private:
    struct node{
        T data;
        node *next;
        node(const T &x,node *N=NULL){data=x;next=N;}
        node():next(NULL){}
        ~node(){}
    };
    node *front,*rear;
public:
    linkQueue(){front=rear=NULL;}
    ~linkQueue();
    bool isEmpty(){return front==NULL;}
    void enQueue(const T &x);
    T deQueue();
    T getHead(){return front->data;}
};

template<class T>
void linkQueue<T>::enQueue(const T &x)
{
    if(rear==NULL) {front=rear=new node(x);}
    else{rear->next=new node(x);rear=rear->next;}
}

template<class T>
linkQueue<T>::~linkQueue()
{
    node *tmp;
    while(front!=NULL)
    {
        tmp=front;
        front=front->next;
        delete tmp;
    }
}

template<class T>
T linkQueue<T>::deQueue()
{
    T value=front->data;
    front=front->next;
    if(front==NULL) rear=NULL;
    return value;
}

int main()
{
    linkQueue<int>busQueue,vanQueue;
    long sum_number=0,tmp;
    int bus_number=0,van_number=0;
    int type=0,ship;
    double busWaitTime=0,vanWaitTime=0;
    double bus_averagetime=0,van_averagetime=0;
    cin >> sum_number;
    for(int i=0;i<sum_number;i++)
    {
        cin >> type >> tmp;
        if(type==1){vanQueue.enQueue(tmp);van_number++;}
        if(type==0){busQueue.enQueue(tmp);bus_number++;}
    }
    for(int timer=0;sum_number>0;timer+=10)
    {
        for(ship=0;ship<8&&!busQueue.isEmpty()&&busQueue.getHead()<=timer;++ship)
        {
            busWaitTime+=timer-busQueue.deQueue();
            sum_number--;
        }
        for(;ship<10&&!vanQueue.isEmpty()&&vanQueue.getHead()<=timer;++ship)
        {
            vanWaitTime+=timer-vanQueue.deQueue();
            sum_number--;
        }
        for(;ship<10&&!busQueue.isEmpty()&&busQueue.getHead()<=timer;++ship)
        {
            busWaitTime+=timer-busQueue.deQueue();
            sum_number--;
        }
    }
    if(bus_number!=0)bus_averagetime=busWaitTime/bus_number;
    if(van_number!=0)van_averagetime=vanWaitTime/van_number;
    printf("%.3f",bus_averagetime);
    printf(" ");
    printf("%.3f",van_averagetime);
    return 0;
}
