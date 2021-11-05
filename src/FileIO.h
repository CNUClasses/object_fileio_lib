/*
 * FileIO.h
 *
 *  Created on: Oct 25, 2021
 *      Author: keith
 */

#ifndef FILEIO_H_
#define FILEIO_H_
#include <string>
#include <fstream>

class FileIO {
private:
	void close();
	std::fstream ms;
	std::string fn;
	
public:
	FileIO(std::string &fle);
	virtual ~FileIO();
	bool read(std::string &s);
	bool writeln(std::string &s);
	void clear();
};

#endif /* FILEIO_H_ */
