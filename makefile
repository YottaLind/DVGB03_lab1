.PHONY: clean run

COMPILER = gcc -O3 -march=native -Werror -Wall -pedantic-errors

SOURCE=$(wildcard *.c)
OBJECTS=$(SOURCE:.c=.o)


complexity-analysis: $(OBJECTS)
	$(COMPILER) -fwhole-program -flto -lm -o $@ $^
	strip $@

%.o: %.c
	$(COMPILER) -c -o $@ $<

clean:
	rm complexity-analysis *.o

run: complexity-analysis
	./$^