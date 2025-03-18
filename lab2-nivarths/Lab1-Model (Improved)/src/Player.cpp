#include "Player.h"
#include "objPosArrayList.h"
#include "objPosDLinkedList.h"
#include "objPosSLinkedList.h"

#include <iostream>
using namespace std;

#define TEST_LENGTH 10
#define LIST_TYPE 2


Player::Player(int x, int y, char symbol, GameMechs* gm, ItemBin* bin)
{
    #if LIST_TYPE == 1
        myPos = new objPosArrayList();
        if (myPos == nullptr) {
            cout << "Error: myPos is NULL! Make sure LIST_TYPE is correctly defined." << endl;
        }        
    #elif LIST_TYPE == 2
        myPos = new objPosDLinkedList();
    #elif LIST_TYPE == 3
        myPos = new objPosSLinkedList();
    #else
        #error "Invalid LIST_TYPE value"
    #endif
    
    // turn false for performance estimation in Lab 2
    killable = false;  
    
    // Configure TEST_LENGTH to validate your asymptotic analysis on movePlayer()
    // with killable turned off.
    objPos newPos(x, y, -1, 0, symbol); 
    myPos->insertTail(newPos); // Line 88 - 93 and 97 new code
    cout << "[DEBUG] Inserted initial position: (" << x << ", " << y << ")" << endl;
    
    cout << "[DEBUG] Player initial list size: " << myPos->getSize() << endl;
    gmRef = gm;
    boardRef = gmRef->getBoardRef();
    binRef = bin;

    myDir = STOP;
    myScore = 0;

    gmRef->addPlayer(this);

    /*cout << "[DEBUG] Measuring insertHead() performance..." << endl;
    for (int i = 0; i < TEST_LENGTH; i++) {
        objPos newPos(x, y, -1, 0, symbol);
        
        gmRef->startMeasurement();
        myPos->insertHead(newPos);
        gmRef->endMeasurementAndRecord();
    }

    cout << "[DEBUG] Player initial list size: " << myPos->getSize() << endl;*/
}

Player::~Player()
{
    delete myPos;
}


void Player::updatePlayerFSM()  // private
{
    char cmd = gmRef->getCMD();   
    switch(cmd)   
    {
        case 'w':
        case 'W':
            if(myDir != DOWN) myDir = UP;   
            break;

        case 's':
        case 'S':
            if(myDir != UP) myDir = DOWN;    
            break;

        case 'a':
        case 'A':
            if(myDir != RIGHT) myDir = LEFT;    
            break;

        case 'd':
        case 'D':
            if(myDir != LEFT) myDir = RIGHT;    
            break;

        default:
            break;   
    }
}   

