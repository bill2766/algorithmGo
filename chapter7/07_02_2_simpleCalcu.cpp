#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <map>
using namespace std;

struct node{
    double num;
    char op;
    bool flag; //true表示操作数，false表示操作符
};

string str;
stack<node> s; //操作符栈
queue<node> q; //后缀表达式序列
map<char,int> op;

void Change(){
    double num;
    node temp;
    //遍历str
    for(int i=0;i<str.length();){
        //如果是数字，则压入q，数字可能是多位数
        if(str[i] >= '0' && str[i] <= '9'){
            temp.flag=true;
            temp.num = str[i] - '0';
            i++;
            while(i<str.length() && str[i] >= '0' && str[i] <= '9'){
                temp.num = temp.num*10 + (str[i] - '0');
                i++;
            }
            q.push(temp);
        //如果是操作符，比较优先级，高于栈顶元素则压入；否则不管它，等到最后依次弹出
        }else{
            temp.flag = false;
            //如果优先级低，则从s中放到q，直到>。意味着把高优先级的弹到q
            if(!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            temp.op = str[i];
            s.push(temp);
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }    
}

double Cal(){
    double temp1,temp2;
    node cur, temp;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.flag == true){
            s.push(cur);
        }else{
            temp2 = s.top().num;
            s.pop();
            temp1 = s.top().num;
            s.pop();
            temp.flag = true;
            if(cur.op == '+') temp.num = temp1 + temp2;
            else if(cur.op == '-') temp.num = temp1 - temp2;
            else if(cur.op == '*') temp.num = temp1 * temp2;
            else temp.num = temp1 / temp2;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin,str),str != "0"){
        for(string::iterator it = str.end();it != str.begin();it--){
            if(*it == ' ') str.erase(it);
        }
        while(!s.empty()) s.pop();
        Change();
        printf("%.2f\n",Cal());
    }
    system("pause");
    return 0;
}