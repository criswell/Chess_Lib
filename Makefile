CC = gcc
CFLAGS = -g -Wall -std=c99 -fgnu89-inline -D_POSIX_C_SOURCE=199309L
LINKER = -lncurses
ELF = chessgame
INC_W_LEVEL = -Wextra -pedantic
BLDFOLDER = ./build
CHESSLIB = chesslib.c

chessgame: main.c chesslib.c chesslib.h
	if [ ! -e $(BLDFOLDER) ]; then mkdir $(BLDFOLDER); fi \
	&& $(CC) $(CFLAGS) $< $(CHESSLIB) -o $@ $(LINKER); mv $@ $(BLDFOLDER)

chessgameWall: main.c chesslib.c chesslib.h
	$(CC) $(CFLAGS) $(INC_W_LEVEL) $< $(CHESSLIB) -o $@ $(LINKER); mv $@ $(BLDFOLDER)

run: chessgame
	exec ./build/chessgame

.PHONY: clean
clean:
	rm -rf build