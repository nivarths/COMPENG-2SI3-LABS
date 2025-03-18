CC=g++
CFLAGS=-I. -lm -g -std=c++11
DEPS = *.h
OBJ = objPos.o objPosArrayList.o objPosDLinkedList.o objPosSLinkedList.o Test.o  

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

Lab2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

test:	testLab2
testLab2:
	./run.sh

.PHONY: clean

clean:
	$(RM) *.o *.exe *.xml Lab2
