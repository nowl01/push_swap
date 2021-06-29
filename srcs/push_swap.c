/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:15:37 by abdait-m          #+#    #+#             */
/*   Updated: 2021/06/29 10:55:04 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../header/push_swap.h"



void	_fill_stack_(t_ps *ps)
{
	int		i;
	long	tmp;

	i = 0;
	if((ps->size_a = ps->fsize - 1) == 1)
		exit(0);
	ps->array = malloc(sizeof(int) * ps->size_a);
	while (i < ps->size_a)
	{
		tmp = _atoi_mod_(ps->argv[i]);
		if (tmp > MAX_INT || tmp < MIN_INT)
			_exit_error_(ps);
		ps->array[i++] = tmp;
		_push_back_(&ps->s_a, tmp);
	}
	if (_check_dup_(&ps->s_a))
		_exit_error_(ps);
}

void	_the_start_(t_ps *ps)
{
	_fill_stack_(ps);
	if (!_already_sorted(ps))
		_sorting_the_stack_(ps);
}

void	_init_vars_(t_ps *ps)
{
	ps->array = NULL;
	ps->argv = NULL;
	ps->s_a = NULL;
	ps->s_b = NULL;
	ps->tmp = NULL;
}

int main(int argc, char **argv)
{
    t_ps *ps;
	
    ps = malloc(sizeof(t_ps));
	_init_vars_(ps);
	if (argc < 2 || _get_args_size(ps, argv, argc) || _get_args_(ps, argv, argc))
		_exit_error_(ps);
	_the_start_(ps);
	_clear_all_(ps);
    return (0);						
}
