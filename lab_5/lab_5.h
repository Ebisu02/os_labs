#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

void lab_4();
int main3();
void main1();

struct Student {
    char firstName[16];
    char lastName[16];
    short int course;
    char group[8];
    double mark;
};

struct List {
    struct Student data;
    struct List *next;
    struct List *prev;
};

struct List* init(char* firstName, char* lastName, short int course, char* group, double mark);
void toList(struct List *list, char* firstName, char* lastName, short int course, char* group, double mark);
// TODO: NOT WORKING RN
void toListByIndex(struct List *list, char* firstName, char* lastName, short int course, char* group, double mark, int index);
struct List *delete(struct List *list);
void printList(struct List *list);
void addFromKeyboard(struct List* list);
void serialize(char* fileName, struct List* list);
// TODO: NOT WORKING RN
struct List* deserialize(char* pathToFile);
void lab_1();
