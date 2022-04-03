#include <iostream>
using namespace std;

class MyStack
{
private:
    int data;
    MyStack *next;

    static int maxVal;
    int secondMaxVal;

public:
    MyStack(int data);
    ~MyStack();
    MyStack *push(int value);
    MyStack *pop(int &value);
    int maxValue1(); //Big 0(n)
    int maxValue2(); //Big 0(1)
};

MyStack::MyStack(int data)
{
    this->data = data;
    this->next = NULL;
    this->maxVal = data;
    this->secondMaxVal = data;
}

MyStack::~MyStack()
{
}

MyStack *MyStack::push(int value)
{
    MyStack *tos = this;

    MyStack *newNode = new MyStack(value);
    newNode->next = tos;
    newNode->secondMaxVal = -1;

    //Setting the max value.
    if (value > maxVal)
    {
        cout << value << "\t";

        newNode->secondMaxVal = maxVal;
        maxVal = value;

        cout << newNode->secondMaxVal << "\t" << maxVal << endl;
    }

    return newNode;
}

MyStack *MyStack::pop(int &value)
{
    MyStack *tos = this;
    MyStack *temp = this;

    //Checking whether BOS reached.
    if (tos == NULL)
    {
        value = -1;
        return NULL;
    }

    value = tos->data;

    if (value == maxVal)
        maxVal = tos->maxVal;

    //Freeing the memory
    temp = tos;
    tos = tos->next;
    delete temp;

    return tos;
}

int MyStack::maxValue1()
{
    MyStack *tos = this;

    int maxVal = 0;

    while (tos != NULL)
    {
        if (tos->data > maxVal)
            maxVal = tos->data;

        tos = tos->next;
    }

    return maxVal;
}

int MyStack::maxValue2()
{
    return this->maxVal;
}

int main()
{
    MyStack *stack = new MyStack(5);
    stack = stack->push(12);
    stack = stack->push(1);
    stack = stack->push(13);
    stack = stack->push(20);

    // int temp;
    // stack = stack->pop(temp);
    // cout << temp << endl;

    // stack = stack->pop(temp);
    // cout << temp << endl;

    // stack = stack->pop(temp);
    // cout << temp << endl;

    // stack = stack->pop(temp);
    // cout << temp << endl;

    // stack = stack->pop(temp);
    // cout << temp << endl;

    // stack = stack->pop(temp);
    // cout << temp << endl;

    // stack = stack->pop(temp);
    // cout << temp << endl;

    cout << "Max val by iterative method " << stack->maxValue1() << endl;

    cout << "Max val by advanced method " << stack->maxValue2() << endl;

    return 0;
}