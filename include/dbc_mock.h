#pragma once
#include <gmock/gmock.h>
#include "dbc_if.h"

class DBConnectionMock : public DBConnectionIf{
	public:
		MOCK_METHOD(bool, open, (), (override));
		MOCK_METHOD(bool, close, (), (override));
		MOCK_METHOD(int, execQuery, (const char*), (override));
};
