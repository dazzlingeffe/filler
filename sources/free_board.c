//
// Created by ira on 25.04.2020.
//

#include "filler.h"

void	free_board(t_board **board)
{
	int	h;

	h = 0;
	while(h < (*board)->height)
		free((*board)->board[h++]);
//	free((*board)->board);
	(*board)->H = 0;
	(*board)->W = 0;
//	*board = NULL;
}

void	free_piece(t_piece **piece)
{
	int h;

	h = 0;
	while (h < (*piece)->height)
		free((*piece)->piece[h++]);
//	free((*piece)->piece);
//	*piece = NULL;
}

void	free_heatmap(t_board **board)
{
	int	h;

	h = 0;
	while(h < (*board)->height)
		free((*board)->heat_map[h++]);
}