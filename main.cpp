/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:03 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/30 16:09:01 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>


int main ()
{
	std::vector<int> foo (3,100);   // three ints with a value of 100
	std::vector<int> bar (2,200);   // two ints with a value of 200	
	
	if (foo==bar) std::cout << "foo and bar are equal\n";
	if (foo!=bar) std::cout << "foo and bar are not equal\n";
	if (foo< bar) std::cout << "foo is less than bar\n";
	if (foo> bar) std::cout << "foo is greater than bar\n";
	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	std::cout << std::endl << std::endl;

	ft::vector<int> ft_foo (3,100);   // three ints with a value of 100
	ft::vector<int> ft_bar (2,200);   // two ints with a value of 200	
	
	if (ft_foo==ft_bar) std::cout << "ft_foo and ft_bar are equal\n";
	if (ft_foo!=ft_bar) std::cout << "ft_foo and ft_bar are not equal\n";
	if (ft_foo< ft_bar) std::cout << "ft_foo is less than ft_bar\n";
	if (ft_foo> ft_bar) std::cout << "ft_foo is greater than ft_bar\n";
	if (ft_foo<=ft_bar) std::cout << "ft_foo is less than or equal to ft_bar\n";
	if (ft_foo>=ft_bar) std::cout << "ft_foo is greater than or equal to ft_bar\n";

	return 0;
}





// int	main(){

	// std::vector<int> vec;
// 
	// for (int i = 0; i < 10; i++){
// 
		// vec.push_back(i);
	// }
	// for (size_t i = 0; i < vec.size(); i++){
// 
		// std::cout << vec[i] << std::endl;
	// }
	// std::cout << "size : " << vec.size() << std::endl;
	// 
	// vec.pop_back();
	// vec.pop_back();
	// std::cout << "size : " << vec.size() << std::endl;
	// for (size_t i = 0; i < vec.size(); i++){
// 
		// std::cout << vec[i] << std::endl;
	// }
// 
	// std::cout << std::endl << std::endl;
// 
	// ft::vector<int> ft_vec;
// 
	// for (int i = 0; i < 10; i++){
// 
		// ft_vec.push_back(i);
	// }
	// for (size_t i = 0; i < ft_vec.size(); i++){
// 
		// std::cout << ft_vec[i] << std::endl;
	// }
	// std::cout << "size : " << ft_vec.size() << std::endl;
	// 
	// ft_vec.pop_back();
	// ft_vec.pop_back();
	// std::cout << "size : " << ft_vec.size() << std::endl;
	// for (size_t i = 0; i < ft_vec.size(); i++){
// 
		// std::cout << ft_vec[i] << std::endl;
	// }
	
	// return (0);
// }
