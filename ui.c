#include "ui.h"

#include "analyze.h"
#include "io.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

static char choice()
{
	printf("\n> ");
	return input();
}

/*static void ui_line(char c, int n)
{
	while (n-- > 0)
	{
		putchar(c);
	}
	putchar('\n');
}*/

static void display(const Benchmark data)
{
	puts("Average:");
	printf("Size\tTime T(s)\tT/(log(n))\n");

	for (size_t index = 0; index < Variants; index++)
	{
		printf("%lu\t%lf\t\n", data.measurement[index].size, data.measurement[index].average);
	}
}

static void options(const char* labels[], const size_t count)
{
	for (size_t index = 0; index < count; index++)
	{
		printf("\n %lu) %s", index, labels[index]);
	}
}

static void menu()
{
	const char* labels[] = {"Exit\n", "Bubble sort", "Insertino sort", "Quick sort", "Linear serch", "Binary search\n"};

	// ui_line('=', MENU_WIDTH);
	options(labels, sizeof(labels) / sizeof(char*));
	// ui_line('-', MENU_WIDTH);
}

void terminal()
{
	menu();

	while (true)
	{
		choice();
		switch ('1')
		{
			case '0':
			{
				return;
			}

			case '1':
			{
				// benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				puts("Calculating...");
				Benchmark result = benchmark(BubbleSort);
				display(result);
				break;
			}

			case '2':
			{
				// benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				puts("Calculating...");
				break;
			}

			case '3':
			{
				// benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				puts("Calculating...");
				break;
			}

			case '4':
			{
				// benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				puts("Calculating...");
				break;
			}

			case '5':
			{
				// benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				puts("Calculating...");
				break;
			}

			default:
			{
				menu();
				break;
			}
		}
	}
}
