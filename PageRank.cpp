#include<iostream>
using namespace std;
int main()
{
	double p[10][10],d=0.85,n,r[10],t,l=0,c=0,m;
	int i,j,k;
	cout<<"Enter the number of pages : ";
	cin>>n;
	cout<<"Enter the links between the pages (1 for link and 0 for no link): "<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>p[i][j];
		}
	}
	cout<<"Enter the number of iteration : ";
	cin>>t;
	for(i=0;i<n;i++)
		r[i] = 1;
		
	cout<<"\n";
	cout<<"Iteration 0 :"<<endl;
	for(i=0;i<n;i++)
		cout<<"PageRank of "<<i<<" is : "<<r[i]<<endl;
		
	cout<<"\n";
	for(m=0;m<t;m++)
	{
		cout<<"Iteration "<<m+1<<":"<<endl;
		for(i=0;i<n;i++)
		{
			j = i + 1;
			for(;j<n+1;j++)
			{
				if(j == n)
					j = 0;
				if(j == i)
					break;
				if(p[j][i] == 1)
				{
					for(k=0;k<n;k++)
					{
						if(p[j][k] == 1)
							c++;
					}
					if(c == 0)
						continue;
					l = l + (r[j]/c);
					c = 0;
				}	
			}
			r[i] = (1 - d) + d * (l);
			l = 0;
			cout<<"PageRank of "<<i<<" is : "<<r[i]<<endl;
		}
		cout<<"\n";
	}
	return 0;
}
