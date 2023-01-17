/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:03 by tbrebion          #+#    #+#             */
/*   Updated: 2023/01/17 18:13:00 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include "stack.hpp"
#include "map.hpp"
#include <map>
#include <list>
#include "utils/pair.hpp"

#define NAMESPACE ft

using namespace NAMESPACE;


template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp, bool print_content = 1)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << printPair(it, false) << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <typename Ty1, typename Ty2>
void	printReverse(map<Ty1, Ty2> &mp)
{
	typename map<Ty1, Ty2>::iterator it = mp.end(), ite = mp.begin();

	std::cout << "printReverse:" << std::endl;
	while (it != ite) {
		it--;
		std::cout << "-> " << printPair(it, false) << std::endl;
	}
	std::cout << "_______________________________________________" << std::endl;
}


template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}


//////////////////////////////////////////////////////////////////////////////////////
//									MAIN											//
//////////////////////////////////////////////////////////////////////////////////////


//MAP


// # define _END			"\x1b[0m"
// # define _BOLD			"\x1b[1m"
// # define _UNDER			"\x1b[4m"
// # define _REV			"\x1b[7m"

// /*
// ** Colors
// */
// # define _GREY			"\x1b[30m"
// # define _RED			"\x1b[31m"
// # define _GREEN			"\x1b[32m"
// # define _YELLOW		"\x1b[33m"
// # define _BLUE			"\x1b[34m"
// # define _PURPLE		"\x1b[35m"
// # define _CYAN			"\x1b[36m"
// # define _WHITE			"\x1b[37m"

// /*
// ** Inverted, i.e. colored backgrounds
// */
// # define _IGREY			"\x1b[40m"
// # define _IRED			"\x1b[41m"
// # define _IGREEN		"\x1b[42m"
// # define _IYELLOW		"\x1b[43m"
// # define _IBLUE			"\x1b[44m"
// # define _IPURPLE		"\x1b[45m"
// # define _ICYAN			"\x1b[46m"
// # define _IWHITE		"\x1b[47m"




// #include <map>
// #include <cstdio>
// #include <iomanip>


// int main()
// {
// 	std::cout << _WHITE << "# test_map" << _END << std::endl;
// 	std::cout << _YELLOW <<  "/* ********************************************************************** */" << std::endl;
// 	std::cout << "/*                          "<< _WHITE << "BASIC TESTS" << _YELLOW << "                                   */" << std::endl;
// 	std::cout << "/* ********************************************************************** */" << _END << std::endl;
// 	std::cout << std::endl;


// 	map<std::string, int> mymap;
// 	print(mymap);


// 	std::cout << "mymap<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap;" << std::endl;

// 	std::cout << std::endl;
// 	std::cout << "mymap.max_size(): " << (mymap.max_size() > 10000) << std::endl;
// 	print(mymap);
// 	std::cout << std::endl;


// 	print(mymap);
// 	mymap.insert(pair<std::string, int>("ft", 42));

// 	print(mymap);
// 	mymap.insert(pair<std::string, int>("one", 1));


// 	std::cout << _WHITE << "# testing upper/lower_bound" << _END << std::endl;
// 	map<std::string, int>::iterator mit;
// 	map<std::string, int>::iterator it;
// 	print(mymap);
// 	it = mymap.lower_bound("aaa");
// 	print(mymap);
// 	std::cout << std::setw(40) << "mymap.lower_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.lower_bound("one");
// 	print(mymap);
// 	std::cout << std::setw(40) << "mymap.lower_bound(\"one\"): " << it->first << ":" << it->second << std::endl;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.lower_bound("oae");
// 	print(mymap);
// 	std::cout << std::setw(40) << "mymap.lower_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.lower_bound("ft");
// 	print(mymap);
// 	std::cout << std::setw(40) << "mymap.lower_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.lower_bound("zzz");
// 	print(mymap);
	
// 	if (it == mymap.end())
// 		std::cout << std::setw(40) << "mymap.lower_bound(\"zzz\"): mymap.end()" << std::endl;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.upper_bound("aaa");
	
// 	print(mymap);
// 	std::cout << std::setw(40) << "mymap.upper_bound(\"aaa\"): " << it->first << ":" << it->second << std::endl;;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.upper_bound("oae");
// 	print(mymap);
// 	std::cout << std::setw(40) << "mymap.upper_bound(\"oae\"): " << it->first << ":" << it->second << std::endl;;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.upper_bound("one");
	
