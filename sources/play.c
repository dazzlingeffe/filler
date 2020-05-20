/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:05:00 by cmeowth           #+#    #+#             */
/*   Updated: 2020/07/28 02:03:06 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void	play(t_board *board, t_piece *piece)
{
	int w;
	int h;
	int cells;
	int min_cells;

	h = -(PHEIGHT);
	markup_heatmap(&board);
	min_cells = 2147483647;
	while (h < BHEIGHT + PHEIGHT)
	{
		w = -(PWIDTH);
		while (w < BWIDTH + PWIDTH)
		{
			cells = count_cells(board, piece, h, w);
			if (cells >= 0 && cells < min_cells)
			{
				min_cells = cells;
				(*board).h = h;
				(*board).w = w;
			}
			++w;
		}
		++h;
	}
	free_heatmap(&board);
}

int		count_cells(t_board *board, t_piece *piece, int x, int y)
{
	int cells;
	int counter;
	int i;
	int j;

	cells = 0;
	counter = 0;
	i = -1;
	while (++i < PHEIGHT)
	{
		j = -1;
		while (++j < PWIDTH)
		{
			if (PIECE[i][j] == '*')
			{
				if ((x + i) >= BHEIGHT || (x + i) < 0 || (y + j) >= BWIDTH ||
				(y + j) < 0 || ft_tolower(BOARD[x + i][y + j]) == board->enemy)
					return (-1);
				if (ft_tolower(BOARD[x + i][y + j]) == board->symbol)
					++counter;
				cells += HEAT[x + i][y + j];
			}
		}
	}
	return (counter == 1 ? cells : -1);
}

void	markup_heatmap(t_board **board)
{
	int i;
	int j;
	int min_dist;
	int h;
	int w;

	min_dist = 2147483647;
	h = (int)(sizeof(int*) * (*board)->height);
	w = (int)(sizeof(int*) * (*board)->width);
	if (!((*board)->heat_map = (int**)ft_memalloc(h)))
		print_error(1);
	i = -1;
	while (++i < (*board)->height)
	{
		if (!((*board)->heat_map[i] = (int*)malloc(w)))
			print_error(1);
		ft_arrayset((*board)->heat_map[i], min_dist, (*board)->width);
		j = -1;
		while (++j < (*board)->width)
			if ((*board)->board[i][j] == '.'
			|| ft_tolower((*board)->board[i][j]) == (*board)->symbol)
				measure_distance(&board, i, j);
			else if (ft_tolower((*board)->board[i][j]) == (*board)->enemy)
				(*board)->heat_map[i][j] = 0;
	}
}

void	measure_distance(t_board ***board, int i, int j)
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
			if (ft_tolower((**board)->board[x][y]) == (**board)->enemy)
			{
				distance = ft_abs(y - j) + ft_abs(x - i);
				if (distance < (**board)->heat_map[i][j])
					(**board)->heat_map[i][j] = distance;
			}
		}
	}
}
