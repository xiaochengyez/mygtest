//
// Created by gongxc on 2021/12/14.
//


#include "../src/handlePath.h"
#include <gtest/gtest.h>


#ifdef LOG_TAG
#undef LOG_TAG
#endif
#define LOG_TAG "handle-test"


class handleTest : public ::testing::Test {
public:
    virtual void SetUp() override {
        rmdir("/home/gongxc/mini/gongxc");

    }

protected:
    int result;
};


TEST_F(handleTest, createFolder1) {
    result = handlePath::CreateFolder("/gongxc","");
    EXPECT_EQ(result,-1);
}
TEST_F(handleTest, createFolder2) {
    result = handlePath::CreateFolder("/home/gongxc","/mini");
    EXPECT_EQ(result,11);
}
TEST_F(handleTest, createFolder3) {
    result = handlePath::CreateFolder("/home/gongxc/mini","gongxc");
    EXPECT_EQ(result,14);
}
TEST_F(handleTest, createFolder4) {
    result = handlePath::CreateFolder("/home/gongxc/mini/gongxc","mini");
    EXPECT_EQ(result,12);
}

int main(int argc, char** argv)
{
    testing::GTEST_FLAG(output) = "xml:";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}