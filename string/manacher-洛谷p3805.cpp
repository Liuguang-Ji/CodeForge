#include <bits/stdc++.h>
using namespace std;
int p[22000005];
string a,s;
int main()
{
	cin>>a;
	s+='$';
	s+='#';
	for(int i=0; i<a.size(); i++)
	{
		s+=a[i];
		s+='#';
	}
	s+='&';
	int r=0,c;
	for(int i=1; i<s.size(); i++)
	{
		if(i<r)
		p[i]=min(p[2*c-i],p[c]+c-i);
		else
		p[i]=1;
		while(s[i+p[i]]==s[i-p[i]])
		p[i]++;
		if(p[i]+i>r)
		{
			r=p[i]+i;
			c=i;
		}
	}
	int ans=0;
	for(int i=1;i<s.size();i++)
	ans=max(ans,p[i]);
	cout<<ans-1<<endl;
	return 0;
}
