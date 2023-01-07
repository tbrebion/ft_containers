/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:03 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/07 14:13:52 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "stack.hpp"
#include "map.hpp"
#include <map>

#define NAMESPACE ft

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}


int main()
{
	pair<int, std::string>			my_pair(8, "salut");
	map<int, std::string>			test;
	map<int, std::string>::iterator	it;

	test.insert(my_pair);
	test.insert(pair<int, std::string>(-4, "bar"));
	test.insert(pair<int, std::string>(2, "machin"));
	test.insert(pair<int, std::string>(3, "foo"));
	test.insert(pair<int, std::string>(746, "Marcel"));
	test.insert(pair<int, std::string>(1, "truc"));
	it = test.begin();
	std::cout << '\n';

	while (it != test.end())
	{
		std::cout << it->first << ", " << it->second << '\n';
		it++;
	}
	std::cout << "End of display loop\n";
}

// int main ()
// {
//   map<char,int> foo,bar;
//   foo['a']=100;
//   foo['b']=200;
//   bar['a']=10;
//   bar['z']=1000;

//   // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;
// }

// int main ()
// {
//   map<char,int> foo,bar;

//   foo['x']=100;
//   foo['y']=200;

//   bar['a']=11;
//   bar['b']=22;
//   bar['c']=33;


//   map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
//   map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

//   swap(bar, foo); //tmp iterates through bar
// 				//tmp2 iterates through foo


//   map<char, int>	other;

//   other['1'] = 73;
//   other['2'] = 173;
//   other['3'] = 763;
//   other['4'] = 73854;
//   other['5'] = 74683;
//   other['6'] = 753;

//   map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

//   std::cout << "foo contains:\n";
//   for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "bar contains:\n";
//   for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

// 	while(tmp != bar.end())
// 	{
// 		std::cout << tmp->first << " => " << tmp->second << '\n';
// 		tmp++;
// 	}
// 	tmp--;

// 	while(tmp2 != foo.end())
// 	{
// 		std::cout << tmp2->first << " => " << tmp2->second << '\n';
// 		tmp2++;
// 	}
// 	tmp2--;

// 	swap(other, foo); //tmp2 iterates through other
// 					//tmp3 iterates throught foo
// 	print(other);
// 	print(foo);
// 	print(bar);
// 	while(tmp != bar.begin())
// 	{
// 		std::cout << tmp->first << " => " << tmp->second << '\n';
// 		tmp--;
// 	}
// 	std::cout << tmp->first << " => " << tmp->second << '\n';

// 	while(tmp2 != other.begin())
// 	{
// 		std::cout << tmp2->first << " => " << tmp2->second << '\n';
// 		tmp2--;
// 	}
// 	std::cout << tmp2->first << " => " << tmp2->second << '\n';

// 	while(tmp3 != foo.end())
// 	{
// 		std::cout << tmp3->first << " => " << tmp3->second << '\n';
// 		tmp3++;
// 	}
// 	tmp3--;

// 	swap(bar, foo);
// 	swap(foo, bar);
// 	swap(bar, foo); //tmp3 iterates through bar
// 				//tmp iterates through foo

// 	print(other);
// 	print(foo);
// 	print(bar);

// 	while(tmp != foo.end())
// 	{
// 		std::cout << tmp->first << " => " << tmp->second << '\n';
// 		tmp++;
// 	}

// 	while(tmp2 != other.end())
// 	{
// 		std::cout << tmp2->first << " => " << tmp2->second << '\n';
// 		tmp2++;
// 	}

// 	while(tmp3 != bar.begin())
// 	{
// 		std::cout << tmp3->first << " => " << tmp3->second << '\n';
// 		tmp3--;
// 	}
// 	std::cout << tmp3->first << " => " << tmp3->second << '\n';
// }



// int main ()
// {
//   map<char,int> mymap;

//   mymap['x'] = 100;
//   mymap['y'] = 200;
//   mymap['z'] = 300;

