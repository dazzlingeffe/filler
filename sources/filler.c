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
		(*board)->lvl = 0;
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
		if (!((*piece)->piece = (char **)ft_memalloc(sizeof(char*) * (*piece)->height)))
			print_error(1);
		(*piece)->lvl = 0;
	}
	else if (line[0] == '.' || line[0] == '*') {
		(*piece)->piece[(*piece)->lvl++] = ft_strdup(line);
		if ((*piece)->height && (*piece)->lvl == (*piece)->height)
			return (1);
	}
	else if (line[0] != ' ')
		return (2);
	return (0);
}

void		set_board_size(t_board **board, char *line)
{
	char 	**tmp;

	tmp = ft_strsplit(line, ' ');
	(*board)->height = ft_atoi(tmp[1]);
	(*board)->width = ft_atoi(tmp[2]);
}

int			main(void) {
	t_board	*board;
	t_piece	*piece;
	char 	*line;
	int i;

	if (!(board = (t_board *)ft_memalloc(sizeof(t_board))) ||
	!(piece = (t_piece *)ft_memalloc(sizeof(t_piece))) ||
	!(line = (char *)ft_memalloc(sizeof(char) * 1)))
		print_error(1);
	if (get_next_line(0, &line) > 0)
	{
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
		}
		else
			return (1);
	}
	piece->lvl = 0;
	piece->width = 0;
	piece->height = 0;
	piece->piece = NULL;
	board->height = 0;
	board->width = 0;
	board->H = 0;
	board->W = 0;
	board->lvl = 0;
	board->heat_map = NULL;
	board->board = NULL;

	ft_strdel(&line);

	while(get_next_line(0, &line) > 0)
	{
		if((i = parsing_data(&board, &piece, line)) == 2)
			break ;
		else if (i == 1)
		{
			play(board, piece);
			print_coordinates(board);
			free_board(&board);
			free_piece(&piece);
		}
		ft_strdel(&line);
	}
	return (1);
}
