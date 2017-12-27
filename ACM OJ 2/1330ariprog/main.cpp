#include <iostream>

using namespace std;

int list[700000];
bool judge[700000]={0};

struct node
{
    int data;
    node *next;
    node():data(0),next(NULL){}
    node(int d,node* n=NULL):data(d),next(n){}
};

void swap(int &x,int &y)
{
    int tmp=x;
    x=y;
    y=tmp;
}

void qsort(int start,int end)
{
    if(start>=end){return;}
    int s=start,e=end,mid=list[(start+end)/2];
    while(s<=e)
    {
        while(list[s]<mid){s++;}
        while(list[e]>mid){e--;}
        if(s<=e)
        {
            swap(list[s],list[e]);
            s++;
            e--;
        }
    }
    qsort(start,e);
    qsort(s,end);
}

int main()
{
    int length,limit,p=0;
    cin >> length >> limit;
    int i,j;
    node* path[10001];
    for(i=0;i<10001;i++)
    {
        path[i]=new node;
    }
    node *w,*w1;
    for(i=0;i<=limit;i++)
    {
        for(j=i;j<=limit;j++)
        {
            if(judge[i*i+j*j]==0){
                list[p]=i*i+j*j;
                p++;
                judge[i*i+j*j]=1;
            }
        }
    }
    qsort(0,p-1);
    int t,tmp1,tmp2,l=0;
    int write=0;
    for(i=0;i<=p-limit;i++)
    {
        for(j=i+1;j<=p-limit+1;j++)
        {
            if((list[i]+(list[j]-list[i])*(length-1))>list[p-1]){break;}
            t=2;
            tmp1=list[j];
            tmp2=list[j]-list[i];
            while(t<length)
            {
                tmp1+=tmp2;
                if(judge[tmp1]==0){break;}
                t++;
            }
            if(t==length){
                w=path[tmp2];
                while(w->next!=NULL){
                    w=w->next;
                }
                w1=new node(list[i]);
                w->next=w1;
                l=l<tmp2?tmp2:l;
            }
        }
    }
    i=1;
    while(i<=l)
    {
        if(path[i]->next==NULL){i++;continue;}
        else{
            w=path[i]->next;
            while(w!=NULL)
            {
                cout << w->data << " " << i <<endl;
                w=w->next;
            }
        }
        i++;
    }
    if(l==0){cout << "NONE";}
    return 0;
}
