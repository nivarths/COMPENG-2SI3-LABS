#include "objPosSHLinkedList.h"
#include <iostream>
using namespace std;

// This is the objPos Singly Linked List with DUMMY HEADER.
// Similar, but not identical as the two linked lists you developed in Lab 2.  

objPosSHLinkedList::objPosSHLinkedList()
{
    listHead = new SNode();
    persistHead = listHead;

    listSize = 0;
}

objPosSHLinkedList::~objPosSHLinkedList()
{
    SNode* currentElement = listHead;
    SNode* targetElement = listHead;

    while(currentElement != nullptr)
    {
        currentElement = currentElement->next;
        delete targetElement;
        targetElement = currentElement;
    }
}

int objPosSHLinkedList::getSize()
{
    return listSize;
}

bool objPosSHLinkedList::isEmpty()
{
    return (listSize == 0);
}

void objPosSHLinkedList::insertHead(const objPos &thisPos)
{    
    SNode* newNode = new SNode();
    newNode->data = thisPos;
    newNode->next = listHead->next;
    listHead->next = newNode;    

    listSize++;
}

void objPosSHLinkedList::insertTail(const objPos &thisPos)
{    
    SNode* readerHead = listHead;
    SNode* newNode = new SNode();
    newNode->data = thisPos;

    while(readerHead->next != nullptr)
        readerHead = readerHead->next;

    readerHead->next = newNode;

    listSize++;
}

void objPosSHLinkedList::insert(const objPos &thisPos, int index)
{
    if(index <= 0) 
    {
        insertHead(thisPos);
        return;
    }
    if(index >= listSize - 1)
    {
        insertTail(thisPos);
        return;
    }

    SNode* readerHead = listHead->next;
    SNode* newNode = new SNode();
    newNode->data = thisPos;

    for(int i = 0; i < index - 1; i++)
        readerHead = readerHead->next;
    
    newNode->next = readerHead->next;
    readerHead->next = newNode;

    listSize++;
}

objPos objPosSHLinkedList::getHead() const
{
    if(listSize == 0) return objPos(-99, 0, 0, 0, 0);

    return listHead->next->data;
}

objPos objPosSHLinkedList::getTail() const
{
    if(listSize == 0) return objPos(-99, 0, 0, 0, 0);
    
    SNode* readerHead = listHead->next;
        
    while(readerHead->next != nullptr)
        readerHead = readerHead->next;

    return readerHead->data;
}

objPos objPosSHLinkedList::get(int index) const
{
    if(listSize == 0) return objPos(-99, 0, 0, 0, 0);
    if(index < 0) return getHead();
    if(index > listSize - 1) return getTail();
    
    SNode* readerHead = listHead->next;

    for(int i = 0; i < index; i++)
        readerHead = readerHead->next;
    
    return readerHead->data;
}

objPos objPosSHLinkedList::getNext()
{
    if(listSize == 0) return objPos(-99, 0, 0, 0, 0);

    if(persistHead == nullptr)
    {
        persistHead = listHead->next;
        cout << "reader head reaching the END!" << endl;        
        return objPos(-99,0,0,0,0); // indicating end of list
    }

    objPos temp = persistHead->data;
    persistHead = persistHead->next;
    return temp;
}

void objPosSHLinkedList::resetReadPos()
{
    persistHead = listHead->next;
}

void objPosSHLinkedList::set(const objPos &thisPos, int index)
{
    if(index < 0) index = 0;
    if(index > listSize - 1) index = listSize - 1;
    
    SNode* readerHead = listHead->next; 
    // traverse to the target replacement spot
    for(int i = 0; i < index; i++)
        readerHead = readerHead->next;

    readerHead->data = thisPos;
}


objPos objPosSHLinkedList::removeHead()
{
    if(listSize == 0) return objPos(-99,0,0,0,0);  // do not delete if no elements to delete

    SNode* targetNode = listHead->next;
    objPos temp = targetNode->data;

    listHead->next = targetNode->next;
    delete targetNode;

    listSize--;
    resetReadPos();

    return temp;
}

objPos objPosSHLinkedList::removeTail()
{
    if(listSize == 0) return objPos(-99,0,0,0,0);  // do not delete if no elements to delete

    SNode* readerHead = listHead->next;
    SNode* targetNode;
    objPos temp;
        
    while(readerHead->next->next != nullptr)
        readerHead = readerHead->next;

    targetNode = readerHead->next;
    temp = targetNode->data;
    readerHead->next = readerHead->next->next;
    delete targetNode; 

    listSize--;
    resetReadPos();
    return temp;
}

objPos objPosSHLinkedList::remove(int index)
{
    if(listSize == 0) return objPos(-99,0,0,0,0);  // do not delete if no elements to delete
    if(index <= 0) return removeHead();
    if(index >= listSize - 1) return removeTail();
    
    SNode* targetNode;
    SNode* readerHead = listHead->next;
    objPos temp;

    for(int i = 0; i < index - 1; i++)
        readerHead = readerHead->next;

    targetNode = readerHead->next;
    temp = targetNode->data;
    readerHead->next = readerHead->next->next;
    delete targetNode;

    listSize--;
    resetReadPos();
    return temp;
}

void objPosSHLinkedList::printList() const
{
    SNode* readerHead = listHead->next;  // skip the header
    
    cout << "List Contains:" << endl;

    cout << "Dummy Node (" << listHead << ") ::" << endl;
    listHead->data.printObjPos();
    cout << "next(" << listHead->next << ")" << endl;
        
    while(readerHead != nullptr)
    {
        cout << readerHead << " :: ";
        readerHead->data.printObjPos();
        cout << "next(" << readerHead->next << ")" << endl;
        readerHead = readerHead->next;
    }

    cout << "END OF LIST" << endl;

    cout << "List Head: " << listHead << endl;
    cout << "List Size: " << listSize << endl;
    cout << "Internal Reader Head Pos: " << persistHead << endl;
}


