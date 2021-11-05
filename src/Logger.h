/*
 * Logger.h
 *
 *  Created on: Nov 2, 2021
 *      Author: keith
 */

#ifndef LOGGER_H_
#define LOGGER_H_
#include <string>
#include "FileIO.h"
const std::string DEFAULT_FILE = "log.txt";

namespace KP {

	enum DEST{
		None	= 0x00,
		StdOut 	= 0x01,
		Fle		= 0x02
	};
	
	class Logger {
	private:
		FileIO fle;
		unsigned char mde;
			
	public:
		Logger(std::string fname=DEFAULT_FILE);
		virtual ~Logger();
		
		/**
		 * 
		 * @param mde made up of DEST enum flags, used to determine log output
		 */
		void setDest(unsigned char mde = DEST::StdOut|DEST::Fle);
		
		virtual void log(std::string s);
	};

} /* namespace KP */

#endif /* LOGGER_H_ */
