/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:24:10 by aehrlich          #+#    #+#             */
/*   Updated: 2023/07/31 18:23:50 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdlib>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (size_t j = 0; j < std::strlen(argv[i]); j++)
				std::putwchar(std::toupper(argv[i][j]));
		}
		std::putwchar('\n');
	}
	return (EXIT_SUCCESS);
}
