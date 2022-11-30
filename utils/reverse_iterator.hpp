/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:14:36 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/30 18:14:36 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator>
#include "iterator_traits.hpp"

namespace ft{

	template<typename Iter>
	class reverse_iterator : public std::iterator <
		typename iterator_traits<Iter>::iterator_category,
		typename iterator_traits<Iter>::value_type,
		typename iterator_traits<Iter>::difference_type,
		typename iterator_traits<Iter>::pointer,
		typename iterator_traits<Iter>::reference > {
		
		
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

			template<typename U>
			reverse_iterator(const reverse_iterator<U> &u) : current(u.base) {}
			
			Iter base()const { 
				return (current);
			}

			reference	operator*()const{

				Iter tmp = current;
				return (*--tmp);
			}

			pointer	operator->()const{

				return (&(operator*()));
			}

			reverse_iterator	&operator++(){
				
				--current;
				return (*this);
			}	

			reverse_iterator	operator++(int){
				
				reverse_iterator	tmp(*this);
				--current;
				return (tmp);
			}

			reverse_iterator	&operator--(){
				
				++current;
				return (*this);
			}

			reverse_iterator	operator--(int){
				
				reverse_iterator	tmp(*this);
				++current;
				return (tmp);
			}

			reverse_iterator	operator+(difference_type n)const{

				return (reverse_iterator(current - n));
			}

			reverse_iterator	&operator+=(difference_type n){

				current -= n;
				return (*this);
			}

			reverse_iterator	operator-(difference_type n)const{

				return (reverse_iterator(current + n));
			}

			reverse_iterator	&operator-=(difference_type n){

				current += n;
				return (*this);
			}

			reference	operator[](difference_type n)const{

				return (*(*this + n));
			}
	};

	template<typename Iter>
	bool	operator==(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){

		return (x.base() == y.base());
	}
	
	template<typename Iter>
	bool	operator!=(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){

		return (x.base() != y.base());
	}

	template<typename Iter>
	bool	operator<(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){

		return (x.base() < y.base());
	}
	
	template<typename Iter>
	bool	operator<=(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){

		return (x.base() <= y.base());
	}

	template<typename Iter>
	bool	operator>(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){

		return (x.base() > y.base());
	}
	
	template<typename Iter>
	bool	operator>=(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){

		return (x.base() >= y.base());
	}

	template<typename Iter>
	typename reverse_iterator<Iter>::difference_type
		operator-(const reverse_iterator<Iter> &x, const reverse_iterator<Iter> &y){

		return (y.base() - x.base());
	}
		
	template<typename Iter>
	reverse_iterator<Iter>	
		operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &x){

		return 	(reverse_iterator<Iter>(x.base() - n));
	}
}

#endif
