//
// Created by ira on 13.04.2020.
//

#include <filler.h>

void 	play(t_board *board, t_piece *piece)
{
	int w;
	int h;
	int cells;
	int min_cells;

	h = -(piece->height);
	markup_heatmap(&board);
	min_cells = FT_INT_MAX;
	while (h < board->height + piece->height)
	{
		w = -(piece->width);
		while (w < board->width + piece->width)
		{
			cells = count_cells(board, piece, h, w);
			if (cells >= 0 && cells < min_cells)
			{
				min_cells = cells;
				(*board).H = h;
				(*board).W = w;
			}
			++w;
		}
		++h;
	}
}

int 	count_cells(t_board *board, t_piece *piece, int x, int y)
{
	int cells;
	int counter;
	int i;
	int j;

	cells = 0;
	counter = 0;
	i = -1;
	while (++i < piece->height)
	{
		j = -1;
		while(++j < piece->width)
		{
			if (piece->piece[i][j] == '*')
			{
				if ((x + i) >= board->height || (x + i) < 0
				|| (y + j) >= board->height || (y + j) < 0
				|| ft_tolower(board->board[x + i][y + j]) == board->enemy || ft_tolower(board->board[x + i][y + j]) == board->enemy - 32)
					return (-1);
				if (ft_tolower(board->board[x + i][y + j]) == board->symbol)
					++counter;
				cells += board->heat_map[x + i][y + j];
			}
		}
	}
	return counter == 1 ? cells : -1;
}

void 	markup_heatmap(t_board **board)
{
	int i;
	int j;
	int min_dist;

	min_dist = FT_INT_MAX;
	if (!((*board)->heat_map = (int**)ft_memalloc(sizeof(int*) * (*board)->height)))
		print_error(1);
//	ft_bzero((*board)->heat_map, (*board)->height);
	i = -1;
	while (++i < (*board)->height)
	{
		if(!((*board)->heat_map[i] = (int*)malloc(sizeof(int) * (*board)->width)))
			print_error(1);
		ft_arrayset((*board)->heat_map[i], min_dist, (*board)->width);
		j = -1;
		while (++j < (*board)->width)
		{
			if ((*board)->board[i][j] == '.' || ft_tolower((*board)->board[i][j]) == (*board)->symbol)
				measure_distance(&board, i, j);
			else if (ft_tolower((*board)->board[i][j]) == (*board)->enemy)
				(*board)->heat_map[i][j] = 0;
		}
	}
}

void 	measure_distance(t_board ***board, int i, int j)
{
	int x;
	int y;
	int distance;

	x = -1;
	while (++x < (**board)->height)
	{
		y = -1;
		while (++y < (**board)->width)
		{
			if ((**board)->board[x][y] == (**board)->enemy || (**board)->board[x][y] == (char)(**board)->enemy - 32)
			{
				distance = ft_abs(y - j) + ft_abs(x - i);
				if (distance < (**board)->heat_map[i][j])
					(**board)->heat_map[i][j] = distance;
			}
		}
	}
}