// 	if (it == mymap.end())
// 		std::cout << std::setw(40) << "mymap.upper_bound(\"one\"): mymap.end()" << std::endl;
// 	print(mymap);
// 	std::cout << std::endl;
// 	it = mymap.upper_bound("ft");
// 	print(mymap);
// 	std::cout << std::setw(40) << "mymap.upper_bound(\"ft\"): " << it->first << ":" << it->second << std::endl;;
// 	std::cout << std::endl;
// 	print(mymap);
// 	it = mymap.upper_bound("zzz");
	
// 	if (it == mymap.end())
// 		std::cout << std::setw(40) << "mymap.upper_bound(\"zzz\"): mymap.end()" << std::endl;
// 	print(mymap);
// 	std::cout << std::endl;

// 	print(mymap);
// 	mymap.erase("undefined");
// 	print(mymap);
// 	mymap.erase("ft");
// 	print(mymap);
// 	std::cout << _WHITE << "# double clear" << _END << std::endl;
// 	mymap.clear();
// 	print(mymap);
// 	mymap.clear();
// 	print(mymap);
// 	mymap["lol"];
// 	print(mymap);
// 	mymap.insert(pair<std::string, int>("xD", 123));
// 	print(mymap);
// 	mymap.insert(mymap.end(), pair<std::string, int>("uch", 442));
// 	print(mymap);
// 	mymap.insert(mymap.begin(), pair<std::string, int>("uch", 22));
// 	print(mymap);
// 	mymap.insert(mymap.end(), pair<std::string, int>("uch", 23));
// 	print(mymap);
// 	mymap.insert(pair<std::string, int>("uch", 23));
// 	print(mymap);
// 	mymap["lol"] = 8;


// 	print(mymap);
// 	map<std::string, int> map2;

// 	print(mymap);
// 	print(map2);
// 	std::cout << "mymap<" << _PURPLE << "std::string" << _END << ", " << _PURPLE << "int" << _END <<"> mymap2;" << std::endl;
// 	print(mymap);
// 	std::cout << "empty line\n";
// 	print(map2);
// 	std::cout << "empty line2\n";

// 	swap(mymap, map2);
// 	std::cout << "empty line3\n";
// 	print(mymap);
// 	std::cout << "empty line4\n";
// 	print(map2);
// 	std::cout << "empty line5\n";

// 	mymap = map2;
// 	print(mymap);
// 	print(map2);

// 	std::cout << std::setw(40) << "map == map2: " << (mymap == map2) << std::endl;
// 	print(mymap);
// 	print(map2);
// 	std::cout << std::endl;

// 	mymap.clear();
// 	print(mymap);
// 	print(map2);

// 	mymap["satan"] = 666;
// 	print(mymap);
// 	print(map2);
// 	std::cout << std::setw(40) << "mymap == map2: " << (mymap == map2) << std::endl;
// 	print(mymap);
// 	print(map2);
// 	std::cout << std::endl;
// 	std::cout << std::setw(40) << "mymap <= map2: " << (mymap <= map2) << std::endl;
// 	print(mymap);
// 	print(map2);
// 	std::cout << std::endl;
// 	std::cout << std::setw(40) << "mymap >= map2: " << (mymap >= map2) << std::endl;
// 	print(mymap);
// 	print(map2);
// 	std::cout << std::endl;
// 	std::cout << std::setw(40) << "mymap > map2: " << (mymap > map2) << std::endl;
// 	print(mymap);
// 	print(map2);
// 	std::cout << std::endl;
// 	std::cout << std::setw(40) << "mymap < map2: " << (mymap > map2) << std::endl;
// 	print(mymap);
// 	print(map2);
// 	std::cout << std::endl;

// 	return 0;
// }











// #define T1 char
// #define T2 int

// template <class MAP>
// void	cmp(const MAP &lhs, const MAP &rhs)
// {
// 	static int i = 0;

// 	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
// 	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
// 	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
// 	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
// }

// int		main(void)
// {
// 	map<T1, T2> mp1;
// 	map<T1, T2> mp2;

// 	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
// 	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

// 	cmp(mp1, mp1); // 0
// 	cmp(mp1, mp2); // 1

// 	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

// 	cmp(mp1, mp2); // 2
// 	cmp(mp2, mp1); // 3

// 	(++(++mp1.begin()))->second = 42;

// 	/////////////////////////////////////////////////
	
// 	std::cout << "/////////////////////////////////////////" << std::endl;
	
// 	for(map<T1, T2>::iterator it1 = mp1.begin(); it1 != mp1.end(); ++it1){

// 		printPair(it1);
// 	}
	
// 	std::cout << "/////////////////////////////////////////" << std::endl;
	
// 	for(map<T1, T2>::iterator it2 = mp2.begin(); it2 != mp2.end(); ++it2){

