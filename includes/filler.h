/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 23:53:46 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:53:46 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# define BHEIGHT board->height
# define BWIDTH board->width
# define BOARD board->board
# define HEAT board->heat_map
# define PIECE piece->piece
# define PHEIGHT piece->height
# define PWIDTH piece->width
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct	s_board
{
	char		**board;
	int			height;
	int			width;
	int			h;
	int			w;
	int			lvl;
	char		symbol;
	char		enemy;
	int			**heat_map;
}				t_board;

typedef struct	s_piece
{
	int			width;
	int			height;
	int			lvl;
	char		**piece;
}				t_piece;

void			set_player(t_board **board, char *line);
int				parsing_data(t_board **board, t_piece **piece, char *line);
void			set_board(t_board **board, char *line);
void			set_piece(t_piece **piece, char *line);
int				parse_piece(t_piece **piece, char *line);
void			print_error(int code);
void			play(t_board *board, t_piece *piece);
void			markup_heatmap(t_board **board);
int				count_cells(t_board *board, t_piece *piece, int x, int y);
void			measure_distance(t_board ***board, int i, int j);
void			print_coordinates(t_board *board);
void			free_board_piece(t_board **board, t_piece **piece);
void			free_heatmap(t_board **board);

#endif
