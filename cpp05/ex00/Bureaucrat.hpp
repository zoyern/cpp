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


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# ifndef BUREAUCRAT
#  define GRADE_MAX 150
#  define GRADE_MIN 1
# endif

class Bureaucrat{
	private:
		const std::string	_name;
		int					_grade;
	public:
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
};

#endif