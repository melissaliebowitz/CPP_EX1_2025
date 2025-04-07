//melissaliebowitz@yahoo.com

#ifndef STACK_HPP
#define STACK_HPP

namespace graph{
    
    class Stack{
        private:
        int *arr;
        int stackSize;
        int capacity;

        public:
        Stack(int c);
        ~Stack();

        int get_stackSize(){return stackSize;}
        int get_capacity(){return capacity;}
        void push(int v);
        int pop();
        bool isFull();
        bool isEmpty();

    };

}




#endif

