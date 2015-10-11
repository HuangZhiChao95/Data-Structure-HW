#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int next[1000000];
int before[1000000];
int n,m,k,l;

int fillPaticipant(int remain,int begin,int step);
int popPaticipant(int remain,int begin,int step);
void insert(int current,int index);
void remove(int current);
void print(int current,int n)
{
	int count=0;
	while (count<n)
	{
		cout<<current<<" ";
		current=next[current];
		++count;
	}
	cout<<endl;

}


int main()
{
	cin>>n>>m>>k>>l;
	for (int i=1; i<=m; ++i)
	{
		next[i]=i+1;
		before[i]=i-1;
	}
	next[m]=1;
	before[1]=m;

	int current=fillPaticipant(n-m,k,l);

	cout<<endl<<endl;

	int result=popPaticipant(n,current,l);
	
	cout<<result;
	system("pause");
}

int fillPaticipant(int remain,int begin,int step)
{
	int current=begin;

	while (remain>0)
	{
		int k=1;
		while (k<step)
		{
			current=next[current];
			++k;
		}
		insert(current,n-remain+1);
		current=next[current];
		--remain;
		print(current,n-remain);
	}
	return current;
}

int popPaticipant(int remain,int begin,int step)
{
	int current=begin;
	while (remain>1)
	{
		int k=1;
		while (k<step-1)
		{
			current=next[current];
			++k;
		}
		if (remain==2)
		{
			current=next[current];
			return current;
		}
		if (step!=1)
		{
			remove(current);
			current=next[current];
			current=next[current];
		}else
		{
			remove(before[current]);
			current=next[current];
		}
		--remain;
		print(current,remain);
	}
	return current;
}

void insert(int current,int index)
{
	int temp=next[current];
	next[index]=temp;
	next[current]=index;

	before[next[index]]=index;
	before[index]=current;

}

void remove(int current)
{
	next[before[current]]=next[current];
	before[next[current]]=before[current];
}
