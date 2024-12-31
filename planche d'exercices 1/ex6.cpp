#include<iostream>
#include<cmath>
using namespace std;
void swap(int &a,int &b){
int x;
x=a;
a=b;
b=x;
}
int main(){
int a=5,b=7;
swap(a,b);
cout<<"a="<<a<<"\n";
cout<<"b="<<b;

}
