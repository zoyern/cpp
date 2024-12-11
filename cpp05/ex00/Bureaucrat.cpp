/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:37:34 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 16:37:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade < GRADE_MIN ? GRADE_MIN : (grade > GRADE_MAX ? GRADE_MAX : grade) ) {}


std::ostream&	operator<<(std::ostream &out, const Bureaucrat &bureaucrat) { return (out << fixed.toFloat());}
