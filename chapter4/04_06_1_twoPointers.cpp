/*
while(i < j){
    if(a[i] + a[j] == m){
        printf("%d %d\n",i,j);
        i++;
        j--;
    }else if(a[i] + a[j] < m){
        i++;
    }else{
        j--;
    }
}
*/

int merge(int A[],int B[],int C[],int n,int m){
    int i=0,j=0,index=0;
    while(i < n && j < m){
        if(A[i] <= B[j]){
            C[index++] = A[i++];
        }else{
            C[index++] = B[j++];
        }
    }
    while(i < n) C[index++] = A[i++];
    while(j < m) C[index++] = B[j++];
    return index;
}