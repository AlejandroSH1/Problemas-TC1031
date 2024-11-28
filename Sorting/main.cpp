#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    string s;
    cin >> s;

    vector<int> numbers;
    for (char c : s) {
        if (isdigit(c)) {
            numbers.push_back(c - '0');
        }
    }

    quickSort(numbers, 0, numbers.size() - 1);

    stringstream result;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) {
            result << "+";
        }
        result << numbers[i];
    }

    cout << result.str() << endl;

    return 0;
}
