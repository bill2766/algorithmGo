#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
int main(){
    map<char,int> mp;
    // mp['c'] = 20;
    // mp['c'] = 30;
    // printf("%d\n",mp['c']);

    mp['m'] = 20;
    mp['r'] = 30;
    mp['a'] = 40;
    for(map<char,int>::iterator it = mp.begin();it != mp.end();it++){
        printf("%c %d\n",it->first,it->second);
    }

    system("pause");
    return 0;
}