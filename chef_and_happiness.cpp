#include<bits/stdc++.h>
using namespace std;
map<int,int> ff;
int main()
{
	int n,t,a[100001],i,flag,count;
	map<int,int>::iterator it;

	cin>>t;

	while(t--)
	{
		vector<int> mm[100001];
		ff.clear();
		count=0;
		flag=0;
		
		cin>>n;

		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}

		for(i=1;i<=n;i++)
		{
			ff[a[i]]++;
			mm[a[i]].push_back(i);
		}

		for(it=ff.begin();it!=ff.end();it++)
		{
			count=0;
			if((it->second)>1)
			{
				for(i=0;i<mm[it->first].size();i++)
				{
					if(ff[mm[it->first][i]]>0)
						count++;
					if(count>=2)
					{
						cout<<"Truly Happy"<<endl;
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				break;
		}
		if(flag==0)
		{
			cout<<"Poor Chef"<<endl;
		}
	}
	return 0;
}