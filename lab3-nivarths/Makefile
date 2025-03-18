CC=g++
CFLAGS=-I. -lm -g -std=c++11
DEPS = *.h
OBJ = objPos.o objPosStack.o objPosSHLinkedList.o cmdQueue.o Test.o  

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab3: $(OBJ)
	$(CC) -o $@ ${OBJ} $(CFLAGS)

test:	testLab3
testLab3:
	./run.sh

.PHONY: clean

clean:
	$(RM) ${OBJ} *.exe *.xml Lab3
