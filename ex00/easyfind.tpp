/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joeyscags <jcupp@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:00:00 by joeyscags         #+#    #+#             */
/*   Updated: 2026/02/24 16:40:59 by joeyscags        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	(void)container;
	(void)value;
	return container.end();
}

#endif
