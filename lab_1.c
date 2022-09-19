#define _CRT_SECURE_NO_WARNINGS
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

struct List *deleteElement(struct List *list) {
    struct List *prev, *next;
    prev = list->prev;
    next = list->next;
    if (prev != NULL) {
        prev->next = list->next;
    }
    if (next != NULL) {
        next->prev = list->prev;
    }
    free(list);
    return(prev);
}

struct List* deleteElementByIndex(struct List *list, int cnt) {
    struct List *p;
    p = list;
    int i = 0;
    while (i < cnt) {
        if (i == cnt - 1) {
            return p;
        }
        p = p->next;
        ++i;
    }
    return NULL;
}

void printList(struct List *list) {
    printf("List:\n");
    struct List *p;
    p = list;
    int num = 1;
    do {
        printf("%s %s %d %s %.2lf\n", p->data.firstName, p->data.lastName, p->data.course, p->data.group, p->data.mark);
        p = p->next;
    } while (p != NULL);
}


void addElementFromKeyboard(struct List* list) {
    int i, j = 1;
    struct List *pnew, *p = list;
    pnew = (struct List*)malloc(sizeof(struct List));

    printf("%s", "FirstName:");
    scanf("%s", pnew->data.firstName);
    printf("%s", pnew->data.firstName);

    printf("%s", "LastName:");
    scanf("%s", pnew->data.lastName);

    printf("%s", "Group:");
    scanf("%s", pnew->data.group);

    double tempMark = 0.0;
    printf("%s", "Mark:");
    scanf("%lf", &tempMark);
    short int tempCourse = 0;
    printf("%s", "Course:");
    scanf("%d", &tempCourse);
    printf("%s", "\n");

    pnew->data.course = tempCourse;
    pnew->data.mark = tempMark;

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = pnew;
    pnew->prev = p;
    pnew->next = NULL;
}

int main() {
    char firstName[16] = "firstName\0";
    char lastName[16] = "lastName\0";
    char group[8] = "group\0";
    double mark = 4.2;
    short int course = 3;
    struct List* journal = init(firstName, lastName, course, group, mark);
    addElementFromKeyboard(journal);
    printList(journal);
}
