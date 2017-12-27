#include <iostream>
#include <string>

using namespace std;

class Editor
{
private:
    struct node;
    node *head;
    int line_length;

public:
    Editor();
    void list(int a,int b);
    void insert(int a,int b,const string &cont);
    void del(int a,int b,int c);
    void print();
    void error(){cout << "Error!" << endl;}
};

struct Editor::node
{
    string data;
    node *next;
public:
    node(string x="",node* n=NULL){data=x;next=n;}
};

Editor::Editor()
{
    line_length=0;
    string str;
    node *p=head=new node;
    getline(cin,str);
    while(str!="******")
    {
        p->next=new node(str);
        p=p->next;
        line_length++;
        getline(cin,str);
    }
}

void Editor::list(int a,int b)
{
    if(a>line_length||b>line_length||a<=0||b<=0||a>b){error();}
    else
    {
        int p=a,q=b-a;
        node *tmp=head;
        while(p>0){tmp=tmp->next;p--;}
        while(q>=0){cout << tmp->data << endl;;tmp=tmp->next;q--;}
    }
}

void Editor::insert(int a,int b,const string &cont)
{
    if(a>line_length||a<=0||b<0){error();}
    else
    {
        int p=a,q=b;
        node *tmp=head;
        while(p>0){tmp=tmp->next;p--;}
        if(q>(tmp->data.size()+1)){error();}
        if(q<(tmp->data.size()+1)){tmp->data.insert(q-1,cont);}
        if(q==(tmp->data.size()+1)){tmp->data=tmp->data+cont;}
    }
}

void Editor::del(int a,int b,int c)
{
    if(a>line_length||a<=0||c<0||b<0){error();}
    else
    {
        int p=a;
        node *tmp=head;
        while(p>0){tmp=tmp->next;p--;}
        if(b>(tmp->data.size())){error();}
        if(b<=(tmp->data.size())){
            if(c>(tmp->data.size()-b+1)){error();}
            else{tmp->data.erase(b-1,c);}
        }
    }
}

void Editor::print()
{
    node *p=head->next;
    int q=line_length;
    while(q>1)
    {
        cout << p->data <<endl;
        q--;
        p=p->next;
    }
    cout << p->data;
}

int main()
{
    Editor editor,*p=&editor;
    char ch;
    string command,content;
    int x,y,z;
    while(true){
        cin >> command;
        if(command=="quit"){p->print();delete p;break;}
        if(command=="list"){
            cin >> x >> y;
            p->list(x,y);
        }
        if(command=="ins"){
            cin >> x >> y;
            ch=cin.get();
            getline(cin,content);
            p->insert(x,y,content);
        }
        if(command=="del"){
            cin >> x >> y >> z;
            p->del(x,y,z);
        }
    }
    return 0;
}
