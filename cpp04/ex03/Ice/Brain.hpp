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


#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# ifndef BRAIN
#  define BRAIN_IDEAS 100
#  define BRAIN_PRINT "Brain"
#  define BRAIN_DEFAULT "created !"
#  define BRAIN_COPY "copy !"
#  define BRAIN_DESTROY "destroyed !"
# endif

class Brain{
	private:
		std::string	_ideas[BRAIN_IDEAS];
	public:
		~Brain();
		Brain();
		Brain(const Brain &brain);

		Brain	&operator=(const Brain &brain);

		std::string	getIdea(size_t index) const;
		bool		setIdea(std::string idea);
};

#endif