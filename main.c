/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:48:08 by mqueguin          #+#    #+#             */
/*   Updated: 2021/03/11 10:48:26 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
	{
		if (!(ft_init_parse(argv[1])))
			return (-1);
	}
	else
	{
		printf("Error\n");
		printf("Il doit y avoir 2 ou 3 parametres.");
	}
	return (0);
}
