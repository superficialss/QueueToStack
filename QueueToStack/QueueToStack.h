#pragma once

class Stack
{
public:
	void Push(const int x)
	{
		if (!q1.empty())
		{
			q2.push(x);
			while (!q1.empty())
			{
				q2.push(q1.front());
				q1.pop();
			}
		}
		else
		{
			q1.push(x);
			while (!q2.empty())
			{
				q1.push(q2.front());
				q2.pop();
			}
		}
	}

	void Pop()
	{
		if (q1.empty() && q2.empty())
		{
			cout << "Stack is empty!" << endl;
			exit(1);
		}
		if (!q1.empty())
		{
			q1.pop();
		}
		else
		{
			q2.pop();
		}
	}

	int Top()
	{
		if (!q1.empty())
		{
			return q1.front();
		}
		else
		{
			return q2.front();
		}
	}

	bool Empty()
	{
		return q1.empty() && q2.empty();
	}

protected:
	queue<int> q1;
	queue<int> q2;
};

void TestStack()
{
	Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);
	s.Push(5);

	while (!s.Empty())
	{
		cout << s.Top() << " ";
		s.Pop();
	}
	cout << endl;
}
