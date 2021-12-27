#include <iostream>
#include <vector>

using namespace std;



int main() {

    int size;
    cin>>size;
    int index;
    int i=0;
    int occurrences;
    int A[size];
    vector<vector<int>> a(1000);
    for(index = 0;index < size;index++){
        cin>>A[index];
    }

    for(index = 0;index < size;index++){
        a[A[index]].push_back(A[index]);
    }

    for(index = 0;index < size;index++){
        if(!a[A[index]].empty()){
            occurrences = a[A[index]].size();
            i = 0;
            while(i < occurrences){
                cout<<a[A[index]][i]<<" ";
                i++;
            }
            a[A[index]].clear();
        }
    }
}