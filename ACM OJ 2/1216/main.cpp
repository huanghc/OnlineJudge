#include <iostream>

using namespace std;

class priorityQueue{
private:
    int currentSize;
    int *array;
    int maxSize;
    void doubleSpace()
    {
        int *tmp=array;
        maxSize*=2;
        array=new int[maxSize];
        for(int i=0;i<=currentSize;++i) array[i]=tmp[i];
        delete [] tmp;
    }
public:
    priorityQueue(int capacity=100){array=new int[capacity];maxSize=capacity;currentSize=0;}
    void enQueue(const int &x);
    void find(const int &x);
    void decrease(int a,int v);
};

void priorityQueue::decrease(int a,int v)
{
    int x,hole=a;
    array[hole]-=v;
    x=array[hole];
    for(;hole>1&&x<array[hole/2];hole=hole/2) array[hole]=array[hole/2];
    array[hole]=x;
}

void priorityQueue::enQueue(const int &x)
{
    if(currentSize==maxSize-1) doubleSpace();
    int hole=++currentSize;
    for(;hole>1&&x<array[hole/2];hole=hole/2) array[hole]=array[hole/2];
    array[hole]=x;
}

void priorityQueue::find(const int &x)
{
    int Min=-1,ID;
    for(int i=1;i<=currentSize;++i)
    {
        if(array[i]>x&&(array[i]<Min||Min==-1))
        {
            Min=array[i];
            ID=i;
        }
    }
    cout << ID << endl;
}

int main()
{
    int num,tmp,vmp;
    char ch[10];
    cin >> num;
    priorityQueue pq;
    while(num>0)
    {
        cin >> ch;
        if(ch[0]=='i') {cin >>tmp;pq.enQueue(tmp);}
        if(ch[0]=='f') {cin >>tmp;pq.find(tmp);}
        if(ch[0]=='d') {cin >>tmp;cin>>vmp;pq.decrease(tmp,vmp);}
        num--;
    }
    return 0;
}
