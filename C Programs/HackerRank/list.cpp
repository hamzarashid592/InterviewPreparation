#include <iostream>
#include<list>
using namespace std;

int main(){

    list <int> testList1;
    list <int> ::iterator it;

    testList1.push_back(1);
    testList1.push_back(2);
    testList1.push_back(3);
    testList1.push_back(4);
    testList1.push_front(6);
    testList1.push_front(7);

    for(it=testList1.begin();it!=testList1.end();it++)
        cout<<*it<<endl;


    for (auto x: testList1)
        cout<<"-->"<<x<<"\t";


    return 0;
}