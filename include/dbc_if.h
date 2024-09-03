#pragma once

class DBConnectionIf{
	public:
		DBConnectionIf(){}
		virtual ~DBConnectionIf(){};

		virtual bool open() = 0;
		virtual bool close() = 0;
		virtual int execQuery(const char*) = 0;
};
