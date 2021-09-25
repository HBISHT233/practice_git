TARGETS = mutex_count
cc_c = $(CROSS_TOOL)gcc

CFLAGS = -Wall -g -std=c99 -Werror -pthread

all: clean $(TARGETS)

$(TARGETS):
	$(CC_C) $(CFLAGS) %@.c -o $@

clean:
	rm -f $(TARGETS)
