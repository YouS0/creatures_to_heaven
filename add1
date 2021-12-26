struct uncAnimal {
    char name;
    int position[2];
    int destinition[2];
    int energy;
}

struct uncAnimal uncAnimals[20];

void moveUncAnimal(struct animal theUncAnimal) {
    int dx = theUncAnimal.destinition[0] - theUncAnimal.position[0];
    int dy = theUncAnimal.destinition[1] - theUncAnimal.position[1];
    
    if (dx > 0) theUncAnimal.position[0] += 1;
    else if (dx < 0) theUncAnimal.position[0] += -1;
    
    if (dy > 0) theUncAnimal.position[1] += 1;
    else if (dy < 0) theUncAnimal.position[1] += -1;
}
