/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:30:23 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/27 19:19:34 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "vector.hpp"
#include "utils/map_iterator.hpp"


namespace ft{

	template<typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
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
			typedef unsigned long	size_type;
			typedef BNode<key_type, mapped_type>	*node;
			typedef mapIterator<key_type, mapped_type>	iterator;
			typedef reverseMapIterator<key_type, mapped_type>	reverse_iterator;
			typedef constMapIterator<key_type, mapped_type>	const_iterator;
			typedef constReverseMapIterator<key_type, mapped_type>	const_reverse_iterator;
			
			class value_compare{

				friend class map;
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
			};
		private:
			allocator_type	_allocator;
			key_compare	_comp;
			node	_root;
			size_type	_length;
			
			void	_debug_tree(node n){

				if(!n)
					return;
				_debug_tree(n->left);
				if (n->parent && !n->end)
					std::cout << n->pair.first << "=" << n->pair.second << std::endl;
				_debug_tree(n->right);
			}
			
			node	_new_node(key_type key, mapped_type value, node parent, bool end = false){
				
				node el = new BNode<key_type, mapped_type>();
				el->pair = ft::make_pair(key, value);
				el->right = 0;
				el->left = 0;
				el->parent = parent;
				el->end = end;
				return (el);
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
				if (key < n->pair.first && !end){
					
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

					if (tmp = _find(n->right, key))
						return (tmp);
				}
				if (n->left){
				
					if (tmp = _find(n->left, key))
						return (tmp);				
				}
				return (0);
			}

			
	};
}

#endif
