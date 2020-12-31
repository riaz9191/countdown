#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

int main() {
	char* numbers[12][7];

	numbers[0][0] = "   ___   ";
	numbers[0][1] = "  / _ \\  ";
	numbers[0][2] = " | | | | ";
	numbers[0][3] = " | | | | ";
	numbers[0][4] = " | |_| | ";
	numbers[0][5] = "  \\___/  ";
	numbers[0][6] = "         ";

	numbers[1][0] = "  __  ";
	numbers[1][1] = " /_ | ";
	numbers[1][2] = "  | | ";
	numbers[1][3] = "  | | ";
	numbers[1][4] = "  | | ";
	numbers[1][5] = "  |_| ";
	numbers[1][6] = "      ";

	numbers[2][0] = "  ___   ";
	numbers[2][1] = " |__ \\  ";
	numbers[2][2] = "    ) | ";
	numbers[2][3] = "   / /  ";
	numbers[2][4] = "  / /_  ";
	numbers[2][5] = " |____| ";
	numbers[2][6] = "        ";

	numbers[3][0] = "  ____   ";
	numbers[3][1] = " |___ \\  ";
	numbers[3][2] = "   __) | ";
	numbers[3][3] = "  |__ <  ";
	numbers[3][4] = "  ___) | ";
	numbers[3][5] = " |____/  ";
	numbers[3][6] = "         ";

	numbers[4][0] = "  _  _    ";
	numbers[4][1] = " | || |   ";
	numbers[4][2] = " | || |_  ";
	numbers[4][3] = " |__   _| ";
	numbers[4][4] = "    | |   ";
	numbers[4][5] = "    |_|   ";
	numbers[4][6] = "          ";

	numbers[5][0] = "  _____  ";
	numbers[5][1] = " | ____| ";
	numbers[5][2] = " | |__   ";
	numbers[5][3] = " |___ \\  ";
	numbers[5][4] = "  ___) | ";
	numbers[5][5] = " |____/  ";
	numbers[5][6] = "         ";

	numbers[6][0] = "    __   ";
        numbers[6][1] = "   / /   ";
        numbers[6][2] = "  / /_   ";
        numbers[6][3] = " | '_ \\  ";
        numbers[6][4] = " | (_) | ";
        numbers[6][5] = "  \\___/  ";
        numbers[6][6] = "         ";

        numbers[7][0] = "  ______  ";
        numbers[7][1] = " |____  | ";
        numbers[7][2] = "     / /  ";
        numbers[7][3] = "    / /   ";
        numbers[7][4] = "   / /    ";
        numbers[7][5] = "  /_/     ";
        numbers[7][6] = "          ";

	numbers[8][0] = "   ___   ";
        numbers[8][1] = "  / _ \\  ";
        numbers[8][2] = " | (_) | ";
        numbers[8][3] = "  > _ <  ";
        numbers[8][4] = " | (_) | ";
        numbers[8][5] = "  \\___/  ";
        numbers[8][6] = "         ";

	numbers[9][0] = "   ___   ";
        numbers[9][1] = "  / _ \\  ";
        numbers[9][2] = " | (_) | ";
        numbers[9][3] = "  \\__, | ";
        numbers[9][4] = "    / /  ";
        numbers[9][5] = "   /_/   ";
        numbers[9][6] = "         ";

	numbers[10][0] = "     ";
	numbers[10][1] = "  _  ";
        numbers[10][2] = " (_) ";
        numbers[10][3] = "     ";
        numbers[10][4] = "  _  ";
        numbers[10][5] = " (_) ";
        numbers[10][6] = "     ";

	numbers[11][0] = "     ";
	numbers[11][1] = "     ";
	numbers[11][2] = "     ";
	numbers[11][3] = "     ";
	numbers[11][4] = "     ";
	numbers[11][5] = "     ";
	numbers[11][6] = "     ";

	char* hny[8];
	hny[0] = " _    _                           _   _                __     __               _ ";
	hny[1] = "| |  | |                         | \\ | |               \\ \\   / /              | |";
	hny[2] = "| |__| | __ _ _ __  _ __  _   _  |  \\| | _____      __  \\ \\_/ /__  __ _ _ __  | |";
	hny[3] = "|  __  |/ _` | '_ \\| '_ \\| | | | | . ` |/ _ \\ \\ /\\ / /   \\   / _ \\/ _` | '__| | |";
	hny[4] = "| |  | | (_| | |_) | |_) | |_| | | |\\  |  __/\\ V  V /     | |  __/ (_| | |    |_|";
	hny[5] = "|_|  |_|\\__,_| .__/| .__/ \\__, | |_| \\_|\\___| \\_/\\_/      |_|\\___|\\__,_|_|    (_)";
	hny[6] = "             | |   | |     __/ |                                                 ";
	hny[7] = "             |_|   |_|    |___/                                                  ";
	
	char output[7][200];

        int row,col;
	initscr();
        getmaxyx(stdscr,row,col);	/* get the number of rows and columns */
        // mvprintw(row-2,0,"This screen has %d rows and %d columns\n",row,col);
        // printw("Try resizing your window(if possible) and then run this program again");
        // refresh();
	curs_set(0);

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);

	attron(COLOR_PAIR(1) | A_BOLD);

	int diff;
	int sec, min, ho, days;

	time_t systemTime;
	time(&systemTime);

	struct tm newYear;
	newYear = *localtime(&systemTime);
	newYear.tm_sec = 0;
	newYear.tm_min = 0;
	newYear.tm_hour = 0;
	newYear.tm_mday = 1;
	newYear.tm_mon = 1 - 1;
	newYear.tm_year += 1;

	diff = (int) difftime(mktime(&newYear), systemTime);

	while(diff > 0) {
		// printf("%f\n", diff);
		days = diff / (60*60*24);
	        ho = (diff % (60*60*24)) / (60*60);
	        min = (diff / 60) % 60;
		sec = diff % 60;

		erase();
		for (int i = 0; i < 7; i++) {
			strcpy(output[i], "");

			if (days > 0) {
				if (days >= 100) {
					strcat(output[i], numbers[days/100][i]);
					strcat(output[i], numbers[(days/10)%10][i]);
					strcat(output[i], numbers[days%10][i]);
				} else if (days >= 10) {
					strcat(output[i], numbers[days/10][i]);
					strcat(output[i], numbers[days%10][i]);
				} else { 
					strcat(output[i], numbers[days][i]);
				}
				// <space> divider
				strcat(output[i], numbers[11][i]);
			}

			if (ho > 0 || days > 0) {
				strcat(output[i], numbers[ho/10][i]);
				strcat(output[i], numbers[ho%10][i]);
				// : divider
				strcat(output[i], numbers[10][i]);
			}

			if (min > 0 || ho > 0 || days > 0) {
				strcat(output[i], numbers[min/10][i]);
				strcat(output[i], numbers[min%10][i]);
				// : divider
				strcat(output[i], numbers[10][i]);
			}

			if (diff >= 10) {
				strcat(output[i], numbers[sec/10][i]);
			}

			strcat(output[i], numbers[sec%10][i]);

			mvprintw(row/2-3+i,(col-strlen(output[i]))/2,"%s",output[i]);
		}
		move(row-1, col-1);
		refresh();
		diff--;
		sleep(1);
	}

	attroff(COLOR_PAIR(1) | A_BOLD);

	attron(COLOR_PAIR(2) | A_BOLD);
	for (int i = 0; i < 8; i++) {
		mvprintw(row/2-3+i,(col-strlen(hny[i]))/2,"%s",hny[i]);
	}
	attroff(COLOR_PAIR(2) | A_BOLD);

	getch();
	endwin();

	return 0;
}
