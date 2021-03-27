#include <iostream>
#include<list>
using namespace std;


class HashTable{

private:
    int buckets;
    list <int> *hashTable;

public:
    HashTable(int tableSize);
    int hashFunction(int item);
    void insertItem(int item);
    void removeItem(int item);
    void printTable();

};


HashTable::HashTable(int tableSize){
    buckets=tableSize; 
    hashTable = new list<int>[buckets];
}

int HashTable::hashFunction(int item){

    return item%buckets;
}

void HashTable::insertItem(int item){
    int index=hashFunction(item);
    hashTable[index].push_back(item);
}

void HashTable::printTable(){
    for (int i=0;i<buckets;i++){
        cout<<i<<"-->";

        for (auto x : hashTable[i])
            cout<<x<<"\t";
        cout<<endl;

    }
}



int main(){

    HashTable ht(13);





    ht.insertItem(2);
    ht.insertItem(4);
    ht.insertItem(6);
    ht.insertItem(7);
    ht.insertItem(10);
    ht.insertItem(12);
    ht.insertItem(42);
    ht.insertItem(55);
    ht.insertItem(13);
    ht.insertItem(77);

    ht.printTable();
    return 0;

}