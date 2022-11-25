/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:30:45 by achansar          #+#    #+#             */
/*   Updated: 2022/11/25 14:12:05 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_data {

    void    *mlx;
    void    *win;
}   t_data;

/*typedef struct s_data {
    
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}   t_data;
*/


int drawline(t_data set, int x0, int y0, int x1, int y1, int color);

/*----LIBFT------*/
char	*get_next_line(int fd);
char	*ft_strdup_gnl(char *s1);
int		ft_strlen(char *s);
int		ft_isin(char *str, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	*ft_free_all(char *s1, char **s2);

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);

#endif