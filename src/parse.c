/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:09:02 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/14 12:27:20 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int		ft_intlen(int nb)
{
	int ret;

	ret = 1;
	if (nb < 0)
		ret++;
	while ((nb = nb / 10))
		ret++;
	return (ret);
}

static void		fill_line(char *line, t_dot *tab, int y)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			tab[x].z = ft_atoi(&line[i]);
			tab[x].x = x;
			tab[x].y = y;
			i += ft_intlen(ft_atoi(&line[i])) - 1;
			x++;
		}
		i++;
	}
}

static int		count_x(char *line)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			ft_putendl("Invalid file : hexa not supported");
			exit(FAILED);
		}
		if (ft_isdigit(line[i]) || line[i] == '-')
		{
			i += ft_intlen(ft_atoi(&line[i])) - 1;
			x++;
		}
		i++;
	}
	return (x);
}

static void		count_y(char *str, int *x, int *y)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		*x = count_x(line);
		*y = *y + 1;
		free(line);
	}
	close(fd);
}

t_dot			**ft_parse_tab(t_fdf *af, char **av)
{
	int		i;
	int		fd;
	char	*line;

	af->len_x = 0;
	af->len_y = 0;
	count_y(av[1], &(af->len_x), &(af->len_y));
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putendl("Error opening");
		exit(FAILED);
	}
	if ((af->tab = (t_dot **)malloc(sizeof(t_dot *) * af->len_y)) == NULL)
		exit(FAILED);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if ((af->tab[i] = (t_dot *)malloc(sizeof(t_dot) * af->len_x)) == NULL)
			exit(FAILED);
		fill_line(line, af->tab[i], i);
		i++;
		free(line);
	}
	close(fd);
	return (af->tab);
}
