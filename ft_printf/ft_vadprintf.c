#include "format.h"

int		ft_vadprintf(const int fd, const char *fmt, va_list args_base)
{
	va_list args;
	t_buff	*buff;
	t_list	*lstfrmt;
	int		n_chars;

	if (!(buff = buff_alloc(0x20)))
		return (-1);
	lstfrmt = NULL;
	n_chars = 0;
	ft_memcpy(args, args_base, sizeof(va_list));
	format_parse(fmt, &lstfrmt);
	format_populate(&lstfrmt, &args);
	n_chars = format_to_buff(lstfrmt, buff);
	ft_lstdel(&lstfrmt, format_free);
	if (n_chars >= 0)
		n_chars += buff_write(fd, buff);
	buff_free(&buff);
	return (n_chars);
}
