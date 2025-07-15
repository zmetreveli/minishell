/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:10:33 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/15 23:16:27 by jbusom-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//! args_echo_utils.c
char		*join_vars(t_token **token_node);
int			count_args(t_token *temp);
char		**copy_in_new_tab(int len, char **new_tab,
				t_command *last_cmd, t_token *tmp);
void		remove_empty_var_args(t_token **tokens);

//! args_echo.c
int			add_args_echo_mode(t_token **token_node, t_command *last_cmd);
int			create_args_echo_mode(t_token **token_node, t_command *last_cmd);

//! args.c
int			count_arguments(t_token *temp);
int			fill_args(t_token	**token_node, t_command *last_cmd);
int			add_args_default_mode(t_token **token_node, t_command *last_cmd);
int			create_args_default_mode(t_token **token_node, t_command *last_cmd);

//! cleanup
void		lst_delone_cmd(t_command *lst, void (*del)(void *));
void		lst_clear_cmd(t_command **lst, void (*del)(void *));

//! commands
void		create_commands(t_data *data, t_token *token);

//! heredoc_utils
bool		fill_heredoc(t_data *data, t_io_fds *io, int fd);

//! heredoc.c
void		parse_heredoc(t_data *data, t_command **last_cmd,
				t_token **token_lst);
bool		get_heredoc(t_data *data, t_io_fds *io);

//! parce_word
void		parse_word(t_command **cmd, t_token **token_lst);

//! parcer.c
t_command	*lst_new_cmd(bool value);
t_command	*lst_last_cmd(t_command *cmd);
void		lst_add_back_cmd(t_command **alst, t_command *new_node);

//! parse_append.c
void		parse_append(t_command **last_cmd, t_token **token_lst);

//! parse_input.c
bool		remove_old_file_ref(t_io_fds *io, bool infile);
void		parse_input(t_command **last_cmd, t_token **token_lst);

//! pipe
void		parse_pipe(t_command **cmd, t_token **token_lst);

//! trunc
void		parse_trunc(t_command **last_cmd, t_token **token_lst);
char		*get_relative_path(char *file_to_open);

#endif
