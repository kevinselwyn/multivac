NAME    := multivac
EXEC    := can
FLAGS   := -Wall -Wextra
BIN_DIR := /usr/local/bin

all: build

build: $(NAME).c
	gcc -o $(EXEC) $< -O2 $(FLAGS)

test: build
	./$(EXEC) entropy be reversed

install: $(EXEC)
	install -m 0755 $(EXEC) $(BIN_DIR)

uninstall:
	rm -f $(BIN_DIR)/$(EXEC)

clean:
	rm -f $(EXEC)