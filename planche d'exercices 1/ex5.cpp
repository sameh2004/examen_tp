#include<iostream>
#include<cmath>
using namespace std;
double f(double x,bool &ok){
if ((x-1)*(2-x)>=0){
return sqrt((x-1)*(2-x));
ok=true;
}
else
    ok=false;
}
int main(){
bool ok;
cout<<f(5,ok)<<"  "<<ok;
}
