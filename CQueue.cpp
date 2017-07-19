/*************************************************************************
	> File Name: CQueue.cpp
	> Author: liumin
	> Mail: 1106863227@qq.com 
	> Created Time: Wed 19 Jul 2017 12:25:13 AM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

template <typename T> 
class CQueue
{
	public:
		CQueue()
		{}

		~CQueue()
		{}

		void appendTail(const T& data)
		{
			stack1.push(data);
		}

		T deleteHead()
		{
			if( stack2.size() <= 0)
			{		
		     	while(stack1.size() > 0)
		     	{
		     		T& data = stack1.top();
		     		stack1.pop();
		     		stack2.push(data);
		     	}
			}
			if(stack2.size() == 0)
			{
				//throw new exception("query is empty");
			}
			T head = stack2.top();
			stack2.pop();
			return head;
		}

	private:
		stack<T> stack1;
		stack<T> stack2;

};

int main()
{
	CQueue<int> que;
	que.appendTail(1);
	que.appendTail(2);
	que.appendTail(3);
	que.appendTail(4);
	que.appendTail(5);

	cout<< que.deleteHead() << endl;
	cout<< que.deleteHead() << endl;
	cout<< que.deleteHead() << endl;
	cout<< que.deleteHead() << endl;
	cout<< que.deleteHead() << endl;

	return 0;
}
