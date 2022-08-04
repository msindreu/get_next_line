/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfredun <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:58 by msindreu          #+#    #+#             */
/*   Updated: 2022/08/04 18:07:51 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_get_line(char *str)
{
	char	*line;
	int 	i;

	i = 0;
	if(!str[0])
		return(NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if(str[i] == '\n')
		i++;
	line = ft_substr(str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_clean(char *str)
{
	char *rest;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	if(str[i] == '\0')
	{
		free(str);
		return(NULL);
	}
	rest = ft_substr(str, i + 1, ft_strlen(str));
	if (!rest)
	{
		return (NULL);
	}
	free(str);
	return (rest);
}

char *ft_reading(int fd, char *str)
{
	char	*buffer;
	int		bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	bytes = 1;
	while (!ft_strchr(buffer, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			str = ft_strjoin(str, buffer);
		}
	}
	free(buffer);
	if (bytes == -1)
	{
		free(str);
		return (NULL);
	}
	return(str);
}

char	*get_next_line(int fd)
{	
	static char	*new_guardado = NULL;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	if(!new_guardado || (new_guardado && !ft_strchr(new_guardado, '\n')))
		new_guardado = ft_reading(fd, new_guardado);
	if(new_guardado == NULL)
		return(NULL);
	line = ft_get_line(new_guardado);
	if(!line)
	{
		free(new_guardado);
		return(NULL);
	}
	new_guardado = ft_clean(new_guardado);
	return (line);
}
