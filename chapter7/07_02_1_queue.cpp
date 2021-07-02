// //使用数组q[]来实现队列
// //而int型变量front存放队首元素的前一个元素的下标、rear存放队尾元素的下标

// void clear(){
//     front = rear = -1;
// }
// int size(){
//     return rear-front;
// }
// bool empty(){
//     if(front == rear) return true;
//     else return false;
// }
// void push(int x){
//     q[++rear] = x;
// }
// void pop(){
//     front++;
// }
// int get_front(){
//     return q[front+1];
// }
// int get_rear(){
//     return q[rear];
// }
// //STL queue实现队列的清空
// while(!q.empty()){
//     q.pop();
// }
// //或者重新定义