// #include <cstdio>
// #include <stdlib.h>
// #include <string.h>

// using namespace std;

// struct Student{
//     char name[10];
//     char id[10];
//     int score;
//     int r;
// }stu[100010];


// bool cmp(Student a,Student b){
//     if(a.score != b.score) return a.score>b.score;
//     else return strcmp(a.name,b.name)<0;
// }

// stu[0].r = 1;
// for(int i=1;i<n;i++){
//     if(stu[i].score == stu[i-1].score){
//         stu[i].r = stu[i-1].r;
//     }else{
//         stu[i].r = i + 1;
//     }
// }


// int r=1;
// for(int i=0;i<n;i++){
//     if(i>0 && stu[i].score != stu[i-1].score){
//         r= i+1;
//     }
//     //输出当前个体信息
// }