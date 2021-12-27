#include <iostream>
#include <vector>
#include<map>
#include <algorithm>
#include <math.h>
#include <set>
#include <sstream>

using namespace std;

class matrix{
    public:
        double row;
        double col;
        string name;
        void print(){
            cout<<row<<" "<<col<<" "<<name<<"\n";
        }
};

int main() {

    int n,i;
    double row,col;
    string name;
    cin>>n;

    stringstream ss[n];
    string s;
    vector<matrix> matrices(n);
    for(i=0;i<n;i++){
        cin>>row>>col;
        matrices[i].row = row;
        matrices[i].col = col;
        ss[i]<<(i+1);
        ss[i]>>s;
        matrices[i].name = "A" + s;
    }

    name ="";
    auto p = matrices.begin();

    while((p+2) != matrices.end()){
        if( (p->row * (p+1)->col / p->col) <= ((p+1)->row * (p+2)->col / (p+1)->col) ){
                p->name = "(" + p->name + " x " + (p+1)->name + ")";
                p->col = (p+1)->col;
                matrices.erase((p+1));
                //cout<<p->name<<"\n";
        }
        else{
                (p+1)->name = "(" + (p+1)->name + " x " + (p+2)->name + ")";
                (p+1)->col = (p+2)->col;
                matrices.erase((p+2));
                //cout<<(p+1)->name<<"\n";
        }
    }

    cout<<"("<<p->name<<" x "<<(p+1)->name<<")";

}
