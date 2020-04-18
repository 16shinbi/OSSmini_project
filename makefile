CC = gcc
CFLAGS = -W -Wall
TARGET = market
DTARGET =market_debug
OBJECTS = product.o manager.o market.o

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET)
