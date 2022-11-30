/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:03 by tbrebion          #+#    #+#             */
/*   Updated: 2022/11/30 18:41:30 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>



template <class T>
void	print(std::vector<std::vector<T> >& lst)
{
	for (typename std::vector<std::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename std::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(std::vector<T>& lst)
{
	for (typename std::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}


template <class T>
void	print(ft::vector<ft::vector<T> >& lst)
{
	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(ft::vector<T>& lst)
{
	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}


int main ()
{
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

{
	std::vector<int> foo,bar;

	foo.push_back(100);
	foo.push_back(200);

	bar.push_back(11);
	bar.push_back(22);
	bar.push_back(33);


	std::vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	std::vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

	swap(bar, foo); //tmp iterates through bar
					//tmp2 iterates through foo


	std::vector<int>	other;

	other.push_back(73);
	other.push_back(173);
	other.push_back(763);
	other.push_back(73854);
	other.push_back(74683);
	other.push_back(753);

	std::vector<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

		std::cout << "foo contains:\n";
		for (std::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
			std::cout << *it << '\n';
	
		std::cout << "bar contains:\n";
		for (std::vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
			std::cout << *it << '\n';

		while(tmp != bar.end())
		{
			std::cout << *tmp << '\n';
			tmp++;
		}
		tmp--;

		while(tmp2 != foo.end())
		{
			std::cout << *tmp2 << '\n';
			tmp2++;
		}
		tmp2--;

		swap(other, foo); //tmp2 iterates through other
						//tmp3 iterates throught foo
		print(other);
		print(foo);
		print(bar);
		while(tmp != bar.begin())
		{
			std::cout << *tmp << '\n';
			tmp--;
		}
		std::cout << *tmp << '\n';

		while(tmp2 != other.begin())
		{
			std::cout << *tmp2 << '\n';
			tmp2--;
		}
			std::cout << *tmp2 << '\n';

		while(tmp3 != foo.end())
		{
			std::cout << *tmp3 << '\n';
			tmp3++;
		}
		tmp3--;

		swap(bar, foo);
		swap(foo, bar);
		swap(bar, foo); //tmp3 iterates through bar
					//tmp iterates through foo

		print(other);
		print(foo);
		print(bar);

		while(tmp != foo.end())
		{
			std::cout << *tmp << '\n';
			tmp++;
		}

		while(tmp2 != other.end())
		{
			std::cout << *tmp2 << '\n';
			tmp2++;
		}

		while(tmp3 != bar.begin())
		{
			std::cout << *tmp3 << '\n';
			tmp3--;
		}
			std::cout << *tmp3 << '\n';
}
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////


	std::cout << std::endl << std::endl << std::endl;

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

  ft::vector<int> ft_foo (3,100);   // three ints with a value of 100
  ft::vector<int> ft_bar (5,200);   // five ints with a value of 200

  ft_foo.swap(ft_bar);

  std::cout << "ft_foo contains:";
  for (unsigned i=0; i<ft_foo.size(); i++)
    std::cout << ' ' << ft_foo[i];
  std::cout << '\n';

  std::cout << "ft_bar contains:";
  for (unsigned i=0; i<ft_bar.size(); i++)
    std::cout << ' ' << ft_bar[i];
  std::cout << '\n';

{
	ft::vector<int> ft_foo,ft_bar;

	ft_foo.push_back(100);
	ft_foo.push_back(200);

	ft_bar.push_back(11);
	ft_bar.push_back(22);
	ft_bar.push_back(33);


	ft::vector<int>::const_iterator ft_tmp = ft_foo.begin(); //ft_tmp iterates through ft_foo
	ft::vector<int>::const_iterator ft_tmp2 = ft_bar.begin(); //ft_tmp2 iterates through ft_bar

	ft::swap(ft_bar, ft_foo); //ft_tmp iterates through ft_bar
					//ft_tmp2 iterates through ft_foo


	ft::vector<int>	ft_other;

	ft_other.push_back(73);
	ft_other.push_back(173);
	ft_other.push_back(763);
	ft_other.push_back(73854);
	ft_other.push_back(74683);
	ft_other.push_back(753);

	ft::vector<int>::const_iterator ft_tmp3 = ft_other.begin(); // ft_tmp3 iterates through ft_other

		std::cout << "ft_foo contains:\n";
		for (ft::vector<int>::iterator it=ft_foo.begin(); it!=ft_foo.end(); ++it)
			std::cout << *it << '\n';
	
		std::cout << "ft_bar contains:\n";
		for (ft::vector<int>::iterator it=ft_bar.begin(); it!=ft_bar.end(); ++it)
			std::cout << *it << '\n';

		while(ft_tmp != ft_bar.end())
		{
			std::cout << *ft_tmp << '\n';
			ft_tmp++;
		}
		ft_tmp--;

		while(ft_tmp2 != ft_foo.end())
		{
			std::cout << *ft_tmp2 << '\n';
			ft_tmp2++;
		}
		ft_tmp2--;

		ft::swap(ft_other, ft_foo); //ft_tmp2 iterates through ft_other
						//ft_tmp3 iterates throught ft_foo
		print(ft_other);
		print(ft_foo);
		print(ft_bar);
		while(ft_tmp != ft_bar.begin())
		{
			std::cout << *ft_tmp << '\n';
			ft_tmp--;
		}
		std::cout << *ft_tmp << '\n';

		while(ft_tmp2 != ft_other.begin())
		{
			std::cout << *ft_tmp2 << '\n';
			ft_tmp2--;
		}
			std::cout << *ft_tmp2 << '\n';

		while(ft_tmp3 != ft_foo.end())
		{
			std::cout << *ft_tmp3 << '\n';
			ft_tmp3++;
		}
		ft_tmp3--;

		ft::swap(ft_bar, ft_foo);
		ft::swap(ft_foo, ft_bar);
		ft::swap(ft_bar, ft_foo); //ft_tmp3 iterates through ft_bar
					//ft_tmp iterates through ft_foo

		print(ft_other);
		print(ft_foo);
		print(ft_bar);

		while(ft_tmp != ft_foo.end())
		{
			std::cout << *ft_tmp << '\n';
			ft_tmp++;
		}

		while(ft_tmp2 != ft_other.end())
		{
			std::cout << *ft_tmp2 << '\n';
			ft_tmp2++;
		}

		while(ft_tmp3 != ft_bar.begin())
		{
			std::cout << *ft_tmp3 << '\n';
			ft_tmp3--;
		}
			std::cout << *ft_tmp3 << '\n';
}


  return 0;
}

