#include<iostream>
#include<cmath>
using namespace std;
double distance(double xa,double ya,double xb,double yb){
double s;
s=pow(xb-xa,2)+pow(yb-ya,2);
s=sqrt(s);
return s;
}
int main(){
double xa=5.5,ya=2.5,xb=3.5,yb=4.2;
cout<<distance(xa,ya,xb,yb);


}
