#include "objPosSLinkedList.h"
#include <iostream>
using namespace std;

// Develop the objPos Singly Linked List WITHOUT DUMMY HEADER.  
// Use the Test cases Test.cpp to complete the Test-Driven Development

objPosSLinkedList::objPosSLinkedList()
{
    listHead = nullptr;
    persistHead = nullptr;
    listSize = 0;
}

objPosSLinkedList::~objPosSLinkedList()
{
    SNode* current = listHead;
    while(current)
    {
        SNode* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

int objPosSLinkedList::getSize()
{
    return listSize;
}

bool objPosSLinkedList::isEmpty() const
{
   return listSize == 0;
}

void objPosSLinkedList::insertHead(const objPos &thisPos)
{
    SNode* newNode = new SNode();
    newNode->data = thisPos;
    newNode->next = listHead;
    listHead = newNode;

    if(listSize == 0)
    {
        persistHead = listHead;
    }

    cout << "Inserting at head: (" << thisPos.getX() << ", " << thisPos.getY() << ")" << endl;

    listSize++;
}

void objPosSLinkedList::insertTail(const objPos &thisPos)
{
    SNode* newNode = new SNode();
    newNode->data = thisPos;
    newNode->next = nullptr;

    if(listSize == 0)
    {
        listHead = newNode;
        persistHead = listHead;
    }
    else
    {
        SNode* temp = listHead;
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    listSize++;
}

void objPosSLinkedList::insert(const objPos &thisPos, int index)
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

    SNode* newNode = new SNode();
    newNode->data = thisPos;

    SNode* temp = listHead;
    for(int i = 0; i < index - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    listSize++;
}

objPos objPosSLinkedList::getHead() const
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    return listHead->data;
    // return listHead->next->data;
}

objPos objPosSLinkedList::getTail() const
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    SNode* temp = listHead;
    while(temp->next)
    {
        temp = temp->next;
    }

    return temp->data;
}

objPos objPosSLinkedList::get(int index) const
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

    SNode* temp = listHead;
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

objPos objPosSLinkedList::getNext()
{
    if(persistHead == nullptr)
    {
        cout << "[ERROR] getNext() - persistHead is NULL! List is empty or broken." << endl;
        return objPos();
    }

    objPos data = persistHead->data;

    if(persistHead->next)
    {
        persistHead = persistHead->next;
    }
    else
    {
        cerr << "[ERROR] getNext() - Reached end of list, resetting read position." << endl;
        persistHead = nullptr; 
    }

    return data;
}

void objPosSLinkedList::resetReadPos()
{
    persistHead = listHead;
}

void objPosSLinkedList::set(const objPos &thisPos, int index)
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

    SNode* temp = listHead;
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    temp->data = thisPos;
}


objPos objPosSLinkedList::removeHead()
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    SNode* toDelete = listHead;
    objPos data = toDelete->data;

    listHead = listHead->next;
    delete toDelete;
    listSize--;

    if(listSize == 0)
    {
        persistHead = nullptr;
    }

    return data;
}

objPos objPosSLinkedList::removeTail()
{
    if(isEmpty())
    {
        cout << "Invalid operation: List is empty." << endl;
        return objPos();
    }

    if(listSize == 1)
    {
        return removeHead();
    }

    SNode* temp = listHead;
    while(temp->next->next)
    {
        temp = temp->next;
    }

    objPos data = temp->next->data;
    cout << "[DEBUG] removeTail() - Deleting node at: (" << data.getX() << ", " << data.getY() << ")" << endl;
    
    delete temp->next;
    temp->next = nullptr;
    listSize--;
    cout << "[DEBUG] removeTail() - Completed. New listSize: " << listSize << endl;
    return data;
}

objPos objPosSLinkedList::remove(int index)
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

    SNode* temp = listHead;
    for(int i = 0; i < index - 1; i++)
    {   
        temp = temp->next;
    }

    SNode* toDelete = temp->next;
    if(toDelete == nullptr)
    {
        cout << "Error: toDelete is NULL" << endl;
        return objPos();
    }

    objPos data = toDelete->data;
    temp->next = toDelete->next;

    if(persistHead == toDelete)
    {
        persistHead = listHead;
    }

    delete toDelete;
    
    listSize--;
    return data;
}

void objPosSLinkedList::printList() const
{
    cout << "Head: " << listHead << endl;

    SNode* temp = listHead;
    int index = 0;

    while(temp)
    {
        cout << "Element " << index << endl;
        cout << "Address: " << temp << endl;

        cout << "Data: ";
        temp->data.printObjPos();
        cout << endl;

        cout << "Next: " << temp->next << endl;
        
        temp = temp->next;
        index++;
    }

    cout << "End of list: " << endl;
}


