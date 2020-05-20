/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:05:00 by cmeowth           #+#    #+#             */
/*   Updated: 2020/03/28 02:03:06 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	print_coordinates(t_board *board)
{
	ft_putnbr(board->h);
	ft_putchar(' ');
	ft_putnbr(board->w);
	ft_putchar('\n');
}
