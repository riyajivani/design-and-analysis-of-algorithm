#include <iostream>
using namespace std;

int x[999],count=0;

bool place(int k,int i)
{
	for(int j=1;j<=k-1;j++)
	{
		if(x[j]==i||abs(j-k)==abs(x[j]-i))
			return false;
	}
	return true;
}

void nQueen(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(place(k,i)==true)
		{
			x[k]=i;
			
			if(k==n)
			{
				cout<<"\npossible solution is: "<<endl;
				
				for(int i=1;i<=n;i++)
				{
					cout<<x[i]<<" ";
				}
				cout<<endl;
				count++;
			}
			else
			{
				nQueen(k+1,n);
			}			
		}
	}
}

int main()
{
	int n;
	
	cout<<"n queen problem: "<<"enter n here: "<<endl;
	cin>>n;
	
	for(int i=1;i<=n;i++)
		x[i]=0;
		
		nQueen(1,n);
		
		cout<<"\n possible solutions are: "<<count<<endl;
		
		return 0;
}