#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int,vector<int>> adjlist;
int levelleaves[105]={0};

void dfs(int node,int level){
    if(adjlist[node].empty()){
        levelleaves[level]++;
        return;
    }
    vector<int>:: iterator itea = adjlist[node].begin();
    for(;itea!=adjlist[node].end();itea++){
        dfs(*itea,level+1);
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    int leaves = n-m;
    for(int i=0;i<m;i++){
        int id1,k, id2;
        cin>>id1>>k;
        for(int j=0;j<k;j++){
            cin>>id2;
            adjlist[id1].push_back(id2);
        }
    }
    dfs(1,0);
    int a=levelleaves[0];
    cout<<levelleaves[0];
    for(int i=1;a<leaves;i++){
        cout<<" "<<levelleaves[i];
        a=a+levelleaves[i];
    }
    return 0;
}
