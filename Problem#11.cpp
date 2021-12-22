#include <iostream>
#include <vector>

using namespace std;



int main() {

    int size;
    cin>>size;
    int index;
    int A[size+1];
    int B[size+1];

    A[0] = 0;
    for(index = 1;index < size + 1;index++){
        cin>>A[index];
    }

    if(size > 1){
        B[0] = 0;
    }

    if(size > 2){
        if(A[0] < 0){
            B[1] = 0;
        } else{
            B[1] = A[0];
        }
    }

    for(index = 2;index<size+1;index++){
        if(A[index] + B[index - 2] >= B[index - 1]){
            B[index] = A[index] + B[index - 2];
        }
        else{
            B[index] = B[index - 1];
        }
    }

    cout<<B[size];

}