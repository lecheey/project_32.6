#pragma once
#include <iostream>
#include "dbc_if.h"
#include <cstring>

class DBConnection : public DBConnectionIf{	
	public:
		DBConnection(){}
		~DBConnection(){}

		bool open(){
			return true;
		}
		bool close(){
			return true;
		}
		int execQuery(const char* query){
			if(std::strcmp(query, "hello") == 0){
				return 2;
			}
			else{
				return 3;
			}
		}
};
