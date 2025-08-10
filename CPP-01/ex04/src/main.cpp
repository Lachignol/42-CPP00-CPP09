/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ascordil <ascordil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:31:12 by ascordil          #+#    #+#             */
/*   Updated: 2025/05/20 19:11:35 by ascordil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstring>

int main(int count, char **argv)
{
	if (count == 4)
	{
		const std::string nameOutputFile = std::string(argv[1]) + ".replace";
		const std::string stringToReplace = argv[2];
		const std::string stringWhoReplace = argv[3];
		std::ifstream inputFile(argv[1], std::ios::in);
		if (!inputFile)
			return (std::cerr << "Input File not found or permission denied" << std::endl , 1);

		std::ofstream outputFile(nameOutputFile.c_str() , std::ios::out);
		if (!outputFile)
			return (std::cerr << "Can't create or find Outputfile" << std::endl , 1);
		std::string extractFirstPart;
		std::string extractSecondPart;
		std::string line;
		unsigned long	pos = 0;
		while (std::getline(inputFile, line))
		{
			pos = 0;
			while ((pos = line.find(stringToReplace, pos)) != std::string::npos)
			{
				extractFirstPart = line.substr(0, pos);
				extractSecondPart = line.substr((pos + stringToReplace.length()), line.length());
				line = extractFirstPart + stringWhoReplace + extractSecondPart;
				pos += stringWhoReplace.length();
			}
			/*std::cout << line << std::endl;*/
			outputFile << line << std::endl;
		}
	}
	else
		return (std::cout << "Format is <Filename> <string-to-replace> <string-of-replacement> " << std::endl , 1);
}
