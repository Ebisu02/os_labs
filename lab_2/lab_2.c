//
// Created by hello on 05.10.2022.
//
// WARNING: WORKING ONLY ON LINUX OS UNCOMMENT TO USE!!!

#include "lab_2.h"

const double KB = 1024;
const double MB = KB * 1024;
const double GB = MB * 1024;


void lab_2() {
    struct sysinfo systemInfo;
    sysinfo(&systemInfo);

    printf("RAM & SWAP:\n");
    printf("Total RAM - %.1f GB ", systemInfo.totalram / GB);
    printf("\nAvailable RAM - %.1f GB ", systemInfo.freeram / GB);
    printf("\nTotal SWAP - %.1f GB ", systemInfo.totalswap / GB);
    printf("\nAvailable SWAP - %.1f GB \n", systemInfo.freeswap / GB);
}

