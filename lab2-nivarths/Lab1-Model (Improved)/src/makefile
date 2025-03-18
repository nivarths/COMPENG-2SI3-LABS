CC = g++
CFLAGS = -I. -I../inc -I../../ -g -std=c++11
VPATH = ../../
OBJ = objPos.o objPosArrayList.o objPosDLinkedList.o objPosSLinkedList.o GameMechs.o MacUILib.o Player.o ItemBin.o ScreenDrawer.o MainGame.o 
DEPS = *.h

ifeq (${OS}, Windows_NT)
	OSSETTING = -DWINDOWS
else
	OSSETTING = -DPOSIX
	POSTLINKER = -lncurses   ## uncomment this if on Linux
endif

EXEC = ../bin/Project

%.o: %.cpp $(DEPENDS)
	$(CC) ${OSSETTING} -c -o $@ $< $(CFLAGS)

${EXEC} : $(OBJ)
	$(CC)  ${OSSETTING} -o $@ $^ $(CFLAGS) ${POSTLINKER}

clean :
	rm -rf ${OBJ} ${EXEC} ${EXEC}.exe

