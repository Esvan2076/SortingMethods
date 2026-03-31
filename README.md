# Sorting Algorithms

Fundamental implementations of sorting algorithms in C++. This project focuses on comparing theoretical time complexity against practical performance when manipulating arrays and containers.

## Complexity Analysis

Below is the performance breakdown of the implemented algorithms. **Stability** indicates whether the relative order of duplicate elements is preserved after sorting.

| Algorithm | Worst Case | Average Case | Space (Extra) | Stable |
| :--- | :---: | :---: | :---: | :---: |
| **Bubble Sort** | $O(n^2)$ | $O(n^2)$ | $O(1)$ | **Yes** |
| **Insertion Sort** | $O(n^2)$ | $O(n^2)$ | $O(1)$ | **Yes** |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | **Yes** |
| **Quick Sort** | $O(n^2)$ | $O(n \log n)$ | $O(\log n)$ | **No** |

## Tech Stack & Environment

* **Language:** C++ (Standard C++20)
* **IDE/Compiler:** Visual Studio 2022 / MSVC
* **Dependencies:** `{fmt}` (for high-performance console output formatting)

## Installation & Usage

1.  Clone the repository.
2.  Open the `.sln` file in Visual Studio 2022.
3.  Ensure `{fmt}` is linked (via vcpkg or NuGet).
4.  Build and Run.

## Author

**FEEH**
*Software Engineer | C++ & Algorithmic Foundations*
