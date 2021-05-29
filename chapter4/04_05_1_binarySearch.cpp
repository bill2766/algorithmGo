#include <cstdio>
#include <stdlib.h>
using namespace std;

int binarySerach(int A[],int left,int right,int x){
    int mid;
    while(left<=right){
        mid = (left+right)/2;
        if(A[mid]==x) return mid;
        else if(A[mid]>x){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return -1;
}

int main(){
    const int n = 10;
    int A[n] = {1,3,4,6,7,8,10,11,12,15};
    printf("%d %d\n",binarySerach(A,0,n-1,6),binarySerach(A,0,n-1,9));
    system("pause");
    return 0;
}

int lower_bound(int A[],int left,int right,int x){
    int mid;
    while(left < right){
        mid = (left+right)/2;
        if(A[mid]>=x){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return left;
}

int upper_bound(int A[],int left,int right,int x){
    int mid;
    while(left < right){
        mid = (left+right)/2;
        if(A[mid] > x){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return left;
}

/*
int solve(int left,int right){
    int mid; //mid为left和right的中点
    while(left < right){ //对[left,right]来说，left==right意味着找到唯一位置
        mid = (left+right) / 2; //取中点
        if(条件成立){ //条件成立，第一个满足条件的元素的位置<=mid
            right = mid; //往左子区间[left,mid]查找
        }else{ //条件不成立，则第一个满足该条件的元素的位置>mid
            left = mid + 1; //往右区间[mid+1,right]查找
        }
    }

    return left; //返回夹出来的位置
}
*/

/*
int solve(int left,int right){
    int mid; //mid为left和right的中点
    while(left+1 < right){ //对(left,right]，left+1==right意味着唯一位置
        mid = (left+right) / 2; //取中点
        if(条件成立){ //条件成立，第一个满足条件的元素的位置<=mid
            right = mid; //往左子区间[left,mid]查找
        }else{ //条件不成立，则第一个满足该条件的元素的位置>mid
            left = mid; //往右区间[mid+1,right]查找
        }
    }

    return right; //返回夹出来的位置
}
*/