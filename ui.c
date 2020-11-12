#include "ui.h"
#include "io.h"
#include "analyze.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

static void ui_invalid_input()
{
	printf("info> bad input\n");
}

static void ui_exit()
{
	printf("info> bye\n");
}

static char ui_get_choice()
{
	char buf[3];

	printf("input> ");
	return read_line(buf, 3) ? buf[0] : 0;
}

static void ui_line(char c, int n)
{
	while (n-- > 0) {
		putchar(c);
	}
	putchar('\n');
}

static void ui_menu_options(const char *options[], int num_options)
{
	int i;

	for (i=0; i<num_options; i++) {
		printf("    %c) %s\n", '0'+i, options[i]);
	}
}

static void ui_menu()
{
	const char *options[] = {
		"Menu\n",
		"Bubble sort",
		"Insertino sort",
		"Quick sort",
		"Linear serch",
		"Binary search\n",
		"Exit",
		// TODO: complete menu
	};

	ui_line('=', MENU_WIDTH);
	ui_menu_options(options, sizeof(options) / sizeof(char *));
	ui_line('-', MENU_WIDTH);
}

//
// Public
//
void ui_run()
{
	bool running, show_menu;
	//result_t result[RESULT_ROWS];
	
	show_menu = true;
	running = true;
	while (running) {
		if (show_menu) {
			show_menu = false;
			ui_menu();
		}
		switch (ui_get_choice()) {
			// House keeping
			case '0':
				show_menu = true;
				break;
			case '6':
				running = false;
				break;
			// Bubble sort
			case '1':
				//benchmark(bubble_sort_t, best_t, result, RESULT_ROWS);
				benchmark(BubbleSort, 10);
				printf("Bubble\n");
				break;
			case '2':
				//benchmark(insertion_sort_t, best_t, result, RESULT_ROWS);
				printf("Insertion\n");
				break;
			case '3':
				//benchmark(quick_sort_t, best_t, result, RESULT_ROWS);
				printf("Quick\n");
				break;
			case '4':
				//benchmark(linear_search_t, best_t, result, RESULT_ROWS);
				printf("Linear\n");
				break;
			case '5':
				//benchmark(binary_search_t, best_t, result, RESULT_ROWS);
				printf("Binary\n");
				break;
			// Invalid input
			default:
				show_menu = false;
				ui_invalid_input();
				break;
		}
	}
	ui_exit();
}
