# PBLE 1: Smart Delivery Planning – Fractional Knapsack

## Aim
To implement the Fractional Knapsack problem in C using the Greedy Algorithm to maximize the total value of packages carried by a delivery vehicle with limited capacity.

## Problem Statement
A delivery company has a vehicle with a fixed carrying capacity. Each package has a specific weight and an associated value or profit. The objective is to maximize the total value carried without exceeding the vehicle's capacity.

In the Fractional Knapsack problem, a complete package or a fraction of a package can be selected.

## Objectives
- Understand and implement the Greedy Method.
- Calculate the value-to-weight ratio of each package.
- Sort packages in decreasing order of value-to-weight ratio.
- Select complete packages whenever possible.
- Select a fraction of a package when the remaining capacity is insufficient.
- Calculate the maximum achievable value.
- Analyze the time and space complexity.

## Algorithm
1. Start.
2. Read the number of packages, their values, weights, and vehicle capacity.
3. Calculate the value-to-weight ratio for each package:

   `Ratio = Value / Weight`

4. Sort all packages in descending order of their ratios.
5. Initialize the remaining capacity and total value to zero and the vehicle capacity, respectively.
6. Traverse the sorted packages:
   - If a package fits completely, select it.
   - Otherwise, select the fraction that fits in the remaining capacity.
7. Update the total weight and total value.
8. Display the selected packages, fractions, total weight used, and maximum value.
9. Stop.

## Example

### Input

| Package | Value | Weight |
|---|---:|---:|
| 1 | 40 | 5 |
| 2 | 30 | 10 |
| 3 | 50 | 5 |
| 4 | 20 | 4 |

**Vehicle capacity:** 15

### Value-to-Weight Ratios

| Package | Value | Weight | Ratio |
|---|---:|---:|---:|
| 3 | 50 | 5 | 10 |
| 1 | 40 | 5 | 8 |
| 4 | 20 | 4 | 5 |
| 2 | 30 | 10 | 3 |

### Optimal Selection

- Package 3: Take 100% — value = 50, weight = 5.
- Package 1: Take 100% — value = 40, weight = 5.
- Package 4: Take 100% — value = 20, weight = 4.
- Package 2: Take 10% — value = 3, weight = 1.

**Total weight used:** 15

**Maximum value obtained:** 113

## Technologies Used
- Programming Language: C
- Concepts: Structures, arrays, functions, sorting, and greedy algorithms.
- Compiler: GCC or any standard C compiler.

## How to Compile and Run

Compile the program using GCC:

```bash
gcc pble.c -o pble
```

Run on Windows:

```powershell
.\pble.exe
```

Alternatively, compile and run in one step:

```bash
gcc pble.c -o pble.exe
.\pble.exe
```

## Menu Options
1. Enter Package Details
2. Display Package Details
3. Calculate Value/Weight Ratio
4. Sort Packages by Ratio
5. Find Maximum Value
6. Display Selected Packages
7. Exit

## Complexity Analysis

The program uses Bubble Sort to arrange packages by their value-to-weight ratios.

- **Time Complexity:** `O(n²)` due to Bubble Sort.
- **Space Complexity:** `O(n)` for storing the package information.

Here, `n` is the number of packages.

## Conclusion
The Fractional Knapsack problem is solved using the Greedy Algorithm. By selecting packages in decreasing order of their value-to-weight ratios, the program maximizes the total value carried without exceeding the vehicle's capacity.

## Repository
GitHub: https://github.com/selvathevar31/PBLE_AOA
