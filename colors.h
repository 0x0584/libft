/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:59:49 by archid-           #+#    #+#             */
/*   Updated: 2020/01/26 01:05:48 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <stdbool.h>

# define COL_FG_BLACK		   "\x1b[30m"
# define COL_FG_RED			   "\x1b[31m"
# define COL_FG_GREEN		   "\x1b[32m"
# define COL_FG_YELLOW		   "\x1b[33m"
# define COL_FG_BLUE		   "\x1b[34m"
# define COL_FG_MAGENTA		   "\x1b[35m"
# define COL_FG_CYAN		   "\x1b[36m"
# define COL_FG_WHITE		   "\x1b[37m"

# define COL_BG_BLACK		   "\x1b[40m"
# define COL_BG_RED		       "\x1b[41m"
# define COL_BG_GREEN		   "\x1b[42m"
# define COL_BG_YELLOW		   "\x1b[43m"
# define COL_BG_BLUE		   "\x1b[44m"
# define COL_BG_MAGENTA	       "\x1b[45m"
# define COL_BG_CYAN		   "\x1b[46m"
# define COL_BG_WHITE		   "\x1b[47m"

# define COL_RESET			   "\x1b[0m"
# define COL_BOLD			   "\x1b[1m"
# define COL_DIM               "\x1b[2m"
# define COL_ITALIC            "\x1b[3m"
# define COL_UNDERLINE		   "\x1b[4m"
# define COL_BLINK			   "\xb[5m"

# define COLORS_BUFF_SIZE			11

enum					e_colors
{
	FG_BLACK, FG_RED, FG_GREEN, FG_YELLOW, FG_BLUE,
	FG_MAGENTA, FG_CYAN, FG_WHITE,

	BG_BLACK, BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE,
	BG_MAGENTA, BG_CYAN, BG_WHITE,

	RESET, BOLD, DIM, ITALIC, UNDERLINE, BLINK
};

typedef struct			s_color
{
	char *base;
	bool is_auto_reset;
}						t_color;

char					*get_color_name(enum e_colors col);

#endif
