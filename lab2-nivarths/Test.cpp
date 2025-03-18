#include "objPos.h"
#include "objPosList.h"
#include "objPosArrayList.h"
#include "objPosDLinkedList.h"
#include "objPosSLinkedList.h"

#include <cstdlib>
#include <ctime>

#define COUNT 10
#define TOTAL_TEST_CASES 100

#include <iostream>
using namespace std;

// ******************* //
// Turn these true once you are ready to test getNext() and resetReadPos()
bool testGetNextReadyD = true;  // For Doubly Linked List
bool testGetNextReadyS = true;  // For Singly Linked List
// ******************* //


objPosList *ListUnderTest;
int passCount;

void clearList();
objPos generateRandomPos();
bool assert_equal(int, int);
bool assert_equal(char, char);

///////////////////////////////////////
///////////////////////////////////////
/// DOUBLY LINKED LIST WITH HEADER ////
///////////////////////////////////////
///////////////////////////////////////

// This is the polymorphic list changer
void createNewDList()
{
	if(ListUnderTest != NULL) clearList();	
	ListUnderTest = new objPosDLinkedList();
}

void testConstructorGetSizeD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testConstructorGetSizeD" << endl;
	createNewDList();
	int expected = 0;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testConstructorIsEmptyTrueD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testConstructorIsEmptyTrueD" << endl;
	createNewDList();	
	bool expected = true;
	bool actual = ListUnderTest->isEmpty();		

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}


// INSERT HEAD
// INSERT HEAD
// INSERT HEAD

void testInsertHeadIsEmptyFalseD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadIsEmptyFalseD" << endl;
	createNewDList();
	objPos testPos{};
	ListUnderTest->insertHead(testPos);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetSizeD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetSizeD" << endl;
	createNewDList();
	objPos testPos{};
	ListUnderTest->insertHead(testPos);
	ListUnderTest->insertHead(testPos);
	ListUnderTest->insertHead(testPos);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetHeadD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetHeadD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetTailD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetTailD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetNegTenD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetNegTenD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetZeroD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetZeroD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetOneD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetOneD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-2];
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetCountN3D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetCountN3D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[2];
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetCountN1D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetCountN1D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetCountP5D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertHeadGetCountP5D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}




// INSERT TAIL
// INSERT TAIL
// INSERT TAIL

void testInsertTailIsEmptyFalseD() {

	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailIsEmptyFalseD" << endl;
	createNewDList();
	objPos testPos{};
	ListUnderTest->insertTail(testPos);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertTailGetSizeD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetSizeD" << endl;
	createNewDList();
	objPos testPos{};
	ListUnderTest->insertTail(testPos);
	ListUnderTest->insertTail(testPos);
	ListUnderTest->insertTail(testPos);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertTailGetHeadD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetHeadD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetTailD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetTailD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetNegTenD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetNegTenD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetZeroD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetZeroD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetOneD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetOneD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetCountN3D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetCountN3D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetCountN1D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetCountN1D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetCountP5D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertTailGetCountP5D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}




// INSERT
// INSERT
// INSERT

void testInsertIsEmptyFalseD() {

	bool result = true;

	cout << "TEST(DLinkedList): testInsertIsEmptyFalseD" << endl;
	createNewDList();
	objPos testPos{};
	ListUnderTest->insert(testPos, 0);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertGetSizeD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetSizeD" << endl;
	createNewDList();
	objPos testPos{};
	ListUnderTest->insert(testPos, 0);
	ListUnderTest->insert(testPos, -1);
	ListUnderTest->insert(testPos, 10);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertGetHeadD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetHeadD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetTailD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetTailD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetNegTenD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetNegTenD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetZeroD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetZeroD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetOneD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetOneD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetCountN3D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetCountN3D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetCountN1D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetCountN1D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetCountP5D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testInsertGetCountP5D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}



// REMOVE HEAD
// REMOVE TAIL
// REMOVE 

