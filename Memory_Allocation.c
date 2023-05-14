// Made by Mike_Zhang (https://mike.ultrafish.io)
// 2023-05-14
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int* memAllocFF;
int* memAllocBF;
int* memAllocWF;

// First Fit Algorithm
void FF(int* inMemSize, int *inHoleSize, int inM, int inH){
    memAllocFF = (int*) malloc(sizeof(int)*inM);
    int i;
    for (i=0;i<inM;i++) {
        memAllocFF[i]=-1;
    }
    for (i=0;i<inM;i++) {
        int j;
        for (j=0;j<inH;j++) {
            if (inMemSize[i]<=inHoleSize[j]) { // first fit
                memAllocFF[i]=j;
                inHoleSize[j]-=inMemSize[i];
                break;
            }
        }
    }
}

// Best Fit Algorithm
void BF(int* inMemSize, int *inHoleSize, int inM, int inH){
    memAllocBF = (int*) malloc(sizeof(int)*inM);
    int i;
    for (i=0;i<inM;i++) {
        memAllocBF[i]=-1;
    }
    for (i=0;i<inM;i++) {
        int j;
        int bfIndex=-1;
        for (j=0;j<inH;j++) {
            if (inMemSize[i]<=inHoleSize[j]) { // fit
                if (bfIndex==-1) { // first time fit
                    bfIndex=j;
                } else if (inHoleSize[j]<inHoleSize[bfIndex]) { // best fit
                    bfIndex=j;
                }
            }
        }
        if (bfIndex!=-1) {
            memAllocBF[i]=bfIndex;
            inHoleSize[bfIndex]-=inMemSize[i];
        }
    }
}

// Worst Fit Algorithm
void WF(int* inMemSize, int *inHoleSize, int inM, int inH){
    memAllocWF = (int*) malloc(sizeof(int)*inM);
    int i;
    for (i=0;i<inM;i++) {
        memAllocWF[i]=-1;
    }
    for (i=0;i<inM;i++) {
        int j;
        int wfIndex=-1;
        for (j=0;j<inH;j++) {
            if (inMemSize[i]<=inHoleSize[j]) { // fit
                if (wfIndex==-1) { // first time fit
                    wfIndex=j;
                } else if (inHoleSize[j]>inHoleSize[wfIndex]) { // worst fit
                    wfIndex=j;
                }
            }
        }
        if (wfIndex!=-1) {
            memAllocWF[i]=wfIndex;
            inHoleSize[wfIndex]-=inMemSize[i];
        }
    }
}
int main() {
    // Set the input Hole Sizes, Required Memory Sizes, and Total Memory Size below
    int holeSize[] = {234, 321, 108}; // Hole Sizes
    int memSize[] = {50,88,96,37,93,35,63,27,49,68,33,58}; // Required Memory Sizes
    int totalMemSize = 1000; // Total Memory Size

    int m = sizeof(memSize) / sizeof(memSize[0]);
    int h = sizeof(holeSize) / sizeof(holeSize[0]);
    int holeSum;
    int holeSizeFF[h], holeSizeBF[h], holeSizeWF[h];
    int i;
    for (i=0;i<h;i++) {
        holeSum+=holeSize[i];
        holeSizeFF[i]=holeSize[i];
        holeSizeBF[i]=holeSize[i];
        holeSizeWF[i]=holeSize[i];
    }
    FF(memSize, holeSizeFF, m, h);
    BF(memSize, holeSizeBF, m, h);
    WF(memSize, holeSizeWF, m, h);

    // print results
    printf("Memory Allocation Algorithms:\n");
    printf("> Original Request Memory: \t");
    for (i=0;i<m;i++) {
        printf("%d ", memSize[i]);
    }
    printf("\n> Original Hole Size: \t\t");
    for (i=0;i<h;i++) {
        printf("%d ", holeSize[i]);
    }

    printf("\n----------------------------------------------");
    printf("\n1. First Fit Algorithm\n");
    int ffAllocNum=0;
    int ffAllocSum=0;
    printf("Request No.\tRequest Size\tAllocated Hole\n");
    for (i=0;i<m;i++) {
        if (memAllocFF[i]!=-1) {
            ffAllocNum++;
            ffAllocSum+=memSize[i];
            printf("%d\t\t%d\t\t%d\n", i+1, memSize[i], memAllocFF[i]+1);
        }
        else {
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, memSize[i]);
        }
    }
    int remainingMem = 0;
    printf("> Remaining Hole Size: \t\t");
        for (i=0;i<h;i++) {
        printf("%d ", holeSizeFF[i]);
        remainingMem+=holeSizeFF[i];
    }
    printf("\n> Average Fit Rate: \t\t%.3f\n", (float)ffAllocNum/m);
    printf("> Average Memory Utilization: \t%.3f\n", (float)(totalMemSize-remainingMem)/totalMemSize);
    printf("> Average Fragmentation Rate: \t%.3f\n", (float)remainingMem/holeSum);
    printf("\n----------------------------------------------");
    printf("\n2. Best Fit Algorithm\n");
    int bfAllocNum=0;
    int bfAllocSum=0;
    printf("Request No.\tRequest Size\tAllocated Hole\n");
    for (i=0;i<m;i++) {
        if (memAllocBF[i]!=-1) {
            bfAllocNum++;
            bfAllocSum+=memSize[i];
            printf("%d\t\t%d\t\t%d\n", i+1, memSize[i], memAllocBF[i]+1);
        }
        else {
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, memSize[i]);
        }
    }
    remainingMem = 0;
    printf("> Remaining Hole Size: \t\t");
        for (i=0;i<h;i++) {
        printf("%d ", holeSizeBF[i]);
        remainingMem+=holeSizeBF[i];
    }
    printf("\n> Average Fit Rate: \t\t%.3f\n", (float)bfAllocNum/m);
    printf("> Average Memory Utilization: \t%.3f\n", (float)(totalMemSize-remainingMem)/totalMemSize);
    printf("> Average Fragmentation Rate: \t%.3f\n", (float)remainingMem/holeSum);
    printf("\n----------------------------------------------");
    printf("\n3. Worst Fit Algorithm\n");
    int wfAllocNum=0;
    int wfAllocSum=0;
    printf("Request No.\tRequest Size\tAllocated Hole\n");
    for (i=0;i<m;i++) {
        if (memAllocWF[i]!=-1) {
            wfAllocNum++;
            wfAllocSum+=memSize[i];
            printf("%d\t\t%d\t\t%d\n", i+1, memSize[i], memAllocWF[i]+1);
        }
        else {
            printf("%d\t\t%d\t\tNot Allocated\n", i+1, memSize[i]);
        }
    }
    remainingMem = 0;
    printf("> Remaining Hole Size: \t\t");
        for (i=0;i<h;i++) {
        printf("%d ", holeSizeWF[i]);
        remainingMem+=holeSizeWF[i];
    }
    printf("\n> Average Fit Rate: \t\t%.3f\n", (float)wfAllocNum/m);
    printf("> Average Memory Utilization: \t%.3f\n", (float)(totalMemSize-remainingMem)/totalMemSize);
    printf("> Average Fragmentation Rate: \t%.3f\n", (float)remainingMem/holeSum);
    return 0;
}
