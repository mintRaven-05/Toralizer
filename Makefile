CC = gcc
CFLAGS = -fPIC -shared -ldl -D_GNU_SOURCE
MAIN = toralize.c
all:
	@echo "Creating toralizer shared object"
	@echo "linking into D_GNU_SOURCE type"
	@$(CC) $(MAIN) -o toralize.so $(CFLAGS)

clean:
	@echo "Cleaning up"
	@echo "removed toralize.so"
	@rm toralize.so