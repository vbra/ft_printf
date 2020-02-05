/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:14 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 16:09:38 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int			ft_format(va_list args, char type, t_flags *flags)
{
	char	*stmp;

	(void)args;
	if (flags->width < 0)
	{
		flags->tiret = 1;
		flags->width = -flags->width;
	}
	if (type == '%')
		return(ft_display_c('%', flags));
	if (type == 'd' || type == 'i')
		return (ft_display_int(va_arg(args, int), flags));
	if (type == 'c')
		return (ft_display_c(va_arg(args, int), flags));
	if (type == 'u')
		ft_display_unsigned_int(va_arg(args, unsigned int), flags);
	if (type == 'p')
		ft_display_pointer(flags, va_arg(args, char *));
	if (type == 's')
	{
		stmp = va_arg(args, char *);
		return (ft_display_string((stmp == NULL) ? "(null)" : stmp, flags));
	}
	if (type == 'x')
		ft_display_hexa(flags, va_arg(args, char *));
	if (type == 'X')
		ft_display_hexamaj(flags, va_arg(args, char *));
	return (1);
}
