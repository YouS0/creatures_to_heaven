#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int movingEnergy;
int moveNumber;
int multiplyEnergy;
int attackPower;
int deffencePower;
void uncDetails(char gene[30]) {
    int i = 0;
    char temp[4];
    
    void tempClear() {
        for (int j = 0; j < 4; j++) temp[j] = '\0';
    }
    
    int tempCount = 0;
    while (gene[i] != '$') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    movingEnergy = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '$') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    moveNumber = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '$') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    multiplyEnergy = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '$') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    attackPower = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '\0') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    deffencePower = atoi(temp);
}

int main()
{
    
    char b[30];
    scanf("%s", b);
    
    uncDetails(b);
    
    printf("%d %d %d %d %d", movingEnergy, moveNumber, multiplyEnergy, attackPower, deffencePower);

    return 0;
}