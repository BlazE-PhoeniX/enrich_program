#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    hari m vinayagam chitra
    vinayagam m annamalai boosanam
    athai1 f annamalai boosanam
    girl1 f mama1 athai1
    chitra f pandurangam selvi
    Tmama1 m pandurangam selvi
    girl2 f Tmama1 mammy1

*/

struct Person {
    char name[30];
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

struct Population {
    char name[30];
    struct Person* person;
};

struct Population populations[100]; 
int noOfMembers=0;

struct Person* searchPerson(char personName[30]) {
    for(int i=0; i<noOfMembers; i++) {
        if(strcmp(personName, populations[i].name)==0) {
            return populations[i].person;
        } 
    }
    return NULL;
}

struct Person* getPerson(char name[30]) {
    struct Person* person = searchPerson(name);
    if(person != NULL) {
        return person;
    }

    person = (struct Person*) malloc(sizeof(struct Person*));
    strcpy(person->name, name);
    person->noOfBro=0;
    person->noOfSis=0;
    person->noOfSons=0;
    person->noOfDaughters=0;

    strcpy(populations[noOfMembers].name, name);
    populations[noOfMembers++].person = person;

    return person;
}

void setSiblings(struct Person* person, struct Person* brothers[10], int noOfBrothers, struct Person* sisters[10], int noOfSisters) {
    for(int i=0; i<noOfBrothers; i++) {
        struct Person* brother = brothers[i];
        person->brothers[i] = brother;
        if(person->isMale) {
            brother->brothers[brother->noOfBro++] = person;
        } else {
            brother->sisters[brother->noOfSis++] = person;
        }
    }
    person->noOfBro = noOfBrothers;

    for(int i=0; i<noOfSisters; i++) {
        struct Person* sister = sisters[i];
        person->sisters[i] = sister;
        if(person->isMale) {
            sister->brothers[sister->noOfBro++] = person;
        } else {
            sister->sisters[sister->noOfSis++] = person;
        }
    }
    person->noOfSis = noOfSisters;
}

void setParents(struct Person* person, char fatherName[30], char motherName[30]) {
    struct Person* father = getPerson(fatherName);
    struct Person* mother = getPerson(motherName);
    father->spouse = mother;
    mother->spouse = father;
    
    setSiblings(person, father->sons, father->noOfSons, father->daughters, father->noOfDaughters);
    if(person->isMale) {
        father->sons[father->noOfSons++] = person;
        mother->sons[mother->noOfSons++] = person;
    } else {
        father->daughters[father->noOfDaughters++] = person;
        mother->daughters[mother->noOfDaughters++] = person;
    }

    person->father = father;
    person->mother = mother;
}

void addPerson(char name[30], int isMale, char fatherName[30], char motherName[30]) {
    struct Person* person = getPerson(name);
    person->isMale = isMale;
    setParents(person, fatherName, motherName);
}

void printPerson(struct Person* person) {
    printf("name: %s ", person->name);
    printf("spouse: %s ", person->spouse->name);
    printf("no of brothers: %d ", person->noOfBro);
    printf("no of sisters: %d ", person->noOfSis);
    printf("no of Sons: %d ", person->noOfSons);
    printf("no of daughters: %d\n\n", person->noOfDaughters);
}   

void printPopulation() {
    for(int i=0; i<noOfMembers; i++) {
        printPerson(populations[i].person);
    }
}

int main() { 
    addPerson("hariprasath", 1, "vinayagam", "chitra");
    addPerson("vinayagam", 1, "annamalai", "boosanam");
    addPerson("chitra", 0, "pandurangam", "selvi");
    printPopulation();
}
 
