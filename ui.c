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

static double TdN(double time, size_t lenght)
{
	return time / (lenght / 2);
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

static double (*bigO_calc[7])(double time, size_t lenght);

static void BigO_Text(O_Notation o)
{
	char bigO_text[][8] = {"T/1", "T/logN", "T/(N/2)", "T/N", "T/NlogN", "T/N²", "T/N³"};

	printf("Size(N)\tTime(T)\t\t\t%s\t\t\t%s\t\t\t%s\n", bigO_text[o - 1], bigO_text[o], bigO_text[o + 1]);
}

static void display(const Benchmark data)
{
	bigO_calc[0] = One;
	bigO_calc[1] = TlogN;
	bigO_calc[2] = TdN;
	bigO_calc[3] = TN;
	bigO_calc[4] = TNlogN;
	bigO_calc[5] = TN2;
	bigO_calc[6] = TN3;

	/* Best */
	printf("\nBest:\n");
	BigO_Text(data.bigO.best_bigO);
	for (size_t index = 0; index < Variants; index++)
	{
		printf("%lu\t%.13lf\t|\t", data.measurement[index].size, data.measurement[index].best);
		// print the calculations here
		double delta = bigO_calc[data.bigO.best_bigO - 1](data.measurement[index].best, data.measurement[index].size);
		printf("%.10e\t", delta);
		delta = bigO_calc[data.bigO.best_bigO](data.measurement[index].best, data.measurement[index].size);
		printf("%.10e\t", delta);
		delta = bigO_calc[data.bigO.best_bigO + 1](data.measurement[index].best, data.measurement[index].size);
		printf("%.10e\t", delta);
		printf("\n");
	}

	/* Average */
	printf("\nAverage:\n");
	BigO_Text(data.bigO.average_bigO);
	for (size_t index = 0; index < Variants; index++)
	{
		printf("%lu\t%.13lf\t|\t", data.measurement[index].size, data.measurement[index].average);
		// print the calculations here
		double delta = bigO_calc[data.bigO.average_bigO - 1](data.measurement[index].average, data.measurement[index].size);
		printf("%.10e\t", delta);
		delta = bigO_calc[data.bigO.average_bigO](data.measurement[index].average, data.measurement[index].size);
		printf("%.10e\t", delta);
		delta = bigO_calc[data.bigO.average_bigO + 1](data.measurement[index].average, data.measurement[index].size);
		printf("%.10e\t", delta);

		printf("\n");
	}

	/* Worst */
	printf("\nWorst:\n");
	BigO_Text(data.bigO.worst_bigO);
	for (size_t index = 0; index < Variants; index++)
	{
		printf("%lu\t%.13lf\t|\t", data.measurement[index].size, data.measurement[index].worst);
		// print the calculations here
		double delta = bigO_calc[data.bigO.worst_bigO - 1](data.measurement[index].worst, data.measurement[index].size);
		printf("%.10e\t", delta);
		delta = bigO_calc[data.bigO.worst_bigO](data.measurement[index].worst, data.measurement[index].size);
		printf("%.10e\t", delta);
		delta = bigO_calc[data.bigO.worst_bigO + 1](data.measurement[index].worst, data.measurement[index].size);
		printf("%.10e\t", delta);
		printf("\n");
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
	const char* labels[] = {"Exit\n", "Bubble sort", "Insertion sort", "Quick sort", "Linear serch", "Binary search\n"};

	options(labels, sizeof(labels) / sizeof(char*));
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
				puts("Calculating...\n");
				Benchmark result = benchmark(BubbleSort);
				puts("BubbleSort:");
				display(result);
				break;
			}

			case '2':
			{
				puts("Calculating...\n");
				Benchmark result = benchmark(InsertionSort);
				puts("InsertionSort:");
				display(result);
				break;
			}

			case '3':
			{
				puts("Calculating...\n");
				Benchmark result = benchmark(QuickSort);
				puts("QuickSort:");
				display(result);
				break;
			}

			case '4':
			{
				puts("Calculating...\n");
				Benchmark result = benchmark(LinearSearch);
				puts("LinearSearch:");
				display(result);
				break;
			}

			case '5':
			{
				puts("Calculating...\n");
				Benchmark result = benchmark(BinarySearch);
				puts("BinarySearch:");
				display(result);
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
