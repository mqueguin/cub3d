/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:46:07 by mqueguin          #+#    #+#             */
/*   Updated: 2020/09/10 15:07:10 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		negative;
	long	result;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		(str[i++] == '-') ? negative *= -1 : negative;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + ((int)str[i++] - '0');
	if (result < 0 && (negative == 1))
		return (-1);
	else if (result < 0 && (negative == -1))
		return (0);
	return (result * negative);
}