//   // show content:
//   map<char,int>::reverse_iterator rit;
//   for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
//     std::cout << rit->first << " => " << rit->second << '\n';


// 	for (map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
//     std::cout << it->first << " => " << it->second << '\n';

// 	map<char, int>::const_reverse_iterator it = mymap.rbegin();
// 	map<char, int>::const_reverse_iterator ti = mymap.rend();

// 	it++;
// 	++it;
// 	it--;
// 	--it;

// 	ti--;
// 	--ti;
// 	++ti;
// 	ti++;

// 	ti = it;

// 	map<char, int>::reverse_iterator end = mymap.rend();
// 	while(it != end)
// 	{
//     	std::cout << it->first << " => " << it->second << '\n';
// 		it++;
// 	}


//   return 0;
// }



// int main ()
// {
//   map<char,int> mymap;
//   map<char,int>::iterator it;

//   // insert some values:
//   mymap['a']=10;
//   mymap['b']=20;
//   mymap['c']=30;
//   mymap['d']=40;
//   mymap['e']=50;
//   mymap['f']=60;

//   it=mymap.find('b');
//   std::cout << "found b\n";
//   mymap.erase (it);                   // erasing by iterator
//   // std::cout << "erase iterator to b\n";
//   // mymap.erase ('c');                  // erasing by key
//   // std::cout << "erase by key 'c'\n";
//   // it=mymap.find ('e');
//   // std::cout << "erase by range 'e' to end\n";
//   // mymap.erase ( it, mymap.end() );    // erasing by range

//   std::cout << " display :\n";
//   // show content:
  
//   std::cout << "mymap begin : " << mymap.begin()->first << std::endl;
  
//   for (it=mymap.begin(); it!=mymap.end(); ++it){

//     std::cout << it->first << " => " << it->second << '\n';
//   }

//   return 0;
// }


// int main ()
// {
//   map<char,int> mymap;

//   mymap['x']=100;
//   mymap['y']=200;
//   mymap['z']=300;

//   std::cout << "mymap contains:\n";
//   for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   mymap.clear();
//   mymap['a']=1101;
//   mymap['b']=2202;

//   std::cout << "mymap contains:\n";
//   for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   return 0;
// }

// int main ()
// {
//   map<char,int> mymap;


// 	if (mymap.begin() != mymap.end())
// 		std::cout << "This should not happen\n";

// 	///////////////////////////////////////
// 	// char a = 'a'; 
// 	// char b = 'b'; 
// 	// char c = 'c'; 

// 	// char &aref = a;
// 	// char &bref = b;
// 	// char &cref = c;
// 	///////////////////////////////////////

//   mymap['b'] = 100;
//   mymap['a'] = 200;
//   mymap['c'] = 300;
// 	// mymap[bref] = 100;
//   	// mymap[aref] = 200;
//   	// mymap[cref] = 300;

// 	if (mymap.begin() == mymap.end())
// 		std::cout << "This is wrong\n";
//   // show content:
//   for (map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); it++)
//     std::cout << it->first << " => " << it->second << '\n';

// 	std::cout << "Hello there\n";
// 	for (map<char,int>::const_iterator it=mymap.begin(); it!=mymap.end(); it++)
//     std::cout << it->first << " => " << it->second << '\n';
// 	std::cout << "General Kenobi\n";

// 	map<char, int>::const_iterator it = mymap.begin();
// 	map<char, int>::const_iterator ti = mymap.end();
// 	std::cout << "Wupwup\n";

// 	it++;
// 	++it;
// 	it--;
// 	--it;
// 	std::cout << "marker1\n";

// 	ti--;
// 	--ti;
// 	++ti;
// 	ti++;

// 	ti = it;

// 	std::cout << "Trump is a kiddo\n";
// 	map<char, int>::iterator end = mymap.end();
// 	while(it != end)
// 	{
//     	std::cout << it->first << " => " << it->second << '\n';
// 		it++;
// 	}

//   return 0;
// }

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////


