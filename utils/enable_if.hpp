/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:35:00 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/21 17:39:50 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft{

	template<bool B, typename T = void>
	struct enable_if{
		
	};

	template<typename T>
	struct	enable_if<true, T>{

		typedef T type;
	};
}

#endif
