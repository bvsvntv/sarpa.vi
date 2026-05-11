CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lSDL2 -lSDL2_ttf
INCLUDES = -I/usr/include/SDL2/
SRCS = ./src/main.c ./src/logic.c ./src/rendering.c
OBJS = ${SRCS:.c=.o}
MAIN = main.bin

$(MAIN) : ${OBJS}
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM) $(OBJS) $(MAIN)
run: clean $(MAIN)
	./main.bin
