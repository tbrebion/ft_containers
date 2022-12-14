/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:43:57 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/11 16:23:03 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "utils.hpp"
#include "pair.hpp"

namespace ft{

	template<typename K, typename T>
	class mapIterator{

		public:
			typedef ft::pair<K, T> value_type;
			typedef ft::pair<K, T> &reference;
			typedef BNode<K, T> *pointer;

			mapIterator() : _ptr(0) {}
			mapIterator(const pointer &p) : _ptr(p) {}
			mapIterator(const mapIterator &cp) {

				(*this) = cp;
			}
			mapIterator	&operator=(const mapIterator &x){

				this->_ptr = x._ptr;
				return (*this);
			}
			pointer	node()const{

				return (_ptr);
			}

			value_type	&operator*()const{

				return (_ptr->pair);
			}

			value_type	*operator->()const{

				return (&_ptr->pair);
			}
			
			bool	operator==(const mapIterator<K, T> &x){

				return (_ptr == x._ptr);
			}

			bool	operator!=(const mapIterator<K, T> &x){

				return (!(*this == x));
			}

			bool	operator>(const mapIterator<K, T> &x){

				return (_ptr > x._ptr);
			}

			bool	operator<(const mapIterator<K, T> &x){

				return (_ptr < x._ptr);
			}

			bool	operator>=(const mapIterator<K, T> &x){

				return (_ptr >= x._ptr);
			}

			bool	operator<=(const mapIterator<K, T> &x){

				return (_ptr <= x._ptr);
			}

			mapIterator	&operator++(){

				_ptr = successor(_ptr);
				return (*this);
			}
			
			mapIterator	&operator--(){

				_ptr = predecessor(_ptr);
				return (*this);
			}

			mapIterator	operator++(int){

				mapIterator	tmp(*this);
				this->operator++();
				return (tmp);
			}
			
			mapIterator	operator--(int){

				mapIterator	tmp(*this);
				this->operator--();
				return (tmp);
			}

			const pointer	&getPtr()const{

				return (_ptr);
			}
			const pointer	&base()const{

				return (_ptr);
			}
		protected:
			pointer	_ptr;
			
