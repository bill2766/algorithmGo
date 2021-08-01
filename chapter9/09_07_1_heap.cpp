
#include <algorithm>
using namespace std;

const int maxn = 100;
//heap为堆，n为元素个数
int heap[maxn],n = 10;

//对heap数组在[low,high]范围进行向下调整
//其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
void downAdjust(int low, int high){
    int i = low, j = i * 2;
    while(j <= high){
        if(j+1 <= high && heap[j+1] > heap[j]){
            j = j+1;
        }
        if(heap[j] > heap[i]){
            swap(heap[j],heap[i]);
            i = j;
            j = i * 2;
        }else{
            break;
        }
    }
}

//建堆
void createHeap(){
    for(int i = n/2; i >= 1;i--){
        downAdjust(i,n);
    }
}

//删除堆顶元素
void deleteTop(){
    heap[1] = heap[n];
    n--;
    downAdjust(1,n);
}

//对heap数组在[low,high]范围进行向上调整
//其中low一般设置为1，high表示欲调整结点的数组下标
void upAdjust(int low, int high){
    int i=high,j=i/2;
    while(j >= low){
        if(heap[i] > heap[j]){
            swap(heap[i],heap[j]);
            i = j;
            j = i / 2;
        }else{
            break;
        }
    }
}

//添加元素
void insert(int x){
    heap[++n] = x;
    upAdjust(1,n);
}

//堆排序
void heapSort(){
    createHeap();
    /*
    while(n > 1){
        swap(heap[n],heap[1]);
        n--;
        downAdjust(1,n);
    }
    */
    for(int i=n;i>1;i--){
        swap(heap[i],heap[1]);
        downAdjust(1,i-1);
    }
}