#include<iostream>
using namespace std;

int next[1000000];
int n,m,k,l;

int fillPaticipant(int remain,int begin,int step);
int popPaticipant(int remain,int begin,int step);
int insert(int current,int index);
int remove(int current);

int main()
{
	cin>>n>>m>>k>>l;
	for (int i=1; i<=m; ++i)
	{
		next[i]=i+1;
	}
	next[m]=1;
	
	int current=fillPaticipant(n-m,k,l);
	cout<<current<<endl;
	
	int result=popPaticipant(n,current,l);
	
	cout<<result;
	
}

int fillPaticipant(int remain,int begin,int step)
{
	int current=begin;
	while (remain>0)
	{
		int k=0;
		while (k<step)
		{
			current=next[current];
			++k;
		}
		insert(current,n-remain);
		current=next[current];
		--remain;
	}
	return current;
}

int popPaticipant(int remain,int begin,int step)
{
	int current=begin;
	while (remain>1)
	{
		int k=0;
		while (k<step-1)
		{
			current=next[current];
			++k;
		}
		remove(current);
		current=next[current];
		--remain;
	}
	return current;
}

int insert(int current,int index)
{
	int temp=next[current];
	next[index]=temp;
	next[current]=index;
}

int remove(int current)
{
	next[current]=next[next[current]];
}
