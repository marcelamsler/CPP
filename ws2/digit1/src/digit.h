#ifndef DIGIT_H_
#define DIGIT_H_

#include <iostream>
#include <vector>

void printLargeDigit(unsigned int number, unsigned int size, std::ostream &out);

void printMultipleLargeDigits(unsigned int number, unsigned int size, std::ostream &out);

std::vector<std::vector<std::string>> generateDigits();

#endif /* DIGIT_H_ */
