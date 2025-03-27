/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:36 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

#ifndef CONFIG
#  define SIZE 4
#  define LEVELS {"DEBUG", "INFO", "WARNING", "ERROR"}
#  define MSG { \
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !", \
    "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !", \
    "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.", \
    "This is unacceptable ! I want to speak to the manager now." \
}
#endif

class Harl {
	private:
		void		debug();
		void		info();
		void		warning();
		void		error();
	public:
		~Harl();
		Harl();
		void	complain(std::string level);
};

#endif