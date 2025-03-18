#include "objPosStack.h"
#include "objPosSHLinkedList.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// Available Data Members from objPosStack.h (Must Review)
//
//      objPosList* myList
//      
//  This is the polymorphic list pointer to the underlying List data structure to
//   support all Stack functionalities
//
//  You should use the provided objPosSHLinkedList as your main design param (Singly with Header)


objPosStack::objPosStack()
{
    // Constructor   
    myList = new objPosSHLinkedList();
}


objPosStack::~objPosStack()
{
    // Destructor
    delete myList;

}


void objPosStack::populateRandomElements(int size)
{
    // This function generates the number of randomly generated objPos instances with uninitialized
    //  x-y coordinate on the Stack, then sort them in ascending order using the digit of 10
    //  of the **number** field in objPos instances.

    // Implementation done.  You'd have to implement the following two private helper functions above.
    srand(time(NULL));
    generateObjects(size);
    sortByTenScoreBS();   // bubble sort
}




// private helper function
void objPosStack::generateObjects(int count)
{
    // Generate and pushes individual objPos isntances with randomly generated Prefix, Number, and Symbol.
    // The total number of generated instances is capped by input variable **count**.
    
    // 1. Generate Prefix A-Z and a-z.  Alphabetic characters only.
    // 2. Generate Number [0, 99]
    // 3. Leave Symbol as *
    // Push every randomly generately objPos into the Stack.

    srand(time(NULL));

    for(int i = 0; i < count; i++)
    {
        char prefix;
        int uppercase = rand() % 2;

        if(uppercase == 0)
        {
            prefix = 'a' + rand() % 26;
        }
        else if(uppercase == 1)
        {
            prefix = 'A' + rand() % 26;
        }

        //int number = rand() % 100;
        int number = 1;
        char symbol = '*';

        int x = rand() % 28 + 1;
        int y = rand() % 12 + 1;

        objPos newObj(x, y, number, prefix, symbol);
        push(newObj);
    }

}


// private helper function
void objPosStack::sortByTenScoreBS()
{
    // Use BUBBLE or SELECTION SORT to sort all the objPos instances in the Stack in ascending order using the doigit of 10
    //  of the **number** field of objPos.

    // You can use the relevant insertion, removal, getter, and setter methods from the objPosSHLinkedList interface
    //  to complete the sorting operations.

    if(size() <= 1)
    {
        return;
    }

    int n = size();

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            objPos first = myList->get(j);
            objPos second = myList->get(j + 1);

            int firstTen = (first.getNum() / 10) % 10;
            int secondTen = (second.getNum() / 10) % 10;

            if(firstTen > secondTen)
            {
                objPos temp = first;
                myList->set(second, j);
                myList->set(temp, j + 1);
            }
        }
    }
    

}




void objPosStack::push(const objPos &thisPos) const
{
    // Push thisPos on to the Stack.
    myList->insertHead(thisPos);

}

objPos objPosStack::pop()
{
    // Pop the top element of the Stack.
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    if(myList->isEmpty())
    {
        return objPos(-99, 0, 0, 0, 0);
    }

    return myList->removeHead();
    
}

objPos objPosStack::top()
{
    // Return the top element of the Stack without removing it
    //  If the Stack is empty, return objPos(-99, 0, 0, 0, 0)
    if(myList->isEmpty())
    {
        return objPos(-99, 0, 0, 0, 0);
    }

    return myList->getHead();
    
}

int objPosStack::size()
{
    // Return the size of the Stack 
    //  Think about which objPosSHLinkedList method can realize this operation.
    return myList->getSize();

}

void objPosStack::printMe()
{
    // NOT GRADED
    //  Print the contents of the Stack

    // IMPORTANT: USE THIS METHOD FOR DEBUGGING!!!
    myList->printList();
    
}