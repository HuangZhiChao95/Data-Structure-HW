#include<iostream>
#include<cmath>

using namespace std;

const int n=18000000;

bool prime[n];
int result;

int main()
{
	int m;
	cin>>m;

	for (int i=2; i<sqrt(m*1.8); ++i)
	{
		if (!prime[i])
		{
			for (int j=2*i; j<n; j+=i)
			{
				prime[j]=1;
			}
		}
	}
	
	result=-1;
	for (int i=4; i<n; ++i)
	{
		result=result-((i-1)>>1)+(i>>1);
		if (!prime[i-2])
		{
			++result;
		}
		if (result==m)
		{
			cout<<i<<endl;
			break;
		}
	}

	return 0;
}
