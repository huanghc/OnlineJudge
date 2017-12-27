#include <iostream>

using namespace std;

int main()
{
    int inDegree[100000],queue[100000];
    int number,amount,p=1;
    cin >> number >>amount;
    struct node
    {
        int data;
        node *next;
        node():data(0),next(NULL){}
        node(int d, node* n=NULL):data(d),next(n){}
    };
    node **map;
    node *tmp;
    map=new node*[number+1];
    for(int j=0;j<number+1;j++)
    {
        map[j]=NULL;
    }
    int begin,end;
    while(p<amount+1)
    {
        cin >> begin >> end;
        tmp=new node(end,map[begin]);
        map[begin]=tmp;
        inDegree[end]++;
        p++;
    }
    begin=end=0;
    for(int i=1;i<number+1;i++)
    {
        if(inDegree[i]==0){queue[end]=i;end++;}
    }
    int now;
    p=0;
    while(number>0)
    {
        now=end;
        while(begin<now)
        {
            tmp=map[queue[begin]];
            while(tmp!=NULL)
            {
                inDegree[tmp->data]--;
                if(inDegree[tmp->data]==0){queue[end]=tmp->data;end++;}
                tmp=tmp->next;
            }
            begin++;
            number--;
        }
        p++;
    }
    cout << p;
    return 0;
}
