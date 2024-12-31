#include<iostream>
using namespace std;
int main(){
int n;
cout<<"donner le nombre de mots \n";
cin>>n;
string ch="",s;
for(int i=0;i<n;i++){
cout<<"donner la mots numero "<<i<<" : ";
cin>>s;
if (s.size()>ch.size())
    ch=s;
}
cout<<"la plus long mots est : "<<ch;



}
