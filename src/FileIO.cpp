/*
 * FileIO.cpp
 *
 *  Created on: Oct 25, 2021
 *      Author: keith
 */

#include "FileIO.h"

FileIO::FileIO(std::string &fn):fn(fn) {
	//try and open it, first for append, if fail, add trunc to force creating file
	ms.open(fn.c_str(),
		std::fstream::in | std::fstream::out | std::fstream::app); //open for append
	if (!ms.is_open())
		ms.open(fn.c_str(),
			std::fstream::in | std::fstream::out | std::fstream::trunc); //file probs not there force it opened and empty
}

FileIO::~FileIO() {
	close();
}

void FileIO::close(){
	if(ms.is_open())
		ms.close();	
}

bool FileIO::read(std::string &s){
	if(!ms.is_open())
		return false;
	
	ms.seekg(std::ios::beg);
	
	std::string lne;
	while(!ms.eof()){
		getline(ms, lne);
		s+=lne + '\n';
	}
	return true;
}
bool FileIO::writeln(std::string &s){
	if(!ms.is_open())
		return false;
	
	ms<<s<<std::endl;
	return true;
}
void FileIO::clear(){
	close();
	ms.open(fn.c_str(),
		std::fstream::in | std::fstream::out | std::fstream::trunc);
}

