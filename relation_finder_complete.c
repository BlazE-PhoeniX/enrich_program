#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Input values:
    boy m father mother
    father m grandfather_p grandmother_p
    aunt_p1 f grandfather_p grandmother_p
    girl_1 f uncle_p1 aunt_p1
    mother f grandfather_m grandmother_m
    uncle_m1 m grandfather_m grandmother_m
    girl_2 f uncle_m1 aunt_m1
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

struct Population {
    char name[30];
    struct Person *person;
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
    struct Person *person = searchPerson(name);
    if(person != NULL) {
        return person;
    }

    person = (struct Person*) malloc(sizeof(struct Person));
    person->noOfBro = person->noOfSis = person->noOfSons = person->noOfDaughters = 0;
    person->father = person->mother = person->spouse = NULL;

    strcpy(person->name, name);

    strcpy(populations[noOfMembers].name, name);
    populations[noOfMembers].person = person;
    noOfMembers++;

    return person;
}

void setSiblings(struct Person *person, struct Person *brothers[10], int noOfBrothers, struct Person *sisters[10], int noOfSisters) {

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
    
    setSiblings(person, father->sons, father->noOfSons, father->daughters, father->noOfDaughters);
    if(person->isMale) {
        father->sons[father->noOfSons] = person;
        mother->sons[mother->noOfSons] = person;
        father->noOfSons = mother->noOfSons = (father->noOfSons + 1);
    } else {
        father->daughters[father->noOfDaughters] = person;
        mother->daughters[mother->noOfDaughters] = person;
        father->noOfDaughters = mother->noOfDaughters = (father->noOfDaughters + 1);
    }

    person->father = father;
    person->mother = mother;
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
        printPerson(populations[i].person);
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
    addPerson("girl_1", 0, "uncle_p1", "aunt_p1");
    addPerson("mother", 0, "grandfather_m", "grandmother_m");
    addPerson("uncle_m1", 1, "grandfather_m", "grandmother_m");
    addPerson("girl_2", 0, "uncle_m1", "aunt_m1");
    // printPopulation();

    listMarriageableCousins(searchPerson("boy"));
    return 0;
}

/*
    Output:

 *   list of boy's marriageable cousins...
 *   girl_1
 *   girl_2

*/


 
