#include "lab_5.h"

void lab_1() {
    char firstName[16] = "TestInit";
    char lastName[16] = "TestInit";
    char group[8] = "ip";
    double mark = 4.2;
    short int course = 3;
    struct List* journal = init(firstName, lastName, course, group, mark);
    toList(journal, "TestToList", "TestToList", 1, "ip", 4.21);
    toList(journal, "TestToList", "TestToList", 1, "ip", 4.21);
    //printf("\n%s", journal->data.firstName);
    delete(journal->next);
    printList(journal);
}