// 		printPair(it2);
// 	}

// 	std::cout << "/////////////////////////////////////////" << std::endl;
	
// 	/////////////////////////////////////////////////

// 	cmp(mp1, mp2); // 4
// 	cmp(mp2, mp1); // 5

// 	swap(mp1, mp2);
	
// 	/////////////////////////////////////////////////
	
// 	std::cout << "/////////////////////////////////////////" << std::endl;
	
// 	for(map<T1, T2>::iterator it1 = mp1.begin(); it1 != mp1.end(); ++it1){

// 		printPair(it1);
// 	}
	
// 	std::cout << "/////////////////////////////////////////" << std::endl;
	
// 	for(map<T1, T2>::iterator it2 = mp2.begin(); it2 != mp2.end(); ++it2){

// 		printPair(it2);
// 	}

// 	std::cout << "/////////////////////////////////////////" << std::endl;
	
// 	/////////////////////////////////////////////////

// 	cmp(mp1, mp2); // 6
// 	cmp(mp2, mp1); // 7

// 	return (0);
// }






// template <typename T>
// class foo {
// 	public:
// 		typedef T	value_type;

// 		foo(void) : value(), _verbose(false) { };
// 		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
// 		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
// 		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
// 		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
// 		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
// 		foo &operator=(value_type src) { this->value = src; return *this; };
// 		foo &operator=(foo const &src) {
// 			if (this->_verbose || src._verbose)
// 				std::cout << "foo::operator=(foo) CALLED" << std::endl;
// 			this->value = src.value;
// 			return *this;
// 		};
// 		value_type	getValue(void) const { return this->value; };
// 		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

// 		operator value_type(void) const {
// 			return value_type(this->value);
// 		}
// 	private:
// 		value_type	value;
// 		bool		_verbose;
// };

// #define T1 float
// #define T2 foo<int>
// typedef pair<const T1, T2> T3;

// int		main(void)
// {
// 	std::list<T3> lst;
// 	unsigned int lst_size = 5;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(2.5 - i, (i + 1) * 7));

// 	map<T1, T2> mp(lst.begin(), lst.end());
// 	map<T1, T2>::reverse_iterator it(mp.rbegin());
// 	map<T1, T2>::const_reverse_iterator ite(mp.rbegin());
// 	printSize(mp);

// 	printPair(++ite);
// 	printPair(ite++);
// 	printPair(ite++);
// 	printPair(++ite);

// 	it->second.m();
// 	ite->second.m();

// 	printPair(++it);
// 	printPair(it++);
// 	printPair(it++);
// 	printPair(++it);

// 	printPair(--ite);
// 	printPair(ite--);
// 	printPair(--ite);
// 	printPair(ite--);

// 	(*it).second.m();
// 	(*ite).second.m();

// 	printPair(--it);
// 	printPair(it--);
// 	printPair(it--);
// 	printPair(--it);

// 	return (0);
// }












// struct ft_more {
// 	bool	operator()(const int &first, const int &second) const {
// 		return (first > second);
// 	}
// };



// int main()
// {
// 	pair<int, std::string>			my_pair(8, "salut");
// 	map<int, std::string, ft_more>			test;

// 	test.insert(my_pair);
// 	test.insert(pair<int, std::string>(-4, "bar"));
// 	test.insert(pair<int, std::string>(0, "MYTEST"));
// 	test.insert(pair<int, std::string>(2, "machin"));
// 	test.insert(pair<int, std::string>(3, "foo"));
// 	test.insert(pair<int, std::string>(746, "Marcel"));
// 	test.insert(pair<int, std::string>(1, "truc"));
// 	test.insert(test.end(), pair<int, std::string>(12, "NEWWWWWWWWWWWWWWW"));
	
// 	printSize(test);
	
// 	return (0);
// }









// int main ()
// {
// 	map<char,int> foo,bar;
// 	foo['a']=100;
// 	foo['b']=200;
// 	bar['a']=10;
// 	bar['z']=1000;

// 	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
// 	if (foo==bar) std::cout << "foo and bar are equal\n";
// 	if (foo!=bar) std::cout << "foo and bar are not equal\n";
// 	if (foo< bar) std::cout << "foo is less than bar\n";
// 	if (foo> bar) std::cout << "foo is greater than bar\n";
// 	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// 	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

// 	return 0;
// }



















// int main ()
// {
// 	map<char,int> foo,bar;

// 	foo['x']=100;
// 	foo['y']=200;

// 	bar['a']=11;
// 	bar['b']=22;
// 	bar['c']=33;


// 	map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
// 	map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

