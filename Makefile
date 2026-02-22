CC=g++
CFLAGS=-Wall -DDYN_LOG
TARGET=./test_log
SRC=./test_log.c
HDR=./log.h

$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
