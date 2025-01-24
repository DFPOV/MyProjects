CC=gcc
CFLAGS=-Wall -g
TARGET=math_matrix
SRCS = math_matrix.c functions.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean