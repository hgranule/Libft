/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgranule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:41:18 by hgranule          #+#    #+#             */
/*   Updated: 2019/09/15 06:05:42 by hgranule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "libft_hidden.h"

static inline void		cpy_bytes(t_byte **dst, t_byte **src, size_t n)
{
	while (n)
	{
		**dst = **src;
		++(*dst);
		++(*src);
		--n;
	}
}

static inline void		cpy_words(t_lword **dst, t_lword **src, size_t n)
{
	while (n)
	{
		**dst = **src;
		++(*dst);
		++(*src);
		--n;
	}
}

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	t_lword	*dst_l;
	t_lword	*src_l;
	size_t	tmp;

	dst_l = (t_lword *)dst;
	src_l = (t_lword *)src;
	if (dst_l == src_l)
		return (dst);
	if (len >= LWORD_SIZE)
	{
		tmp = LWORD_SIZE - ((size_t)dst_l & 0x07);
		cpy_bytes((t_byte **)&dst_l, (t_byte **)&src_l, tmp);
		len -= tmp;
		tmp = len / LWORD_SIZE;
		cpy_words((t_lword **)&dst_l, (t_lword **)&src_l, tmp);
		len -= tmp * LWORD_SIZE;
	}
	cpy_bytes((t_byte **)&dst_l, (t_byte **)&src_l, len);
	return (dst);
}
