/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:10:58 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/22 16:30:06 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft{

	template<typename Tp, Tp v>
	struct integral_constant{
		
		typedef Tp value_type;
		typedef integral_constant<Tp, v> type;
		
		static const Tp value = v;

		operator value_type()const{

			return v;
		}
	};
	
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;
	
	template<typename Tp>
	struct is_integral : public false_type {};

	template<typename Tp>
	struct is_integral<const Tp> : public is_integral<Tp> {};

	template<typename Tp>
	struct is_integral<volatile Tp> : public is_integral<Tp> {};
	
	template<typename Tp>
	struct is_integral<volatile const Tp> : public is_integral<Tp> {};

	template<>
	struct is_integral<char> : public true_type {};

	template<>
	struct is_integral<bool> : public true_type {};

	template<>
	struct is_integral<int> : public true_type {};

	template<>
	struct is_integral<long> : public true_type {};

	template<>
	struct is_integral<long long> : public true_type {};
	
	template<>
	struct is_integral<short> : public true_type {};
	
	template<>
	struct is_integral<wchar_t> : public true_type {};

	template<>
	struct is_integral<unsigned char> : public true_type {};
	
	template<>
	struct is_integral<unsigned int> : public true_type {};

	template<>
	struct is_integral<unsigned long> : public true_type {};
	
	template<>
	struct is_integral<unsigned long long> : public true_type {};
	
	template<>
	struct is_integral<unsigned short> : public true_type {};	
}

#endif
