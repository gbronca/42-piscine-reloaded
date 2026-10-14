/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 10:27:19 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/09/22 10:51:46 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char *));

int	ft_count_if(char **tab, int (*f)(char *))
{
	int	i;
	int	count;

	if (!tab || !f)
		return (0);
	i = 0;
	count = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			++count;
		++i;
	}
	return (count);
}
