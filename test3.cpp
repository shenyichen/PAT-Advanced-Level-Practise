#include<iostream>
#include<cstring>
using namespace std;
int main(){
	string a;
	a+='1';
	a+='2';
	a+='\0';
	cout<<a<<a;
}
