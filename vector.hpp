/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:54:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/23 16:53:46 by tbrebion         ###   ########.fr       */
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
#include "utils/enable_if.hpp"
#include "utils/equal.hpp"
#include "utils/is_integral.hpp"
#include "utils/iterator_traits.hpp"
#include "utils/lexicographical_compare.hpp"
#include "utils/normal_iterator.hpp"
#include "utils/pair.hpp"
#include "utils/reverse_iterator.hpp"

namespace ft{
	
	template<typename Tp, typename Allocator = std::allocator<Tp>>
	class vector{

		public:
		
			typedef typename Allocator::value_type 			value_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef typename Allocator::reference 			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef typename Allocator::size_type 			size_type;
			typedef typename Allocator::difference_type 	difference_type;

			typedef ft::normal_iterator<pointer, vector> 		iterator;
			typedef ft::normal_iterator<const_pointer, vector> 	const_iterator;
			typedef ft::reverse_iterator<iterator>		 		reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			typedef Allocator		allocator_type;
			Allocator				vector_allocator;
			
		private:
		
			pointer	V_start;
			pointer	V_finish;
			pointer	V_end_of_storage;

		protected:	
		
			void	_Range_check(size_type n)const{
				
				if (n >= this->size()){

					throw std::out_of_range("Out of Range error : vector::_Range_check");
				}
			}
		
		public:
		
			vector() : V_start(NULL), V_finish(NULL), V_end_of_storage(NULL){
				
			}

			explicit vector(size_t n, const Tp &value = Tp()){
				
				this->V_start = vector_allocator.allocate(n);
				this->V_finish = this->V_start + n;
				this->V_end_of_storage = this->V_finish;	
				for (pointer x = this->V_start; n != 0; --n, ++x){

					vector_allocator.construct(x, value);
				}
			}

			vector(const vector &x){

				this->V_start = vector_allocator.allocate(x.end() - x.begin());
				pointer y = this->V_start;
				for (pointer z = x.V_start; z != x.V_finish; ++z, ++y){

					vector_allocator.construct(y, *z);
				}
				this->V_finish = y;
				this->V_end_of_storage = this->V_finish;
			}
			
			
	};
}

#endif
