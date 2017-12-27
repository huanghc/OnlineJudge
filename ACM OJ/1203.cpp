using namespace std;
template <class elemType>
class list{
	public:
		virtual void clear()=0;
		virtual int length() const=0;
		virtual int search(const elemType &x) const=0;
		virtual elemType visit(int i) const=0;
		virtual void traverse() const=0;
		virtual ~list(){};
		virtual void insert(int i, const elemType &x)=0; 
};
 
class OutOfBound{};
class IllegalSize{};
template <class elemType>
class seqList: public list<elemType>
{ 
 
private:
    elemType *data;
    int currentLength;
    int maxSize;
    
    void doubleSpace();
public:
    seqList(int initSize = 21000); 
	seqList(const seqList &other);
    ~seqList()  {delete [] data;}
    int length() const {return currentLength;}
    int search(const elemType &x) const ;
    elemType visit(int i) const;
    void insert(int i, const elemType &x); 
    void remove(int i);  
    void clear();
    void traverse() const ;
    seqList<elemType> &operator=(const seqList<elemType> &other);
	seqList<elemType> operator+ (const seqList<elemType> &a);
    
};
 
template <class elemType> 
seqList <elemType>::seqList(const seqList<elemType> &other){
	currentLength=other.currentLength;
	maxSize=other.maxSize;		   	       
	data=new elemType[maxSize];
	for (int i=0;i<currentLength;++i){
		data[i]=other.data[i];
	}
}
 
template <class elemType> 
void seqList< elemType >:: doubleSpace()
{   elemType *tmp=new elemType[maxSize*2];
	if (!tmp) throw IllegalSize();
	for (int j = 0; j < currentLength; ++j)  tmp[j] = data[j];
	delete []data;  
	data = tmp; 
    maxSize = maxSize*2;
}
 
template <class elemType>
seqList <elemType> :: seqList(int initSize){
	if (initSize <= 0) throw IllegalSize();	
	data = new elemType[initSize+1];
	if  (!data) throw IllegalSize();
	maxSize = initSize;
	currentLength = 0;
}
 
template <class elemType>
int seqList <elemType> :: search(const elemType &x) const{
	if (x>=currentLength || x<0) throw OutOfBound();
	for (int j=0;j<currentLength;++j){
		if (data[j] == x) return j;
	}
	return -1;
} 
 
template <class elemType>
elemType seqList <elemType> :: visit(int i) const{
	if (i>=currentLength || i<0) throw OutOfBound();
	return data[i];
}
 
template <class elemType>
void seqList <elemType> :: insert(int i, const elemType &x){
	if (i>currentLength || i<0) throw OutOfBound();
	if (maxSize == currentLength) doubleSpace();
	for (int j=currentLength; j>i; j--)
        data[j]=data[j-1]; 
    data[i]=x;
    currentLength++;
}
 
template <class elemType>
void seqList <elemType> :: remove(int i){
	if (i>=currentLength || i<0) throw OutOfBound();
	for (int j=i;j<currentLength-1;++j){
		data[j]=data[j+1];
	}
	currentLength--;
}
 
template <class elemType>
void seqList <elemType> :: clear(){
	currentLength = 0;
}
 
template <class elemType>
void seqList <elemType> :: traverse() const{
	for (int i=0;i<currentLength;++i){
		cout<<data[i]<<' ';
	}
}
 
template <class elemType>
seqList<elemType> seqList<elemType>::operator+(const seqList<elemType> &a){
    int len=currentLength+a.currentLength;
	seqList<elemType> c(len);
	for (int i=0;i<currentLength;++i){
		c.data[i]=data[i];
	}
    for (int i=currentLength;i<len;++i){
    	c.data[i]=a.data[i-currentLength];
	}
	c.currentLength = len;
	return c;		
}
 
template <class elemType>
seqList<elemType> &seqList<elemType>::operator=(const seqList<elemType> &other){
	if (this==&other) return *this;
	delete [] data;
    currentLength=other.currentLength;
	maxSize=other.maxSize;		   	       
	data=new elemType[maxSize];
	for (int i=0;i<currentLength;++i){
		data[i]=other.data[i];
	}
	return *this;
}
 
int main(){	
	string lei;
	cin>>lei;
 
	int n,m;
	cin>>n>>m;
 
	if (lei=="int"){
		seqList<int> chlist1(n);
		seqList<int> chlist2(m);
		seqList<int> chlist3(m+n);
		int ctmp;
		for (int i=0;i<n;++i){
			cin>>ctmp;chlist1.insert(i,ctmp);				
		}
		for (int i=0;i<m;++i){
			cin>>ctmp;chlist2.insert(i,ctmp);
		}
		chlist3=(chlist1+chlist2);
		chlist3.traverse();
	}
	if (lei=="double"){
		seqList<double> chlist1(n);
		seqList<double> chlist2(m);
		seqList<double> chlist3(m+n);
		double ctmp;
		for (int i=0;i<n;++i){
			cin>>ctmp;chlist1.insert(i,ctmp);				
		}
		for (int i=0;i<m;++i){
			cin>>ctmp;chlist2.insert(i,ctmp);
		}
		chlist3=(chlist1+chlist2);
		chlist3.traverse();
	}
	if (lei=="char"){
		seqList<char> chlist1(n);
		seqList<char> chlist2(m);
		seqList<char> chlist3(m+n);
		char ctmp;
		for (int i=0;i<n;++i){
			cin>>ctmp;chlist1.insert(i,ctmp);				
		}
		for (int i=0;i<m;++i){
			cin>>ctmp;chlist2.insert(i,ctmp);
		}
		chlist3=(chlist1+chlist2);
		chlist3.traverse();
	}		
}