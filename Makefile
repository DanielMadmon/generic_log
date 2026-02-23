CC    =gcc
CFLAGS=-Wall -fPIC -shared -DDYN_LOG
SRC   =./generic_log.c
HDR   =./generic_log.h
TARGET=libgeneric_log.so


$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
