//
// Created by ira on 09.04.2020.
//

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct	s_board
{
	char 		**board;
	int 		height;
	int 		width;
	int 		H;
	int 		W;
	int 		lvl;
	char 		symbol;
	char 		enemy;
	int 		**heat_map;
}				t_board;

typedef struct	s_piece
{
	int 		width;
	int			height;
	int 		lvl;
	char		**piece;
}				t_piece;

void		init(t_board **board, t_piece **piece);
void 		set_player(t_board **board, char *line);

int			parsing_data(t_board **board, t_piece **piece, char *line);
void		set_board(t_board **board, char *line);
void 		set_piece(t_piece **piece, char *line);
int			parse_piece(t_piece **piece, char *line);

void 		print_error(int code);

void 		play(t_board *board, t_piece *piece);
void 		markup_heatmap(t_board **board);
int 		count_cells(t_board *board, t_piece *piece, int x, int y);
void 		measure_distance(t_board ***board, int i, int j);

void		print_coordinates(t_board *board);

void		free_board(t_board **board);
void		free_piece(t_piece **piece);
void		free_heatmap(t_board **board);

#endif //FILLER_FILLER_H
