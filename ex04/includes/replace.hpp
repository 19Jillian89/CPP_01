#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>

std::string replaceLine(std::string line, std::string s1, std::string s2);
void        replaceInFile(std::string filename, std::string s1, std::string s2);

#endif
