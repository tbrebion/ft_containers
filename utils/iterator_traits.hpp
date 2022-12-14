/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:08:41 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/23 12:11:47 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iterator>

namespace ft{

	template <typename Iter>
	struct iterator_traits{

		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer 				pointer;
		typedef typename Iter::reference 			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};
	
	template <typename T>
	struct iterator_traits<T*>{
		
		typedef std::ptrdiff_t	difference_type;
		typedef T	value_type;
		typedef T	*pointer;
		typedef	T	&reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};
	
	template <typename T>
	struct iterator_traits<const T*>{
		
		typedef std::ptrdiff_t	difference_type;
		typedef const T	value_type;
		typedef const T	*pointer;
		typedef	const T	&reference;
		typedef std::random_access_iterator_tag	iterator_category;
	};
	
}

#endif
