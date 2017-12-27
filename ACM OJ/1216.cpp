#include <iostream>
using namespace std;

template <class Type>
class priorityQueue{
	private:
		int currentSize;
		Type *array;
		int maxSize;
		
	public:
		priorityQueue(int capacity = 1000000){
			array = new Type[capacity];
			maxSize = capacity;
			currentSize = 0;
		}
		priorityQueue(const Type data[],int size){
			maxSize = size+100000;
			currentSize = size;
			array = new Type[maxSize+100000];
			for (int i=0;i<size;++i){
				array[i+1] = data[i];
			}
			buildHeap();
		}
		~priorityQueue(){
			delete [] array;
		}
		
		void doubleSpace(){
	        int *tmp=array;
	        maxSize*=2;
	        array=new int[maxSize];
	        for(int i=0;i<=currentSize;++i) array[i]=tmp[i];
	        delete [] tmp;
		}
		
		bool isEmpty() const {
			return currentSize==0;
		}
		void enQueue(const Type &x){
			if (currentSize==maxSize-1){
				doubleSpace();
			}
			
			int hole = ++currentSize;
			for (;hole>1 && x<array[hole/2];hole/=2){
				array[hole] =array[hole/2];
			}
			array[hole] = x;
		}
		
		Type deQueue(){
			Type minItem;
			minItem = array[1];
			array[1] = array[currentSize--];
			percolateDown(1);
			return minItem;
		}
		
		Type getHead() const {
			return array[1];
		}
		
		void buildHeap(){
			for (int i=currentSize/2;i>0;i--){
				percolateDown(i);
			}
		}

		void percolateDown(int hole){
			int child;
			Type tmp = array[hole];
			for (;hole*2<=currentSize;hole=child){
				child = hole*2;
				if (child!=currentSize && array[child+1]<array[child]){
					child++;
				}
				if (array[child]<tmp){
					array[hole] = array[child];
				}
				else {
					break;
				}
				array[hole] = tmp;
			}
		}
		
		void decrease(int a,Type v){
		    int x,hole=a;
		    array[hole]-=v;
		    x=array[hole];
		    for(;hole>1&&x<array[hole/2];hole=hole/2) array[hole]=array[hole/2];
		    array[hole]=x;
		}
		
		int find(const Type &x){
		    int Min=99999,ID;
		    for(int i=1;i<=currentSize;++i){		    
		        if(array[i]>x&&(array[i]<Min||Min==99999)){		        
		            Min=array[i];
		            ID=i;
		        }
		    }
		    cout << ID << endl;	
		}
}; 

int main()
{
    int n,num,vmp;cin >> n;
    char ch[10];   
    priorityQueue <int> pq;
    for (int i=0;i<n;++i){    
        cin >> ch;
        if(ch[0]=='i') {cin>>num;pq.enQueue(num);}
        if(ch[0]=='f') {cin>>num;pq.find(num);}
        if(ch[0]=='d') {cin>>num;cin>>vmp;pq.decrease(num,vmp);}
    }
    return 0;
}
