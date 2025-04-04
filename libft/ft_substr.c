/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:22:40 by zmetreve          #+#    #+#             */
/*   Updated: 2024/10/07 08:57:36 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
/*
int main(void)
{
    char *s = "Hola, ¿como estás?";
    unsigned int start = 6; // El índice de donde comienza la substring
    size_t len = 4; // La longitud máxima de la substring
    char *substr;

    // Llamada a ft_substr para obtener la substring
    substr = ft_substr(s, start, len);

    if (substr != NULL)
    {
        printf("La substring es: %s\n", substr);
        free(substr); // No olvides liberar la memoria asignada con malloc
    }
    else
    {
        printf("Error al crear la substring\n");
    }

    return (0);
}*/
