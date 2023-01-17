/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:30:23 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/17 15:46:41 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include "vector.hpp"
#include "utils/map_iterator.hpp"


namespace ft{

	template<typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<BNode<const Key, T> > >
	class map{

		public:
			typedef Key	key_type;
			typedef T	mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef Compare	key_compare;
			typedef Alloc	allocator_type;
			typedef T	&reference;
			typedef const T	&const_reference;
			typedef T	*pointer;
			typedef const T	*const_pointer;
			typedef size_t	size_type;
			typedef BNode<key_type, mapped_type>	*node;
			typedef mapIterator<key_type, mapped_type>	iterator;
			typedef reverseMapIterator<key_type, mapped_type>	reverse_iterator;
			typedef constMapIterator<key_type, mapped_type>	const_iterator;
			typedef constReverseMapIterator<key_type, mapped_type>	const_reverse_iterator;
			
			class value_compare : public std::binary_function<value_type, value_type, bool>{

				
				protected:
					Compare	comp;
					value_compare(Compare c) : comp(c) {}
				public:
					typedef bool	result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool	operator()(const value_type &x, const value_type &y)const{

						return(comp(x.first, y.first));
					}
					bool	operator()(const key_type &x, const value_type &y)const{

						return(comp(x, y.first));
					}
					bool	operator()(const value_type &x, const key_type &y)const{

						return(comp(x.first, y));
					}
					friend class map;
			};
		private:
			allocator_type	_allocator;
			key_compare	_comp;
			node	_root;
			size_type	_length;
			
			node	_new_node(key_type key, mapped_type value, node parent, bool end = false){
				
				node n = new BNode<key_type, mapped_type>();
				n->pair = ft::make_pair(key, value);
				n->right = 0;
				n->left = 0;
				n->parent = parent;
				n->end = end;
				return (n);
			}
			
			void	_free_tree(node n){

				if (n->right)
					_free_tree(n->right);
				if (n->left)
					_free_tree(n->left);
				delete n;
			}
			
			node	_insert_node(node n, key_type key, mapped_type value, bool end = false){
				
				if (n->end){

					if (!n->left){

						n->left = _new_node(key, value, n, end);
						return (n->left);
					}
					return (_insert_node(n->left, key, value));
				}
				if (_comp(key, n->pair.first) && !end){
					
					if (!n->left){

						n->left = _new_node(key, value, n, end);
						return (n->left);
					}
					else
						return (_insert_node(n->left, key, value));
				}
				else{

					if (!n->right){

						n->right = _new_node(key, value, n, end);
						return (n->right);
					}
					else
						return (_insert_node(n->right, key, value));						
				}
			}
			
			node	_find(node n, key_type key)const{

				node	tmp;
				
				if (!n->end && n->pair.first == key && n->parent)
					return (n);
				if (n->right){

					if ((tmp = _find(n->right, key)))
						return (tmp);
				}
				if (n->left){
				
					if ((tmp = _find(n->left, key)))
						return (tmp);				
				}
				return (0);
			}

			void	_delete_node(node n){

				node parent = n->parent;
				if (!n->left && !n->right){

					if (parent->right == n)
						parent->right = 0;
					else
						parent->left = 0;
					delete n;
					return;
				}
				if (n->right && !n->left){

					if (parent->right == n)
						parent->right = n->right;
					else
						parent->left = n->right;
					n->right->parent = parent;
					delete n;
					return;
				}
				if (n->left && !n->right){

					if (parent->right == n)
						parent->right = n->left;
					else
						parent->left = n->left;
					n->left->parent = parent;
					delete n;
					return;
				}
				node next = (++iterator(n)).node();
				if (!next)
					next = (--iterator(n)).node();
				ft::swap(next->pair, n->pair);
				_delete_node(next);
			}

			void	_init_tree(){

				_root = _new_node(key_type(), mapped_type(), 0);
				_root->right = _new_node(key_type(), mapped_type(), _root, true);
				_length = 0;
			}

			node	_end()const{

				return (_root->right);
			}

		public:
			explicit map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp){

				_init_tree();
			}

