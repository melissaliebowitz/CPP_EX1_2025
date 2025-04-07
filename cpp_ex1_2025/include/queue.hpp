//melissaliebowitz@yahoo.com

#ifndef QUEUE_H
#define QUEUE_H

namespace graph{


    class Queue{
        private:
        int *arr;
        int front, rear, size, capacity;

        public:
        Queue(int c);
        ~Queue();

        int get_size(){return size;}
        int get_front(){return front;}
        int get_rear(){return rear;}
        int get_capacity(){return capacity;}
        
        bool isEmpty();
        bool isFull();
        void enqueue(int v);
        int dequeue();
        int peek();

    };
}

#endif 