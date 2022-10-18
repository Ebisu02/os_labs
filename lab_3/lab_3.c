//
// Created by hello on 05.10.2022.
//

#include "lab_3.h"

// WARNING: WORKING ONLY ON LINUX OS UNCOMMENT TO USE!!!

void ex2() {
    pid_t p1, p2, p3, p4, p5, p6, p7, p8;
    printf("Parent of all: %d\n", getpid());
    p1 = fork();
    //pause();
    if (p1 == 0) {
        printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
        p2 = fork();
        //pause();
        if (p2 == 0) {
            printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
        }
    }
    else {
        p3 = fork();
        //pause();
        if (p3 == 0) {
            printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
            p4 = fork();
            //pause();
            if (p4 == 0) {
                printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
                p5 = fork();
                //pause();
                if (p5 == 0) {
                    printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
                }
            }
        }
        else {
            p6 = fork();
            //pause();
            if (p6 == 0) {
                printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
                p7 = fork();
                //pause();
                if (p7 == 0) {
                    printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
                }
            }
        }
    }
    if (p1 > 0) {
        p8 = fork();
        pause();
        if (p8 == 0) {
            printf("Child with id: %d and and its Parent id: %d \n", getpid(), getppid());
        }
    }
    for (int i = 0; i < 5; ++i) { wait(NULL); }
}

void ex1() {
    pid_t _pid, p_pid;
    _pid = fork();
    printf("PROC: %i\nPARENT: %i\n", _pid, p_pid = (int) getpid());
    system("ps | grep \"main\" | uniq");
    if (_pid != 0) {
        //kill( _pid, SIGSEGV);
        kill( p_pid, SIGTERM);
    }
    printf("AFTER KILLING:\n");
    printf("PROC: %i\nPARENT: %i\n", _pid, p_pid = (int) getpid());
}

void fcreate_proc() {
    pid_t child_pid, parent_pid;
    double s = 0.0;
    FILE* fp;
    child_pid = fork();
    fp = fopen("test.dat", "a+");
    if (child_pid != 0) {
        s += 3.14;
        fprintf(fp, "CHILD: %i s=%g &s=%u fp=%u\n", (int) getpid(), s, &s, fp);
    }
    else {
        s += 2.72;
        fprintf(fp, "CHILD: %i s=%g &s=%u fp=%u\n", (int) getpid(), s, &s, fp);
    }
    fclose(fp);
}

void recreate_proc() {
    pid_t child_pid, parent_pid;
    int i = 0;
    fprintf(stdout, "Before REACREATION %i\n", parent_pid = (int)getpid());
    child_pid = fork();
    while (i++ < 5) {
        if (child_pid != 0) {
            oldman();
        }
        else {
            recreation_proc();
        }
    }
}

void oldman() {
    fprintf(stdout, "I'm not yet dead! My ID is %i\n", (int) getpid());
}

void recreation_proc() {
    fprintf(stdout, "Who I am? My ID is %i\n", (int) getpid());
}

void create_proc() {
    pid_t child_pid, parent_pid;
    double s = 0.0;
    child_pid = fork();
    if (child_pid != 0) {
        s += 3.14;
        fprintf(stdout, "CHILD: %i s=%g &s=%u\n", (int) getpid(), s, &s);
    }
    else {
        s += 2.72;
        fprintf(stdout, "PARENT: %i s=%g &s=%u\n", (int) getpid(), s, &s);
    }
}

