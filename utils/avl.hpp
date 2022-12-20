/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:09:59 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/20 17:26:53 by tbrebion         ###   ########.fr       */
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

				// deleteTree();
			}
			
			avl	&assign(const avl &x){

				deleteTree();
				n_alloc = x.n_alloc;
				p_alloc = x.p_alloc;
				_cmp = x._cmp;
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

				p_alloc.destroy(node->data);
				p_alloc.deallocate(node->data, 1);
				node->data = NULL;
				n_alloc.deallocate(node, 1);
				node = NULL;
			}

			void	clear(){
				
				deleteTree();
				_size = 0;
			}

			iterator	begin(){

				ft::avlNode<T>	*first = find(findMin(_root).first);
				return (iterator(first, this));
			}

			iterator	end(){

				return (iterator(NULL, this));
			}

			const_iterator	begin()const{

				ft::avlNode<T>	*first = find(findMin(_root).first);
				return (iterator(first, this));
			}

			const_iterator	end()const{

				return (iterator(NULL, this));
			}
			
			reverse_iterator	rbegin(){

				return(reverse_iterator(end()));
			}

			reverse_iterator	rend(){

				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rbegin()const{

				return(reverse_iterator(end()));
			}

			const_reverse_iterator	rend()const{

				return (reverse_iterator(begin()));
			}

			ft::avlNode<T>	*newNode(T obj){

				ft::avlNode<T>	*node = n_alloc.allocate(1);
				n_alloc.construct(node, ft::avlNode<T>()); /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				node->data = p_alloc.allocate(1);
				p_alloc.construct(node->data, obj);
				return (node);
			}

			int	height(){

				if (_root == NULL){

					return (0);
				}
				return (height(_root - 1));
			}

			bool	contains(key k)const{

				return (contains(_root, k));
			}
			
			bool	insert(T value){

				if (!contains(_root, value.first)){

					_root = insert(_root, value);
					_root->parent = NULL;
					_size++;
					return (true);
				}
				return (false);
			}

			bool	remove(key val){

				if (contains(_root, val)){

					_root = remove(_root, val);
					// if (_root)
						// _root->parent = NULL;
					_size--;
					return (true);
				}
				return (false);
			}

			ft::avlNode<T>	*find(key val){

				if (contains(_root, val)){
					
					return (find(_root, val));
				}
				return (NULL);
			}
			ft::avlNode<T>	*find(key val)const{

				if (contains(_root, val)){

					return (find(_root, val));
				}
				return (NULL);
			}

			iterator	bound(key val, std::string s){

				ft::avlNode<T>	*con = NULL;
				
				if (s == "lower"){

					lower_bound(_root, val, &con);
					if (!con){

						return (iterator(NULL, this));
					}
					else{

						return (iterator(con, this));
					}
				}
				else{

					upper_bound(_root, val, &con);
					if (!con){

						return (iterator(NULL, this));
					}
					else{

						return (iterator(con, this));
					}					
				}
				return (iterator(NULL, this));
			}

			const_iterator	bound(key val, std::string s)const{

				ft::avlNode<T>	*con = NULL;
				
				if (s == "lower"){

					lower_bound(_root, val, &con);
					if (!con){

						return (const_iterator(NULL, this));
					}
					else{

						return (const_iterator(con, this));
					}
				}
				else{

					upper_bound(_root, val, &con);
					if (!con){

						return (const_iterator(NULL, this));
					}
					else{

						return (const_iterator(con, this));
					}					
				}
				return (iterator(NULL, this));
			}
			
			size_t	get_alloc()const{

				return (n_alloc.max_size());
			}

			node_alloc	get_allocator()const{

				return (n_alloc);
			}

			ft::avlNode<T>	*get_root()const{

				return (_root);
			}

			ft::avlNode<T>	*findm(ft::avlNode<T> *node){

				while (node->left != NULL){

					node = node->left;
				}
				return (node);
			}
			
			ft::avlNode<T>	*findM(ft::avlNode<T> *node){

				while (node->right != NULL){

					node = node->right;
				}
				return (node);
			}

			ft::avlNode<T>	*findm(ft::avlNode<T> *node)const{

				while (node->left != NULL){

					node = node->left;
				}
				return (node);
			}
			
			ft::avlNode<T>	*findM(ft::avlNode<T> *node)const{

				while (node->right != NULL){

					node = node->right;
				}
				return (node);
			}

		private:
		
			int	height(ft::avlNode<T> *node){

				if (node == NULL)
					return (-1);
				int	leftHeight = height(node->left) + 1;
				int	rightHeight = height(node->right) + 1;
				if (leftHeight > rightHeight)
					return (leftHeight);
				return (rightHeight);
			}
			
			bool	contains(ft::avlNode<T> *node, key k)const{

				if (node == NULL)
					return (false);
				bool cmp = _cmp(node->data->first, k);
				bool cmp1 = _cmp(k, node->data->first);
				if (!cmp1 && !cmp)
					return (true);
				if (!cmp)
					return (contains(node->left, k));
				if (cmp)
					return (contains(node->right, k));
				return (true);
			}

			ft::avlNode<T>	*insert(ft::avlNode<T> *node, T val){

				if (node == NULL)
					return (newNode(val));
				bool cmp = _cmp(val.first, node->data->first);
				if (cmp){

					node->left = insert(node->left, val);
					node->left->parent = node;
				}
				else if(!cmp){

					node->right = insert(node->right, val);
					node->right->parent = node;					
				}
				update(node);
				return (balance(node));
			}

			void	update(ft::avlNode<T> *node){

				int leftNodeHeight = (node->left == NULL) ? -1 : node->left->height;
				int rightNodeHeight = (node->right == NULL) ? -1 : node->right->height;
				node->height = 1 + ft::max(leftNodeHeight, rightNodeHeight);
				node->bf = rightNodeHeight - leftNodeHeight;
			}
			
			ft::avlNode<T>	*balance(ft::avlNode<T> *node){

				if (node->bf == -2){

					if (node->left->bf <= 0)
						return (leftleftCase(node));
					else
						return (leftrightCase(node));
				}
				else if (node->bf == 2){

					if (node->right->bf >= 0)
						return (rightrightCase(node));
					else
						return (rightleftCase(node));
				}
				return (node);
			}

			ft::avlNode<T>	*leftleftCase(ft::avlNode<T> *node){

				return (rightRotation(node));
			}
			
			ft::avlNode<T>	*leftrightCase(ft::avlNode<T> *node){

				node->left = leftRotation(node->left);
				return (leftleftCase(node));
			}

			ft::avlNode<T>	*rightrightCase(ft::avlNode<T> *node){

				return (leftRotation(node));
			}
			
			ft::avlNode<T>	*rightleftCase(ft::avlNode<T> *node){

				node->right = rightRotation(node->right);
				return (rightrightCase(node));
			}

			ft::avlNode<T>	*leftRotation(ft::avlNode<T> *node){

				ft::avlNode<T>	*tmp = node->right;
				node->right = tmp->left;
				tmp->left = node;
				resetParent(node, tmp);
				update(node);
				update(tmp);
				return (tmp);
			}
			
			ft::avlNode<T>	*rightRotation(ft::avlNode<T> *node){
				
				ft::avlNode<T>	*tmp = node->left;
				node->left = tmp->right;
				tmp->right = node;
				resetParent(node, tmp);
				update(node);
				update(tmp);
				return (tmp);
			}

			void	resetParent(ft::avlNode<T> *oldRoot, ft::avlNode<T> *newRoot)const{

				if (!oldRoot->parent){

					newRoot->parent = NULL;
					if (oldRoot->left)
						oldRoot->left->parent = oldRoot;
					if (oldRoot->right)
						oldRoot->right->parent = oldRoot;
					oldRoot->parent = newRoot;
					return;
				}
				newRoot->parent = oldRoot->parent;
				oldRoot->parent = newRoot;
				if (oldRoot->left)
					oldRoot->left->parent = oldRoot;
				if (oldRoot->right)
					oldRoot->right->parent = oldRoot;
			}

			ft::avlNode<T>	*remove(ft::avlNode<T> *node, key val){

				if (node == NULL)
					return (NULL);
				int cmp = _cmp(val, node->data->first);  ////bool
				bool cmp1 = _cmp(node->data->first, val);
				if (!cmp && !cmp1){

					if (node->left == NULL)
						return (node->right);
					else if (node->right == NULL)
						return (node->left);
					else{

						if (height(node->left) > height(node->right)){

							T Svalue = findMax(node->left);
							node->data = &Svalue;
							node->left = remove(node->left, Svalue.first);
						}
						else{

							T Svalue = findMin(node->right);
							node->data = &Svalue;
							node->right = remove(node->right, Svalue.first);							
						}
					}
				}
				else if (cmp)
					node->left = remove(node->left, val);
				else if (!cmp)
					node->right = remove(node->right, val);
				update(node);
				return (balance(node));
			}

			ft::avlNode<T>	*find(ft::avlNode<T> *node, key val){

				if (node == NULL)
					return (NULL);
				bool cmp = _cmp(node->data->first, val);
				bool cmp1 = _cmp(val, node->data->first);
				if (!cmp && !cmp1)
					return (node);
				if (!cmp)
					return (find(node->left, val));
				else if(cmp)
					return (find(node->right, val));
				return (node);
			}

			ft::avlNode<T>	*find(ft::avlNode<T> *node, key val)const{

				if (node == NULL)
					return (NULL);
				bool cmp = _cmp(node->data->first, val);
				bool cmp1 = _cmp(val, node->data->first);
				if (!cmp && !cmp1)
					return (node);
				if (!cmp)
					return (find(node->left, val));
				else if(cmp)
					return (find(node->right, val));
				return (node);
			}

			void	lower_bound(ft::avlNode<T> *node, key val, ft::avlNode<T> **con)const{

				if (node == NULL)
					return;
				bool cmp = _cmp(node->data->first, val);
				bool cmp1 = _cmp(val, node->data->first);
				if (!cmp && !cmp1){

					*con = node;
					return;
				}
				if (!cmp)
					lower_bound(node->left, val, con);
				if (*con == NULL && !cmp){

					*con = node;
					return;
				}
				if (cmp)
					lower_bound(node->right, val, con);
			}
			
			void	upper_bound(ft::avlNode<T> *node, key val, ft::avlNode<T> **con)const{

				if (node == NULL)
					return;
				bool cmp = _cmp(node->data->first, val);
				bool cmp1 = _cmp(val, node->data->first);
				if (!cmp && !cmp1){

					*con = node->right;
					return;
				}
				if (!cmp)
					upper_bound(node->left, val, con);
				if (*con == NULL && !cmp){

					*con = node;
					return;
				}
				if (cmp)
					upper_bound(node->right, val, con);
			}
			
			T	findMin(ft::avlNode<T> *node){

				if (node == NULL)
					return (ft::make_pair(key(), value()));
				while (node->left != NULL)
					node = node->left;
				return (*(node->data));
			}
			
			T	findMax(ft::avlNode<T> *node){

				if (node == NULL)
					return (ft::make_pair(key(), value()));
				while (node->right != NULL)
					node = node->right;
				return (*(node->data));
			}
			
			T	findMin(ft::avlNode<T> *node)const{

				if (node == NULL)
					return (ft::make_pair(key(), value()));
				while (node->left != NULL)
					node = node->left;
				return (*(node->data));
			}
			
			T	findMax(ft::avlNode<T> *node)const{

				if (node == NULL)
					return (ft::make_pair(key(), value()));
				while (node->right != NULL)
					node = node->right;
				return (*(node->data));
			}
			
		private:
			ft::avlNode<T>	*_root;
			node_alloc		n_alloc;
			pair_alloc		p_alloc;
			int				_size;
			Compare			_cmp;
	};
}

#endif
