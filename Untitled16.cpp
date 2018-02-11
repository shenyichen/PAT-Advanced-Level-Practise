#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> order(2001,-1),stripe,result; 



int main()
{
  int n,t,tmp;
  scanf("%d",&t);
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
    scanf("%d",&tmp);
    order[tmp]=i;
  }
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d",&tmp);
    stripe.push_back(order[tmp]);
  }

  for(int i=0;i<stripe.size();i++)
  {
    if(stripe[i]==-1)continue;
    if(result.size()==0)
    {
      result.push_back(stripe[i]);
      continue;
    }
    
    if(stripe[i]>=result.back())
    result.push_back(stripe[i]);
    else{
      int pos=upper_bound(result.begin(),result.end(),stripe[i])-result.begin();
      result[pos]=stripe[i];
    }
   } 
    
   cout<<result.size();
}
