#include "../../ft_printf.h"

void	ft_display_pointer(t_flags *flags, char *pt)
{
	__uint64_t	read;
	int			width;
	int 		tmp_w;
	int			tmp_p;

	tmp_w = 0;
	tmp_p = 0;
	read = (__uint64_t)pt;
	width = ft_width_nb_64(read);
	if (read)
	{
		if (flags->width <= flags->precision 
		&& flags->precision > width)
			tmp_p = flags->precision - width;
		if (flags->width >= flags->precision 
		&& flags->precision > width)
		{
			tmp_w = flags->width - flags->precision - 2;
			tmp_p = flags->precision - width;
		}
		if ((flags->width && flags->precision == 0) ||
		(flags->width >= flags->precision))
			tmp_w = flags->width - width - 2;
		if (flags->width > flags->precision && flags->width > width
		&& flags->precision > width)
		{
			tmp_w = flags->width - flags->precision - 2;
		}
		if (flags->tiret == 0)
			while (tmp_w-- > 0)
				ft_putchar_fd(' ', 2);
		ft_putstr_fd("0x", 2);
		if (flags->percent != 2)
			while (tmp_p-- > 0)
				ft_putchar_fd('0', 2);
		ft_putpointer_fd(read, 2);
		if (flags->tiret && flags->percent != 2)
			while (tmp_w-- > 0)
				ft_putchar_fd(' ', 2);
	}
	else
	{
		if (flags->tiret == 0)
			while (tmp_w-- > 0)
				ft_putchar_fd(' ', 2);
		if (pt != NULL)
			ft_putstr_fd("0x", 2);
		if (flags->percent != 2)
			while (tmp_p-- > 0)
				ft_putchar_fd('0', 2);
		ft_putstr_fd("(nil)", 2);
		if (flags->tiret && flags->percent != 2)
			while (tmp_w-- > 0)
				ft_putchar_fd(' ', 2);
	}
}