#include "filler.h"

void	free_board(t_board **board)
{
	int	h;

	h = 0;
	while(h < (*board)->height)
		free((*board)->board[h++]);
	(*board)->H = 0;
	(*board)->W = 0;
}

void	free_piece(t_piece **piece)
{
	int h;

	h = 0;
	while (h < (*piece)->height)
		free((*piece)->piece[h++]);
}

void	free_heatmap(t_board **board)
{
	int	h;

	h = 0;
	while(h < (*board)->height)
		free((*board)->heat_map[h++]);
}