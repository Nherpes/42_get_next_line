/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:42:09 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/28 11:43:05 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h> //open include

#undef BUFFER_SIZE //redefining bytes to read from default
#define BUFFER_SIZE 5

char	*ft_full_line()

//don't forget NULL checks and FREE's
char	*get_next_line(int fd)
{
	void		*read_ptr;
	static char	*buffer;

	if (!fd || fd <= 2)
		return (NULL);
	read_ptr = malloc(BUFFER_SIZE * sizeof(char *));
	buffer = malloc(BUFFER_SIZE * sizeof(char *));
	read(fd, read_ptr, BUFFER_SIZE);
	printf("read: %s\n", (char *)read_ptr);
	printf("buff: %s\n\n", buffer);
	buffer += BUFFER_SIZE;
	return ("pengas");
}

int	main(void)
{
	//OPEN IS FORBIDDEN OUTSIDE MAIN
	int fd;
	fd = open("code.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
}
