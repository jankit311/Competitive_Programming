#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod = 1e9+7;

void boost()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
} 
int main()
{  
   int t=1;
   //cin>>t;
   while(t--)
    {
      int n,m,i,j,xorsum=0;
      cin>>n>>m;
      int a[n][m];
      vector<int> v;
      for(i=0;i<n;i++)
      {
        for(j=0;j<m;j++)
        {
          cin>>a[i][j];
          if(!j){xorsum^=a[i][j];v.push_back(j+1);}
        }
      }
      if(xorsum>0)
      {
        cout<<"TAK\n";
        for(i=0;i<n;i++)cout<<v[i]<<" ";
        return 0;
      }
      for(i=0;i<n;i++)
      {
        for(j=1;j<m;j++)
        {
          if(a[i][j]!=a[i][0])
          {
              v[i]=j+1;
              cout<<"TAK\n";
              for(i=0;i<n;i++)cout<<v[i]<<" ";
              return 0;
          }
        }
      }
      cout<<"NIE"; 
    }
return 0;
}