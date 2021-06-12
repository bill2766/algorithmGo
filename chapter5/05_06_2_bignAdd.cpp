#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct bign{
    int d[1000];
    int len;

    bign(){
        memset(d,0,sizeof(d));
        len = 0;
    }
};

bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i=0;i<a.len;i++){
        a.d[i] = str[a.len - i - 1] - '0';
    }
    return a;
}

bign add(bign a, bign b){
    bign c;
    int carry = 0; //��λ
    for(int i=0;i<a.len || i<b.len;i++){
        int temp = a.d[i] + b.d[i] + carry;
        c.d[c.len++] = temp % 10; //��λ���
        carry = temp / 10; //���ܵĽ�λ
    }
    if(carry != 0){ //���һ�����ܵĽ�λ
        c.d[c.len++] = carry;
    }
    return c;
}

bign sub(bign a,bign b){
    bign c;
    for(int i=0;i<a.len || i<b.len;i++){
        if(a.d[i] < b.d[i]){
            a.d[i+1]--;
            a.d[i] += 10;
        }
        c.d[c.len++] = a.d[i] - b.d[i];
    }
    while(c.len -1 >= 1 && c.d[c.len-1]==0){ //���ٱ���1λ && ȥ����λ��0
        c.len--;
    }
    return c;
}

void print(bign a){
    for(int i=a.len-1;i>=0;i--){
        printf("%d",a.d[i]);
    }
}

int main(){
    char str1[1000],str2[1000];
    scanf("%s%s",str1,str2);
    bign a = change(str1);
    bign b = change(str2);
    // print(add(a,b));
    print(sub(a,b));

    system("pause");
    return 0;
}