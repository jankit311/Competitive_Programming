#include<bits/stdc++.h>
using namespace std ;

int main()
{

int t ;
cin>>t ;
int n , k ;
while(t--)
{
cin>>n>>k ;
vector<pair<int,int> > vp ;
multiset<int> myset ;
for(int i = 0 ; i < n ; i++)
{
int x , y ;
cin>>x>>y ;
vp.push_back(make_pair(x , y));


}

sort(vp.begin() , vp.end());
for(int i = 0 ; i < k ; i++)
	myset.insert(vp[i].second);

int i = k-1 ;
int min ;
int max = INT_MIN;
int ans ;
while(i<n)
{
 min = *myset.begin() ;
 ans = min - vp[i].first ;
 if(ans > max)
 	max = ans ;
    myset.erase(myset.begin()) ;
    myset.insert(vp[++i].second) ;
   
    
    
}
max = max>0?max:0 ;
cout<<max<<endl ;

}

return  0 ;

}