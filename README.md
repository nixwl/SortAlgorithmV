# SortAlgorithmV
## project introduction 

- Why Do ? This project is a course assignment, tend to implement bubble sort, quick sort (traditional, improved, non-recursive), heap sort, merge sort. At the same time, evaluate the pros and cons of these algorithms
- what Do ? Implementation and verification of several sorting algorithms

## Main functions

- F1: Implemented four basic algorithms, bubble sort, quick sort (traditional), heap sort, merge sort
- F2: Implemented non recursive quick sort and use `bfprt` algorithm to update quick sort. It mainly optimized the selection of pivot values.
- F3: We used timers to calculate the running time of different sorting algorithms and counted the running time of different algorithms
- F4: We have analyzed the stability of these algorithms and verified whether they have stability

## Insufficient

- Some system codes do not consider synchronous input and output, and some test data is written dead by us, making it inconvenient for flexible testing
- Not all sorting algorithms has been added

## Usage

- First: Compile C++programs, then a executable file will be generated in dir: `./output/x.exe`.Check `makefile.win`(it's a makefile)to get more details
- Second: Run `x.exe` in command line, eg: `x.exe <command> -p1 xx -p2`, you can use `x.exe help` for more help