void testRemoveHeadD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveHeadD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}	
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->removeHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveTailD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveTailD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->removeTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveNegTenD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveNegTenD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->remove(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveZeroD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveZeroD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->remove(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveOneD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveOneD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}	
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->remove(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveCountN3D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveCountN3D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->remove(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveCountN1D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveCountN1D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->remove(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveCountP5D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testRemoveCountP5D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->remove(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}



// SET
// SET
// SET

void testSetNegTenD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testSetNegTenD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}

	objPos expected = generateRandomPos();	
	ListUnderTest->set(expected, -10);
	objPos actual = ListUnderTest->get(-10);	
	
	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetZeroD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testSetZeroD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, 0);
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetOneD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testSetOneD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, 1);
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetCountN3D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testSetCountN3D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT-3);
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetCountN1D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testSetCountN1D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT-1);
	objPos actual = ListUnderTest->get(COUNT-1);

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetCountP5D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testSetCountP5D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT+5);
	objPos actual = ListUnderTest->get(COUNT+5);

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}


// GET NEXT and RESET
// GET NEXT and RESET
// GET NEXT and RESET

void testGetNextResetWholeListD() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testGetNextResetWholeListD" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}

void testGetNextResetPos2D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testGetNextResetPos2D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 2; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}

void testGetNextResetPos5D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testGetNextResetPos5D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 5; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}

void testGetNextResetPos8D() {
	
	bool result = true;

	cout << "TEST(DLinkedList): testGetNextResetPos8D" << endl;
	createNewDList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 8; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}


///////////////////////////////////////
///////////////////////////////////////
// SINGLY LINKED LIST WITHOUT HEADER //
///////////////////////////////////////
///////////////////////////////////////

// This is the polymorphic list changer
void createNewSList()
{
	if(ListUnderTest != NULL) clearList();		
	ListUnderTest = new objPosSLinkedList();
}


void testConstructorGetSizeS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testConstructorGetSizeS" << endl;
	createNewSList();
	int expected = 0;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testConstructorIsEmptyTrueS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testConstructorIsEmptyTrueS" << endl;
	createNewSList();	
	bool expected = true;
	bool actual = ListUnderTest->isEmpty();		

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

// INSERT HEAD
// INSERT HEAD
// INSERT HEAD

void testInsertHeadIsEmptyFalseS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadIsEmptyFalseS" << endl;
	createNewSList();
	objPos testPos{};
	ListUnderTest->insertHead(testPos);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetSizeS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetSizeS" << endl;
	createNewSList();
	objPos testPos{};
	ListUnderTest->insertHead(testPos);
	ListUnderTest->insertHead(testPos);
	ListUnderTest->insertHead(testPos);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetHeadS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetHeadS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetTailS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetTailS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetNegTenS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetNegTenS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetZeroS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetZeroS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetOneS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetOneS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-2];
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetCountN3S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetCountN3S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[2];
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetCountN1S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetCountN1S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertHeadGetCountP5S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertHeadGetCountP5S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertHead(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}


// INSERT TAIL
// INSERT TAIL
// INSERT TAIL

void testInsertTailIsEmptyFalseS() {

	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailIsEmptyFalseS" << endl;
	createNewSList();
	objPos testPos{};
	ListUnderTest->insertTail(testPos);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertTailGetSizeS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetSizeS" << endl;
	createNewSList();
	objPos testPos{};
	ListUnderTest->insertTail(testPos);
	ListUnderTest->insertTail(testPos);
	ListUnderTest->insertTail(testPos);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertTailGetHeadS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetHeadS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetTailS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetTailS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetNegTenS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetNegTenS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetZeroS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetZeroS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetOneS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetOneS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetCountN3S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetCountN3S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetCountN1S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetCountN1S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertTailGetCountP5S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertTailGetCountP5S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insertTail(itemArray[i]);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

// INSERT
// INSERT
// INSERT

void testInsertIsEmptyFalseS() {

	bool result = true;

	cout << "TEST(SLinkedList): testInsertIsEmptyFalseS" << endl;
	createNewSList();
	objPos testPos{};
	ListUnderTest->insert(testPos, 0);

	bool expected = false;
	bool actual = ListUnderTest->isEmpty();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertGetSizeS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetSizeS" << endl;
	createNewSList();
	objPos testPos{};
	ListUnderTest->insert(testPos, 0);
	ListUnderTest->insert(testPos, -1);
	ListUnderTest->insert(testPos, 10);
	int expected = 3;
	int actual = ListUnderTest->getSize();	

	result = result && assert_equal(expected, actual);
	clearList();
	if(result) passCount++;
}

void testInsertGetHeadS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetHeadS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->getHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetTailS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetTailS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->getTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetNegTenS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetNegTenS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetZeroS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetZeroS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetOneS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetOneS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetCountN3S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetCountN3S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetCountN1S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetCountN1S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testInsertGetCountP5S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testInsertGetCountP5S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->get(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}


// REMOVE HEAD
// REMOVE TAIL
// REMOVE 

void testRemoveHeadS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveHeadS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}	
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->removeHead();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveTailS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveTailS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->removeTail();	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveNegTenS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveNegTenS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->remove(-10);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveZeroS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveZeroS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[0];
	objPos actual = ListUnderTest->remove(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveOneS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveOneS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}	
	
	objPos expected = itemArray[1];
	objPos actual = ListUnderTest->remove(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveCountN3S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveCountN3S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-3];
	objPos actual = ListUnderTest->remove(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveCountN1S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveCountN1S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->remove(COUNT-1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}

void testRemoveCountP5S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testRemoveCountP5S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = itemArray[COUNT-1];
	objPos actual = ListUnderTest->remove(COUNT+5);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());

	int actualSize = ListUnderTest->getSize();
	int expectedSize = COUNT - 1;

	result = result && assert_equal(expectedSize, actualSize);

	clearList();
	if(result) passCount++;
}


