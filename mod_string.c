/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoole <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 19:03:25 by spoole            #+#    #+#             */
/*   Updated: 2019/05/25 23:37:49 by spoole           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			mod_string_char(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = NULL;
	if (mod->frmt_spec != '%')
		arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->frmt_spec == 'c' || mod->frmt_spec == 'C')
	{
		mod->arg_text = ft_strnew(1);
		mod->arg_text[0] = (char)arg->data.vdata;
	}
	else if (arg != NULL && arg->data.vdata == NULL)
		mod->arg_text = "(null)";
	else if (mod->frmt_spec != '%')
		mod->arg_text = (char*)arg->data.vdata;
	if (mod->precision != -1 && mod->arg_text[0] != '%'\
	&& mod->frmt_spec != 'c')
		string_precision(mod);
	if (mod->frmt_spec == 'c' && mod->arg_text[0] == '\0' && mod->min_wid == 0)
		print_zero(info);
	else
	{
		set_string(mod);
		add_string(info, mod->res);
	}
}

void			mod_string_signed(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->len_mod[0] == '0')
		mod->arg_text = ft_itoa((int)arg->data.vdata);
	else if (mod->len_mod[0] == 'l')
	{
		if (mod->len_mod[1] == 'l')
			mod->arg_text = ft_itoa((long long)arg->data.vdata);
		else
			mod->arg_text = ft_itoa((long)arg->data.vdata);
	}
	else if (mod->len_mod[0] == 'h')
	{
		if (mod->len_mod[1] == 'h')
			mod->arg_text = ft_itoa((signed char)arg->data.vdata);
		else
			mod->arg_text = ft_itoa((short)arg->data.vdata);
	}
	else if (mod->len_mod[0] == 'j' || mod->len_mod[0] == 'z')
		mod->arg_text = ft_itoa((intmax_t)arg->data.vdata);
	else
		return ;
	finish_signed(info, mod);
}

void			mod_string_unsigned(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->frmt_spec == 'o')
		mod->arg_text = unsigned_len_mod(arg, mod, 8);
	else if (mod->frmt_spec == 'u')
		mod->arg_text = unsigned_len_mod(arg, mod, 10);
	else if (mod->frmt_spec == 'x' || mod->frmt_spec == 'X')
		mod->arg_text = unsigned_len_mod(arg, mod, 16);
	if (mod->frmt_spec == 'x')
		lower(mod->arg_text);
	signed_prec(mod);
	set_string(mod);
	if (mod->flags && mod->flags->hash == '1' && (mod->frmt_spec == 'x'\
		|| mod->frmt_spec == 'X'))
		add_x(mod);
	add_string(info, mod->res);
}

void			mod_string_point(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	mod->len_mod[0] = 'l';
	mod->arg_text = unsigned_len_mod(arg, mod, 16);
	lower(mod->arg_text);
	if (mod->precision == 0 && mod->arg_text != NULL)
	{
		free(mod->arg_text);
		mod->arg_text = NULL;
	}
	else if (mod->precision != -1)
		signed_prec(mod);
	set_string(mod);
	add_x(mod);
	add_string(info, mod->res);
	if (mod->arg_text && mod->arg_text[0] != '\0')
		free(mod->arg_text);
}

void			mod_string_float(t_printf *info, t_mod *mod)
{
	t_arg_node	*arg;

	arg = find_arg(info->arg_begin, mod->arg_num);
	if (mod->precision == -1)
		mod->precision = 6;
	if (mod->len_mod[0] == 'L')
		mod->arg_text = ft_ftoa(arg->data.ld, mod->precision);
	else
		mod->arg_text = ft_ftoa(arg->data.flt, mod->precision);
	if (mod->flags && mod->flags->plus == '1')
		add_plus(mod);
	if (mod->flags)
		signed_prec(mod);
	set_string(mod);
	add_string(info, mod->res);
}
