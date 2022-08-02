/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfredun <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:14:58 by msindreu          #+#    #+#             */
/*   Updated: 2022/08/02 18:56:40 by msindreu         ###   ########.fr       */
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

char	*ft_clean(char *new_guardado)
{
	char *rest;
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (new_guardado[i] != '\n' && new_guardado[i] != '\0')
	{
		i++;
	}
	if(new_guardado[i] == '\0')
	{
		free(new_guardado);
		return(NULL);
	}
	rest = ft_substr(new_guardado, i + 1, ft_strlen(new_guardado));
	if (!rest)
	{
		return (NULL);
	}
	free(new_guardado);
	return (rest);
}

char *fill_static_save_var(int fd, char *new_guardado)
{
	char	*buffer;
	int		readed_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	readed_bytes = 1;

	while (!ft_strchr(buffer, '\n') && readed_bytes > 0)
	{
		readed_bytes = read(fd, buffer, BUFFER_SIZE);
		if (readed_bytes > 0)
		{
			buffer[readed_bytes] = '\0';
			new_guardado = ft_strjoin(new_guardado, buffer);
		}
	}
	free(buffer);
	if (readed_bytes == -1)
	{
		free(new_guardado);
		return (NULL);
	}
	return(new_guardado);
}

char	*get_next_line(int fd)
{	
	static char	*new_guardado = NULL;
	char	*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	if(!new_guardado || (new_guardado && !ft_strchr(new_guardado, '\n')))
		new_guardado = fill_static_save_var(fd, new_guardado);
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
