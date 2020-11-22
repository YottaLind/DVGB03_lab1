#include "ui.h"

#include <math.h>
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

static double One(double time, size_t lenght)
{
	return time / 1;
}

static double TlogN(double time, size_t lenght)
{
	return time / log10(lenght);
}

static double TN(double time, size_t lenght)
{
	return time / lenght;
}

static double TNlogN(double time, size_t lenght)
{
	return time / (lenght * log10(lenght));
}

static double TN2(double time, size_t lenght)
{
	return time / (lenght * lenght);
}

static double TN3(double time, size_t lenght)
{
	return time / (lenght * lenght * lenght);
}

static double(*bigO_calc[6])(double time, size_t lenght);

static void list(const Benchmark data, Case c)
{
	bigO_calc[0] = One;
	bigO_calc[1] = TlogN;
	bigO_calc[2] = TN;
	bigO_calc[3] = TNlogN;
	bigO_calc[4] = TN2;
	bigO_calc[5] = TN3;
	
	switch (c)
	{
	case best_t:
		for (size_t index = 0; index < Variants; index++)
		{
			printf("%lu\t%lf\t|\t", data.measurement[index].size, data.measurement[index].best);
			//print the calculations here
			double delta = bigO_calc[data.bigO.best_bigO](data.measurement->best,data.measurement->size);
			printf("delta: %.10e", delta);
			printf("\n");
		}
		break;
	case worst_t:
		for (size_t index = 0; index < Variants; index++)
		{
			printf("%lu\t%lf\t|\t", data.measurement[index].size, data.measurement[index].worst);
			//print the calculations here

			printf("\n");
		}
		break;
	case average_t:
		for (size_t index = 0; index < Variants; index++)
		{
			printf("%lu\t%lf\t|\t", data.measurement[index].size, data.measurement[index].average);
			//print the calculations here
			printf("\n");
		}
		break;

	default:
		break;
	}
}

static void display(const Benchmark data)
{
	puts("\nBest case:");
	list(data, best_t);
	puts("\nWorst case:");
	list(data, worst_t);
	puts("\nAverage case:");
	list(data, average_t);

}

static void options(const char *labels[], const size_t count)
{
	for (size_t index = 0; index < count; index++)
	{
		printf("\n %lu) %s", index, labels[index]);
	}
}

static void menu()
{
	const char *labels[] = {"Exit\n", "Bubble sort", "Insertino sort", "Quick sort", "Linear serch", "Binary search\n"};

	// ui_line('=', MENU_WIDTH);
	options(labels, sizeof(labels) / sizeof(char *));
	// ui_line('-', MENU_WIDTH);
}

void terminal()
{
	menu();

	while (true)
	{

		switch (choice())
		{
		case '0':
		{
			return;
			break;
		}

		case '1':
		{
			// benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
			puts("Calculating...");
			Benchmark result = benchmark(BubbleSort);
			puts("BubbleSort: \n");
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
