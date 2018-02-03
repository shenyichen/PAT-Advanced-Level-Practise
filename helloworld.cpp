#include<stdio.h>
#define Max 8

int main()
{
    long a,b,sum;
    int i,c[Max];
    scanf("%d %d",&a, &b);
    sum=a+b;

    if (sum<0){printf("-");sum=0-sum;}
    i=0;
    c[i]=sum%10;
    sum/=10;
    while (sum>0)
    {
        i++;
        c[i]=sum%10;
        sum/=10;
    }
    //printf("%d\n",i);
    for (;i>=0;i--)
    {
        printf("%d",c[i]);
        if (i%3==0&&i!=0)printf(",");
    }
    return 0;
}
