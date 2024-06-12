if [ $# -eq 1 ]; then
	gcc -Wall -Werror -Wextra -Wpedantic -fsanitize=address *.c
else
	gcc -Wall -Werror -Wextra -Wpedantic *.c
fi