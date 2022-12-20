/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:20:52 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/20 16:32:46 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft{
	
	template<typename Tp, typename Container = vector<Tp> >
	class	stack{

		public:
			typedef Container							container_type;
			typedef typename container_type::value_type	value_type;
			typedef typename container_type::size_type	size_type;
			
		protected:
			container_type	c;
		
		public:
			explicit stack(const Container &c = Container()) : c(c) {

			}

			bool	empty()const{

				return (c.empty());
			}

			size_type	size()const{

				return (c.size());
			}

			value_type	&top(){

				return (c.back());
			}

			const value_type	&top()const{

				return (c.back());			
			}

			void	push(const value_type &v){

				c.push_back(v);
			}
		
			void	pop(){

				c.pop_back();
			}

			template<typename T1, typename C1>
			friend bool	operator==(const stack<T1, C1> &x, const stack<T1, C1> &y);
		
			template<typename T1, typename C1>
			friend bool	operator!=(const stack<T1, C1> &x, const stack<T1, C1> &y);

			template<typename T1, typename C1>
			friend bool	operator<(const stack<T1, C1> &x, const stack<T1, C1> &y);
		
			template<typename T1, typename C1>
			friend bool	operator>(const stack<T1, C1> &x, const stack<T1, C1> &y);
		
			template<typename T1, typename C1>
			friend bool	operator<=(const stack<T1, C1> &x, const stack<T1, C1> &y);
		
			template<typename T1, typename C1>
			friend bool	operator>=(const stack<T1, C1> &x, const stack<T1, C1> &y);
	};

	template<typename Tp, typename Container>
	bool	operator==(const stack<Tp, Container> &x, const stack<Tp, Container> &y){

		return (x.c == y.c);
	}

	template<typename Tp, typename Container>
	bool	operator!=(const stack<Tp, Container> &x, const stack<Tp, Container> &y){

		return (!(x.c == y.c));
	}
	
	template<typename Tp, typename Container>
	bool	operator<(const stack<Tp, Container> &x, const stack<Tp, Container> &y){

		return (x.c < y.c);
	}
	
	template<typename Tp, typename Container>
	bool	operator>(const stack<Tp, Container> &x, const stack<Tp, Container> &y){

		return (y < x);
	}

	template<typename Tp, typename Container>
	bool	operator<=(const stack<Tp, Container> &x, const stack<Tp, Container> &y){

		return (!(y < x));
	}
	
	template<typename Tp, typename Container>
	bool	operator>=(const stack<Tp, Container> &x, const stack<Tp, Container> &y){
		
		return (!(x < y));
	}
}

#endif
