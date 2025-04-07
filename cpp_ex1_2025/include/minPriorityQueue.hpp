//melissaliebowitz@yahoo.com

#ifndef MIN_PRIORITY_QUEUE_HPP
#define MIN_PRIORITY_QUEUE_HPP
namespace graph{

    class MinPriorityQueue {
    private:
        int* keys;
        bool* inQueue;
        int numVertices;

    public:
        MinPriorityQueue(int n);
        ~MinPriorityQueue();

        bool isEmpty();
        void decreaseKey(int vertex, int newKey);
        int extractMin();
        int getKey(int vertex);
        bool contains(int vertex);
   
    };
}

#endif
