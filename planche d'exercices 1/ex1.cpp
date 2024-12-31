#include<iostream>
using namespace std;
const double kilo_mile=1/1.609;
const double mile_kilo=1.609;
void kilomile(){
cout<<"donner le nombre de kilometres= ";
int a;
cin>>a;
cout<<a*kilo_mile;
cout<<" miles.";

}


void milekilo(){
    cout<<"donner le nombre de miles= ";
    int a;
    cin>>a;
    cout<<a*mile_kilo;
    cout<<" kilometres";

}


int main(){
cout<<"choisissez une option :\n";
cout<<"1.convertir de kilometres en miles\n";
cout<<"2.convertir de miles en kilometres\n";
int n;
cin>>n;
if (n==1)
    kilomile();
else
    milekilo();
return 0;


}
