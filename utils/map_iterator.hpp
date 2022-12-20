/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:57 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/20 17:15:07 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "../vector.hpp"

namespace ft{

	template<typename T, typename node, typename compare, typename tree>
	class map_iterator : std::iterator<std::bidirectional_iterator_tag, T>{

		public:
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::iterator_category iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::value_type value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::difference_type difference_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::pointer pointer;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::reference reference;
			
			map_iterator() : _ptr(), _tree(), _cmp() {}
			map_iterator(node *nd, const tree *tr) : _ptr(nd), _tree(tr) {}
			map_iterator(const map_iterator &x) {

				(*this) = x;
			}
			virtual ~map_iterator() {}

			node	*base()const {

				return (_ptr);
			}

			map_iterator	&operator=(const map_iterator &x){

				this->_ptr = x._ptr;
				this->_tree = x._tree;
				this->_cmp = x._cmp;
				return (*this);
			}

			operator	map_iterator<const T, const node, compare, tree>()const{

				return (map_iterator<const T, const node, compare, tree>(_ptr, _tree));
			}

			T	*operator->()const {

				return (_ptr->data);
			}

			T	&operator*()const {

				return (*(_ptr->data));
			}
			
			map_iterator	&operator++(){

				node 	*p;
				
				if (_ptr == NULL){

					*this = map_iterator(_tree->findm(_tree->get_root()), _tree);
					return (*this);
				}
				if (_ptr == _tree->findM(_tree->get_root())){

					*this = map_iterator(NULL, _tree);
					return (*this);
				}
				if (_ptr->right != NULL){

					_ptr = _ptr->right;
					while (_ptr->left != NULL){

						_ptr = _ptr->left;
					}
				}
				else{

					p = _ptr->parent;
					while (p != NULL && _ptr == p->right){

						_ptr = p;
						p = p->parent;
					}
					_ptr = p;
				}
				return (*this);
			}

			map_iterator	operator++(int){

				map_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			map_iterator	&operator--(){

				node	*p;

				if (_ptr == NULL){

					_ptr = _tree->findM(_tree->get_root());
				}
				else{

					if (_ptr->left != NULL){

						_ptr = _ptr->left;
						while (_ptr->right != NULL){

							_ptr = _ptr->right;
						}
					}
					else{

						p = _ptr->parent;
						while (p != NULL && _ptr == p->left){

							_ptr = p;
							p = p->parent;
						}
						_ptr = p;
					}
				}
				return (*this);
			}

			map_iterator	operator--(int){

				map_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}

			friend bool	operator==(const map_iterator &x, const map_iterator &y){

				return (x._ptr == y._ptr);
			}
			
			friend bool	operator!=(const map_iterator &x, const map_iterator &y){

				return (x._ptr != y._ptr);
			}
			
		private:
			node		*_ptr;
			const tree 	*_tree;
			compare		*_cmp;
	};
}

#endif
