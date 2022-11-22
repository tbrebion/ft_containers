/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:33:43 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/22 16:54:16 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft{

	template<typename InputIt1, typename InputIt2>
	bool	lexicographical_compare(InputIt1 beg1, InputIt1 end1, 
									InputIt2 beg2, InputIt2 end2) {

		for ( ; (beg1 != end1) && (beg2 != end2); ++beg1, ++beg2){

			if (*beg1 < *beg2){
				
				return true;
			}

			if (*beg2 < *beg1){

				return false;
			}
		}
		return ((beg1 == end1) && (beg2 != end2));
	}
}

#endif
