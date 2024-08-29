NAME = wcat.c

bin/$(NAME): bin/ $(NAME).c
        gcc -Wall -Wextra -g -o bin/$(NAME) $(NAME).c

bin/:
       mkdir bin

run: bin/$(NAME)
         ./bin/$(NAME)

.PHONY: clean
clean:
       rm -rf bin
