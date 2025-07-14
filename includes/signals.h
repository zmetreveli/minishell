/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmetreve <zmetreve@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 01:00:12 by zmetreve          #+#    #+#             */
/*   Updated: 2025/07/14 22:52:31 by zmetreve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

//! Signals
void	signal_reset_prompt(int signo);
void	signal_print_newline(int signal);
void	set_signals_interactive(void);
void	set_signals_noninteractive(void);
void	ignore_sigquit(void);

#endif
