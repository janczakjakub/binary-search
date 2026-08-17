CC = cc
CFLAGS = -Wall -Wextra -std=c11 -O2
LDFLAGS = -lm
APP = benchmark

SRCS = main.c binary_search.c simple_search.c
OBJS = $(SRCS:.c=.o)

.PHONY: all run clean

all: $(APP)

$(APP): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

run: $(APP)
	./$(APP)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(APP) $(OBJS)
