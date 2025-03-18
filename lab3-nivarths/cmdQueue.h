#ifndef CMDQUEUE_H
#define CMDQUEUE_H

// You must implement the array-based circular queue as discussed in class
// You must NOT use any existing data structures such as Lists to design the queue.

// each player object needs one cmd queue
// place it in either GameMechs or Player class, 
// so to allow simultaneous control
#define DEFAULT_CAPACITY 100

class cmdQueue
{
    private:
        char* queue;
        int capacity;
        int size;
        int front;  // enqueue here
        int end;    // dequeue here

    public:
        cmdQueue();
        cmdQueue(int cap);
        ~cmdQueue();

        void enqueue(char thisCmd);
        char dequeue();
        int getSize() const;
        void clearQueue();

        void printMe() const;
};

#endif