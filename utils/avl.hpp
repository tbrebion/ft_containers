/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:09:59 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/13 13:26:55 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AVL_HPP
#define AVL_HPP

#include "../vector.hpp"
#include "map_iterator.hpp"

namespace ft{

	template<typename T, typename Compare = std::less<typename T::first_type>, typename Allocator = std::allocator<T> >
	class avl{

		public:
			typedef T 																value_type;
			typedef ft::avlNode<const T> 											const_node;
			typedef Allocator 														pair_alloc;
			typedef typename Allocator::template rebind<ft::avlNode<T> >::other 	node_alloc;
			typedef ft::map_iterator<T, ft::avlNode<T>, Compare, avl>				iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::map_iterator<const T, const ft::avlNode<T>, Compare, avl>	const_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;
			typedef typename value_type::first_type									key;
			typedef typename value_type::second_type								value;
			
			avl() : _root(NULL), _size(0) {}
			avl(const avl &x) : _root(NULL){

				*this = assign(x);
			}
			~avl(){

				deleteTree();
			}
			
			avl	&assign(const avl &x){

				deleteTree();
				n_alloc = x.n_alloc;
				p_alloc = x.p_alloc;
				_comp = x._comp;
				for (const_iterator it = x.begin(); it != x.end(); it++){

					insert(*it);
				}
				_size = x._size;
				
				return (*this);
			}

			int	size()const{

				return (_size);
			}

			bool	empty()const{

				if (_size == 0){

					return (true);
				}
				return (false);
			}

			void	deleteTree(){

				_root = delTree(_root);
				_size = 0;
			}

			ft::avlNode<T>	*delTree(ft::avlNode<T> *node){

				if (node != NULL){
				
					delTree(node->left);
					delTree(node->right);
					deleteNode(node);
				}
				return (NULL);
			}

			void	deleteNode(ft::avlNode<T> *node){

				
			}
			
		private:
			ft::avlNode<T>	*_root;
			node_alloc		n_alloc;
			pair_alloc		p_alloc;
			int				_size;
			Compare			_comp;
	};
}

#endif
