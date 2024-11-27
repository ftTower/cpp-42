/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauer <tauer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 01:14:54 by tauer             #+#    #+#             */
/*   Updated: 2024/11/27 01:44:29 by tauer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// int	main(void) {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return (0);
// }

int main() {
    MutantStack<int> mystack;

    mystack.push(5);
    mystack.push(10);
    mystack.push(15);

    MutantStack<int>::iterator it = mystack.begin();
    MutantStack<int>::iterator ite = mystack.end();

    std::cout << "Contenu du MutantStack : ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "Top element: " << mystack.top() << std::endl;
    mystack.pop();
    std::cout << "New top after pop: " << mystack.top() << std::endl;

    mystack.push(20);
    mystack.push(25);

    std::cout << "For-range : ";
    for (unsigned int i = 0 ; i < mystack.size(); i++) {
        std::cout << *(mystack.begin() + i) << " ";
    }
    std::cout << std::endl;

    return 0;
}