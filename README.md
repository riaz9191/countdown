# Countdown in C
This project is a small countdown-timer to New Year, coded in C using the ncurses library.

## Features
- automatically selects the next year transition, based on the system time
- countdown in the format DDD HH:MM:SS
- format changes as the time ticks away, eg. HH:MM:SS to MM:SS to SS to S
- runs in the terminal
- timer in ASCII-art
- coded in C
- uses the ncurses library
- makefile included

## How to use?
1. compile the code, using the make file, or enter the compile command manually:
	`make` or `gcc -o countdown countdown.c -lncurses -std=c99`
2. run the compiled executable:
	`./countdown`
	
## License
See the [LICENSE](LICENSE) file for license rights and limitations (MIT).