		private:
			pointer	successor(pointer ptr){

				pointer next;
				if (!ptr->right){

					next = ptr;
					while(next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			}
			
			pointer	predecessor(pointer ptr){

				pointer next;
				if (!ptr->left){

					next = ptr;
					while(next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->left;
					while(next->right)
						next = next->right;
				}
				return (next);
			}
	};

////////////////////////////////////////////////////////////////////////////////
	
	template<typename K, typename T>
	class constMapIterator{

		public:
			typedef ft::pair<K, T> value_type;
			typedef ft::pair<K, T> &reference;
			typedef BNode<K, T> *pointer;

			constMapIterator() : _ptr(0) {}
			constMapIterator(const pointer &p) : _ptr(p) {}
			constMapIterator(const constMapIterator &cp) {

				(*this) = cp;
			}
			constMapIterator(const mapIterator<K, T> &cp) {

				(*this) = cp;
			}
			constMapIterator	&operator=(const constMapIterator &x){

				this->_ptr = x._ptr;
				return (*this);
			}
			constMapIterator	&operator=(const mapIterator<K, T> &x){

				this->_ptr = x.getPtr();
				return (*this);
			}
			pointer	node()const{

				return (_ptr);
			}

			value_type	&operator*()const{

				return (_ptr->pair);
			}

			value_type	*operator->()const{

				return (&_ptr->pair);
			}
			
			bool	operator==(const constMapIterator<K, T> &x){

				return (_ptr == x._ptr);
			}

			bool	operator!=(const constMapIterator<K, T> &x){

				return (!(*this == x));
			}

			bool	operator>(const constMapIterator<K, T> &x){

				return (_ptr > x._ptr);
			}

			bool	operator<(const constMapIterator<K, T> &x){

				return (_ptr < x._ptr);
			}

			bool	operator>=(const constMapIterator<K, T> &x){

				return (_ptr >= x._ptr);
			}

			bool	operator<=(const constMapIterator<K, T> &x){

				return (_ptr <= x._ptr);
			}

			constMapIterator	&operator++(){

				_ptr = successor(_ptr);
				return (*this);
			}
			
			constMapIterator	&operator--(){

				_ptr = predecessor(_ptr);
				return (*this);
			}

			constMapIterator	operator++(int){

				constMapIterator	tmp(*this);
				this->operator++();
				return (tmp);
			}
			
			constMapIterator	operator--(int){

				constMapIterator	tmp(*this);
				this->operator--();
				return (tmp);
			}
			
			const pointer	&getPtr()const{

				return (_ptr);
			}

			const pointer	&base()const{

				return (_ptr);
			}

		protected:
			pointer	_ptr;
			
		private:
			pointer	successor(pointer ptr){

				pointer next;
				if (!ptr->right){

					next = ptr;
					while(next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			}
			
			pointer	predecessor(pointer ptr){

				pointer next;
				if (!ptr->left){

					next = ptr;
					while(next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->left;
					while(next->right)
						next = next->right;
				}
				return (next);
			}
	};

// ////////////////////////////////////////////////////////////////////////////////

	template<typename K, typename T>
	class reverseMapIterator{

		public:
			typedef ft::pair<K, T> value_type;
			typedef ft::pair<K, T> &reference;
			typedef BNode<K, T> *pointer;

			reverseMapIterator() : _ptr(0) {}
			reverseMapIterator(const pointer &p) : _ptr(p) {}
			reverseMapIterator(const reverseMapIterator &cp) {

				(*this) = cp;
			}
			reverseMapIterator(const mapIterator<K, T> &cp) {

				(*this) = cp;
			}
			reverseMapIterator(const constMapIterator<K, T> &cp) {

				(*this) = cp;
			}
			reverseMapIterator	&operator=(const reverseMapIterator &x){

				this->_ptr = x._ptr;
				return (*this);
			}
			reverseMapIterator	&operator=(const mapIterator<K, T> &x){

				this->_ptr = x.getPtr();
				return (*this);
			}
			reverseMapIterator	&operator=(const constMapIterator<K, T> &x){

				this->_ptr = x.getPtr();
				return (*this);
			}
			pointer	node()const{

				return (_ptr);
			}

			value_type	&operator*()const{

				return (_ptr->pair);
			}

			value_type	*operator->()const{

				return (&_ptr->pair);
			}
			
			bool	operator==(const reverseMapIterator<K, T> &x){

				return (_ptr == x._ptr);
			}

			bool	operator!=(const reverseMapIterator<K, T> &x){

				return (!(*this == x));
			}

			bool	operator>(const reverseMapIterator<K, T> &x){

				return (_ptr > x._ptr);
			}

			bool	operator<(const reverseMapIterator<K, T> &x){

				return (_ptr < x._ptr);
			}

			bool	operator>=(const reverseMapIterator<K, T> &x){

				return (_ptr >= x._ptr);
			}

			bool	operator<=(const reverseMapIterator<K, T> &x){

				return (_ptr <= x._ptr);
			}

			reverseMapIterator	&operator++(){

				_ptr = predecessor(_ptr);
				return (*this);
			}
			
			reverseMapIterator	&operator--(){

				_ptr = successor(_ptr);
				return (*this);
			}

			reverseMapIterator	operator++(int){

				reverseMapIterator	tmp(*this);
				this->operator++();
				return (tmp);
			}
			
			reverseMapIterator	operator--(int){

				reverseMapIterator	tmp(*this);
				this->operator--();
				return (tmp);
			}

			const pointer	&getPtr()const{

				return (_ptr);
			}
			
			const pointer	&base()const{

				return (_ptr);
			}

		protected:
			pointer	_ptr;
			
		private:
			pointer	successor(pointer ptr){

				pointer next;
				if (!ptr->right){

					next = ptr;
					while(next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			}
			
			pointer	predecessor(pointer ptr){

				pointer next;
				if (!ptr->left){

					next = ptr;
					while(next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->left;
					while(next->right)
						next = next->right;
				}
				return (next);
			}
	};
	
////////////////////////////////////////////////////////////////////////////////

	template<typename K, typename T>
	class constReverseMapIterator{

		public:
			typedef ft::pair<K, T> value_type;
			typedef ft::pair<K, T> &reference;
			typedef BNode<K, T> *pointer;

			constReverseMapIterator() : _ptr(0) {}
			constReverseMapIterator(const pointer &p) : _ptr(p) {}
			constReverseMapIterator(const constReverseMapIterator &cp) {

				(*this) = cp;
			}
			constReverseMapIterator(const reverseMapIterator<K, T> &cp) {

				(*this) = cp;
			}
			
			constReverseMapIterator(const mapIterator<K, T> &cp) {

				(*this) = cp;
			}
			constReverseMapIterator(const constMapIterator<K, T> &cp) {

				(*this) = cp;
			}
			constReverseMapIterator	&operator=(const constReverseMapIterator &x){

				this->_ptr = x._ptr;
				return (*this);
			}
			constReverseMapIterator	&operator=(const reverseMapIterator<K, T> &x){

				this->_ptr = x.getPtr();
				return (*this);
			}			
			constReverseMapIterator	&operator=(const mapIterator<K, T> &x){

				this->_ptr = x.getPtr();
				return (*this);
			}
			constReverseMapIterator	&operator=(const constMapIterator<K, T> &x){

				this->_ptr = x.getPtr();
				return (*this);
			}
			
			pointer	node()const{

				return (_ptr);
			}

			value_type	&operator*()const{

				return (_ptr->pair);
			}

			value_type	*operator->()const{

				return (&_ptr->pair);
			}
			
			bool	operator==(const constReverseMapIterator<K, T> &x){

				return (_ptr == x._ptr);
			}

			bool	operator!=(const constReverseMapIterator<K, T> &x){

				return (!(*this == x));
			}

			bool	operator>(const constReverseMapIterator<K, T> &x){

				return (_ptr > x._ptr);
			}

			bool	operator<(const constReverseMapIterator<K, T> &x){

				return (_ptr < x._ptr);
			}

			bool	operator>=(const constReverseMapIterator<K, T> &x){

				return (_ptr >= x._ptr);
			}

			bool	operator<=(const constReverseMapIterator<K, T> &x){

				return (_ptr <= x._ptr);
			}

			constReverseMapIterator	&operator++(){

				_ptr = predecessor(_ptr);
				return (*this);
			}
			
			constReverseMapIterator	&operator--(){

				_ptr = successor(_ptr);
				return (*this);
			}

			constReverseMapIterator	operator++(int){

				constReverseMapIterator	tmp(*this);
				this->operator++();
				return (tmp);
			}
			
			constReverseMapIterator	operator--(int){

				constReverseMapIterator	tmp(*this);
				this->operator--();
				return (tmp);
			}
			
			const pointer	&getPtr()const{

				return (_ptr);
			}

			const pointer	&base()const{

				return (_ptr);
			}

		protected:
			pointer	_ptr;
			
		private:
			pointer	successor(pointer ptr){

				pointer next;
				if (!ptr->right){

					next = ptr;
					while(next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			}
			
			pointer	predecessor(pointer ptr){

				pointer next;
				if (!ptr->left){

					next = ptr;
					while(next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else{

					next = ptr->left;
					while(next->right)
						next = next->right;
				}
				return (next);
			}
	};
}

#endif
