/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sharnvon <sharnvon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:37:54 by sharnvon          #+#    #+#             */
/*   Updated: 2022/12/31 15:39:56 by sharnvon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template< typename T>
class MutantStack : public virtual std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const &src);
		~MutantStack(void);
		T	*begin(void);
		T	*end(void);
		class iterator {
			public:
				iterator(void);
				iterator(T *pointer);
				// iterator(iterator &src);
				~iterator(void);
				iterator	&operator=(iterator &rhs);
				bool		operator!=(iterator &rhs);
				bool		operator==(iterator &rhs);
				iterator	operator++(void);
				iterator	operator++(int);
				iterator	operator--(void);
				iterator	operator--(int);
				T			operator*(void);

			private:
				T	*_iterator;
		};

	private:
		std::stack<T>	_stackValue;
};

template< typename T >
std::ostream	&operator<<(std::ostream &out, MutantStack<T> &rhs);
template< typename T >
std::ostream	&operator<<(std::ostream &out, typename MutantStack<T>::iterator &rhs);

# include "MutantStack.tpp"
#endif