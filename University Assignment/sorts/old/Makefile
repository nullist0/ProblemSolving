CC=g++
OBJS=ort.o heap.o countHeap.o quick.o countQuick.o
TARGET=sort.out
 
all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

ort.o: ./headers/heap.h ./headers/quick.h ./headers/countheap.h ./headers/countquick.h ort.cpp
heap.o: ./headers/heap.h heap.cpp
countHeap.o: ./headers/countheap.h countHeap.cpp
quick.o: ./headers/quick.h quick.cpp
countQuick.o: ./headers/countquick.h countQuick.cpp