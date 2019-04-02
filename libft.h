/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:32:57 by archid-           #+#    #+#             */
/*   Updated: 2019/04/02 05:36:41 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Standard headers
*/

# include <stdlib.h>

/*
** Types
*/

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

typedef enum	e_bool
{
	false = (1 == 0),
	true = !false
}				t_bool;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
** Memory related functions
*/

void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **mem);
void			ft_bzero(void *s, size_t n);

/*
** String related functions
*/

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dst, char *src);
char			*ft_strchr(const char *s, int c);
char			*ft_strncat(char *dst, char *src, size_t len);
char			*ft_strstr(char *s, char *to_find);
char			*ft_strnstr(char *s, char *tofind, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_iswhitespace(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);

/*
** Math related functions
 */

int				ft_power(int x, int y);
int				ft_atoi(const char *s);

#endif

/*
*****************************************************************************
**                            ..uu.									 	   **
**                           ?$""`?i           z'					 	   **
**                           `M  .@"          x"					 	   **
**                           'Z :#"  .   .    f 8M					 	   **
**                           '&H?`  :$f U8   <  MP   x#'			 	   **
**                           d#`    XM  $5.  $  M' xM"				 	   **
**                         .!">     @  'f`$L:M  R.@!`				 	   **
**                        +`  >     R  X  "NXF  R"*L				 	   **
**                            k    'f  M   "$$ :E  5.				 	   **
**                            %    `~  "    `  'K  'M				 	   **
**                                .uH          'E   `h				 	   **
**                             .x*`             X     `				 	   **
**                          .uf`                *					 	   **
**                        .@8     .									 	   **
**                       'E9F  uf"          ,     ,					 	   **
**                         9h+"   $M    eH. 8b. .8    .....			 	   **
**                        .8`     $'   M 'E  `R;'   d?"""`"#		 	   **
**                       ` E      @    b  d   9R    ?*     @		 	   **
**                         >      K.zM `%M'   9'    Xf   .f			 	   **
**                        ;       R'          9     M  .=`			 	   **
**                        t                   M     Mx~				 	   **
**                        @                  lR    z"				 	   **
**                        @                  `   ;"					 	   **
**                                            `						 	   **
*****************************************************************************
*/
