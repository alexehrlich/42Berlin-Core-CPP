/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrlich <aehrlich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 09:03:04 by aehrlich          #+#    #+#             */
/*   Updated: 2023/11/22 15:33:48 by aehrlich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;
	size_t			findPos;
	size_t			searchStartPos;

	if (argc != 4)
		return (std::cout << "Args needed <filename> <s1> <s2>" << std::endl, 1);
	infile.open(argv[1]);
	if (infile.fail())
		return (std::cout << "File does not exist" << std::endl, 1);
	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
	{
		infile.close();
		return (std::cout << "Could not create file" << std::endl, 1);
	}
	while (std::getline(infile, line))
	{
		searchStartPos = 0;
		findPos = line.find(std::string(argv[2]), searchStartPos);
		if (findPos != std::string::npos)
		{
			while (findPos != std::string::npos)
			{
				outfile << line.substr(searchStartPos, findPos - searchStartPos);
				outfile << argv[3];
				searchStartPos = findPos + std::string(argv[2]).length();
				findPos = line.find(std::string(argv[2]), searchStartPos);
			}
			outfile << line.substr(searchStartPos, findPos - searchStartPos);
		}
		else
			outfile << line;
		if (!infile.eof())
			outfile << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
