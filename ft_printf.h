/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auhoris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:40:09 by auhoris           #+#    #+#             */
/*   Updated: 2020/11/20 13:00:10 by auhoris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define FLAGS "-+ 0#"
# define IS_NUM(x) (x >= '0' && x <= '9')
# define SPECIFIER "cspdiuxX%"
# define LEN_MOD "lh"

# define OFF -1
# define ON 1
# define ERROR -1
# define ZERO 0
# define HEX_ON 2

typedef struct	s_args
{
	va_list		ap;
	const char	*format;
	char		*f_cpy;
	int			left_align;
	int			printed;
	int			read;
	int			width;
	int			prec;
	int			zero_f;
	int			plus_f;
	int			minus_f;
	int			space_f;
	int			hex_f;
	char		filler;
	char		sign;
	int			len_mod;
	char		*res;
}				t_args;

typedef struct	s_fill
{
	char	*width;
	char	*prec;
}				t_fill;

int				ft_printf(char *format, ...);
int				ft_inset(char *set, char c);
int				ft_start_parsing(t_args *par);
int				ft_disp_char(t_args *par);
char			*ft_make_filler(int size, char fill);
int				ft_disp_str(t_args *par);
int				ft_disp_int(t_args *par);
char			*ft_set_sign(t_args *par, char *filler, int str_len);
char			*ft_check_sign(t_args *par, char *str);
int				ft_prep_u(t_args *par);
int				ft_disp_u(t_args *par);
int				ft_disp_p(t_args *par);
int				ft_disp_percent(t_args *par);
char			*ft_itoa_ll(long long n);
int				ft_prep_int(t_args *par);
void			free_filler(t_fill *fill);
t_fill			*ft_init_fill();

#endif
