/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_node_blob.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: archid- <archid-@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:46:42 by archid-           #+#    #+#             */
/*   Updated: 2020/12/18 11:47:04 by archid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

void		blob_free(void *blob)
{
	free(blob);
}

void		blob_keep(void *blob)
{
	(void)blob;
}

void		*blob_identity(void *blob)
{
	return (blob);
}
