// //ʹ������q[]��ʵ�ֶ���
// //��int�ͱ���front��Ŷ���Ԫ�ص�ǰһ��Ԫ�ص��±ꡢrear��Ŷ�βԪ�ص��±�

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
// //STL queueʵ�ֶ��е����
// while(!q.empty()){
//     q.pop();
// }
// //�������¶���