// template <class T>
// void	print(vector<vector<T> >& lst)
// {
// 	for (typename vector<vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(vector<T>& lst)
// {
// 	for (typename vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }
// class Awesome {

// 	public:

// 		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
// 		Awesome( int n ) : _n( n ) { std::cout << "Int constructor" << std::endl; (void)n; }
// 		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
// 		virtual ~Awesome(void) {}

// 		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
// 		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// 		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
// 		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// 		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// 		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// 		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// 		void operator+=(int rhs){ _n += rhs; }
// 		int get( void ) const { return this->_n; }

// 	private:

// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template <class T>
// void	print_vector(vector<T> &test)
// {
// 	typename vector<T>::iterator		beg = test.begin();
// 	typename vector<T>::iterator		end = test.end();
// 	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
// 	for (typename vector<T>::iterator it = beg; it != end; it++)
// 	{
// 		std::cout << *it << " ";
// 		if (((it - beg) % 10 == 9) && it > beg)
// 			std::cout << std::endl;
// 	}
// 	std::cout << std::endl;
// }

// template <class T>
// void	push_pop_back_tests(void)
// {
// 	std::cout << std::endl << "PUSH BACK & POP BACK TESTS" << std::endl;
// 	vector<T> test;

// 	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
// 	for (size_t i = 0; i < 51; i++)
// 	{
// 		test.push_back(i);
// 		std::cout << test.size() << ": " << test.capacity() << " - ";
// 		if (!(i % 10) && i != 0)
// 			std::cout << std::endl;
// 	}
// 	print_vector<T>(test);
// 	test.pop_back();
// 	test.pop_back();
// 	test.pop_back();
// 	test.pop_back();
// 	print_vector<T>(test);
// }

// template <class T>
// void	resize_tests(void)
// {
// 	std::cout << std::endl << "RESIZE TESTS" << std::endl;
// 	vector<T> test(12, 12);

// 	test.resize(72);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(100);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(4170);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(171, 12);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(62);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// }

// template <class T>
// void	insert_tests()
// {
// 	std::cout << std::endl << "INSERT TESTS" << std::endl;
// 	vector<T> test(1, 1);
// 	vector<T> test2(5, 5);

// 	test.insert(test.begin(), 200, 12);
// 	print_vector<T>(test);
// 	test.insert(test.begin() + 12, 200, 30);
// 	print_vector<T>(test);
// 	test.insert(test.end(), 12, 50);
// 	print_vector<T>(test);
// 	test.insert(test.end() - 1, 0, 60);
// 	print_vector<T>(test);
// 	test.insert(test.end() - 1, 1, 70);
// 	print_vector<T>(test);
// 	test.insert(test.begin() + 412, test2.begin(), test2.end());
// 	print_vector<T>(test);
// 	test.insert(test.begin() + 6, test2.begin(), test2.end());
// 	print_vector<T>(test);
// 	test.insert(test.end(), test2.begin(), test2.end());
// 	print_vector<T>(test);
// }

// template <class T>
// void	reserve_tests(void)
// {
// 	std::cout << std::endl << "RESERVE TESTS" << std::endl;
// 	vector<T> test(65, 7);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(12);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(66);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(128);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(1023);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(10252);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	try
// 	{
// 		test.reserve(test.max_size() + 1);
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout << "error : " << e.what() << std::endl;
// 	}
// 	print_vector<T>(test);
// }

// template <class T>
// void	copy_swap_tests(void)
// {
// 	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
// 	vector<T> test;
// 	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
// 	vector<T> test_copy(test);
// 	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
// 	print_vector<T>(test_copy);
// 	vector<T> test_range(test.begin() + 20, test.begin() + 30);
// 	print_vector<T>(test_range);
// 	test_copy.swap(test);
// 	print_vector<T>(test);
// 	print_vector<T>(test_copy);
// 	test_copy.swap(test_range);
// 	print_vector<T>(test_range);
// 	print_vector<T>(test_copy);
// 	test.swap(test_copy);
// 	print_vector<T>(test);
// 	print_vector<T>(test_copy);
// }

