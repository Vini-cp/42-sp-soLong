/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcordeir <vcordeir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:09:46 by vcordeir          #+#    #+#             */
/*   Updated: 2021/11/21 20:45:30 by vcordeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static	char	*create_flag_array(const char *fmt)
{
	int		i;
	char	*s;

	i = 0;
	while (ft_printf_isflag(fmt[i]) || ft_isdigit(fmt[i]))
		i++;
	s = ft_substr(fmt, 0, i);
	return (s);
}

static	int	check_specifier(const char **fmt)
{
	if (!*(*fmt + 1))
		return (0);
	*fmt += 1;
	return (1);
}

static	int	iter(const char **fmt, t_flags **node, va_list args, int *i)
{
	if (ft_isdigit(**fmt) || ft_printf_isflag(**fmt))
	{
		ft_printf_get_flag(create_flag_array(*fmt), args, &node);
		ft_printf_empty_zeros(&node);
		*fmt += ft_strlen(create_flag_array(*fmt));
		if (!**fmt)
			return (0);
		to_string(*fmt, args, &node);
		if ((*node)->c == ' ' || (*node)->c == 'c' || (*node)->c == 'u')
			*i += ft_printf_print(*node);
		else
			*i += ft_printf_print_p_str(*node);
	}
	else
	{
		to_string(*fmt, args, &node);
		if ((*node)->c == ' ' || (*node)->c == 'c' || (*node)->c == 'u')
			*i += ft_printf_print(*node);
		else
			*i += ft_printf_print_p_str(*node);
	}
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_flags		*node;
	int			i;

	i = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		node = ft_printf_newflag();
		if (*fmt == '%')
		{
			if (!check_specifier(&fmt))
				return (i);
			if (*fmt == '%')
				i += ft_printf_putchar(*fmt);
			else if (!iter(&fmt, &node, args, &i))
				return (i);
			fmt += 1;
		}
		else
			i += ft_printf_putchar(*(fmt++));
	}
	va_end(args);
	return (i);
}
