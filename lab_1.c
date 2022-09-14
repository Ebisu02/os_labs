#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Student {
  char* firstName;
  char* lastName;
  short int course;
  char* group;
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
  list->data.firstName = firstName;
  list->data.lastName = lastName;
  list->data.course = course;
  list->data.group = group;
  list->data.mark = mark;

  list->next = NULL;
  list->prev = NULL;

  return(list);
}

void add(struct List *list, char* firstName, char* lastName, short int course, char* group, double mark, int n) {
  int i, j = 1;
  struct List *pnew, *p = list;
  pnew = (struct List*)malloc(sizeof(struct List));

  pnew->data.firstName = firstName;
  pnew->data.lastName = lastName;
  pnew->data.course = course;
  pnew->data.group = group;
  pnew->data.mark = mark;

  if (n <= 1 || list == NULL) {
    pnew->next = list;
    list = pnew;
  }
  else {
    if (p->next != NULL) {
      p = p->next;
      ++j;
    }
    if (n <= j + 1)
    {
      pnew->next = p->next;
      p->next = pnew;
    }
  }
}

struct List *addElement(struct List *list, char* firstName, char* lastName, short int course, char* group, double mark) {
  struct List *temp, *p;
  temp = (struct List*)malloc(sizeof(struct List));
  p = list->next;
  list->next = temp;

  temp->data.firstName = firstName;
  temp->data.lastName = lastName;
  temp->data.mark = mark;
  temp->data.course = course;
  temp->data.group = group;

  temp->next = p;
  temp->prev = list;
  if (p != NULL) {
    p->prev = temp;
  }
  return(temp);
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
    printf("%s %s %d %s %.2f %s", p->data.firstName, p->data.lastName, p->data.course, p->data.group, p->data.mark, "\n");
    ++num;
    p = p->next;
  } while (p != NULL);
}

struct List* listNav(struct List *list, int cnt) {
  struct List *p;
  p = list;
  int i = 0;
  while (i < cnt) {
    if (i == cnt - 1) {
      printf("%s", p->data.firstName);
      printf("%s", " ");
      printf("%s", p->data.lastName);
      printf("%s", " ");
      printf("%d", p->data.course);
      printf("%s", " ");
      printf("%s", p->data.group);
      printf("%s", " ");
      printf("%f", p->data.mark);
      return p;
    }
    p = p->next;
    ++i;
  }
  return NULL;
}

int main() {
  char firstName[16] = "Serega\0";
  char lastName[16] = "Familia\0";
  char group[8] = "ip-015\0";
  double mark = 4.2;
  short int course = 3;

  char firstNameTest[16] = "Alina\0";
  char lastNameTest[16] = "Flia\0";
  char groupTest[8] = "ip-015\0";
  double markTest = 4.9;
  short int courseTest = 2;

  struct List* journal = init(firstName, lastName, course, group, mark);
  addElement(journal, firstNameTest, lastNameTest, courseTest, groupTest, markTest);
  printList(journal);
}
