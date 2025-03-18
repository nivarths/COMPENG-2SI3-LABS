#include "objPosDLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Doubly Linked List WITH DUMMY HEADER here.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosDLinkedList::objPosDLinkedList()
{
    listHead = new DNode();
    listTail = new DNode();

    listHead->next = listTail;
    listTail->prev = listHead;

    persistHead = listHead->next;
    listSize = 0;
}

objPosDLinkedList::~objPosDLinkedList()
{
    DNode* current = listHead;
    while(current)
    {
        DNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

int objPosDLinkedList::getSize()
{
    return listSize;
}

bool objPosDLinkedList::isEmpty() const
{
   return listSize == 0;
}

void objPosDLinkedList::insertHead(const objPos &thisPos)
{
    if (thisPos.getX() == 0 && thisPos.getY() == 0) {
        cout << "[WARNING] insertHead() - Attempted to insert (0,0)! Ensure this is intentional." << endl;
    }

    if (listHead->next == listTail) {  
        persistHead = listHead->next; 
    }

    DNode* newNode = new DNode();
    newNode->data = thisPos;

    newNode->next = listHead->next;
    newNode->prev = listHead;
    listHead->next->prev = newNode;
    listHead->next = newNode;

    listSize++;

}

void objPosDLinkedList::insertTail(const objPos &thisPos)
{
    if (thisPos.getX() == 0 && thisPos.getY() == 0) {
        cout << "[WARNING] insertTail() - Inserting (0,0)! Is this intentional?" << endl;
    }
    
    DNode* newNode = new DNode();
    newNode->data = thisPos;

    newNode->next = listTail;
    newNode->prev = listHead->prev;

    listTail->prev->next = newNode;
    listTail->prev = newNode;

    if (persistHead == listHead) {  
        persistHead = listHead->next;  
    }

    listSize++; 
}

void objPosDLinkedList::insert(const objPos &thisPos, int index)
{
    if(index <= 0)
    {
        insertHead(thisPos);
        return;
    }

    if(index >= listSize)
    {
        insertTail(thisPos);
        return;
    }

    DNode* current = listHead->next;
    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }

    DNode* newNode = new DNode();
    newNode->data = thisPos;

    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    listSize++;
}

objPos objPosDLinkedList::getHead() const
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    if (listHead->next == listTail || listHead->next == nullptr)
    {
        cout << "[ERROR] getHead() - listHead->next is invalid! Corrupt list?" << endl;
        return objPos(); 
    }

    return listHead->next->data;
}

objPos objPosDLinkedList::getTail() const
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    return listTail->prev->data;
}

objPos objPosDLinkedList::get(int index) const
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    if(index <= 0)
    {
        return getHead();
    }

    if(index >= listSize - 1)
    {
        return getTail();
    }

    DNode* current = listHead->next;
    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

objPos objPosDLinkedList::getNext()
{

    if (isEmpty()) {
        cout << "[ERROR] getNext() - List is empty! Returning default objPos." << endl;
        return objPos();
    }

    if (persistHead == nullptr ){ 
        cout << "[ERROR] getNext() - persistHead is NULL or listHead, resetting read position." << endl;
        resetReadPos();
        if(persistHead == nullptr) return objPos();
    }

    objPos data = persistHead->data;  

    if (persistHead->next != listTail) {  
        persistHead = persistHead->next;  
    } else {
        persistHead = nullptr;
    }

    return data;

}

void objPosDLinkedList::resetReadPos()
{

    if (listSize == 0) { 
        cout << "[ERROR] resetReadPos() - List is empty!" << endl;
        persistHead = nullptr;
        return;
    }

    persistHead = listHead->next;

    if (persistHead == listTail) { 
        persistHead = nullptr;
    } 

}

void objPosDLinkedList::set(const objPos &thisPos, int index)
{
    if(isEmpty())
    {
        return;
    }

    if(index < 0)
    {
        index = 0;
    }

    if(index >= listSize)
    {
        index = listSize - 1;
    }

    DNode* current = listHead->next;
    for(int i = 0; i < index; i++)
    {
        current = current->next;
    }

    current->data = thisPos;
}


objPos objPosDLinkedList::removeHead()
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    DNode* toDelete = listHead->next;
    objPos data = toDelete->data;

    listHead->next = toDelete->next;
    toDelete->next->prev = listHead;

    delete toDelete;
    listSize--;

    return data;
}

objPos objPosDLinkedList::removeTail()
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    DNode* toDelete = listTail->prev;
    
    if (toDelete == listHead || toDelete == nullptr)
    {
        cout << "[ERROR] removeTail() - toDelete is listHead! Corrupt list?" << endl;
        return objPos();
    }

    objPos data = toDelete->data;

    cout << "[DEBUG] removeTail() - Deleting node at: (" << data.getX() << ", " << data.getY() << ")" << endl;


    listTail->prev = toDelete->prev;
    if(toDelete->prev)
    {
        toDelete->prev->next = listTail;
    }
    else
    {
        listHead->next = listTail;
    }
    
    

    delete toDelete;
    listSize--;

    cout << "[DEBUG] removeTail() - Completed. New listSize: " << listSize << endl;
    return data;
}

objPos objPosDLinkedList::remove(int index)
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    if(index <= 0)
    {
        return removeHead();
    }

    if(index >= listSize - 1)
    {
        return removeTail();
    }

    DNode* current = listHead->next;
    for(int i = 0; i < index; i++)
    {
        if(current->next == nullptr)
        {
            cout << "Error: Out of bounds access." << endl;
            return objPos();
        }
        
        current = current->next;
    }

    objPos data = current->data;

    if(current->prev)
    {
        current->prev->next = current->next;
    }
    
    if(current->next)
    {
        current->next->prev = current->prev;
    }
    

    delete current;
    listSize--;

    return data;
}


void objPosDLinkedList::printList() const
{
    cout << "Head: " << listHead << endl;

    DNode* current = listHead;
    while(current)
    {
        cout << "Address: " << current << endl;
        
        cout << "Data: ";
        current->data.printObjPos();
        cout << endl;

        cout << "Next: " << current->next << endl;
        cout << "Prev: " << current->prev << endl;
        current = current->next;
    }

    cout << "Tail: " << listTail << endl;
}


