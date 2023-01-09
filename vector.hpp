/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:54:23 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/09 17:50:36 by tbrebion         ###   ########.fr       */
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
#include "utils/utils.hpp"

namespace ft{
	
	template<typename Tp, typename Allocator = std::allocator<Tp> >
	class vector{

		public:
		
			typedef typename Allocator::value_type 			value_type;
			typedef typename Allocator::pointer 			pointer;
			typedef typename Allocator::const_pointer 		const_pointer;
			typedef typename Allocator::reference 			reference;
			typedef typename Allocator::const_reference 	const_reference;
			typedef typename Allocator::size_type 			size_type;
			typedef typename Allocator::difference_type 	difference_type;

			typedef ft::normal_iterator<pointer> 		iterator;
			typedef ft::normal_iterator<const_pointer> 	const_iterator;
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
			
			template<typename InputIterator>
			vector(InputIterator first, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
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
				size_type cap_tmp = this->capacity();
				vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
				pointer tmp = vector_allocator.allocate(cap_tmp > x.capacity() ? cap_tmp : x.capacity());
				pointer y = tmp;
				for (const_iterator it = x.begin(); it != x.end(); ++it, ++y){

					vector_allocator.construct(y, *it);
				}
				this->V_start = tmp;
				this->V_finish = tmp + x.size();
				this->V_end_of_storage = (tmp + cap_tmp) > (tmp + x.capacity()) ? (tmp + cap_tmp) : (tmp + x.capacity());
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

			class	reserveException : public std::exception{

				public:
					const char* what() const throw(){

						return ("vector::reserve");
					}
			};

			void	reserve(size_type n){

				if (n > max_size()){

						throw reserveException();
						// std::cout << "length error" << std::endl;
						// return;
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

				return (*(end() - 1));
			}
			
			const_reference		back()const{

				return (*(end() - 1));
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

				pointer pos = first.base();
				for (pointer pos2 = last.base(); pos2 != this->V_finish; ++pos2, ++pos){

					*pos = *pos2;
				}
				pointer ptr = pos;
				while (ptr != this->V_finish){
				
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

			template<typename InputIterator>
			void	
			assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last){
				
				clear();
				size_type n = ft::distance(first, last);
				if (n > capacity()){

					pointer tmp = vector_allocator.allocate(n);
					vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
					for (size_type i = 0; first != last; ++first, ++i){

						vector_allocator.construct(tmp + i, *first);
					}
					this->V_start = tmp;
					this->V_finish = tmp + n;
					this->V_end_of_storage = this->V_finish;
				}
				else{

					for (size_type i = 0; first != last; ++first, ++i){

						vector_allocator.construct(this->V_start + i, *first);
					}
					this->V_finish += n;
				}
			}

			void	push_back(const value_type &x){

				if (this->V_finish != this->V_end_of_storage){

					vector_allocator.construct(this->V_finish++, x);
				}
				else{

					insert(end(), x);
				}
			}

			void	pop_back(){

				vector_allocator.destroy(--this->V_finish);
			}

			void	clear(){

				for (pointer x = this->V_start; x != this->V_finish; ++x){

					vector_allocator.destroy(x);
				}
				this->V_finish = this->V_start;
			}

			iterator	insert(iterator position, const value_type &x){

				size_type n = position - begin();
				if (this->V_finish != this->V_end_of_storage && position == end()){

					vector_allocator.construct(this->V_finish, x);
					++this->V_finish;
				}
				else{

					size_type len = size() ? 2 * size() : 1;
					pointer tmp = vector_allocator.allocate(len);
					pointer y = tmp;
					for (iterator it = begin(); it != position; ++it, ++y){
						
						vector_allocator.construct(y, *it);
					}
					vector_allocator.construct(y++, x);
					for ( ; position != end(); ++position, ++y){

						vector_allocator.construct(y, *position);
					}
					clear();
					vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
					this->V_start = tmp;
					this->V_finish = y;
					this->V_end_of_storage = this->V_start + len;
				}
				return (begin() + n);
			}

			void	insert(iterator position, size_type n, const value_type &x){

				if (n == 0){

					return;
				}
				if ((this->V_end_of_storage - this->V_finish) >= difference_type(n)){

					if (difference_type(end() - position) < difference_type(n)){

						for (iterator it1 = position + n, it2 = position; it2 != end(); ++it1, ++it2){

							vector_allocator.construct(&*it1, *it2);
						}
						for (iterator it = position; it != end(); ++it){

							*it = x;
						}
						for (pointer ptr = this->V_finish; ptr != this->V_finish + (n - (end() - position)); ++ptr){

							vector_allocator.construct(ptr, x);
						}
						this->V_finish += n;
					}
					else{

						difference_type diff = (end() - position) - n;
						pointer ptr = this->V_finish;
						for (iterator it = position + diff; it != end(); ++it, ++ptr){
						
							vector_allocator.construct(ptr, *it);
						}
						this->V_finish = ptr;
						for (iterator it1 = end() - n, it2 = position + diff; it2 != position; ){

							*(--it1) = *(--it2);
						}
						for (iterator it = position; it != position + n; ++it){

							*it = x;
						}
					}
				}
				else{

					size_type len = size() + n;
					size_type endS = (len > (size() * 2)) ? len : (size() * 2);
					pointer y = vector_allocator.allocate(endS);
					pointer z = y;
					for (iterator it = begin(); it != position; ++it, ++z){

						vector_allocator.construct(z, *it);
					}
					while (n--){

						vector_allocator.construct(z++, x);
					}
					for ( ; position != end(); ++position, ++z){

						vector_allocator.construct(z, *position);
					}
					clear();
					vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
					this->V_start = y;
					this->V_finish = y + len;
					this->V_end_of_storage = y + endS;
				}
			}
			
			template<typename InputIterator>
			void	insert(iterator position, InputIterator first, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last){

				if (first == last){

					return;
				}
				size_type n = ft::distance(first, last);
				if (this->V_end_of_storage - this->V_finish >= difference_type(n)){

					if (difference_type(end() - position) < difference_type(n)){

						for (iterator it1 = position + n, it2 = position; it2 != end(); ++it1, ++it2){

							vector_allocator.construct(&*it1, *it2);
						}
						for ( ; position != end(); ++position, ++first){

							*position = *first;
						}
						while (first != last){

							vector_allocator.construct(&*position, *first);
							first++;
							position++;
						}
						this->V_finish += n;
					}
					else{

						difference_type diff = (end() - position) - n;
						pointer ptr = this->V_finish;
						for (iterator it = position + diff; it != end(); ++it, ++ptr){
							
							vector_allocator.construct(ptr, *it);
						}
						this->V_finish = ptr;
						for (iterator it1 = end() - n, it2 = position + diff; it2 != position; ){

							*(--it1) = *(--it2);
						}
						for (iterator it = position; first != last; ++it, ++first){

							*it = *first;
						}
					}
				}
				else{

					size_type len = size() + n;
					pointer y = vector_allocator.allocate(len);
					pointer z = y;
					for (iterator it = begin(); it != position; ++it, ++z){

						vector_allocator.construct(z, *it);
					}
					while (first != last){

						vector_allocator.construct(z, *first);
						first++;
						z++;
					}
					for ( ; position != end(); ++position, ++z){

						vector_allocator.construct(z, *position);
					}
					clear();
					vector_allocator.deallocate(this->V_start, this->V_end_of_storage - this->V_start);
					this->V_start = y;
					this->V_finish = y + len;
					this->V_end_of_storage = this->V_finish;
				}
			}

			allocator_type get_allocator()const{

				return (this->vector_allocator);
			}

			void	swap(vector &x){

				ft::swap(this->V_start, x.V_start);
				ft::swap(this->V_finish, x.V_finish);
				ft::swap(this->V_end_of_storage, x.V_end_of_storage);
				ft::swap(this->vector_allocator, x.vector_allocator);
			}
	};
	
	template<typename T, typename Allocator>
	inline bool	operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y){

		return (x.size() == y.size() && equal(x.begin(), x.end(), y.begin()));
	}
	
	template<typename T, typename Allocator>
	inline bool	operator!=(const vector<T, Allocator> &x, const vector<T, Allocator> &y){

		return (!(x == y));
	}

	template<typename T, typename Allocator>		
	inline bool	operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y){
		
		return (lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	
	template<typename T, typename Allocator>		
	inline bool	operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y){

		return (y < x);
	}
		
	template<typename T, typename Allocator>		
	inline bool	operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y){

		return (!(y < x));
	}
		
	template<typename T, typename Allocator>		
	inline bool	operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y){
		
		return (!(x < y));
	}

	template<typename T, typename Allocator>		
	inline void	swap(vector<T, Allocator> &x, vector<T, Allocator> &y){
		
		x.swap(y);
	}
}

#endif
