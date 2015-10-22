#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;


const int size = 1700000 + 10;

int *mfirst,*cfirst;
char *csequence,*msequence;
int *mnode_place,*cnode_place;
int n,m,cs_size,ms_size;
int curr,p;
int *next,*mnode;

void input();
void initmsequence(int left,int right);
void initcsequence(int left,int right);
int compare();

int main()
{
	std::ios::sync_with_stdio(false);

	mfirst = new int[size];
	cfirst = new int[size];
	mnode_place = new int[size];
	cnode_place = new int[size];

	for (int i = 0; i < size; ++i)
	{
		mfirst[i] = 0;
		cfirst[i] = 0;
		mnode_place[i] = 0;
		cnode_place[i] = 0;
	}

	input();

	if ((n < 1000000) && (m < 1000000))
	{
		if ((n > 300000) || (m>300000))
		{
			cout << -1;
			return 0;
		}
	}

	if ((m== 0) || (n == 0))
	{
		cout << -1;
		return 0;
	}

	msequence = new char[2 * size];
	mnode = new int[2 * size];

	for (int i = 0; i < 2*size; ++i)
	{
		msequence[i] = 0;
		mnode[i] = 0;
	}

	curr=0;
	p = 0;
	initmsequence(0,n-1);
	ms_size = curr;

	delete[] mfirst;
	delete[] mnode_place;
	csequence = new char[2 * size];

	for (int i = 0; i < 2 * size; ++i)
	{
		csequence[i] = 0;
	}

	curr=0;
	p=0;
	initcsequence(0,m-1);
	cs_size=curr;

	delete[] cfirst;
	delete[] cnode_place;
	/*
	for (int i = 0; i < ms_size; ++i)
	{
		cout << msequence[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < ms_size; ++i)
	{
		cout << mnode[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < cs_size; ++i)
	{
		cout << csequence[i] << " ";
	}
	cout << endl;*/

	next = new int[2 * size];

	for (int i = 0; i < 2 * size; ++i)
	{
		next[i] = 0;
	}
	cout<<compare();

}

void input()
{
	//std::fstream in("e:\\test1.txt");
	cin >> n;
	int temp;
	for (int i=0; i<n; ++i)
	{
		cin>>mfirst[i];
	}
	for (int i=0; i<n; ++i)
	{
		cin >> temp;
		mnode_place[temp]=i;
	}
	cin >> m;
	for (int i=0; i<m; ++i)
	{
		cin>>cfirst[i];
	}
	for (int i=0; i<m; ++i)
	{
		cin >> temp;
		cnode_place[temp]=i;
	}
}

void initmsequence(int left,int right)
{
	int node = mfirst[p];
	int m = mnode_place[node];
	mnode[curr] = node;
	if (m!=left)
	{
		msequence[curr++]=1;
		++p;
		initmsequence(left,m-1);
		msequence[curr++] = 2;
		mnode[curr] = node;
	}
	if (m!=right)
	{
		msequence[curr++] =3;
		++p;
		initmsequence(m+1,right);
		msequence[curr++] =4;
		mnode[curr] = node;
	}
}

void initcsequence(int left, int right)
{

	int m=cnode_place[cfirst[p]];
	if (m!=left)
	{
		csequence[curr++]=1;
		++p;
		initcsequence(left,m-1);
		csequence[curr++]=2;
	}
	if (m!=right)
	{
		csequence[curr++]=3;
		++p;
		initcsequence(m+1,right);
		csequence[curr++]=4;
	}
}

int compare()
{
	
	int i=1,j=0;
	
	while (i<cs_size)
	{
		if (csequence[i]==csequence[j])
		{
			next[i]=j+1;
			++i;
			++j;
		}
		else
		{
			if (j>0) 
			{
				j=next[j-1];
			}
			else
			{
				next[i]=0;
				++i;
			}
		}
	}
	
	i=0;
	j=0;
	
	while (i<ms_size)
	{
		if (msequence[i] == csequence[j])
		{
			if (j == cs_size - 1)
			{
				return mnode[i+1];
			}
			++i;
			++j;
		}
		else
		{
			if (j > 0) j = next[j - 1]; else ++i;
		}
	}
	return -1;
}
