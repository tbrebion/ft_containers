/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:30:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/16 17:37:55 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "vector.hpp"
#include "utils/map_iterator.hpp"

namespace ft{

	template<typename Key, 
		typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<pair<const Key, T>> >
	class map{

		public:
			typedef Key										key_type;
			typedef	T 										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			
			typedef	class value_compare : std::binary_function<value_type, value_type, bool>{

				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool	operator() (const value_type &x, const value_type &y)const{

						return (comp(x.first, y.first));
					}
			} value_compare;
			
			typedef Allocator																	allocator_type;
			typedef typename allocator_type::reference											reference;
			typedef typename allocator_type::const_reference									const_reference;
			typedef typename allocator_type::pointer											pointer;
			typedef typename allocator_type::const_pointer										const_pointer;
			typedef typename allocator_type::difference_type									difference_type; /////////////////////
			typedef ft::avl<value_type, Compare, Allocator>										tree;
			typedef typename ft::avl<value_type, Compare, Allocator>::iterator					iterator;
			typedef typename ft::avl<value_type, Compare, Allocator>::const_iterator			const_iterator;
			typedef typename ft::avl<value_type, Compare, Allocator>::reverse_iterator			reverse_iterator;
			typedef typename ft::avl<value_type, Compare, Allocator>::const_reverse_iterator	const_reverse_iterator;
			typedef typename allocator_type::size_type											size_type;
			
			explicit map(const key_compare &cmp = key_compare(), const allocator_type &alloc = allocator_type()) : _cmp(cmp), _alloc(alloc) {}
			
			template<typename InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &cmp = key_compare(), 
			const allocator_type &alloc = allocator_type()) : _cmp(cmp), _alloc(alloc) {

				for ( ; first != last; first++){

					_avl.insert(*first);
				}
			}

			map(const map &x) : _avl(x._avl), _alloc(x._alloc), _cmp(x._cmp) {}

			map	&operator=(const map &x){

				_alloc = x._alloc;
				_cmp = x._cmp;
				_avl = _avl.assign(x._avl);
				return (*this);
			}

			iterator	begin(){

				return (_avl.begin());
			}

			const_iterator	begin()const{

				return (_avl.begin());
			}

			iterator	end(){

				return (_avl.end());
			}

			const_iterator	end()const{

				return (_avl.end());
			}
			
			reverse_iterator	rbegin(){

				return (_avl.rbegin());
			}

			const_reverse_iterator	rbegin()const{

				return (_avl.rbegin());
			}

			reverse_iterator	rend(){

				return (_avl.rend());
			}

			const_reverse_iterator	rend()const{

				return (_avl.rend());
			}

			bool	empty(){

				return (_avl.empty());
			}

			size_type	size()const{

				return (_avl.size());
			}

			size_type	max_size(){

				return (_avl.get_alloc());
			}

			key_compare	key_comp()const{

				return (_cmp);
			}

			value_compare	value_comp()const{

				return (value_compare(_cmp));
			}

			mapped_type &operator[](key &k){

				if (_avl.find(k) == NULL)
					return ((insert(ft::make_pair(k, mapped_type())).first)->second);
				return (_avl.find(k)->data->second);
			}

			ft::pair<iterator, bool>	insert(const value_type &x){

				bool sec = _avl.insert(x);
				iterator first = iterator(find(x.first), &_avl);
				ft::pair<iterator, bool> ret = ft::make_pair(first, sec);
				return (ret);
			}

			iterator	insert(iterator position, const value_type &x){

				(void)position;
				_avl.insert(x);
				return (iterator(_avl.find(x.first), &_avl));
			}
			
			template<InputIterator>
			void	insert(InputIterator first, InputIterator last){

				for ( ; first != last; first++)
					_avl.insert(*first);
				return;
			}

			void	erase(iterator position){

				key_type x = position->first;
				_avl.remove(x);
				return;
			}

			size_type	erase(const key_type &x){

				return (_avl.remove(x));
			}

			void	erase(iterator first, iterator last){

				ft::vector<key_type>	keys;
				for ( ; first != last; first++)
					keys.push_back(first->first);
				for (size_t i = 0; i < keys.size(); i++)
					_avl.remove(keys[i]);
				return;
			}

			void	swap(map &x){

				tree	tmp_avl;
				
				tmp_avl = x._avl;
				x._avl = _avl;
				_avl = tmp_avl;
				return;
			}

			void	clear(){

				_avl.clear();
			}

			iterator	find(const key_type &x){

				return (iterator(_avl.find(x), &_avl));
			}

			const_iterator	find(const key_type &x)const{

				return (iterator(_avl.find(x), &_avl));
			}

			size_type	count(const key_type &x)const{

				return (_avl.contains(x));
			}

			/////////////////////////////
			
			
		private:
			tree			_avl;
			allocator_type	_alloc;
			key_compare		_cmp;
				
	};
	
}

#endif
