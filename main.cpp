/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:32:56 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/13 18:43:37 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "common.hpp"

// #define T1 char
// #define T2 foo<float>
// typedef TESTED_NAMESPACE::map<T1, T2> _map;
// typedef _map::const_iterator const_it;

// static unsigned int i = 0;

// void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
// {
// 	bool res[2];

// 	std::cout << "\t-- [" << ++i << "] --" << std::endl;
// 	res[0] = mp.key_comp()(it1->first, it2->first);
// 	res[1] = mp.value_comp()(*it1, *it2);
// 	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
// 	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
// }

// int		main(void)
// {
// 	_map	mp;

// 	mp['a'] = 2.3;
// 	mp['b'] = 1.4;
// 	mp['c'] = 0.3;
// 	mp['d'] = 4.2;
// 	printSize(mp);

// 	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
// 		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
// 			ft_comp(mp, it1, it2);

// 	printSize(mp);
// 	return (0);
// }


#include "common.hpp"
#include <list>

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, (i + 1) * 7));

	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	TESTED_NAMESPACE::map<T1, T2>::iterator it_ = mp.begin();
	TESTED_NAMESPACE::map<T1, T2>::reverse_iterator it(it_), ite;
	printSize(mp);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == dec(it, 3).base()) << std::endl;

	printPair(it.base());
	printPair(inc(it.base(), 1));

	std::cout << "TEST OFFSET" << std::endl;
	--it;
	printPair(it);
	printPair(it.base());

	it = mp.rbegin(); ite = mp.rend();
	while (it != ite)
		std::cout << "[rev] " << printPair(it++, false) << std::endl;
	printReverse(mp);

	return (0);
}
