/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:36 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/21 15:40:42 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"

namespace ft{

	template<class Iter>
	class reverse_iterator : public std::iterator <
		typename iterator_traits<Iter>::iterartor_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference >{
		
		
		protected:
			Iter current;
			
		public:
			typedef Iter iterator_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::reference reference;
			typedef typename iterator_traits<Iter>::iterator_category iterator_category;

			reverse_iterator() : current() {}
			
			explicit reverse_iterator(Iter x) : current(x) {}

			template<class U>
			reverse_iterator(const reverse_iterator<U> &u) : current(u.base) {}
			
			Iter base()const { 
				return (current);
			}

			

	};
}

#endif
