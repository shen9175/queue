#ifndef QUEUE_H
#define QUEUE_H
#include <array>
#include <stdexcept>
#include <iostream>

using namespace std;

#define MAX_SIZE 12
template <typename T> class Queue
{

	public:
	typedef typename array<T,MAX_SIZE>::size_type size_type;
	Queue();
	Queue(const Queue&) = default;
	Queue& operator=(const Queue &) = default;
	~Queue() = default;

	bool isEmpty();
	void EnQueue(T x);
	T DeQueue();
	void print();

	private:
	array<T,MAX_SIZE> a;
	size_type head,tail,size;
};





template<typename T> Queue<T>::Queue()
{
	head=0;
	tail=0;
	size=0;
}

template<typename T> bool Queue<T>::isEmpty()
{
	if(size==0)
		return true;
	else
		return false;
}

template<typename T> void Queue<T>::EnQueue(T x)
{
	if(size>=MAX_SIZE)
		throw overflow_error("Queue Overflow!");
	else
		{
		a[tail]=x;
		++tail;
		if(tail==MAX_SIZE)
			tail=0;
		++size;
		}
}

template<typename T> T Queue<T>::DeQueue()
{
	if(isEmpty())
		throw underflow_error("Queue underflow!");
	else
		{
		T ret=a[head];
		++head;
		if(head==MAX_SIZE)
			head=0;
		--size;
		return ret;
		}
}

template<typename T> void Queue<T>::print()
{
	size_type index=head;
	cout<<"head="<<head<<"  "<<"tail="<<tail<<"  "<<"size="<<size<<endl;
	for(size_type i=0;i<size;++i)
		{
		cout<<a[index++]<<" ";
		if(index==MAX_SIZE)
			index=0;
		}
	cout<<endl;
}





#endif