// 	swap(bar, foo); //tmp iterates through bar
// 				//tmp2 iterates through foo


// 	map<char, int>	other;

// 	other['1'] = 73;
// 	other['2'] = 173;
// 	other['3'] = 763;
// 	other['4'] = 73854;
// 	other['5'] = 74683;
// 	other['6'] = 753;

// 	map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

// 	std::cout << "foo contains:\n";
// 	for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
// 	std::cout << it->first << " => " << it->second << '\n';

// 	std::cout << "bar contains:\n";
// 	for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
// 	std::cout << it->first << " => " << it->second << '\n';

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
// 	return (0);
// }










// int main ()
// {
// 	map<char,int> mymap;

// 	mymap['x'] = 100;
// 	mymap['y'] = 200;
// 	mymap['z'] = 300;

// 	// show content:
// 	map<char,int>::reverse_iterator rit;
// 	for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
// 		std::cout << rit->first << " => " << rit->second << '\n';


// 	for (map<char,int>::const_reverse_iterator it=mymap.rbegin(); it!=mymap.rend(); it++)
// 		std::cout << it->first << " => " << it->second << '\n';

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
// 		std::cout << it->first << " => " << it->second << '\n';
// 		it++;
// 	}


// 	return 0;
// }







// int main ()
// {
// 	map<char,int> mymap;
// 	map<char,int>::iterator it;

// 	// insert some values:
// 	mymap['a']=10;
// 	mymap['b']=20;
// 	mymap['c']=30;
// 	mymap['d']=40;
// 	mymap['e']=50;
// 	mymap['f']=60;

// 	it=mymap.find('b');
// 	std::cout << "found b\n";
// 	mymap.erase (it);                   // erasing by iterator

// 	std::cout << " display :\n";
// 	// show content:

// 	std::cout << "mymap begin : " << mymap.begin()->first << std::endl;

// 	for (it=mymap.begin(); it!=mymap.end(); ++it){

// 		std::cout << it->first << " => " << it->second << '\n';
// 	}

// 	return 0;
// }





///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

// VECTOR :

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
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////



// STACK :

#include <vector>
#include <iostream>
#include <iomanip>
#include <limits>

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

int main()
{
	std::vector<int>	myv;

	std::cout << "myv.max_size(): " << (myv.max_size() > 10000) << std::endl;

	try
	{
		myv.front();
	}
	catch (std::exception &e)
	{
		std::cout << "Catching exception myv: " << e.what() << std::endl;
	}

	myv.back();
	
	try
	{
		myv.at(0);
	}
	catch (std::exception &e)
	{
		std::cout << "Catching exception myv: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "myv.capacity(): " << myv.capacity() << std::endl;
	myv.reserve(0);
	std::cout << "myv.reserve(0);" << std::endl;
	std::cout << "myv.capacity(): " << myv.capacity() << std::endl;
	try
	{
		myv.reserve(1);
	}
	catch (std::exception& e)
	{
		std::cout << "caught : " << e.what() << std::endl;
	}
	std::cout << "myv.capacity(): " << myv.capacity() << std::endl;
	std::cout << std::endl;

	std::cout << "myv.reserve(" << std::numeric_limits<size_t>::max() << ");" << std::endl;
	try
	{
		myv.reserve(std::numeric_limits<size_t>::max());
	}
	catch (std::exception &e)
	{
		std::cout << "Catching exception myv: " << e.what() << std::endl;
	}

	myv.resize(8);
	std::cout << "myv.capacity(): " << myv.capacity() << std::endl;

	myv.push_back(4);
	std::cout << "myv.capacity(): " << myv.capacity() << std::endl;
	myv.erase(myv.begin());

	std::cout << "# launching clear twice" << std::endl;
	myv.clear();
	myv.clear();
	std::cout << "myv.capacity(): " << myv.capacity() << std::endl;


	myv.assign((size_t)10, 8);
	myv.assign(myv.begin(), myv.begin() + 4); // wtf that works

	std::vector<int> myv2;
	myv.swap(myv2);
	myv.swap(myv2);
	myv.erase(myv.begin() + 2);
	myv2 = myv;
	myv.at(2) = 1;
	myv[1] = 0;

	std::cout << std::setw(30) << "myv < myv2: " << (myv < myv2) << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(30) << "myv > myv2: " << (myv > myv2) << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(30) << "myv == myv2: " << (myv == myv2) << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(30) << "myv != myv2: " << (myv == myv2) << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(30) << "myv <= myv2: " << (myv <= myv2) << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(30) << "myv >= myv2: " << (myv >= myv2) << std::endl;

	return 0;
}