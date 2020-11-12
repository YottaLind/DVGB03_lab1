.PHONY: clean all

COMPILER = gcc -O3 -march=native -Werror -Wall #-pedantic-errors

SOURCE=$(wildcard *.c)
OBJECTS=$(SOURCE:.c=.o)

all: program.out

program.out: $(OBJECTS)
	$(COMPILER) -fwhole-program -flto -lm -o program.out $^

%.o: %.c
	$(COMPILER) -c -O3 -o $@ $<

clean:
	rm *.out *.o