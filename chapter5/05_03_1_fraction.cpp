#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
    // return !b ? a : gcd(b,a%b);
}

struct Fraction{
    int up,down;
};

Fraction reduction(Fraction result){
    if(result.down < 0){
        result.up = -result.up;
        result.down = -result.down;
    }
    if(result.up==0){
        result.down=1;
    }else{
        int d = gcd(abs(result.up),abs(result.down));
        result.up /= d;
        result.down /= d;
    }
}

Fraction add(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction minu(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction multi(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

Fraction divide(Fraction f1,Fraction f2){
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}

void showResult(Fraction r){
    r = reduction(r);
    if(r.down==1) printf("%lld",r.up);
    else if(abs(r.up) > r.down){
        printf("%d %d/%d",r.up/r.down,abs(r.up) % r.down, r.down);
    }else{
        printf("%d/%d",r.up,r.down);
    }
}

int main(){

    system("pause");
    return 0;
}