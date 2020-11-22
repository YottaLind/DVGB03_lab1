.PHONY: clean run

COMPILER = gcc -O0 -march=native -Wall

SOURCE = $(wildcard *.c)
OBJECTS = $(SOURCE:.c=.o)


complexity-analysis: $(OBJECTS)
	$(COMPILER) -fwhole-program -flto  -o $@ $^ -lm
	strip $@

%.o: %.c
	$(COMPILER) -c -o $@ $<

clean:
	rm complexity-analysis *.o

run: complexity-analysis
	./$^