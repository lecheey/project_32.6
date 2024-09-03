#pragma once
#include "dbc.h"
#include "dbc_if.h"

class ClassThatUsesDB{
	DBConnectionIf* someDBC = new DBConnection;
	public:
		ClassThatUsesDB(){};
		ClassThatUsesDB(DBConnectionIf* _someDBC) : someDBC(_someDBC){}
		
		~ClassThatUsesDB(){
			delete someDBC;
		}
		
		bool openConnection(){
			return someDBC->open();
		}

		bool closeConnection(){
			return someDBC->close();
		}

		int useConnection(const char* q){
			return someDBC->execQuery(q);
		}
};