void Player::movePlayer()
{    
    updatePlayerFSM();   
    if(myDir == STOP) return;    
    
    cout << "[DEBUG] undrawPlayer() start" << endl;
    undrawPlayer(); 

    if (myPos->isEmpty()) {
        cout << "[ERROR] movePlayer() - No positions available. Aborting move." << endl;
        return;
    }
        
    objPos currHeadPos = myPos->getHead(); 
    
    if (currHeadPos.getX() == -99) {
        cout << "[ERROR] movePlayer() - Invalid head position detected! List is corrupt?" << endl;
        return;
    }

    int inX = currHeadPos.getX();  
    int inY = currHeadPos.getY();     
        
    switch(myDir) 
    {
        case UP:            
            if(--inY < 1)  
                inY = gmRef->getBoardSizeY() - 2; 
            break;

        case DOWN:
            if(++inY > (gmRef->getBoardSizeY() - 2))
                inY = 1;
            break;

        case LEFT:
            if(--inX < 1)  
                inX = gmRef->getBoardSizeX() - 2;
            break;

        case RIGHT:
            if(++inX > (gmRef->getBoardSizeX() - 2)) 
                inX = 1; 
            break;

        default:
            break; 
    } 

    if (inX != currHeadPos.getX() || inY != currHeadPos.getY()) 
    { 
        objPos newHead(inX, inY, -1, 0, currHeadPos.getSym()); // ✅ Create new head with correct position
        myPos->insertHead(newHead);  // ✅ Insert new head 

    
        cout << "[DEBUG] Moving to: (" << inX << ", " << inY << ")" << endl;
        // gmRef->startMeasurement();
        // gmRef->endMeasurementAndRecord();    

        cout << "[DEBUG] Head inserted. List size: " << myPos->getSize() << endl;

        if(!checkCollision())            // check collision.  If collision never happened,  
        {
            cout << "[DEBUG] No collision detected. Calling removeTail()" << endl;
            gmRef->startMeasurement();
            myPos->removeTail();         // removeTail.  Otherwise, generate new item.    
            gmRef->endMeasurementAndRecord();
            cout << "[DEBUG] After removeTail(). List size: " << myPos->getSize() << endl;
        }
        // Think about how you'd measure removeTail() computation time.
    }
    else
    {
        cout << "[ERROR] movePlayer() - No change in position! Something is wrong." << endl;
    }
    
    cout << "[DEBUG] Checking self-collision..." << endl;
    if(killable){                         
        if(checkSelfCollision())
        {
            cout << "[DEBUG] Self-collision detected! Game Over." << endl;
            gmRef->setGameLost();       // If colliding with itself, end game.
        }
    }
    cout << "[DEBUG] movePlayer() completed successfully." << endl;
}    

    
bool Player::checkCollision()  // private
{    
    // 1. Check Item Bin for Item ObjPos
    objPos target = binRef->getItem();  
    bool collided = myPos->getHead().isOverlap(&target); 

    // 2. check whether objPos are equal
    if(collided)
    {
        // 3. If yes, collision takes place
        // Generate New Item(s)
        binRef->generateItem();

        // Increase Score by Number
        myScore += target.getNum();
    }

    return collided;
}// Omega(1)

bool Player::checkSelfCollision()  // private
{    
    // Make sure snake is long enough to kill itself
    int length = myPos->getSize(); 
    if(length < 4) return false; 

    // Then check for self collision
    myPos->resetReadPos(); 
    objPos tempPos; 
    objPos headPos = myPos->getNext();

    if (headPos.getX() == -99) {  // Error handling
        cout << "[ERROR] checkSelfCollision() - Head position is invalid!" << endl;
        return false;
    }

    cout << "[DEBUG] Checking self-collision for head at: (" 
    << headPos.getX() << ", " << headPos.getY() << ")" << endl;
    
    for(int i = 1; i < length; i++) 
    {
        tempPos = myPos->getNext();
        
        if (tempPos.getX() == -99) {  // Error handling for corrupted data
            cout << "[ERROR] checkSelfCollision() - Encountered invalid body position!" << endl;
            return false;
        }

        cout << "[DEBUG] Comparing head (" << headPos.getX() << ", " << headPos.getY()
             << ") with body (" << tempPos.getX() << ", " << tempPos.getY() << ")" << endl;
        if(headPos.isOverlap(&tempPos))
        {
            // set game end.
            cout << "[DEBUG] Self-collision detected!" << endl;
            cout << flush;
            return true;
        }
    }

    return false;
}



void Player::drawPlayer()  
{   
    if (myPos->isEmpty()) return;  // ✅ Avoid calling getNext() if list is empty
    
    objPos targetPos;  
    int scanSize = myPos->getSize();  // get the list size  

    myPos->resetReadPos();  
    for(int i = 0; i < scanSize; i++) 
    {
        targetPos = myPos->getNext();  
        boardRef[targetPos.getY()][targetPos.getX()] = targetPos.getSym();   
    }  
}  
    

void Player::undrawPlayer()  // private helper function
{
    if (myPos->isEmpty()) return;  // ✅ Avoid calling getNext() if list is empty
    
    objPos targetPos;  
    int scanSize = myPos->getSize();  // get the list size  
 
    myPos->resetReadPos();  
    for(int i = 0; i < scanSize; i++)  
    {
        targetPos = myPos->getNext(); 
        boardRef[targetPos.getY()][targetPos.getX()] = ' '; 
    }
}  
    


void Player::increaseScore()
{
    myScore++;
}

int Player::getScore() const
{
    return myScore;    
}

objPosList* Player::getPlayerPos() const
{
    return myPos;   
}  
    
