int cal(int n,int p){
    int ans = 0;
    for(int i =2; i<=n; i++){
        int temp = i;
        while(temp % p ==0){
            ans++;
            temp /= p;
        }
    }
    return ans;
}

int cal(int n,int p){
    int ans = 0;
    while(n){
        ans += n/p;
        n /= p;
    }
    return ans;
}

int cal(int n,int p){
    if(n<p) return 0;
    return n/p+cal(n/p,p);
}