/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_type_idet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:00:35 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/07 12:58:24 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_map_type_idet(t_ident *ident)
{
	if (ident->type_ident_no)
		free(ident->type_ident_no);
	if (ident->type_ident_so)
		free(ident->type_ident_so);
	if (ident->type_ident_we)
		free(ident->type_ident_we);
	if (ident->type_ident_ea)
		free(ident->type_ident_ea);
}
