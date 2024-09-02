# Sorting Algorithms in C++

This repository contains implementations of various sorting algorithms in C++. The project is designed to help users understand the differences between sorting algorithms, their complexities, and performance.

## Implemented Sorting Algorithms

- **Bubble Sort**: A simple comparison-based sorting algorithm with O(n^2) time complexity.
- **Insertion Sort**: A simple sorting algorithm that builds the final sorted array one item at a time with O(n^2) time complexity.
- **Selection Sort**: A simple comparison-based sorting algorithm that has O(n^2) time complexity.
- **Merge Sort**: A divide-and-conquer algorithm with O(n log n) time complexity.
- **Quick Sort**: An efficient sorting algorithm with an average-case time complexity of O(n log n).

## Features

- **User Input**: Enter a list of numbers to be sorted.
- **Choose Sorting Algorithm**: Select which sorting algorithm to use.
- **Execution Time**: Measure and display the execution time of the chosen sorting algorithm.
- **Time Complexity Information**: Displays the time and space complexities for each sorting algorithm.

## Getting Started

### Prerequisites

To compile and run the code, you'll need:

- A C++ compiler like `g++`.
- Basic knowledge of C++ and how to use a terminal or command prompt.

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/sorting-algorithms-cpp.git
   cd sorting-algorithms-cpp
   ```

2. **Compile the program**:
   ```bash
   g++ -o sorting sorting.cpp
   ```

3. **Run the executable**:
   ```bash
   ./sorting
   ```

## Usage

1. After running the program, you'll be prompted to enter numbers separated by spaces. Input the list of numbers you want to sort.
2. Next, choose the sorting algorithm by entering the corresponding number from the menu.
3. The program will output the sorted array, display the time complexity, and show the execution time.

### Example

```
Enter numbers separated by spaces: 34 7 23 32 5 62
Choose a sorting algorithm:
1. Bubble Sort
2. Insertion Sort
3. Selection Sort
4. Merge Sort
5. Quick Sort
Enter your choice (1-5): 4

Merge Sort - Time Complexity: O(n log n), Space Complexity: O(n)
Sorted Array: 5 7 23 32 34 62
Execution Time: 0.000345 seconds
```

## Contributing

Contributions are welcome! Please follow these steps to contribute:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -am 'Add new feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Open a Pull Request.


### Instructions for Use:

1. **Replace Placeholder Text**: Make sure to replace `"https://github.com/your-username/sorting-algorithms-cpp.git"` with the actual URL of your repository.
2. **Update Contact Information**: Update `[your-email@example.com]` with your actual email address.
3. **Include a License**: If you decide to include a LICENSE file, ensure that you provide the correct licensing information.
