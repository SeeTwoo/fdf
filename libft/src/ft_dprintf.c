/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeschon <wbeschon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:52:15 by wbeschon          #+#    #+#             */
/*   Updated: 2025/03/05 12:39:51 by wbeschon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	parsing(char *format, char *buff, int ret, va_list arg)
{
	buff += ret;
	if (*format && *format != '%')
		return (strlcpy
}

int	ft_dprintf(int fd, char const *format, ...)
{
	int		ret;
	int		offset;
	char	buff[1024];
	va_list	arg;

	if (!format)
		return (-1);
	va_start(arg, format);
	ret = 0;
	while (*format)
	{
		offset = parsing(format, buff, ret, arg);
		if (offset == -1)
			return (-1);
		format += offset;
		ret += offset;
	}
	write(fd, buff, ret);
	return (ret);
}
