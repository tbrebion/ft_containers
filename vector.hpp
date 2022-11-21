/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:54:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/21 15:11:02 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <limits>
#include <memory>
#include <stdexcept>
#include <utility>


namespace ft{
	
	template< class T, class Allocator = std::allocator<T> >
	class vector{

		public:
			typedef T value_type;
			typedef Allocator allocator_type;
			typedef typename allocator_type::size_type size_type;
			typedef typename allocator_type::difference_type difference_type; 
			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;
			typedef wrap_iter<pointer> iterator;
			typedef wrap_iter<const_pointer> const_iterator;
			
	};	
}

#endif
