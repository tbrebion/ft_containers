/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:57 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/09 18:23:57 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../vector.hpp"

namespace ft{

	template<typename T, typename node, typename compare, typename tree>
	class map_iterator : std::iterator<std::bidirectional_iterator_tag, T>{

		public:
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::difference_type difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::pointer pointer;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::reference reference;
			
			map_iterator() : _nd(), _tree(), _cmp() {}
			map_iterator(node *nd, tree *tr) : _nd(nd), _tree(tr) {}

		private:
			node		*_nd;
			const tree 	*_tree;
			compare		*_cmp
	};
}

#endif
