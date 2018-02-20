#include <iostream>  
#include <vector>  
#include <stdio.h>  
#include <algorithm>  
#include <queue>  
#include <string.h>  
#include <unordered_map>  
#include <map>  
using namespace std;  
bool IsPrime(int n){  
    if(n==1)  
        return false;  
    for (int i=2; i<=sqrt(n); ++i) {  
        if(n%i==0)  
            return false;  
    }  
    return true;  
}  
int main(){  
    int n,m;  
    scanf("%d %d",&n,&m);  
    if(!IsPrime(n)){  
        for (int i=n+1;; ++i) {  
            if(IsPrime(i)){  
                n = i;  
                break;  
            }  
        }  
    }  
    vector<bool>ans(n,false);  
    for (int i=0; i<m; ++i) {  
        int t;  
        scanf("%d",&t);  
        int x = t%n;  
        if(ans[x]==false){  
            printf("%d",x);  
            ans[x]=true;  
        }else{  
            bool flag = false;  
            for(int j=0;j<n;++j){  
                int pos = (j*j+x)%n;  
                if(ans[pos]==false){  
                    ans[pos]=true;  
                    flag = true;  
                    printf("%d",pos);  
                    break;  
                }  
            }  
            if(!flag)  
                printf("-");  
        }  
        printf(i==m-1?"\n":" ");  
    }  
    return 0;  
}  