// SET
// SET
// SET

void testSetNegTenS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testSetNegTenS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}

	objPos expected = generateRandomPos();	
	ListUnderTest->set(expected, -10);
	objPos actual = ListUnderTest->get(-10);	
	
	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetZeroS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testSetZeroS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, 0);
	objPos actual = ListUnderTest->get(0);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetOneS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testSetOneS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, 1);
	objPos actual = ListUnderTest->get(1);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetCountN3S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testSetCountN3S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT-3);
	objPos actual = ListUnderTest->get(COUNT-3);	

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetCountN1S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testSetCountN1S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT-1);
	objPos actual = ListUnderTest->get(COUNT-1);

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

void testSetCountP5S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testSetCountP5S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected = generateRandomPos();
	ListUnderTest->set(expected, COUNT+5);
	objPos actual = ListUnderTest->get(COUNT+5);

	result = result && assert_equal(expected.getX(), actual.getX());
	result = result && assert_equal(expected.getY(), actual.getY());
	result = result && assert_equal(expected.getNum(), actual.getNum());
	result = result && assert_equal(expected.getPF(), actual.getPF());
	result = result && assert_equal(expected.getSym(), actual.getSym());
	clearList();
	if(result) passCount++;
}

// GET NEXT and RESET
// GET NEXT and RESET
// GET NEXT and RESET

void testGetNextResetWholeListS() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testGetNextResetWholeListS" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}

void testGetNextResetPos2S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testGetNextResetPos2S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 2; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}

void testGetNextResetPos5S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testGetNextResetPos5S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 5; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}

void testGetNextResetPos8S() {
	
	bool result = true;

	cout << "TEST(SLinkedList): testGetNextResetPos8S" << endl;
	createNewSList();
	objPos itemArray[COUNT];
	for(int i = 0; i < COUNT; i++)	
	{
		itemArray[i] = generateRandomPos();
		ListUnderTest->insert(itemArray[i], i);
	}
	
	objPos expected, actual;
	ListUnderTest->resetReadPos();
	for(int i = 0; i < 8; i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}

	ListUnderTest->resetReadPos();
	for(int i = 0; i < ListUnderTest->getSize(); i++)
	{
		expected = itemArray[i];
		actual = ListUnderTest->getNext();

		result = result && assert_equal(expected.getX(), actual.getX());
		result = result && assert_equal(expected.getY(), actual.getY());
		result = result && assert_equal(expected.getNum(), actual.getNum());
		result = result && assert_equal(expected.getPF(), actual.getPF());
		result = result && assert_equal(expected.getSym(), actual.getSym());
	}
	
	clearList();
	if(result) passCount++;
}


