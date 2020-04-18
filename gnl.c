#include "get_next_line.h"
#include "stdio.h"

int	main() {
	char *line;
	int	i;

	line = (char*)malloc(sizeof(char) * 10000);
	i = 0;
	if ((i = get_next_line(STDIN_FILENO, &line)) > 0)
		printf("%d\n", i);
	free(&line);
	while ((i = get_next_line(STDIN_FILENO, &line)) > 0)
		printf("->%d->", i);
	return (0);
}
