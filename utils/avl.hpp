/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:09:59 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/12 19:12:15 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
#define AVL_HPP

#include "../vector.hpp"
#include "map_iterator.hpp"

namespace ft{

	template<typename T, typename Compare = std::less<typename T::first_type>, typename Allocator = std::allocator<T> >
	class avl{

		public:
			typedef T value_type;
			typedef ft::avlNode<const T> const_node;
			typedef Allocator pair_alloc;
			
	};
}

#endif
