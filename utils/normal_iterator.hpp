/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:25:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/30 16:00:55 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMAL_ITERATOR_HPP
#define NORMAL_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft{

	template<typename Iter>
	class normal_iterator{

		private:
			Iter i;

		public:
			typedef Iter iterator_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::reference reference;
			typedef typename iterator_traits<Iter>::iterator_category iterator_category;
			
			normal_iterator() : i() {}

			explicit normal_iterator(Iter x) : i(x) {}

			template<typename U>
			normal_iterator(const normal_iterator<U> &u) : i(u.base()) {}

			Iter	base()const{ 
				
				return (i);
			}

			reference	operator*()const{

				return (*i);
			}

			pointer		operator->()const{

				return (i);
			}
			
			normal_iterator	&operator++(){

				++i;
				return (*this);
			}

			normal_iterator	operator++(int){

				normal_iterator	tmp(*this);
				++i;
				return (tmp);
			}

			normal_iterator	&operator--(){

				--i;
				return (*this);
			}
			
			normal_iterator	operator--(int){

				normal_iterator	tmp(*this);
				--i;
				return (tmp);
			}

			normal_iterator	operator+(difference_type n)const{

				return (normal_iterator(i + n));
			}

			normal_iterator	&operator+=(difference_type n){

				i += n;
				return (*this);
			}
			
			normal_iterator	operator-(difference_type n)const{

				return (normal_iterator(i - n));
			}
			
			normal_iterator	&operator-=(difference_type n){

				i -= n;
				return (*this);
			}

			reference	operator[](difference_type n)const{

				return (i[n]);
			}

			// template<typename U>
			// friend class normal_iterator;

			// template<typename T, typename Allocator>
			// friend class vector;
			// class friend.....
	};

	template<typename Iter>
	bool	operator==(const normal_iterator<Iter> &x, const normal_iterator<Iter> &y){

		return (x.base() == y.base());
	}
	
	template<typename Iter1, typename Iter2>
	bool	operator==(const normal_iterator<Iter1> &x, const normal_iterator<Iter2> &y){

		return (x.base() == y.base());
	}
	
	template<typename Iter>
	bool	operator!=(const normal_iterator<Iter> &x, const normal_iterator<Iter> &y){

		return (!(x == y));
	}
	
	template<typename Iter1, typename Iter2>
	bool	operator!=(const normal_iterator<Iter1> &x, const normal_iterator<Iter2> &y){

		return (!(x == y));
	}
	
	template<typename Iter>
	bool	operator<(const normal_iterator<Iter> &x, const normal_iterator<Iter> &y){

		return (x.base() < y.base());
	}
	
	template<typename Iter1, typename Iter2>
	bool	operator<(const normal_iterator<Iter1> &x, const normal_iterator<Iter2> &y){

		return (x.base() < y.base());
	}
	
	template<typename Iter>
	bool	operator>(const normal_iterator<Iter> &x, const normal_iterator<Iter> &y){

		return (y < x);
	}
	
	template<typename Iter1, typename Iter2>
	bool	operator>(const normal_iterator<Iter1> &x, const normal_iterator<Iter2> &y){

		return (y < x);
	}

	template<typename Iter>
	bool	operator<=(const normal_iterator<Iter> &x, const normal_iterator<Iter> &y){

		return (!(y < x));
	}
	
	template<typename Iter1, typename Iter2>
	bool	operator<=(const normal_iterator<Iter1> &x, const normal_iterator<Iter2> &y){

		return (!(y < x));
	}
	
	template<typename Iter>
	bool	operator>=(const normal_iterator<Iter> &x, const normal_iterator<Iter> &y){

		return (!(x < y));
	}
	
	template<typename Iter1, typename Iter2>
	bool	operator>=(const normal_iterator<Iter1> &x, const normal_iterator<Iter2> &y){

		return (!(x < y));
	}
	
	template<typename Iter1, typename Iter2>
	typename normal_iterator<Iter1>::difference_type	
		operator-(const normal_iterator<Iter1> &x, const normal_iterator<Iter2> &y){
		
		return (x.base() - y.base());
	}
	
	template<typename Iter>
	normal_iterator<Iter>	
		operator+(typename normal_iterator<Iter>::difference_type n, const normal_iterator<Iter> &x){
			
		return (normal_iterator<Iter>(x.base() + n));
	}
}

#endif