// template <class T>
// void	reverse_it_tests(void)
// {
// 	std::cout << std::endl << "REVERSE IT TESTS" << std::endl;
// 	vector<T> test;
// 	for (size_t i = 0; i < 12; i++) { test.push_back(i); }
// 	typename vector<T>::reverse_iterator		revbeg = test.rbegin();
// 	for (typename vector<T>::reverse_iterator it = revbeg; it != test.rend(); it++)
// 	{
// 		std::cout << *it << " ";
// 		if (!((revbeg - it) % 10) && it != revbeg)
// 			std::cout << std::endl;
// 	}
// 	std::cout << *(test.rbegin() + 2) << std::endl;
// 	std::cout << *(test.rend() - 8) << std::endl;
// 	std::cout << (test.rbegin() == revbeg) << std::endl;
// 	revbeg++;
// 	std::cout << *revbeg << std::endl;
// 	std::cout << (test.rbegin() == test.rend()) << std::endl;
// 	std::cout << (test.rbegin() <= test.rbegin()) << std::endl;
// 	std::cout << (test.rbegin() < test.rend()) << std::endl;
// 	std::cout << (test.rbegin() >= test.rend()) << std::endl;
// 	revbeg += 3;
// 	std::cout << *revbeg << std::endl;
// 	std::cout << std::endl;
// }

// template <class T>
// void	erase_clear_tests(void)
// {
// 	std::cout << std::endl << "ERASE && CLEAR TESTS" << std::endl;
// 	vector<T> test(31, 12);
// 	test.erase(test.begin(), test.begin() + 5);
// 	print_vector<T>(test);
// 	test.erase(test.begin() + 12, test.begin() + 16);
// 	print_vector<T>(test);
// 	test.clear();
// 	print_vector<T>(test);
// }

// void	max_size_tests(void)
// {
// 	std::cout << std::endl << "MAX SIZE TESTS" << std::endl;
// 	vector<int> test(31, 12);
// 	vector<std::string> test2;
// 	vector<long long int> test3;
// 	vector<Awesome> test4;
// 	vector<unsigned int> test5(12, 340);
// 	std::cout << test.max_size() << std::endl;
// 	std::cout << test2.max_size() << std::endl;
// 	std::cout << test3.max_size() << std::endl;
// 	std::cout << test4.max_size() << std::endl;
// 	std::cout << test5.max_size() << std::endl;
// }

// void	awesome_tests(void)
// {
// 	std::cout << std::endl << "AWESOME TESTS" << std::endl;
// 	vector<Awesome> test(21, 12);
// 	print_vector<Awesome>(test);
// 	vector<Awesome> test2;
// 	print_vector<Awesome>(test2);
// 	test2.push_back(12);
// 	test2.push_back(8);
// 	test2.push_back(16);
// 	print_vector<Awesome>(test2);
// 	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
// 	test.assign(test2.begin(), test2.end());
// 	print_vector<Awesome>(test);
// 	test = test2;
// 	print_vector<Awesome>(test);
// 	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
// 	test.insert(test.end(), test2.begin(), test2.end());
// 	print_vector<Awesome>(test);
// 	test.insert(test.begin(), test2.begin(), test2.end());
// 	test2 = test;
// 	print_vector<Awesome>(test);
// 	std::cout << "end awesome test" << std::endl;
// }

// int main()
// {
// 	push_pop_back_tests<int>();
// 	resize_tests<int>();
// 	insert_tests<int>();
// 	reserve_tests<int>();
// 	copy_swap_tests<int>();
// 	reverse_it_tests<int>();
// 	erase_clear_tests<int>();
// 	max_size_tests();
// 	awesome_tests();
// 	push_pop_back_tests<Awesome>();
// 	resize_tests<Awesome>();
// 	insert_tests<Awesome>();
// 	reserve_tests<Awesome>();
// 	copy_swap_tests<Awesome>();
// 	reverse_it_tests<Awesome>();
// 	erase_clear_tests<Awesome>();
// }

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
