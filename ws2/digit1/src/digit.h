#ifndef DIGIT_H_
#define DIGIT_H_

#include <iostream>
#include <vector>

void printLargeDigit(unsigned int number, unsigned int size, std::ostream &out);

void printMultipleLargeDigits(unsigned int number, unsigned int size, std::ostream &out);

std::vector<std::vector<std::string>> generateDigits();

std::vector<std::vector<std::string>> generateMultipleLargeDigitVector(std::string digits);

std::vector<std::string> getLargeDigit (unsigned int number);

#endif /* DIGIT_H_ */
