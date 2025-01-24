CC = gcc
CFLAGS = -Wall -g
LDFLAGS =

EXEC = mySA

SOURCES = functions.c vader_lexicon_reader.c

OBJECTS = $(SOURCES:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJECTS) $(EXEC)

.PHONY: all clean
