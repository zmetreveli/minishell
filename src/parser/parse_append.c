/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 23:24:47 by zmetreve          #+#    #+#             */
/*   Updated: 2025/04/21 23:27:43 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* open_outfile_append:
*	Abre un archivo de salida en modo append. Si ya había un archivo de salida
*	definido, lo libera y lo reemplaza. Si falló previamente la apertura de
*	un archivo de entrada o salida (porque no existe o por permisos), 
*	no intenta abrir ningún otro archivo de salida.
*
*	Ejemplos:
*		echo hola > archivo_prohibido >> test
*		echo hola >> archivo_prohibido >> test
*		< archivo_prohibido cat >> test
*	En estos tres casos, el archivo "test" no debería abrirse ni crearse.
*/

static void	open_outfile_append(t_io_fds *io, char *file, char *var_filename)
{
if (!remove_old_file_ref(io, false))
    return ;
io->outfile = ft_strdup(file);
if (io->outfile && io->outfile[0] == '\0' && var_filename)
{
    errmsg_cmd(var_filename, NULL, "ambiguous redirect", false);
    return ;
}
io->fd_out = open(io->outfile, O_WRONLY | O_CREAT | O_APPEND, 0664);
if (io->fd_out == -1)
    errmsg_cmd(io->outfile, NULL, strerror(errno), false);
}

/************ APPEND ************
** Redirección de salida en modo "append" (agregar).
** Hace que el archivo cuyo nombre resulta de la expansión de la palabra
** se abra para agregar contenido (append) en el descriptor de archivo n,
** o en la salida estándar (fd 1) si no se especifica n.
** Si el archivo no existe, se crea.
**
** El formato general para redirección con append es: [n]>>cualquerPalabra.
*/

void	parse_append(t_command **last_cmd, t_token **token_lst)
{
t_token		*temp;
t_command	*cmd;

temp = *token_lst;
cmd = lst_last_cmd(*last_cmd);
init_io(cmd);
open_outfile_append(cmd->io_fds, temp->next->str, temp->next->str_backup);
if (temp->next->next)
    temp = temp->next->next;
else
    temp = temp->next;
*token_lst = temp;
}