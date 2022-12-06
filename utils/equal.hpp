/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:53:32 by tbrebion          #+#    #+#             */
/*   Updated: 2022/12/06 15:09:27 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft{

	template<typename InputIt1>
	bool	equal(InputIt1 beg1, InputIt1 end1, InputIt1 beg2){
		
		while (beg1 != end1){

			if (!(*beg1 == *beg2)){
				
				return false;
			}
			++beg1, ++beg2;
		}
		return true;
	}
	
	template<typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 beg1, InputIt1 end1, InputIt2 beg2){
		
		while (beg1 != end1){

			if (!(*beg1 == *beg2)){
				
				return false;
			}
			++beg1, ++beg2;
		}
		return true;
	}
}

#endif