bool runAllTests(int argc, char const *argv[]) {
		
    testConstructorGetSizeD();	
	testConstructorIsEmptyTrueD();

	testInsertHeadIsEmptyFalseD();
	testInsertHeadGetSizeD();
	testInsertHeadGetHeadD();
	testInsertHeadGetTailD();
	testInsertHeadGetNegTenD();
	testInsertHeadGetZeroD();
	testInsertHeadGetOneD();
	testInsertHeadGetCountN3D();
	testInsertHeadGetCountN1D();
	testInsertHeadGetCountP5D();

	testInsertTailIsEmptyFalseD();
	testInsertTailGetSizeD();
	testInsertTailGetHeadD();
	testInsertTailGetTailD();
	testInsertTailGetNegTenD();
	testInsertTailGetZeroD();
	testInsertTailGetOneD();
	testInsertTailGetCountN3D();
	testInsertTailGetCountN1D();
	testInsertTailGetCountP5D();

	testInsertIsEmptyFalseD();
	testInsertGetSizeD();
	testInsertGetHeadD();
	testInsertGetTailD();
	testInsertGetNegTenD();
	testInsertGetZeroD();
	testInsertGetOneD();
	testInsertGetCountN3D();
	testInsertGetCountN1D();
	testInsertGetCountP5D();

	testRemoveHeadD();
	testRemoveTailD();
	testRemoveNegTenD();
	testRemoveZeroD();
	testRemoveOneD();
	testRemoveCountN3D();
	testRemoveCountN1D();
	testRemoveCountP5D();

	testSetNegTenD();
	testSetZeroD();
	testSetOneD();
	testSetCountN3D();
	testSetCountN1D();
	testSetCountP5D();

	if(testGetNextReadyD)
	{
		testGetNextResetWholeListD();
		testGetNextResetPos2D();
		testGetNextResetPos5D();
		testGetNextResetPos8D();
	}



	testConstructorGetSizeS();
	testConstructorIsEmptyTrueS();

	testInsertHeadIsEmptyFalseS();
	testInsertHeadGetSizeS();
	testInsertHeadGetHeadS();
	testInsertHeadGetTailS();
	testInsertHeadGetNegTenS();
	testInsertHeadGetZeroS();
	testInsertHeadGetOneS();
	testInsertHeadGetCountN3S();
	testInsertHeadGetCountN1S();
	testInsertHeadGetCountP5S();
	
	testInsertTailIsEmptyFalseS();
	testInsertTailGetSizeS();
	testInsertTailGetHeadS();
	testInsertTailGetTailS();
	testInsertTailGetNegTenS();
	testInsertTailGetZeroS();
	testInsertTailGetOneS();
	testInsertTailGetCountN3S();
	testInsertTailGetCountN1S();
	testInsertTailGetCountP5S();
	
	testInsertIsEmptyFalseS();
	testInsertGetSizeS();
	testInsertGetHeadS();
	testInsertGetTailS();
	testInsertGetNegTenS();
	testInsertGetZeroS();
	testInsertGetOneS();
	testInsertGetCountN3S();
	testInsertGetCountN1S();
	testInsertGetCountP5S();

	testRemoveHeadS();
	testRemoveTailS();
	testRemoveNegTenS();
	testRemoveZeroS();
	testRemoveOneS();
	testRemoveCountN3S();
	testRemoveCountN1S();
	testRemoveCountP5S();
	
	testSetNegTenS();
	testSetZeroS();
	testSetOneS();
	testSetCountN3S();
	testSetCountN1S();
	testSetCountP5S();
	
	if(testGetNextReadyS)
	{
		testGetNextResetWholeListS();
		testGetNextResetPos2S();
		testGetNextResetPos5S();
		testGetNextResetPos8S();
	}	
	
	if(passCount != TOTAL_TEST_CASES) 
		return false;
	else 
		return true;
}

int main(int argc, char const *argv[]) {
  	
	srand(time(NULL));	
	passCount = 0;
	bool successCode = runAllTests(argc, argv);
	if(successCode)	cout << endl << "Passed All Tests" << endl;
	else			cout << "Failed Tests, Check Failure" << endl;		
	cout << "Test Case Score: " << passCount << " / " << TOTAL_TEST_CASES << endl;

	return successCode? EXIT_SUCCESS : EXIT_FAILURE;
}

void clearList()
{
	delete ListUnderTest;
	ListUnderTest = NULL;	
}

objPos generateRandomPos()
{
	objPos temp;

	temp.setX(rand() % 100);
	temp.setY(rand() % 100);
	temp.setNum(rand() % 500);
	temp.setPF(rand() % 26 + 'a');
	temp.setSym(rand() % 26 + 'A');

	return temp;
}


bool assert_equal(int a, int b)
{
	bool result = (a == b);
	if(!result)	
	{
		cout << "\t\t[ASSERTION] Expected: " << a << ", but Actual: " << b << endl;		
	}
	return result;
}

bool assert_equal(char a, char b)
{
	bool result = (a == b);
	if(!result)	
	{
		cout << "\t\tExpected: " << a << ", but Actual: " << b << endl;		
	}
	return result;
}