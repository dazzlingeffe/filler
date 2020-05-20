/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:05:00 by cmeowth           #+#    #+#             */
/*   Updated: 2020/17/28 02:03:06 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_board_piece(t_board **board, t_piece **piece)
{
	int	h;

	h = 0;
	while (h < (*board)->height)
		free((*board)->board[h++]);
	(*board)->h = 0;
	(*board)->w = 0;
	h = 0;
	while (h < (*piece)->height)
		free((*piece)->piece[h++]);
}

void	free_heatmap(t_board **board)
{
	int	h;

	h = 0;
	while (h < (*board)->height)
		free((*board)->heat_map[h++]);
}
