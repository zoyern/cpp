/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almounib <almounib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 23:17:10 by almounib          #+#    #+#             */
/*   Updated: 2024/11/19 21:25:52 by almounib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class PhoneBook {
	private:
		Contact	_list[8];
		int		_index;
	public:
		PhoneBook();
		~PhoneBook();
		void	add();
		Contact get();
		int		set();
};
