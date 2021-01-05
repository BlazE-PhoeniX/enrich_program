#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Input values:
        boy m father mother
        father m grandfather_p grandmother_p
        aunt_p1 f grandfather_p grandmother_p
        aunt_p2 f grandfather_p grandmother_p
        uncle_p3 m grandfather_p grandmother_p
        girl_1 f uncle_p1 aunt_p1
        girl_2 f uncle_p1 aunt_p1
        girl_3 f uncle_p2 aunt_p2
        girl_4 f uncle_p3 aunt_p3
        mother f grandfather_m grandmother_m
        uncle_m1 m grandfather_m grandmother_m
        aunt_m2 f grandfather_m grandmother_m
        girl_5 f uncle_m1 aunt_m1
        girl_6 f uncle_m1 aunt_m1
        girl_7 f uncle_m2 aunt_m2
*/

struct Person {
    char name[15];
    int isMale;
    int noOfBro;
    int noOfSis;
    int noOfSons;
    int noOfDaughters;

    struct Person *father;
    struct Person *mother;
    struct Person *brothers[10];
    struct Person *sisters[10];
    struct Person *spouse;
    struct Person *sons[10]; 
    struct Person *daughters[10];
};

struct Person *populations[100]; 
int noOfMembers=0;

void addToDB(struct Person *person) {
    populations[noOfMembers] = person;
    noOfMembers++;
}

struct Person* searchPerson(char personName[30]) {
    for(int i=0; i<noOfMembers; i++) {
        if(strcmp(personName, populations[i]->name)==0) {
            return populations[i];
        } 
    }
    return NULL;
}

struct Person* getPerson(char name[30]) {
    struct Person *person = searchPerson(name);
    if(person != NULL) {
        return person;
    }

    person = (struct Person*) malloc(sizeof(struct Person));
    person->noOfBro = person->noOfSis = person->noOfSons = person->noOfDaughters = 0;
    person->father = person->mother = person->spouse = NULL;

    strcpy(person->name, name);

    addToDB(person);

    return person;
}

void setChild(struct Person *parent, struct Person *child) {
    if(child->isMale) {
        parent->sons[parent->noOfSons] = child;
        parent->noOfSons++;
    } else {
        parent->daughters[parent->noOfDaughters] = child;
        parent->noOfDaughters++;
    }
}

void setBrothers(struct Person *person, struct Person *brothers[10], int noOfBrothers) {
    for(int i=0; i<noOfBrothers; i++) {
        struct Person *brother = brothers[i];
        person->brothers[i] = brother;
        if(person->isMale) {
            brother->brothers[brother->noOfBro] = person;
            brother->noOfBro += 1;
        } else {
            brother->sisters[brother->noOfSis] = person;
            brother->noOfSis += 1;
        }
    }
    person->noOfBro = noOfBrothers;
}

void setSisters(struct Person *person, struct Person *sisters[10], int noOfSisters) {
    for(int i=0; i<noOfSisters; i++) {
        struct Person *sister = sisters[i];
        person->sisters[i] = sister;
        if(person->isMale) {
            sister->brothers[sister->noOfBro] = person;
            sister->noOfBro += 1;
        } else {
            sister->sisters[sister->noOfSis] = person;
            sister->noOfSis += 1;
        }
    }
    person->noOfSis = noOfSisters;
} 

void setParents(struct Person* person, char fatherName[30], char motherName[30]) {
    struct Person *father = getPerson(fatherName);
    struct Person *mother = getPerson(motherName);
    
    father->spouse = mother;
    mother->spouse = father;
    
    person->father = father;
    person->mother = mother;

    setBrothers(person, father->sons, father->noOfSons);
    setSisters(person, father->daughters, father->noOfDaughters);

    setChild(mother, person);
    setChild(father, person);
}

void addPerson(char name[30], int isMale, char fatherName[30], char motherName[30]) {
    struct Person *person = getPerson(name);
    person->isMale = isMale;
    setParents(person, fatherName, motherName);
}

void printPerson(struct Person* person) {
    printf("name=%s / ", person->name);
    printf("spouse=%s / ", person->spouse->name);
    printf("no_of_brothers=%d / ", person->noOfBro);
    printf("no_of_sisters=%d / ", person->noOfSis);
    printf("no_of_Sons=%d / ", person->noOfSons);
    printf("no_of_daughters=%d\n\n", person->noOfDaughters);
} 

void printPopulation() {
    for(int i=0; i<noOfMembers; i++) {
        printPerson(populations[i]);
    }
}

void listDaughters(struct Person *person) {
    for(int i=0; i<person->noOfDaughters; i++) {
        printf("%s\n", person->daughters[i]->name);
    }
}

void listSons(struct Person *person) {
    for(int i=0; i<person->noOfSons; i++) {
        printf("%s\n", person->sons[i]->name);
    }
}

void listMarriageableCousins(struct Person *person) {
    if(person->father!=NULL && person->mother!=NULL) {
        printf("list of %s's marriageable cousins...\n", person->name);

        if(person->isMale){

            for(int i=0; i<person->father->noOfSis; i++) {
                listDaughters(person->father->sisters[i]);
            }

            for(int i=0; i<person->mother->noOfBro; i++) {
                listDaughters(person->mother->brothers[i]);
            }

        } else {
            
            for(int i=0; i<person->father->noOfSis; i++) {
                listSons(person->father->sisters[i]);
            }

            for(int i=0; i<person->mother->noOfBro; i++) {
                listSons(person->mother->brothers[i]);
            }

        }
        printf("\n");
    }
}

int main() { 
    addPerson("boy", 1, "father", "mother");
    addPerson("father", 1, "grandfather_p", "grandmother_p");
    addPerson("aunt_p1", 0, "grandfather_p", "grandmother_p");
    addPerson("aunt_p2", 0, "grandfather_p", "grandmother_p");
    addPerson("uncle_p3", 1, "grandfather_p", "grandmother_p");
    addPerson("girl_1", 0, "uncle_p1", "aunt_p1");
    addPerson("girl_2", 0, "uncle_p1", "aunt_p1");
    addPerson("girl_3", 0, "uncle_p2", "aunt_p2");
    addPerson("girl_4", 0, "uncle_p3", "aunt_p3");
    addPerson("mother", 0, "grandfather_m", "grandmother_m");
    addPerson("uncle_m1", 1, "grandfather_m", "grandmother_m");
    addPerson("aunt_m2", 0, "grandfather_m", "grandmother_m");
    addPerson("girl_5", 0, "uncle_m1", "aunt_m1");
    addPerson("girl_6", 0, "uncle_m1", "aunt_m1");
    addPerson("girl_7", 0, "uncle_m2", "aunt_m2");
    // printPopulation();

    listMarriageableCousins(searchPerson("boy"));
    return 0;
}

/*
    Output:
       list of boy's marriageable cousins...
       girl_1
       girl_2
       girl_3
       girl_5
       girl_6
*/


 
