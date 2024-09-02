#include <iostream>
#include <vector>
#include <chrono> // For measuring execution time

using namespace std;

void print_complexities(const string& algo) {
    if (algo == "Bubble Sort") {
        cout << "\nBubble Sort - Time Complexity: O(n^2), Space Complexity: O(1)" << endl;
    } else if (algo == "Insertion Sort") {
        cout << "\nInsertion Sort - Time Complexity: O(n^2), Space Complexity: O(1)" << endl;
    } else if (algo == "Selection Sort") {
        cout << "\nSelection Sort - Time Complexity: O(n^2), Space Complexity: O(1)" << endl;
    } else if (algo == "Merge Sort") {
        cout << "\nMerge Sort - Time Complexity: O(n log n), Space Complexity: O(n)" << endl;
    } else if (algo == "Quick Sort") {
        cout << "\nQuick Sort - Time Complexity: O(n^2), Space Complexity: O(log n)" << endl;
    }
}

vector<int> bubble_sort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}

vector<int> insertion_sort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}

vector<int> selection_sort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    return arr;
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(arr, left, mid);
    merge_sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

vector<int> quick_sort(vector<int> arr) {
    if (arr.size() <= 1) {
        return arr;
    }
    int pivot = arr[arr.size() / 2];
    vector<int> left, right, middle;
    for (int x : arr) {
        if (x < pivot)
            left.push_back(x);
        else if (x == pivot)
            middle.push_back(x);
        else
            right.push_back(x);
    }
    left = quick_sort(left);
    right = quick_sort(right);
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

int main() {
    vector<int> arr;
    int num;
    cout << "Enter numbers separated by spaces (end input with a non-numeric character): ";
    while (cin >> num) {
        arr.push_back(num);
    }
    
    cin.clear(); // Clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input

    cout << "\nChoose a sorting algorithm:" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;

    int choice;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    vector<int> sorted_arr;
    auto start_time = chrono::high_resolution_clock::now();

    switch (choice) {
        case 1:
            sorted_arr = bubble_sort(arr);
            print_complexities("Bubble Sort");
            break;
        case 2:
            sorted_arr = insertion_sort(arr);
            print_complexities("Insertion Sort");
            break;
        case 3:
            sorted_arr = selection_sort(arr);
            print_complexities("Selection Sort");
            break;
        case 4:
            sorted_arr = arr;
            merge_sort(sorted_arr, 0, sorted_arr.size() - 1);
            print_complexities("Merge Sort");
            break;
        case 5:
            sorted_arr = quick_sort(arr);
            print_complexities("Quick Sort");
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;

    cout << "Sorted Array: ";
    for (int x : sorted_arr) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Execution Time: " << elapsed.count() << " seconds" << endl;

    return 0;
}
