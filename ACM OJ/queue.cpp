
template <class elemType>
class queue{
	public:
		virtual bool isEmpty()=0;
		virtual void enQueue(const elemType &x)=0;
		virtual elemType deQueue()=0;
		virtual elemType getHead()=0;
		virtual ~queue(){}
};

template <class elemType>
class linkQueue:public queue<elemType>{
	private:
		struct node{
			elemType data;
			node *next;
			node (const elemType &x,node *N=NULL){
				data=x;next=N;
			}
			node(){
				next=NULL;
			}
			~node(){
			}
		};
		
		node *front,*rear;
	
	public:
		linkQueue(){
			front=rear=NULL;
		}
		~linkQueue(){
			node *tmp;
			while (front!=NULL){
				tmp=front;
				front = front->next;
				delete tmp;
			}
		}
		bool isEmpty(){
			return front==NULL;
		}
		void enQueue(const elemType &x){
			if (rear==NULL){
				front=rear=new node(x);
			}
			else{
				rear->next=new node(x);
				rear=rear->next;
			}
		}
		elemType deQueue(){
			node *tmp=front;
			elemType value=front->data;
			front=front->next;
			if (front==NULL) rear=NULL;
			delete tmp;
			return value;
		}
		elemType getHead(){
			return front->data;
		}
};

template <class elemType>
class seqQueue:public queue<elemType>{
	private:
		elemType *elem;
		int maxsize;
		int front, rear;
		
		void doublespace();
	
	public:
		seqQueue(int size=10){
			elem=new elemType [size];
			maxsize = size;
			front=rear=0;
		}
		~seqQueue(){
			delete [] elem;
		} 
		bool isEmpty(){
			return front==rear;
		}
		void enQueue(const elemType &x){						
			if ((rear+1)%maxsize==front){
				doublespace();
			}
			rear=(rear+1)%maxsize; 
			elem[rear]=x;
		}
		elemType deQueue(){
			front=(front+1)%maxsize;
			return elem[front];
		}
		elemType getHead(){
			return elem[(front+1)%maxsiz];
		}
}; 

template <class elemType>
void seqQueue<elemType>::doublespace(){
	elemType *tmp= new elemType[2*maxsize];
	for (int i=0;i<maxsize;++i){
		tmp[i]=elem[(front+i)%maxsize];
	}
	front=0;
	rear=maxsize-1;
	maxsize*=2;
	delete elem;
	elem=tmp;
}

