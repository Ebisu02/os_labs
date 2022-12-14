//
// Created by hello on 04.10.2022.
//

#include "lab_5.h"

struct List* init(char* firstName, char* lastName, short int course, char* group, double mark) {
    struct List *list;
    list = (struct List*)malloc(sizeof(struct List));
    strcpy(list->data.firstName, firstName);
    strcpy(list->data.lastName, lastName);
    strcpy(list->data.group, group);
    list->data.course = course;
    list->data.mark = mark;

    list->next = NULL;
    list->prev = NULL;

    return(list);
}

void toList(struct List *list, char* firstName, char* lastName, short int course, char* group, double mark) {
    int i, j = 1;
    struct List *pnew, *p = list;
    pnew = (struct List*)malloc(sizeof(struct List));

    strcpy(pnew->data.firstName, firstName);
    strcpy(pnew->data.lastName, lastName);
    pnew->data.course = course;
    strcpy(pnew->data.group, group);
    pnew->data.mark = mark;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = pnew;
    pnew->prev = p;
    pnew->next = NULL;
}


// NOT WORKING
void toListByIndex(struct List *list, char* firstName, char* lastName, short int course, char* group, double mark, int index) {
    struct List *pnew, *p = list;
    pnew = (struct List*)malloc(sizeof(struct List));

    strcpy(pnew->data.firstName, firstName);
    strcpy(pnew->data.lastName, lastName);
    pnew->data.course = course;
    strcpy(pnew->data.group, group);
    pnew->data.mark = mark;
    int counter = 0;
    while (p->next != NULL && counter != index) {
        p = p->next;
        ++counter;
    }
    if (p->next != NULL) {
        struct List *ptemp = p;
        pnew->next = p->next;
        pnew->prev = p->prev;
        p->prev->next = pnew;
        p->next->prev = pnew;
        p->next = NULL;
        p->prev = NULL;
        while (pnew->next != NULL) {
            pnew = pnew->next;
        }
        pnew->next = p;
        p->prev = pnew;
        p->next = NULL;
    }
    else {
        p->next = pnew;
        pnew->prev = p;
        pnew->next = NULL;
    }
}

struct List *delete(struct List *list) {
    struct List *prev, *next;
    prev = list->prev;
    next = list->next;

    if (next == NULL && prev == NULL) {
        free(list);
        return(prev);
    }
    if (next == NULL && prev != NULL) {
        prev->next = NULL;
        free(list);
        return(prev);
    }
    if (next != NULL && prev == NULL) {
        next->prev = NULL;
        free(list);
        return (prev);
    }
    if (next != NULL && prev != NULL) {
        next->prev = prev;
        prev->next = next;
        free(list);
        return(prev);
    }
    return(prev);
}

void printList(struct List *list) {
    printf("List:\n");
    struct List *p;
    p = list;
    do {
        printf("%s %s %d %s %.2lf\n", p->data.firstName, p->data.lastName, p->data.course, p->data.group, p->data.mark);
        p = p->next;
    } while (p != NULL);
}

void addFromKeyboard(struct List* list) {
    struct List *pnew, *p = list;
    pnew = (struct List*)malloc(sizeof(struct List));
    char tFName[16], tLName[16], tGroup[8];
    double tMark;
    short int tCourse;

    printf("%s", "FirstName:");
    scanf("%s", tFName);

    printf("%s", "LastName:");
    scanf("%s", tLName);

    printf("%s", "Group:");
    scanf("%s", tGroup);

    printf("%s", "Mark:");
    scanf("%lf", &tMark);

    printf("%s", "Course:");
    scanf("%d", &tCourse);

    printf("%s", "\n");

    strcpy(pnew->data.firstName, tFName);
    strcpy(pnew->data.lastName, tLName);
    strcpy(pnew->data.group, tGroup);
    pnew->data.mark = tMark;
    pnew->data.course = tCourse;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = pnew;
    pnew->prev = p;
    pnew->next = NULL;
}

void serialize(char* fileName, struct List* list) {
    FILE* t;
    t = fopen(fileName, "bw");
    fwrite(&list, sizeof(list), 1, t);
    fclose(t);
}

struct List* deserialize(char* pathToFile) {
    return NULL;
}
