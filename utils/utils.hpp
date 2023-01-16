/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:49:27 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/16 17:28:15 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include "iterator_traits.hpp"
#include "pair.hpp"
#include <typeinfo>

namespace ft{

	template<typename Iter>
	typename iterator_traits<Iter>::difference_type distance(Iter first, Iter last){

		typename iterator_traits<Iter>::difference_type n = 0;
		while (first++ != last){

			++n;
		}
		return (n);
	}

	template<typename Tp>
	void	swap(Tp &x, Tp &y){

		Tp	tmp(x);
		x = y;
		y = tmp;
	}

	template<typename Tp>
	const Tp	&max(const Tp &x, const Tp &y){

		return ((x < y) ? y : x);
	}


	template<typename T>
	struct less : std::binary_function<T, T, bool>{

		bool	operator()(const T &x, const T &y)const{

			return (x < y);
		}
	};	

	template<typename Key, typename T>
	struct BNode{

		ft::pair<Key, T>	pair;
		BNode				*parent;
		BNode				*left;
		BNode				*right;
		bool				end;
	};

}

#endif
