#include "filler.h"

int			parsing_data(t_board **board, t_piece **piece, char *line)
{
	int 	r;

	r = 0;
	if (!ft_strncmp("Plateau", line, 7))
	{
		set_board(board, line);
	}
	else if (ft_isdigit(line[0]))
		(*board)->board[(*board)->lvl++] = ft_strdup(line + 4);
	else if (!ft_strncmp("Piece", line, 5))
		set_piece(piece, line);
	else if (line[0] == '.' || line[0] == '*') {
		r = parse_piece(piece, line);
	}
	else if (line[0] != ' ')
		r = 2;
	return (r);
}

int		parse_piece(t_piece **piece, char *line)
{
	(*piece)->piece[(*piece)->lvl++] = ft_strdup(line);
	if ((*piece)->height && (*piece)->lvl == (*piece)->height)
		return (1);
	return (0);
}

void 		set_piece(t_piece **piece, char *line)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]))
		++i;
	(*piece)->height = ft_atoi(line + i);
	while (line[i] != ' ')
		++i;
	(*piece)->width = ft_atoi(line + i + 1);
	if (!((*piece)->piece = (char **)ft_memalloc(sizeof(char*) * (*piece)->height)))
		perror("memory allocation failed");
	(*piece)->lvl = 0;
}

void		set_board(t_board **board, char *line)
{
	char 	**tmp;

	tmp = ft_strsplit(line, ' ');
	(*board)->height = ft_atoi(tmp[1]);
	(*board)->width = ft_atoi(tmp[2]);
	if (!((*board)->board = (char **)ft_memalloc(sizeof(char*) * (*board)->height)))
		perror("memory allocation failed");
	(*board)->lvl = 0;
}