//
// Created by hello on 04.10.2022.
//

#ifndef OS_LABS_LAB_1_H
#define OS_LABS_LAB_1_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

#endif //OS_LABS_LAB_1_H
