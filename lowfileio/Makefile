CC=gcc
CFLAGS=-g -Wall
OBJS=fileOpenClose.o
TARGET=fileOpenClose

all:$(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS)
