#include <iostream>
#include <vector>
#include<map>
#include <algorithm>

#include <set>
#include <sstream>

using namespace std;

class Employee{
    public:
        string ID;
        string name;
        string department;
};

class Transaction{
    public:
        string sold_product;
        pair<string,int> sold_by; // The second part of the pair (sold_by) is to indicate the row in Employees table
                                  // which has the same ID in the first part of the pair (sold_by)
        string sold_to;
};



int main(){

    vector<Employee> Employees(2);
    vector<Transaction> Transactions(3);

    Employees[0].ID = "XDFSE1";
    Employees[0].name = "Jack";
    Employees[0].department = "Electronics";

    Employees[1].ID = "XDVBA2";
    Employees[1].name = "Mary";
    Employees[1].department = "Aesthetics";

    ////////////////////////////////////

    Transactions[0].sold_product = "TV";
    Transactions[0].sold_by.first = "XDFSE1";
    Transactions[0].sold_by.second = 0;
    Transactions[0].sold_to = "Mark";

    Transactions[1].sold_product = "Radio";
    Transactions[1].sold_by.first = "XDFSE1";
    Transactions[1].sold_by.second = 0;
    Transactions[1].sold_to = "Susan";

    Transactions[2].sold_product = "Skincare Ointment";
    Transactions[2].sold_by.first = "XDVBA2";
    Transactions[2].sold_by.second = 1;
    Transactions[2].sold_to = "Lisa";


    cout<<Employees[Transactions[2].sold_by.second].name<<" "
    <<Employees[Transactions[2].sold_by.second].department<<"\n";

    // Hashing here is depending on the row index of Employees table
}
