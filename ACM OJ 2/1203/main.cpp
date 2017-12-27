#include <iostream>

using namespace std;

template<class T>
class seqList
{
    friend seqList operator+(const seqList &a,const seqList &b)
    {
        seqList<T> c(a.length+b.length);
        for(int i=0;i<a.length;i++){c.data[i]=a.data[i];}
        for(int j=0;j<b.length;j++){c.data[a.length+j]=b.data[j];}
        return c;
    }
    friend istream& operator>>(istream &in,seqList& obj)
    {
        for(int i=0;i<obj.length;++i){in >> obj.data[i];}
        return in;
    }
    friend ostream& operator<<(ostream &os,const seqList& obj)
    {
        for(int i=0;i<obj.length;++i){os << obj.data[i] << " ";}
    return os;
    }
private:
    T *data;
    int length;
public:
    seqList(int initSize=10);
    seqList(const seqList &);
    seqList &operator=(const seqList &);
};

template<class T>
seqList<T>::seqList(int initSize)
{
    data=new T[initSize];
    length=initSize;
}

template<class T>
seqList<T>::seqList(const seqList<T> &other)
{
    length=other.length;
    data=new T[other.length];
    for(int i=0;i<other.length;++i){data[i]=other.data[i];}
}

template<class T>
seqList<T>& seqList<T>::operator=(const seqList<T> &other)
{
    if(this==&other) return *this;
    delete []data;
    length=other.length;
    data=new T[other.length];
    for(int i=0;i<other.length;++i){data[i]=other.data[i];}
    return *this;
}

int main()
{
    char ch[6];
    int x,y;
    cin >> ch;
    cin >> x >> y;
    if(ch[0]=='c'){seqList<char> s1(x),s2(y),s3(x+y);cin >> s1;cin >> s2;s3=s1+s2;cout << s3;}
    if(ch[0]=='i'){seqList<int> s1(x),s2(y),s3(x+y);cin >> s1;cin >> s2;s3=s1+s2;cout << s3;}
    if(ch[0]=='d'){seqList<double> s1(x),s2(y),s3(x+y);cin >> s1;cin >> s2;s3=s1+s2;cout << s3;}
    return 0;
}
