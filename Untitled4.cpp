#include <stdio.h>  
#include <string.h>  
#define MAX 110  
struct result{  
    char d[MAX]; // 0.xxx����  
    int k; // 10��k�η�  
};  
  
result getResult(char *a, int n){  
    result r;  
    int firstPos = -1;  
    int pointPos = -1;  
    int index = 0;  
    int i;  
    for (i = 0; a[i]; i++){  
        if (a[i] == '.'){  
            pointPos = i;  
            continue;  
        }  
        else if (a[i] == '0' && firstPos == -1) // ������0��ͷ���������  
            continue;  
        else{  
            if (firstPos == -1)  
                firstPos = i; // ��һ����0���ֵ�λ��  
            if (index < n)  
            {  
                if (index < strlen(a))  
                    r.d[index++] = a[i]; // �����ض��ľ��ȣ���������������Ӧ���֣�û����0  
                else  
                    r.d[index++] = '0';  
            }  
        }  
    }  
    r.d[index] = 0; // �����ֽ�β��\0����ֹԽ��  
    if (pointPos == -1)  
        pointPos = i; // ���û���ҵ�С���㣬��С������������Ǹ�������  
    if (pointPos - firstPos < 0) // �ж�С�������һ����0���ֵ�λ�ù�ϵ������10�ļ��η�  
        r.k = - (firstPos - pointPos - 1); // ���η�������0.015��pointPos = 1, firstPos = 3, 3 - 1 - 1 = 1, -1����Ϊ������С�����ȥ,0.15*10^-1  
    else  
        r.k = pointPos - firstPos; // ���η�������21.25��pointPos = 2��firstPos = 0��2-0=2��0.2125*10^2  
    if (index == 0){ // ���index = 0������ֵΪ0����ÿһλ��д0���ټ�\0  
        int i;  
        for (i = 0; i != n; i++)  
            r.d[i] = '0';  
        r.d[i] = 0;  
        r.k = 0;  
    }  
    return r;  
}  
  
int main(){  
    int n;  
    char a[MAX], b[MAX];  
    scanf("%d%s%s", &n, a, b);  
    result r1 = getResult(a, n);  
    result r2 = getResult(b, n);  
    if (strcmp(r1.d, r2.d) == 0 && r1.k == r2.k)  
        printf("YES 0.%s*10^%d\n", r1.d, r1.k);  
    else  
        printf("NO 0.%s*10^%d 0.%s*10^%d\n", r1.d, r1.k, r2.d, r2.k);  
    return 0;  
}  
