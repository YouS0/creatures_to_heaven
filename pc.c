#include <stdio.h>


int main(){
    
    char sent[1000];
    gets(sent);
    int j = 0;
    int maxi , maxj,mini,minj;
    int max = 0 ;
    int min = 150;
    for(int i = 0 ; sent[i] ; i++){
        if(sent[i] == 32  || sent[i] ==10 || sent[i] ==44 && sent[i+1] != 32  && sent[i+1] !=10 && sent[i+1] !=44 ){
            if(i-j > max ) {
                max = i-j;
                maxi = i;
                maxj = j;
            }
            if(i-j < min) {
                min = i - j;
                mini = i;
                minj = j;
            }
            j = i+1;
            
        }
    }
    for(int i = minj ; i < mini ; i++){
        printf("%c" , sent[i]);
    }
    printf("\n");
    for(int i = maxj ; i < maxi ; i++){
        printf("%c" , sent[i]);
    }    










}