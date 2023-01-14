/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:32:56 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/14 21:20:53 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vector.hpp"
#include <vector>
#include "stack.hpp"
#include "map.hpp"
#include <map>
#include <list>
#include "utils/pair.hpp"
#include "common.hpp"

#define NAMESPACE ft

using namespace NAMESPACE;

#define T1 int
#define T2 std::string



struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};



typedef map<T1, T2, ft_more> ft_mp;
typedef map<T1, T2, ft_more>::iterator ft_mp_it;



int		main(void)
{
	ft_mp mp;


	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	// mp.insert(pair<int, std::string>(42, "fgzgxfn"));
	// mp.insert(pair<int, std::string>(25, "funny"));
	// mp.insert(pair<int, std::string>(80, "hey"));
	// mp.insert(pair<int, std::string>(12, "no"));
	// mp.insert(pair<int, std::string>(27, "bee"));
	// mp.insert(pair<int, std::string>(90, "8"));
	
	// ft_mp_it it = mp.end();
	// it--;
	// printPair(it);
	
	printSize(mp);

	return (0);
}
