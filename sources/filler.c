#include <fcntl.h>
#include "filler.h"
#include "stdio.h"

void 		print_error(int code)
{
	ft_putstr("Error\n");

	exit(code);
}

int			parsing_data(t_board **board, t_piece **piece, char *line)
{
	int		i;

	if (!ft_strncmp("Plateau", line, 7))
	{
		set_board_size(board, line);
		if (!((*board)->board = (char **)ft_memalloc(sizeof(char*) * (*board)->height)))
			print_error(1);
	}
	else if (ft_isdigit(line[0]))
		(*board)->board[(*board)->lvl++] = ft_strdup(line + 4);
	else if (!ft_strncmp("Piece", line, 5))
	{
		i = 0;
		while (!ft_isdigit(line[i]))
			++i;
		(*piece)->height = ft_atoi(line + i);
		while (line[i] != ' ')
			++i;
		(*piece)->width = ft_atoi(line + i + 1);
		if (!((*piece)->piece = ft_memalloc(sizeof(char*) * (*piece)->width)))
			print_error(1);
	}
	else if (line[0] == '.' || line[0] == '*')
		(*piece)->piece[(*piece)->lvl++] = ft_strdup(line);
	if ((*piece)->height && (*piece)->lvl == (*piece)->height)
		return (1);
	return (0);
}

void		set_board_size(t_board **board, char *line)
{
	int 	i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	(*board)->height = ft_atoi(line + i);
	(*board)->width = ft_atoi(line + i + 2);
}

int			main(void) {
	t_board	*board;
	t_piece	*piece;
	char 	*line;

	if (!(board = (t_board *)ft_memalloc(sizeof(t_board))) ||
	!(piece = (t_piece *)ft_memalloc(sizeof(t_piece))) ||
	!(line = (char *)ft_memalloc(sizeof(char))))
		print_error(1);

	int fd = open("file.txt", O_RDWR);
	while (get_next_line(0, &line) > 0)
	{
		dprintf(fd, "%s\n", line);
		if (!ft_strncmp(line, "$$$", 3))
		{
			if (line[10] == '1') {
				board->symbol = 'o';
				board->enemy = 'x';
			}
			else {
				board->symbol = 'x';
				board->enemy = 'o';
			}
			break ;
		}
	}
	ft_strdel(&line);
	while(get_next_line(0, &line) > 0)
	{
//		set_board_size(&board, line);
//		if (!(board->board = (char **)ft_memalloc(sizeof(char*) * board->height)))
//			print_error(1);
		dprintf(fd, "%s\n", line);
		if(parsing_data(&board, &piece, line))
		{
			play(board, piece);
			print_coordinates(board);
		}
		ft_strdel(&line);
	}
	return (0);
}
