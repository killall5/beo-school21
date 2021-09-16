.PHONY: all debug clean

SRC := $(wildcard *.c)
BIN := $(SRC:.c=)

debug prod: $(BIN)
debug: CFLAGS += -g3

clean:
	rm -rf $(BIN) *.dSYM

%.exe: %.c
	$(CC) $(CFLAGS) -c $< -o $@

