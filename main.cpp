#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "ctu_db.h"
#include "dbc.h"
#include "dbc_if.h"
#include "dbc_mock.h"

class DBConnectionFix : public ::testing::Test{
	protected:
		DBConnectionFix(){}
		~DBConnectionFix(){}

		void SetUp(){
			someDBConnection = new DBConnectionMock();
		}
		void TearDown(){
		}

		DBConnectionMock* someDBConnection;
};

TEST_F(DBConnectionFix, testcase1){
	ClassThatUsesDB ClassTUDB{someDBConnection};
	
	EXPECT_CALL(*someDBConnection, open).WillOnce(::testing::Return(true));
	EXPECT_CALL(*someDBConnection, close).WillOnce(::testing::Return(true));

	ClassTUDB.openConnection();
	ClassTUDB.closeConnection();
}

TEST(BestTest, testcase2){
	DBConnection* someDBConnection2 = new DBConnection();
	ClassThatUsesDB ClassTUDB{someDBConnection2};

    int res1{0};
    int res2{0};

    res1 = ClassTUDB.useConnection("hello");
    res2 = ClassTUDB.useConnection("goodbye");

    ASSERT_EQ(res1, 2);
    ASSERT_EQ(res2, 3);
}

int main(int argc, char** argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
