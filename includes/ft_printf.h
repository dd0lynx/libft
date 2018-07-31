/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddowty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 15:07:00 by ddowty            #+#    #+#             */
/*   Updated: 2016/12/23 15:07:02 by ddowty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct		s_txt_mod
{
	int				color;
	int				c256;
	int				bold;
	int				italic;
	int				underline;
	int				open;
}					t_txt_mod;

typedef struct		s_form
{
	int				f_just;
	int				f_plus;
	int				f_space;
	int				f_alt;
	int				f_zero;
	int				f_toupper;
	int				lmod_h;
	int				lmod_hh;
	int				lmod_l;
	int				lmod_ll;
	int				lmod_j;
	int				lmod_z;
	int				lmod_t;
	int				lmod_ldouble;
	int				min_w;
	int				precision;
	char			d_type;
	t_txt_mod		t_mod;
	char			*buff;
	int				count;
}					t_form;

int					reset_arg(char *arg, int i, t_txt_mod *t_mod);
int					set_color(char *arg, int i, t_txt_mod *t_mod);
int					set_format(char *arg, int i, t_txt_mod *t_mod);
int					valid_mod(const char *format, t_txt_mod *t_mod);
char				*convert_txt_mod(const char *format, t_form *fp);
int					convert_n(char **str, t_form *fp, va_list *va);
int					convert_char(char **str, t_form *fp, va_list *va);
int					convert_str(char **str, t_form *fp, va_list *va);
int					convert_ptr(char **str, t_form *fp, va_list *va);
int					convert_uint(char **str, t_form *fp, va_list *va);
int					convert_int(char **str, t_form *fp, va_list *va);
int					convert_wildcard(t_form *fp, va_list *va, int precision);
int					convert_arg(t_form *fp, va_list *va);
int					pad_str(char **str, int len, t_form *fp);
int					get_length(const char *format, t_form *fp);
char				*get_form(const char *format, t_form *fp, va_list *va);
int					ft_printf(const char *format, ...);
#endif
