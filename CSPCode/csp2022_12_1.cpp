#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(){
    int n;
    double i;
    cin>>n>>i;
    double sum=0;
    for(int k=0;k<=n;k++){
        double a;
        cin>>a;
        sum+=a*pow(1+i,-k);
    }
    cout<<fixed<<setprecision(3)<<sum<<endl;
    return 0;
}
