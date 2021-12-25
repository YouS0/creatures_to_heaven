#include <stdio.h>
#include <math.h>
#include <string.h>


void mapprinter(char world[][20],int size){
    for(int i=0;i<size;i++){
        printf("|");
        for(int j=0;j<size;j++){

            printf("%c|",world[i][j]);
        }
        printf("\n");
    }
}

void swap(char world[][20],int a,int b,int i,int j){
    char temp;
    temp=world[a][b];
    world[a][b]=world[i][j];
    world[i][j]=temp;
}

int main(){

    FILE *readfile;

    readfile = fopen("map-phase0.txt" , "rt" );
    if(!readfile) printf("File did not open!");
    char lines[100];
    char world[20][20];

    fgets(lines , 100 , readfile);
    int size = atof(&lines[0]);
    //input size of world
    for(int i = 0 ; i<size ; i++){
        for(int j = 0 ; j<size ; j++){
            world[i][j]='-';
        }
    }
    int deadend_cords[200];
    fgets(lines , 100 , readfile);
    int deadends = atof(&lines[2]);
    int position = 0;
    for(int i = 5 ; i<strlen(lines) ; i++){
        if(lines[i]>='0' && lines[i]<='9') {
            deadend_cords[position] = atof(&lines[i]);
            position +=1;
            if(atof(&lines[i])>=10)i++;
        }
    }
    //get deadend cordinators
    for(int j = 0 ; j<2*deadends ; j++){
        world[deadend_cords[j]][deadend_cords[j+1]] = '#';
        j++;
    }
    //apply the deadends in final world cordinators
    fgets(lines , 100 , readfile);
    int heavens = atof(&lines[2]);
    int heaven_cords[100];
    position = 0;
    for(int i = 5 ; i<strlen(lines) ; i++){
        if(lines[i]>='0' && lines[i]<='9') {
            heaven_cords[position] = atof(&lines[i]);
            position +=1;
            if(atof(&lines[i])>=10)i++;
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
        numberOfCreatures = atof(&lines[2]);
        position = 0;
        for(int i = 5 ; i<strlen(lines);i++){
            if(lines[i]>='0' && lines[i]<='9') {
                creatures_cord[position] = atof(&lines[i]);
                position +=1;
                if(atof(&lines[i])>=10)i++;
            }
        }
        for(int j = 0 ; j<2*numberOfCreatures ; j++){
            world[creatures_cord[j]][creatures_cord[j+1]] = lines[0];
            j++;
        }
        fgets(lines , 100 ,readfile);
    }


    
    mapprinter(world,size);
    int ch;
    ch=fgetc(readfile);
    printf("The Creature under your control : %c\n",ch);
    int panimal[20];
    int n=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){

            if(world[i][j]==ch){
                panimal[n]=i;
                panimal[n+1]=j;
                n+=2;
            }
        }
    }
    int sw=0;
    
    for(;sw==0;){
        for(int i=0;i<n&&sw==0;i+=2){
            char direc;
            printf("you are at position:(%d,%d)\n",panimal[i],panimal[i+1]);
            printf("please enter your direction of movement:\n");
            scanf(" %c",&direc);
            if(direc=='a'){
                
                if(world[panimal[i]][panimal[i+1]-1]=='-'){
                    swap(world,panimal[i],panimal[i+1],panimal[i],panimal[i+1]-1);
                    panimal[i+1]-=1;
                }
                else if(world[panimal[i]][panimal[i+1]-1]=='H'){
                    sw=1;
                    world[panimal[i]][panimal[i+1]-1]=world[panimal[i]][panimal[i+1]];
                    world[panimal[i]][panimal[i+1]]='-';
                }
                else{
                     printf("\aERROR:please enter another direction\n");
                     i-=2;
                }
            }
            else if(direc=='w'){
                if(world[panimal[i]-1][panimal[i+1]]=='-'){
                    swap(world,panimal[i]-1,panimal[i+1],panimal[i],panimal[i+1]);
                    panimal[i]-=1;
                }
                else if(world[panimal[i]-1][panimal[i+1]]=='H'){
                    sw=1;
                    world[panimal[i]-1][panimal[i+1]]=world[panimal[i]][panimal[i+1]];
                    world[panimal[i]][panimal[i+1]]='-';
                }
                else{
                    printf("\aERROR:please enter another direction\n");
                    i-=2;
                }
            }
            else if(direc=='d'){
                if(world[panimal[i]][panimal[i+1]+1]=='-'){
                    swap(world,panimal[i],panimal[i+1]+1,panimal[i],panimal[i+1]);
                    panimal[i+1]+=1;
                }
                else if(world[panimal[i]][panimal[i+1]+1]=='H'){
                    sw=1;
                    world[panimal[i]][panimal[i+1]+1]=world[panimal[i]][panimal[i+1]];
                    world[panimal[i]][panimal[i+1]]='-';
                }
                else{
                    printf("\aERROR:please enter another direction\n");
                    i-=2;
                }
            }
            else if(direc=='x'){
                if(world[panimal[i]+1][panimal[i+1]]=='-'){
                    swap(world,panimal[i]+1,panimal[i+1],panimal[i],panimal[i+1]);
                    panimal[i]+=1;
                }
                else if(world[panimal[i]+1][panimal[i+1]]=='H'){
                    sw=1;
                    world[panimal[i]+1][panimal[i+1]]=world[panimal[i]][panimal[i+1]];
                    world[panimal[i]][panimal[i+1]]='-';
                }
                else{
                    printf("\aERROR:please enter another direction\n");
                    i-=2;
                }
            }
            else if(direc=='q'){
                if(world[panimal[i]-1][panimal[i+1]-1]=='-'){
                    swap(world,panimal[i]-1,panimal[i+1]-1,panimal[i],panimal[i+1]);
                    panimal[i]-=1;
                    panimal[i+1]-=1;
                }
                else if(world[panimal[i]-1][panimal[i+1]-1]=='H'){
                    sw=1;
                    world[panimal[i]-1][panimal[i+1]-1]=world[panimal[i]][panimal[i+1]];
                    world[panimal[i]][panimal[i+1]]='-';
                }
                else{
                    printf("\aERROR:please enter another direction\n");
                    i-=2;
                }
            }
            else if(direc=='e'){
                if(world[panimal[i]-1][panimal[i+1]+1]=='-'){
                    swap(world,panimal[i]-1,panimal[i+1]+1,panimal[i],panimal[i+1]);
                    panimal[i]-=1;
                    panimal[i+1]+=1;
                }
                else if(world[panimal[i]-1][panimal[i+1]+1]=='H'){
                    sw=1;
                    world[panimal[i]-1][panimal[i+1]+1]=world[panimal[i]][panimal[i+1]];
                    world[panimal[i]][panimal[i+1]]='-';
                }
                else{
                    printf("\aERROR:please enter another direction\n");
                    i-=2;
                }
            }
            else if(direc=='c'){
                if(world[panimal[i]+1][panimal[i+1]+1]=='-'){
                    swap(world,panimal[i]+1,panimal[i+1]+1,panimal[i],panimal[i+1]);
                    panimal[i]+=1;
                    panimal[i+1]+=1;
                }
                else if(world[panimal[i]+1][panimal[i+1]+1]=='H'){
                    sw=1;
                    world[panimal[i]+1][panimal[i+1]+1]=world[panimal[i]][panimal[i+1]];
                    world[panimal[i]][panimal[i+1]]='-';
                }
                else{
                    printf("\aERROR:please enter another direction\n");
                    i-=2;
                }
            }
            else if(direc=='z'){
                    if(world[panimal[i]+1][panimal[i+1]-1]=='-'){
                        swap(world,panimal[i]+1,panimal[i+1]-1,panimal[i],panimal[i+1]);
                        panimal[i]+=1;
                        panimal[i+1]-=1;
                    }
                    else if(world[panimal[i]+1][panimal[i+1]-1]=='H'){
                        sw=1;
                        world[panimal[i]+1][panimal[i+1]-1]=world[panimal[i]][panimal[i+1]];
                        world[panimal[i]][panimal[i+1]]='-';
                    }
                    else{
                        printf("\aERROR:please enter another direction\n");
                        i-=2;
                    }
                }
            else{
                printf("\athis direction isn't available!!\n");
                i-=2;
            }
            mapprinter(world,size);
        }
        if(sw==1) printf("creature %c won!!!",ch);
    }
}