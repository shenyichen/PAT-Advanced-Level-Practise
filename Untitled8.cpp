#include<iostream>  
#include<algorithm> 
#include<vector>
using namespace std;  
class MIceCMP
{
private:
  vector<int>*weight;
public:
  MIceCMP(vector<int>*w) :weight(w){}
  bool operator()(const int &A,const int&B)
  {
    return (*weight)[A] > (*weight)[B];
  }
};
int main()
{      
  int NP, NG,index,group,from,to;
  cin >> NP >> NG;
  vector<int>laoshuWeight(NP);
  for (index = 0; index < NP; index++)
    cin >> laoshuWeight[index];
  vector<int>order(NP);
  for (index = 0; index < NP; index++)
    cin >> order[index];
  vector<int>ansRank(NP);
  vector<int>temp;
  while (order.size()>1)
  {
    temp.clear();
    group = (order.size()+ NG-1) / NG;
    from = 0; 
    while (from<order.size())
    {
      to = from + NG>order.size()?order.size():from+NG;
      sort(order.begin() + from, order.begin() + to, MIceCMP(&laoshuWeight));
      temp.push_back(order[from]);
      for (from++; from < to; from++)
        ansRank[order[from]] = group + 1;
    }
    order = temp;
  }
  ansRank[order[0]] = 1;
  NP--;
  for (index = 0; index < NP; index++)cout << ansRank[index] << " ";
  cout << ansRank[index] << endl;
  system("pause");
  return 0;
}
