#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

long long m_w , m_z;
int get_random() {
    m_z = 36969*(m_z & 65535) + (m_z>>16);
    m_w = 18000*(m_w & 65535) + (m_w>>16);
    long long res = (m_z<<16) + m_w;
    return res % 1000000000;
}

int main() {
    for (int i = 0; i < 2; i++) {
        int n,k;
        cin >> n >> k >> m_w >> m_z;
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = get_random();
        }
        quickSort(arr, 0, n - 1);
        cout << arr[k-1] << endl;
    }
    return 0;
}






