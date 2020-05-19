#include <fcntl.h>
#include "filler.h"

void		print_error(int i)
{
	ft_putstr("Error");
	exit(i);
}

void		init(t_board **board, t_piece **piece)
{
	(*piece)->lvl = 0;
	(*piece)->width = 0;
	(*piece)->height = 0;
	(*piece)->piece = NULL;
	(*board)->height = 0;
	(*board)->width = 0;
	(*board)->H = 0;
	(*board)->W = 0;
	(*board)->lvl = 0;
	(*board)->heat_map = NULL;
	(*board)->board = NULL;
}

void 		set_player(t_board **board, char *line)
{
	if (!ft_strncmp(line, "$$$", 3))
	{
		(*board)->symbol = line[10] == '1' ? 'o' : 'x';
		(*board)->enemy = line[10] == '1' ? 'x' : 'o';
	}
}

int			main(void)
{
	t_board	*board;
	t_piece	*piece;
	char 	*line;
	int 	i;

	if (!(board = (t_board *)ft_memalloc(sizeof(t_board))) ||
	!(piece = (t_piece *)ft_memalloc(sizeof(t_piece))) ||
	!(line = (char *)ft_memalloc(sizeof(char) * 1)))
		perror("memory allocation failed");
	if (get_next_line(0, &line) > 0)
		set_player(&board, line);
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
