//
// Created by Evan Shaw on 4/26/23.
//

#ifndef CPP_TEST_STATICHELPERFUNCTIONS_H
#define CPP_TEST_STATICHELPERFUNCTIONS_H


static void padTo(std::string &str, const size_t num, const char paddingChar = ' ') {
	if (num > str.size())
		str.insert(0, num - str.size(), paddingChar);
}


#endif //CPP_TEST_STATICHELPERFUNCTIONS_H
