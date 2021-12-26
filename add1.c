struct uncAnimal {
    char name;
    int position[2];
    int destinition[2];
    int energy;
};

struct uncAnimal uncAnimals[20];
int uncAnimalsCount = 0;

void addUncAnimal(char _name, int x_position, int y_position, int x_destinition, int y_destinition, int _energy) {
    struct uncAnimal theUncAnimal = {_name, {x_position, y_position}, {x_destinition, y_destinition}, _energy};
    uncAnimals[uncAnimalsCount] = theUncAnimal;
    
    uncAnimalsCount++;
}

void moveUncAnimal(struct uncAnimal theUncAnimal) {
    int dx = theUncAnimal.destinition[0] - theUncAnimal.position[0];
    int dy = theUncAnimal.destinition[1] - theUncAnimal.position[1];
    
    if (dx > 0) theUncAnimal.position[0] += 1;
    else if (dx < 0) theUncAnimal.position[0] += -1;
    
    if (dy > 0) theUncAnimal.position[1] += 1;
    else if (dy < 0) theUncAnimal.position[1] += -1;
}
