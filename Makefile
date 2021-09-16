.PHONY: all debug clean

CFLAGS += -Werror
SRC := $(wildcard *.c)
BIN := $(SRC:.c=.exe)

debug prod: $(BIN)
debug: CFLAGS += -g3

clean:
	rm -rf $(BIN) *.dSYM

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

