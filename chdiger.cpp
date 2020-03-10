#include<bits/stdc++.h>
using namespace std;

multiset<pair<int,int> > s;

int main()
{
	int t,d,l,i,prev,newl,c;
	pair<int,int> p;
	int str[20],ans[20];
	string ch;

	scanf("%d",&t);
	while(t--)
	{
		i=1;
		newl=c=0;
		s.clear();
		cin>>ch;
		l=ch.length();
		for(i=0;i<l;i++)
			str[i+1]=ch[i]-'0';

		scanf("%d",&d);
		for(i=1;i<=l;i++)
		{
			s.insert(make_pair(str[i],i));
		}

		prev=1;
		int count=0;
		while(newl!=l)
		{
			int td=0;
			p=*s.begin();
			if(p.first>=d)
			{
				c+=l-newl;
				newl=l;
				s.clear();
				break;
			}
			ans[count++]=p.first;
			newl++;
			for(i=prev;i<=p.second;i++)
			{
				multiset<pair<int,int> >::iterator it = s.find(make_pair(str[i],i));
				if(it!=s.end())
				{
					s.erase(it);
					if(it->second!=p.second)
					{
						c++;
						td++;
					}
				}
			}
			prev = p.second+1;
			newl+=td;
		}
		for(i=0;i<count;i++)
			printf("%d",ans[i]);
		for(i=0;i<c;i++)
			printf("%d",d);
		printf("\n");
	}
	return 0;
}