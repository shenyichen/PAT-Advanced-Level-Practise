#include<iostream>
using namespace std;
//ֵ����
 void change1(int n){
    cout<<"ֵ����--����������ַ"<<&n<<endl;         //��ʾ���ǿ����ĵ�ַ������Դ��ַ 
    n++;
}

//���ô���
void change2(int &n){
    cout<<"���ô���--����������ַ"<<&n<<endl; 
    n++;
}
 //ָ�봫��
void change3(int *n){
     cout<<"ָ�봫��--����������ַ "<<n<<endl; 
    *n=*n+1;
 } 
int     main(){
    int n=10;
    cout<<"ʵ�εĵ�ַ"<<&n<<endl;
    change1(n);
    cout<<"after change1() n="<<n<<endl;
    change2(n);
    cout<<"after change2() n="<<n<<endl;
    change3(&n);
    cout<<"after change3() n="<<n<<endl;
    return true;
}
