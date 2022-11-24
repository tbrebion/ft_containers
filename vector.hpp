/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:54:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/24 17:58:59 by tbrebion         ###   ########.fr       */
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

			vector(const vector<Tp> &x){

				this->V_start = vector_allocator.allocate(x.end() - x.begin());
				pointer y = this->V_start;
				for (pointer z = x.V_start; z != x.V_finish; ++z, ++y){

					vector_allocator.construct(y, *z);
				}
				this->V_finish = y;
				this->V_end_of_storage = this->V_finish;
			}
			
			template<InputIterator>
			vector(InputIterator first, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InpuIterator>::type last,
					const Allocator& = Allocator()){

				this->V_start = vector_allocator.allocate(ft::distance(first, last));
				pointer x = this->V_start;
				for ( ; first != last; ++first, ++x){

					vector_allocator.construct(x, *first);
				}
				this->V_finish = x;
				this->V_end_of_storage = this->V_finish;
			}
			
			vector	&operator=(const vector &x){

				if (this == &x){
					
					return (*this);
				}
				clear();
				vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
				pointer tmp = vector_allocator.allocate(x.size());
				pointer y = tmp;
				for (const_iterator it = x.begin(); it != x.end(); ++it, ++y){

					vector_allocator.construct(y, *it);
				}
				this->V_start = tmp;
				this->V_finish = tmp + x.size();
				this->V_end_of_storage = tmp + x.capacity();
				return (*this);
			}

			~vector(){

				clear();
				vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
			}
			
			iterator	begin(){

				return (iterator(this->V_start));
			}
			
			const_iterator	begin()const{

				return (const_iterator(this->V_start));
			}

			iterator	end(){

				return (iterator(this->V_finish));
			}

			const_iterator	end()const{

				return (const_iterator(this->V_finish));
			}

			reverse_iterator	rbegin(){

				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin()const{

				return (const_reverse_iterator(end()));
			}
			
			reverse_iterator	rend(){

				return (reverse_iterator(begin()));
			}
			
			const_reverse_iterator	rend()const{

				return (const_reverse_iterator(begin()));
			}

			size_type	size()const{

				return (size_type(this->V_finish - this->V_start));
			}

			size_type	max_size()const{

				return (vector_allocator.max_size());
			}

			size_type	capacity()const{

				return (this->V_end_of_storage - V_start);
			}

			bool	empty()const{

				return (this->V_start == this->V_finish);
			}

			void	reserve(size_type n){

				if (n > max_size()){

					return;
				}
				if (n > capacity()){

					pointer x = vector_allocator.allocate(n);
					pointer y = x;
					for (pointer ptr = this->V_start; ptr != this->V_finish; ++ptr, ++y){

						vector_allocator.construct(y, *ptr);
					}
					clear();
					vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
					this->V_start = x;
					this->V_finish = y;
					this->V_end_of_storage = this->V_start + n;
				}
			}

			void	resize(size_type n, value_type val = value_type()){

				if (n < size()){

					for (pointer i = this->V_start + n; i != this->V_finish; ++i){
						
						vector_allocator.destroy(i);
					}
					this->V_finish = this->V_start + n;
				}
				else if (n > size()){

					insert(end(), n - size(), val);
				}
			}

			reference	operator[](size_type n){

				return (*(this->V_start + n));
			}
						
			const_reference	operator[](size_type n)const{

				return (*(this->V_start + n));
			}

			reference	at(size_type n){

				_Range_check(n);
				return ((*this)[n]);
			}
			
			const_reference		at(size_type n)const{

				_Range_check(n);
				return ((*this)[n]);
			}
			
			reference	front(){

				return (*begin());
			}
			
			const_reference	front()const{

				return (*begin());
			}
			
			reference	back(){

				return (*(end() - 1))
			}
			
			const_reference		back()const{

				return (*(end() - 1))
			}

			iterator	erase(iterator position){

				if (position + 1 != end()){

					for (pointer x = position.base() + 1, y = position.base(); x != this->V_finish; ++x, ++y){

						*y = *x;
					}
				}
				vector_allocator.destroy(--this->V_finish);
				return (position);
			}

			iterator	erase(iterator first, iterator last){

				pointer pos = fisrt.base();
				for (pointer pos2 = last.base(); pos2 != this->V_finish; ++pos2, ++pos){

					*pos = *pos2;
				}
				pointer ptr = pos;
				while (pos != this->V_finish){
				
					vector_allocator.destroy(ptr++);
				}
				this->V_finish = this->V_finish - (ptr - pos);
				return (first);
			}

			void	assign(size_type n, const value_type &val){

				clear();
				if (n > capacity()){

					pointer x = vector_allocator.allocate(n);
					pointer y = x;
					vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
					while (n--){

						vector_allocator.construct(y++, val);
					}
					this->V_start = x;
					this->V_finish = y;
					this->V_end_of_storage = this->V_finish;
				}
				else{
				
					for (size_type i = 0; i != n; ++i){

						vector_allocator.construct(this->V_start + i, val);
					}
					this->V_finish += n;
				}
			}
	};
}

#endif
