#ifndef OBJPOSSLINKEDLIST_H
#define OBJPOSSLINKEDLIST_H

#include "objPosList.h"
#include "objPos.h"

class objPos;

class SNode  // singly list node
{        
    public:
        objPos data;
        SNode* next;
                
        SNode()
        {
            data = objPos(0,0,0,0,0);
            next = nullptr;            
        }        
};

// Public inheritance - using ObjPosList interface
class objPosSLinkedList : public objPosList
{
    // Singly linked list with only head pointer, and WITHOUT DUMMY HEADER
    private:
        SNode* listHead;        
        SNode* persistHead;
        int listSize;     

    public:
        objPosSLinkedList();
        virtual ~objPosSLinkedList();  // polymorphic destructor

        // Once inheriting interface (Pure Abstract Class), must provide concrete implementation
        // for all the interface functions.
        int getSize();
        bool isEmpty() const;

        void insertHead(const objPos &thisPos);
        void insertTail(const objPos &thisPos);
        void insert(const objPos &thisPos, int index);
        
        objPos getHead() const;
        objPos getTail() const;
        objPos get(int index) const;
        objPos getNext();
        void resetReadPos();
        void set(const objPos &thisPos, int index);

        objPos removeHead();
        objPos removeTail();
        objPos remove(int index);

        void printList() const;
};


#endif