#include<iostream>
using namespace std;
int main(){
cout<<"donner 10 entiers";
int a,m;
cin>>m;
for(int i=0;i<9;i++){
    cin>>a;
    if (a<m)
        m=a;
}
cout<<"le plus petit entier est "<<m;
return 0;
}
