#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10;
bool vis[N];
double x[N],y[N],dis[N];
int n;
double ans=0.0;
double distance(int i,int j)
{
	return (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
}
void prim()
{
	dis[1]=0.0;
	vis[1]=1;
	for(int i=1; i<=n; i++)
	{
		int v=1;
		double minn=1e9*1.0;
		for(int j=1; j<=n; j++)
			if(vis[j]==0&&dis[j]<minn)
			{
				v=j;
				minn=dis[j];
			}
		vis[v]=1;
		ans+=dis[v];
		for(int j=1; j<=n; j++)
			dis[j]=min(distance(j,v),dis[j]);
	}
	return;
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>x[i]>>y[i];
		dis[i]=1e12*1.0;
	}
	prim();
	printf("%.2f",ans);
	return 0;
}
