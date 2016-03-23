#define QUEUE_H
#include <iostream>
#include <cassert>
 using namespace std;
struct intdouble
{
	int q;
	double w;
};


class Queue
{
private:
	intdouble *queuePtr;
    const int size;  
    int begin,       
        end;         
    int elemCT;      
public:
    Queue(int =10);  
    Queue(const Queue &);
    ~Queue();            
 
    void enqueue(const intdouble &);
    intdouble dequeue();
    void printQueue();
};
 

 


Queue::Queue(int sizeQueue) :
    size(sizeQueue), 
    begin(0), end(0), elemCT(0)
{
    
    queuePtr = new intdouble[size + 1];
}
 


Queue::Queue(const Queue &otherQueue) :
	size(otherQueue.size), begin(otherQueue.begin),
	end(otherQueue.end), elemCT(otherQueue.elemCT)
	
{
	queuePtr = new intdouble[size + 1];
    for (int ix = 0; ix < size; ix++)
        queuePtr[ix] = otherQueue.queuePtr[ix]; 
}
 

Queue::~Queue()
{
    delete [] queuePtr;
}
 


void Queue::enqueue(const intdouble &newElem)
{
    assert( elemCT < size );
 
    queuePtr[end++] = newElem;
 
    elemCT++;
 
    if (end > size)
        end -= size + 1;
}
 

intdouble Queue::dequeue()
{
    assert( elemCT > 0 );
 
	intdouble returnValue = queuePtr[begin++];
    elemCT--;
 
    if (begin > size)
        begin -= size + 1;
 
    return returnValue;
}
 

void Queue::printQueue()
{
    std::cout << "Ocher: ";
 
    if (end == 0 && begin == 0)
		std::cout << " pusto\n";
    else
    {
        for (int i = end-1; i >= begin; i--)
			std::cout << queuePtr[i].q << " ";
		std::cout << endl;
		for (int i = end-1; i >= begin; i--)
			std::cout << queuePtr[i].w << " ";
		std::cout << endl;
    }
}
 
