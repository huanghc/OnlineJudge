#include <iostream>
using namespace std;

template <class Type>
class priorityQueue{
	private:
		int currentSize;
		Type *array;
		int maxSize;
		
	public:
		priorityQueue(int capacity = 100){
			array = new Type[capacity];
			maxSize = capacity;
			currentSize = 0;
		}
		priorityQueue(const Type data[],int size){
			maxSize = size+100;
			currentSize = size;
			array = new Type[maxSize+100];
			for (int i=0;i<size;++i){
				array[i+1] = data[i];
			}
			buildHeap();
		}
		~priorityQueue(){
			delete [] array;
		}
		
		void doubleSpace(){
			Type *tmp=new Type[maxSize*2];
			for (int j = 0; j < currentSize; ++j)  tmp[j] = array[j];
			delete []array;  
			array = tmp; 
		    maxSize = maxSize*2;
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
				percolateDown();
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
}; 

int main(){
	cout<<"111:"<<endl;
}
