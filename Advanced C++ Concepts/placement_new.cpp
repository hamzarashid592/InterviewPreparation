// Points
//  --> The new[] operator to allocate memory to an object is an expensive operation as it changes the mode from user mode to kernel.
//  --> So if we want to allocate memory to a number of pointers, we use the placement new approach.
//  --> We allocate a chunk of memory using the new[] operator only once.
//  --> Then we allocate out pointers using that chunk. Therefore, our calls to the kernel have been reduced to 1.

#include <iostream>
using namespace std;

class BaseClass
{
private:
    int data;

public:
    BaseClass()
    {
        cout << "Constructor" << endl;
    }
    BaseClass(int x)
    {
        data = x;
    }
    ~BaseClass()
    {
        cout << "Destructor" << endl;
    }
    void printData()
    {
        cout << data << endl;
    }
};

int main()
{
    // -------------
    // Old approach.
    // -------------
    cout << "\tOld approach" << endl;
    BaseClass *baseObj = new BaseClass();
    // Some work here.
    delete baseObj;

    // -------------
    // New approach.
    // -------------
    cout << "\tNew approach" << endl;

    // Allocating the chunk.
    char *memoryPool = new char[10 * sizeof(BaseClass)]; // If we want to allocate 10 pointers.

    // Allocating memory to pointers using that chunk.
    BaseClass *baseObj1 = new (&memoryPool[0]) BaseClass();
    BaseClass *baseObj2 = new (&memoryPool[4]) BaseClass();
    BaseClass *baseObj3 = new (&memoryPool[8]) BaseClass();
    BaseClass *baseObj4 = new (&memoryPool[12]) BaseClass();
    BaseClass *baseObj5 = new (&memoryPool[16]) BaseClass();
    BaseClass *baseObj6 = new (&memoryPool[20]) BaseClass();
    BaseClass *baseObj7 = new (&memoryPool[24]) BaseClass();
    BaseClass *baseObj8 = new (&memoryPool[28]) BaseClass();
    BaseClass *baseObj9 = new (&memoryPool[32]) BaseClass();
    BaseClass *baseObj10 = new (&memoryPool[36]) BaseClass();

    // Working with the created pointers.

    // Calling destructors.
    baseObj1->~BaseClass();
    baseObj2->~BaseClass();
    baseObj3->~BaseClass();
    baseObj4->~BaseClass();
    baseObj5->~BaseClass();
    baseObj6->~BaseClass();
    baseObj7->~BaseClass();
    baseObj8->~BaseClass();
    baseObj9->~BaseClass();
    baseObj10->~BaseClass();

    // Freeing up the memory pool.
    delete memoryPool;

    return 0;
}