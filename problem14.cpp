#include<iostream>
#include<list>
#include<string>
#include<fstream>
using namespace std;

list<char> *stack[100000];
int key[100000];
int stack_size=0;
int priority[256];
string input;

void init();
void work();
void print(int);

int main()
{
	init();
	work();
	print(0);
}

void init()
{
	cin>>input;
	priority[0]=100;
	priority['+']=1;
	priority['-']=1;
	priority['*']=2;
	priority['/']=2;
	priority['!']=3;
	priority['(']=4;
	priority[')']=4;
}

void work()
{
	for (int i=0; i<input.size(); ++i)
	{
		if (priority[input[i]]==0)
		{
			stack[stack_size]=new list<char>();
			stack[stack_size]->push_back(input[i]);
			key[stack_size]=0;
			++stack_size;
		}else{
			if (input[i]=='!')
			{
				if (key[stack_size-1]!='!'&&key[stack_size-1]!=0)
				{
					stack[stack_size-1]->push_front('(');
					stack[stack_size-1]->push_back(')');
					stack[stack_size-1]->push_back('!');
				}else
				{
					stack[stack_size-1]->push_back('!');
				}
				key[stack_size-1]='!';
				continue;
			}
			if (priority[key[stack_size-2]]<priority[input[i]])
			{
				stack[stack_size-2]->push_front('(');
				stack[stack_size-2]->push_back(')');
			}
			if (priority[key[stack_size-1]]<=priority[input[i]])
			{
				stack[stack_size-1]->push_front('(');
				stack[stack_size-1]->push_back(')');
			}
			
			stack[stack_size-2]->push_back(input[i]);
			stack[stack_size-2]->splice(stack[stack_size-2]->end(),*stack[stack_size-1]);
			key[stack_size-2]=input[i];
			delete stack[stack_size-1];
			--stack_size;
		}
	}
}

void print(int n)
{
	for (list<char>::iterator it=stack[n]->begin(); it!=stack[n]->end(); ++it)
	{
		cout<<*it;
	}
	cout<<endl;
}