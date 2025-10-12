#include <bits/stdc++.h>
using namespace std;
const double esp=1e-6;
double mi[15];
int main()
{
	int n;
	double l,r,mid1,mid2,temp;
	cin>>n>>l>>r;
	for(int i=n; i>=0; i--)
		cin>>mi[i];
	while(r-l>esp)
	{
		temp=(r-l)/3.0;
		mid1=l+temp;
		mid2=r-temp;
		double midz1=0.0,midz2=0.0;
		for(int i=0;i<=n;i++)
		{
			midz1+=mi[i]*pow(mid1,i);
			midz2+=mi[i]*pow(mid2,i);
		}
		if(midz1<midz2)
			l=mid1;
		else
			r=mid2;
	}
	printf("%.5lf\n",l);
	return 0;
}
