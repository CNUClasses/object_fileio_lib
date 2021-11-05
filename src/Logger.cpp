/*
 * Logger.cpp
 *
 *  Created on: Nov 2, 2021
 *      Author: keith
 */
#include <iostream>
#include "Logger.h"
using namespace std;

namespace KP {

Logger::Logger(std::string fname):fle(fname) {
	setDest(DEST::StdOut|DEST::Fle);
	fle.clear();
}

Logger::~Logger() {
}

void Logger::setDest(unsigned char mde){
	this->mde = mde;
}

void Logger::log(std::string s){
	if(mde & DEST::StdOut)
		cout<<s<<endl;
	
	if(mde & DEST::Fle)
		fle.writeln(s);
}


} /* namespace KP */
