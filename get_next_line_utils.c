#include "get_next_line.h"


// size_t	ft_strjoin_getsize_including_if_no_string(char *s)
// {
// 	size_t	size;
// 	if (s)
// 		size = ft_strlen(s);
// 	else
// 		size = 0;
// 	return (size);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	size_t	size_s1;
// 	size_t	size_s2;
// 	size_t	count;
// 	char	*ptr;
// 	if (!s1)
// 	{
// 		s1 = (char *)malloc(1 * sizeof(char));
// 		s1[0] = '\0';
// 	}
// 	count = 0;
// 	size_s1 = ft_strlen(s1);
// 	size_s2 = ft_strjoin_getsize_including_if_no_string(s2);
// 	ptr = malloc(sizeof(char) * (size_s1 + size_s2 +1));
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (count++ < size_s1)
// 		ptr[count -1] = s1[count -1];
// 	count = 0;
// 	while (count++ < size_s2)
// 		ptr[size_s1 + count -1] = s2[count -1];
// 	ptr[size_s1 + count -1] = '\0';
// 	free(s1);
// 	return (ptr);
// }

char	*ft_strjoin(char *s1, char *s2)
{
	char		*nstr;
	size_t		i;

	i = 0;
	if(!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if(!s1)
			return(NULL);
		s1[0] = '\0';
	}
	nstr = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!nstr)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		nstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		nstr[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	nstr[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (nstr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	else
		return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if (ft_strlen(s) <= start || len == 0 || ft_strlen(s) == 0)
		size = 0;
	else if (len <= ft_strlen(s) && start + len < ft_strlen(s))
		size = len;
	else
		size = ft_strlen(s) - start;
	subs = (char *) malloc(size + 1);
	if (subs == NULL)
		return (0);
	*subs = '\0';
	if (start < ft_strlen(s))
	{
		while (i < size)
		{
			subs[i] = s[start + i];
			i++;
		}
		subs[i] = '\0';
	}
	return (subs);
}

