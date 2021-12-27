#include <iostream>
#include <vector>
#include<map>
#include <algorithm>

#include <set>
#include <sstream>

using namespace std;

int binary_search(vector<int> &toys, int low, int high, int key = 0){
    if(low > high){
        return -1;
    }

    int mid = (low + high) / 2;

    if(toys[mid] == key && toys[mid-1] == 1) // first defective toy
    {
        return  mid;
    }
    else if(toys[mid] == 1){
        return binary_search(toys, mid+1,high,key);
    }
    else if(toys[mid] == key){
        return binary_search(toys, low,mid - 1,key);
    }

    return -1;
}

int main() {

    int i,result;
    vector<int> toys(100,1); // let serial number of every toy is the index of the vector of toys
//    toys[99] = 0;
//    toys[98] = 0;
    for(i=75;i<100;i++){
        toys[i] = 0;
    }

    result = binary_search(toys,0,toys.size()-1);

    if(result < 0)
        cout<<"NO toy is defective\n";
    else
        cout<<"First defective toy is with serial: "<<result<<"\n";
}
