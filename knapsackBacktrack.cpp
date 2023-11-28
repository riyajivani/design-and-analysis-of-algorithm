#include <iostream>
using namespace std;

int n,M,v[100],w[100],x[100],fp,fw;

int BOUND(int cp,int cw,int k)
{
	int b,c;
	
	b=cp;
	c=cw;
	
	for(int i=k+1;i<=n;i++)
	{
		c=c+w[i];
		
		if(c<M)
		b=b+v[i];
		
		else
		return (b+(1-(c-M)/w[i])*v[i]);
	}
	return b;
}

void BK_KNAPSACK(int M,int w[],int v[],int n)
{
	int cw=0,cp=0,k=1,y[n];
	fp=-1;
	
	while(k<=n && cw+w[k]<=M)
	{
		cw=cw=w[k];
		cp=cp+v[k];
		y[k]=1;
		k=k+1;
	}
	
	if(k>n)
	{
		fp=cp;
		fw=cw;
		k=n;
		
		for(int i=1;i<=n;i++)
		{
			x[i]=y[i];
		}
	}
	else
		y[k]=0;
		
	while(BOUND(cp,cw,k)<=fp)
	{
		while(k!=0 && x[k]!=1)
			k=k-1;
			
		if(k==0)
			return;
		else
		{
			y[k]=0;
			cw=cw-w[k];
			cp=cp-v[k];
		}
		k=k+1;
	}	
}

int main()
{
	cout<<"enter total items: ";
	cin>>n;
	
	cout<<"\nenter values: ";
	for(int i=1;i<=n;i++)
	{
		cin>>v[i];
	} 
	
	cout<<"\nenter weights: ";
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	 
	cout<<"\nenter max weight: ";
	cin>>M;
	
	BK_KNAPSACK(M,w,v,n);
	
	cout<<"\npossible solution is: ";
	for(int i=1;i<=n;i++)
	{
		cout<<x[i];
	}
	
	cout<<"\n max profit can be earned: ";
	cout<<fp<<endl;
	
	return 0;
}