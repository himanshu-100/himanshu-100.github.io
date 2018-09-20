/*
	Author: @himkha_100
	Himanshu Khandelwal, NITW
*/
#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define s(t) scanf("%d",&t)
#define p(t) printf("%d\n",t)
#define pb push_back
#define f(t) for(int i=0;i<t;i++)
#define fi first
#define se second
#define all(t) t.begin(),t.end()
#define ci(t) cin>>t
#define co(t) cout<<t
#define mii map<int,int>
#define pii pair<int,int>
using namespace std;
struct query{
	int x;
	int y;
};
vector< vector<int> > a;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		a.clear();
		string s1,s2;
		cin>>s1;
		cin>>s2;
		int m=s1.length();
		int n=s2.length();
		int q;
		cin>>q;
		vector<query> v;
		int mx=0,my=0;
		while(q--)
		{
			int a,b;
			cin>>a>>b;
			query temp;
			temp.x=a;
			mx=max(mx,a);
			temp.y=b;
			my=max(my,b);
			v.pb(temp);
		}
		a.resize(mx+5);
		f(mx+5)
		{
			a[i].resize(my+5);
		}
		int lx,ly;
		ly=min(m,my+1);
		lx=min(n,mx+1);
		for(int i=0;i<ly;i++)
		{
			if(s1[i]=='0')
			{
				a[0][i+1]=0;
			}
			else
			{
				a[0][i+1]=1;
			}
		}
		for(int i=0;i<lx;i++)
		{
			if(s2[i]=='0')
			{
				a[i+1][0]=0;
			}
			else
			{
				a[i+1][0]=1;
			}
		}
		string ans;
		for(int i=1;i<=mx;i++)
		{
			for(int j=1;j<=my;j++)
			{
				if(a[i-1][j]==0||a[i][j-1]==0)
				{
					a[i][j]=1;
				}
				else
				{
					a[i][j]=0;
				}
			}
		}
		f(v.size())
		{
			int x,y;
			x=v[i].x;
			y=v[i].y;
			if(a[x][y]==0)
			{
				ans+='0';
			}
			else
			{
				ans+='1';
			}
		}
		cout<<ans<<endl;
	}	
	return 0;
}


