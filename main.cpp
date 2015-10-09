#include "queue.h"
#include <stdexcept>
#include <iostream>
#include <random>
using namespace std;
template <typename T> void test(Queue<T> testobj/*,bool type*/);
int main()
{
	Queue<unsigned> q;
	test(q);
	Queue<double> qd;
	test(qd);
	return 0;
}


template <typename T> void test(Queue<T> testobj/*,bool type*/)
{
	
	default_random_engine e;
/*
	if(type)
		goto inttype;
	else
		goto floattype;
inttype:
		uniform_int_distribution<unsigned> u(0,9);
floattype:
		uniform_real_distribution<double> u(0,9);
*/
	uniform_real_distribution<double> u(0,9);


	try{
		cout<<"Now testing Queue Enqueue and DeQueue function:"<<endl;
		char ch;
		while(1)
		{
			try{
			bool quit=false;
			cout<<"EnQueue or DeQueue? press \"E or e\" for EnQueue, press \"D or d\" for DeQueue, press \"Q or q\" for quit: ";
			cin>>ch;
			switch(ch)
			{
				case 'e':
				case 'E':
					{
						T temp=u(e);
						testobj.EnQueue(temp);
						cout<<"Generated random number: "<<temp<<" put it into the queue."<<endl;
						cout<<"Now the queue is:"<<endl;
						testobj.print();
						break;
					}
				case 'D':
				case 'd':
					{
						cout<<"Number: "<<testobj.DeQueue()<<" is DeQueued."<<endl;
						cout<<"Now the queue is:"<<endl;
						testobj.print();
						break;
					}
				case 'q':
				case 'Q':
					{
					quit=true;
					break;
					}
				default:
					throw runtime_error("Invalid input, try again!");
					break;
			}//end switch

			if(quit)
				break;

		  }//end inner try
			catch(runtime_error err)
			{
				cerr<<err.what()<<endl;
			}
		}//end while
		
	   }
	catch(overflow_error over)
		{
			cerr<<over.what()<<endl;
		}
	catch(underflow_error under)
		{
			cerr<<under.what()<<endl;
		}

	Queue<T> q2(testobj);
	Queue<T> q3;
	q3=q2;
	cout<<"Now testing the copy assignement and assignment operator!"<<endl;
	cout<<"The copy constructor assigned q2 from q, the q2 is:"<<endl;
	q2.print();
	cout<<"The assignment operator: q3=q2. the q3 is:"<<endl;
	q3.print();

} 
