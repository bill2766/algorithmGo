#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
using namespace std;

int randPartition(int A[],int left,int right){
    int p = (round(1.0*rand()/RAND_MAX * (right-left) + left));
    swap(A[p],A[left]);
    int temp = A[left];
    while(left < right){
        while(left<right && A[right]>temp) right--;
        A[left] = A[right];
        while(left<right && A[left]<temp) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

int randSelect(int A[],int left,int right,int K){
    if(left == right) return A[left];
    int p = randPartition(A,left,right);
    int M = p-left+1;
    if(K == M) return A[p];
    if(K<M){
        return randSelect(A,left,p-1,K);
    }else{
        return randSelect(A,p+1,right,K-M);
    }
}