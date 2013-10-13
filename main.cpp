/*
 * main.cpp
 *
 *  Created on: 2013/10/13
 *      Author: TSUNEMICHI
 */
#include "gmock/gmock.h"

int main(int argc, char** argv) {
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}
