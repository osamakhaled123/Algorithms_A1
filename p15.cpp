#include <iostream>
#include <vector>

using namespace std;



int main() {

    int size;
    cin>>size;
    int index;
    int min=size+1;
    int A[size];
    vector<vector<int>> a(1000);

    for(index = 0;index < size;index++){
        cin>>A[index];
    }

    for(index = 0;index < size;index++){
        a[A[index]].push_back(A[index]);
    }

    for(index = 0;index < size;index++){
        if(a[A[index]].size() > 1){
            if(min > a[A[index]].size() - 1){
                min = a[A[index]].size() - 1;
            }
            if(min == 1){
                break;
            }
        }
    }

    if(min == size + 1){
        cout<<"Invalid Input";
    }
    else{
        cout<<"The minimum index of the repeating element is "<<min;
    }

}