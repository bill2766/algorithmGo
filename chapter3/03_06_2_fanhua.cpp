#include <cstdio>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
    char sentence[90];
    char word[90][90];
    gets(sentence);

    char* p;
    int index = 0;
    p = strtok(sentence," ");
    // printf("%s\n",sentence);
    while(p){
        strcpy(word[index],p);
        // printf("p: %s\n",p);
        // printf("word: %s\n",word[index]);
        index++;
        p = strtok(NULL," ");
    }

    // printf("index: %d\n",index);
    // printf("index4: %s\n",word[4]);
    for(int i=index-1;i>=0;i--){
        printf("%s",word[i]);
        if(i>0){
            printf(" ");
        }
    }

    system("pause");
    return 0;
}