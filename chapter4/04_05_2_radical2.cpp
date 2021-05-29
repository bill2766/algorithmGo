#include <cstdio>
#include <stdlib.h>
using namespace std;

const double eps = 1e-5;
double f(double x){
    return x*x;
}

double calSqrt(){
    double left = 1;
    double right = 2;
    double mid;
    while((right-left) > eps){
        mid = (left+right)/2;
        if(f(mid) > 2){
            right = mid;
        }else{
            left = mid;
        }
    }
    return mid;
}

int main(){
    printf("%lf\n",calSqrt());

    system("pause");
    return 0;
}

/*
double sovle(double L,double R){
    double left = L;
    double right = R;
    double mid;
    while((right-left) > eps){
        mid = (left+right)/2;
        if(f(mid) > 2){
            right = mid;
        }else{
            left = mid;
        }
    }
    return mid;
}
*/