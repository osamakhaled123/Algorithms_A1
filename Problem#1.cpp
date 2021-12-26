#include <iostream>

using namespace std;

int insertionSort(int arr[], int n) {
    int key, j;
    int count = 0;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i;
        while (j >= 1 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
            count++;
        }
        arr[j] = key;
    }
    return count;
}

int main() {
    for (int i = 0; i < 2; i++) {
        cout <<"Enter the size of the Array:";
        int n;
        cin >> n;
        int arr[n];
        cout <<"Enter the Array elements (1 2 3 4 5):";
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        cout <<insertionSort(arr, n) << endl;
    }

    return 0;
}
