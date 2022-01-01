#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int movingEnergyTemp;
int moveNumberTemp;
int multiplyEnergyTemp;
int attackPowerTemp;
int deffencePowerTemp;
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
    movingEnergyTemp = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '$') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    moveNumberTemp = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '$') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    multiplyEnergyTemp = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '$') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    attackPowerTemp = atoi(temp);
    tempCount = 0;
    tempClear();
    i++;
    
    while (gene[i] != '\0') {
        temp[tempCount] = gene[i];
        
        tempCount++;
        i++;
    }
    deffencePowerTemp = atoi(temp);
}

int main()
{
    
    char b[30];
    scanf("%s", b);
    
    uncDetails(b);
    
    printf("%d %d %d %d %d", movingEnergy, moveNumber, multiplyEnergy, attackPower, deffencePower);

    return 0;
}
