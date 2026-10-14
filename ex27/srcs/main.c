/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcouto-b <gcouto-b@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:05:51 by gcouto-b          #+#    #+#             */
/*   Updated: 2026/09/22 18:59:46 by gcouto-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	display_file(char *name);

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		if (argc == 1)
			write(2, "File name missing.\n", 19);
		else
			write(2, "Too many arguments.\n", 20);
		return (1);
	}
	if (display_file(argv[1]) != 0)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	return (0);
}

int	display_file(char *name)
{
	ssize_t		data;
	char		buffer[1024];
	int			fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (-1);
	data = read(fd, buffer, sizeof(buffer));
	while (data > 0)
	{
		write(1, buffer, data);
		data = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
	if (data < 0)
		return (-1);
	return (0);
}