			template<typename InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp){

				_init_tree();
				insert(first, last);
			}

			map(const map<Key, T> &cp){

				_init_tree();
				(*this) = cp;
			}

			~map(){

				_free_tree(_root);
			}

			map	&operator=(const map<Key, T> &x){

				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			const_iterator	begin()const{

				node n = _root;
				if (!n->left && !n->right)
					return (end());
				if (!n->left && n->right)
					n = n->right;
				while (n->left)
					n = n->left;
				return (const_iterator(n));
			}

			iterator	begin(){

				node n = _root;
				if (!n->left && !n->right)
					return (end());
				if (!n->left && n->right)
					n = n->right;
				while (n->left)
					n = n->left;
				return (iterator(n));
			}
			
			const_iterator	end()const{

				return (const_iterator(_end()));
			}
			
			iterator	end(){

				return (iterator(_end()));
			}
			
			reverse_iterator	rbegin(){

				iterator i = end();
				i--;
				return (reverse_iterator(i.node()));
			}
			
			const_reverse_iterator	rbegin()const{

				iterator i = end();
				i--;
				return (const_reverse_iterator(i.node()));
			}
			
			reverse_iterator	rend(){

				return (reverse_iterator(_root));
			}
			
			const_reverse_iterator	rend()const{

				return (const_reverse_iterator(_root));
			}
			
			bool	empty()const{
				
				return (_length == 0);
			}

			size_type	size()const{

				return (_length);
			}

			size_type	max_size()const{

				return (_allocator.max_size());
			}

			mapped_type	&operator[](const key_type &k){

				iterator tmp = find(k);
				if (tmp != end())
					return (tmp->second);
				return (insert(ft::make_pair(k, mapped_type())).first->second);
			}

			ft::pair<iterator, bool>	insert(const value_type &value){

				iterator tmp;
				if ((tmp = find(value.first)) != end())
					return (ft::make_pair(tmp, false));
				++_length;				
				return (ft::make_pair(iterator(_insert_node(_root->right, value.first, value.second)), true));
			}

			iterator	insert(iterator position, const value_type &value){

				(void)position;
				iterator tmp;
				if ((tmp = find(value.first)) != end()){
					
					return (tmp);
				}
				++_length;
				return(iterator(_insert_node(_root->right, value.first, value.second)));
			}

			template<typename InputIterator>
			void	insert(InputIterator first, InputIterator last){

				while (first != last){

					insert(*first);
					++first;
				}
			}

			void	erase(iterator position){

				_delete_node(position.node());
				--_length;
			}

			size_type	erase(const key_type &value){

				int i = 0;
				iterator it;
				while ((it = find(value)) != end()){

					erase(it);
					++i;
				}
				return (i);
			}

			void	erase(iterator first, iterator last){

				while (first != last)
					erase(first++);
			}

			void	swap(map &x){

				ft::swap(_length, x._length);
				ft::swap(_root, x._root);
			}

			void	clear(){

				erase(begin(), end());
			}

			key_compare	key_comp()const{

				return (_comp);
			}

			value_compare	value_comp()const{

				return (value_compare(key_compare()));
			}

			iterator	find(const key_type &k){

				if (empty())
					return (end());
				node tmp = _find(_root, k);
				if (tmp)
					return (iterator(tmp));
				return (end());
			}
			
			const_iterator	find(const key_type &k)const{

				if (empty())					
					return (end());
				node tmp = _find(_root, k);
				if (tmp)
					return (const_iterator(tmp));
				return (end());
			}

			size_type	count(const key_type &k)const{

				size_t c = 0;
				const_iterator it = begin();
				while (it != end()){

					if (it->first == k)
						++c;
					++it;
				}
				return (c);
			}

			iterator lower_bound(const key_type &k){
			
				iterator it = begin();
				while (it != end()){

					if (this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			}
			
			const_iterator lower_bound(const key_type &k)const{
			
				const_iterator it = begin();
				while (it != end()){

					if (this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			}

			iterator upper_bound(const key_type &k){

				iterator it = begin();
				while (it != end()){

					if (it->first != k && this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			}

			const_iterator upper_bound(const key_type &k)const{

				const_iterator it = begin();
				while (it != end()){

					if (it->first != k && this->_comp(it->first, k) <= 0)
						return (it);
					++it;
				}
				return (end());
			}

			ft::pair<const_iterator, const_iterator>	equal_range(const key_type &k)const{
				
				return (ft::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}
			
			ft::pair<iterator, iterator>	equal_range(const key_type &k){
				
				return (ft::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}
	};
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	void	swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y){

		x.swap(y);
	}

	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator==(const ft::map<Key, T, Compare, Alloc> &x, const ft::map<Key, T, Compare, Alloc> &y){

		if (x.size() != y.size())
			return (false);
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it = y.begin();
		typename ft::map<Key, T, Compare, Alloc>::const_iterator it2 = x.begin();
		while (it != y.end()){

			if (*it != *it2)
				return (false);
			++it;
			++it2;
		}
		return (true);
	}
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator!=(const ft::map<Key, T, Compare, Alloc> &x, const ft::map<Key, T, Compare, Alloc> &y){

		return (!(x == y));
	}
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<(const ft::map<Key, T, Compare, Alloc> &x, const ft::map<Key, T, Compare, Alloc> &y){

		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>(const ft::map<Key, T, Compare, Alloc> &x, const ft::map<Key, T, Compare, Alloc> &y){

		return (y < x); 
	}
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator<=(const ft::map<Key, T, Compare, Alloc> &x, const ft::map<Key, T, Compare, Alloc> &y){

		return (!(y < x));
	}	
	
	template<typename Key, typename T, typename Compare, typename Alloc>
	bool	operator>=(const ft::map<Key, T, Compare, Alloc> &x, const ft::map<Key, T, Compare, Alloc> &y){

		return (!(x < y));
	}
}

#endif
