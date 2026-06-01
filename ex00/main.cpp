/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilnassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 16:56:08 by ilnassi           #+#    #+#             */
/*   Updated: 2026/06/01 18:37:29 by ilnassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
    Zombie* Brad = newZombie("Brad");
    Brad->announce();

    delete Brad;

    randomChump("Jill");
    {
        Zombie chris("Chris");
        chris.announce();
    }

    return 0;
}
