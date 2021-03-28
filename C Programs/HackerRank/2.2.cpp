#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        void pop() {
            //If the both the stacks are empty.
            if(stack_oldest_on_top.empty() && stack_newest_on_top.empty())
                return;

            //We populate the elements from the first stack to this stack.
            // stack_newest_on_top-->stack_oldest_on_top
            else if (stack_oldest_on_top.empty()){

                //Keep on extracting items from stack_newest_on_top until it becomes empty.
                while (!stack_newest_on_top.empty()){
                    int item=stack_newest_on_top.top();
                    stack_oldest_on_top.push(item);
                    stack_newest_on_top.pop();
                }
            }
            //Pop element from stack oldest on top which is FIFO queue.
            stack_oldest_on_top.pop();
        }

        int front() {
            //If the both the stacks are empty.
            if(stack_oldest_on_top.empty() && stack_newest_on_top.empty())
                return 0;

            //We populate the elements from the first stack to this stack.
            // stack_newest_on_top-->stack_oldest_on_top
            else if (stack_oldest_on_top.empty()){

                //Keep on extracting items from stack_newest_on_top until it becomes empty.
                while (!stack_newest_on_top.empty()){
                    int item=stack_newest_on_top.top();
                    stack_oldest_on_top.push(item);
                    stack_newest_on_top.pop();
                }
            }
            //Pop element from stack oldest on top which is FIFO queue.
            return stack_oldest_on_top.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}