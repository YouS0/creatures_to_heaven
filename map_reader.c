#include <stdio.h>
#include <math.h>
#include <string.h>




int main(){

    FILE *readfile;

    readfile = fopen("C:\\creatures_to_heaven\\map-pahse0.txt" , "rt" );
    if(!readfile) printf("File did not open!");
    char lines[100];
    char world[20][20];
    for(int i = 0 ; i<20 ; i++){
        for(int j = 0 ; j<20 ; j++){
            world[i][j]='-';
        }
    }
    int deadend_cords[200];
    fgets(lines , 100 , readfile);
    int size = atoi(&lines[0]);
    //input size of world
    fgets(lines , 100 , readfile);
    int deadends = atoi(&lines[2]);
    int position = 0;
    for(int i = 5 ; i<strlen(lines) ; i++){
        if(lines[i]>='0' && lines[i]<='9') {
            deadend_cords[position] = atoi(&lines[i]);
            position +=1;
            if(atoi(&lines[i])>=10)i++;
        }
    }
    //get deadend cordinators
    for(int j = 0 ; j<2*deadends ; j++){
        world[deadend_cords[j]][deadend_cords[j+1]] = '#';
        j++;
    }
    //apply the deadends in final world cordinators
    fgets(lines , 100 , readfile);
    int heavens = atoi(&lines[2]);
    int heaven_cords[100];
    position = 0;
    for(int i = 5 ; i<strlen(lines) ; i++){
        if(lines[i]>='0' && lines[i]<='9') {
            heaven_cords[position] = atoi(&lines[i]);
            position +=1;
            if(atoi(&lines[i])>=10)i++;
        }
    }
    //get heaven cordinators
    for(int j = 0 ; j<2*heavens ; j++){
        world[heaven_cords[j]][heaven_cords[j+1]] = 'H';
        j++;
    }
    //apply heaven cordinators to final world
    char endofline[]="===\n";
    int k = 0;
    while (k!=2){
        fgets(lines , 100 ,readfile);
        if(strcmp(lines , endofline)==0)k++;
    }
    int creatures_cord[200];
    int numberOfCreatures=0;
    fgets(lines , 100 ,readfile);
    while(strcmp(lines,endofline)!=0){
        numberOfCreatures = atoi(&lines[2]);
        position = 0;
        for(int i = 5 ; i<strlen(lines);i++){
            if(lines[i]>='0' && lines[i]<='9') {
                creatures_cord[position] = atoi(&lines[i]);
                position +=1;
                if(atoi(&lines[i])>=10)i++;
            }
        }
        for(int j = 0 ; j<2*numberOfCreatures ; j++){
            world[creatures_cord[j]][creatures_cord[j+1]] = lines[0];
            j++;
        }
        fgets(lines , 100 ,readfile);
    }


    
    


    for(int i = 0 ; i<20 ; i++){
        printf("|");
        for(int j = 0 ; j<20 ; j++){

            printf("%c|" , world[i][j]);
        }
        printf("\n");
    }
    fgets(lines,10,readfile);
    printf("The Creature under your control : %s",lines);
}