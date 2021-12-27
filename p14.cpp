#include <iostream>
#include <vector>

using namespace std;



int main() {

    int size;
    cin>>size;
    int index, target, num;
    int min=size+1;
    int A[size];
    bool found = false;
    vector<vector<int>> a(1000);

    for(index = 0;index < size;index++){
        cin>>A[index];
    }

    cin>>target;

    for(index = 0;index < size;index++){
        a[A[index]].push_back(A[index]);
    }

    for(index = 0;index < size;index++){

        if(a[target-A[index]] == a[A[index]]){
            if(a[A[index]].size() > 1){
                if(!found){
                    found = true;
                    cout<<"Pair found ("<<A[index]<<","<<target-A[index]<<") ";
                }
                else{
                    cout<<"Or "<<"Pair found ("<<A[index]<<","<<target-A[index]<<") ";
                }
            }
            a[A[index]].clear();
        }

        else if(a[target-A[index]].size() > 0){
            if(!found){
                found = true;
                cout<<"Pair found ("<<A[index]<<","<<target-A[index]<<") ";
            }
            else{
                cout<<"Or "<<"Pair found ("<<A[index]<<","<<target-A[index]<<") ";
            }

            a[target-A[index]].clear();
            a[A[index]].clear();
        }
    }

    if(!found){
        cout<<"Pair not found";
    }

}