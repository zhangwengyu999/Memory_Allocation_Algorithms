> ***Please carefully read the [Disclaimer of Liability](#disclaimer-of-liability) below first.***  
> All materials in this archive are for reference only. The actual one may vary.

# Memory_Allocation_Algorithms
Implementation of Memory Allocation Algorithms in C Programming Language

Containing following three algorithms:
- First Fit (FF);
- Best Fit (BF);
- Worst Fit (WF).

---

## Before Running
Please configure the input memory data in the `main()` function in `Memory_Allocation.c` file before running.

For example:

```c
int main() {
    // Set the input Hole Sizes, Required Memory Sizes, and Total Memory Size below
    int holeSize[] = {234, 321, 108}; // Hole Sizes
    int memSize[] = {50,88,96,37,93,35,63,27,49,68,33,58}; // Required Memory Sizes
    int totalMemSize = 1000; // Total Memory Size
    // ...
}
```

---

## Compile and Run

1. Open the terminal;
2. Change directory to this folder;
3. Compile the `Memory_Allocation.c` file with `gcc` command:

```bash
gcc Memory_Allocation.c -o Memory_Allocation
```

4. Run the executable file:

```bash
./Memory_Allocation
```

5. The output will be shown in the terminal, for example:

```bash
./Memory_Allocation
Memory Allocation Algorithms:
> Original Request Memory:      50 88 96 37 93 35 63 27 49 68 33 58 
> Original Hole Size:           234 321 108 
----------------------------------------------
1. First Fit Algorithm
Request No.     Request Size    Allocated Hole
1               50              1
2               88              1
3               96              1
4               37              2
5               93              2
6               35              2
7               63              2
8               27              2
9               49              2
10              68              3
11              33              3
12              58              Not Allocated
> Remaining Hole Size:          0 17 7 
> Average Fit Rate:             0.917
> Average Memory Utilization:   0.976
> Average Fragmentation Rate:   0.036

----------------------------------------------
2. Best Fit Algorithm
Request No.     Request Size    Allocated Hole
1               50              3
2               88              1
3               96              1
4               37              1
5               93              2
6               35              3
7               63              2
8               27              2
9               49              2
10              68              2
11              33              Not Allocated
12              58              Not Allocated
> Remaining Hole Size:          13 21 23 
> Average Fit Rate:             0.833
> Average Memory Utilization:   0.943
> Average Fragmentation Rate:   0.086

----------------------------------------------
3. Worst Fit Algorithm
Request No.     Request Size    Allocated Hole
1               50              2
2               88              2
3               96              1
4               37              2
5               93              2
6               35              1
7               63              3
8               27              1
9               49              1
10              68              Not Allocated
11              33              2
12              58              Not Allocated
> Remaining Hole Size:          27 20 45 
> Average Fit Rate:             0.833
> Average Memory Utilization:   0.908
> Average Fragmentation Rate:   0.139
```

---

## Disclaimer of Liability

**The material and information contained on this website is for general information, reference, and self-learning purposes only. You should not rely upon the material or information on the website as a basis for making any academic, business, legal or any other decisions. You should not copy any material or information on the website into any of your academic, business, legal or any other non-private usages. ZHANG Wengyu will not be responsible for any consequences due to your violations.**


Whilst ZHANG Wengyu endeavours to keep the information up to date and correct, ZHANG Wengyu makes no representations or warranties of any kind, express or implied about the completeness, accuracy, reliability, suitability or availability with respect to the website or the information, products, services or related graphics contained on the website for any purpose. Any reliance you place on such material is therefore strictly at your own risk.


ZHANG Wengyu will not be liable for any false, inaccurate, inappropriate or incomplete information presented on the website.


Although every effort is made to keep the website up and running smoothly, due to the nature of the Internet and the technology involved, ZHANG Wengyu takes no responsibility for and will not be liable for the website being temporarily unavailable due to technical issues (or otherwise) beyond its control or for any loss or damage suffered as a result of the use of or access to, or inability to use or access this website whatsoever.
