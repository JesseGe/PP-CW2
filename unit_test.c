#include "unity.h"
#include "headfile.h"
#include"unity_internals.h"
void test_basic_fileread()
{
	char* file;
	file = (char*)malloc(sizeof(char));
	readf(file);
	file = "../testx.txt";
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, readf(file), "The program should return when not raeding the file");
	file = "../test1.txt";
	TEST_ASSERT_EQUAL_INT_MESSAGE(-1, readf(file), "wrong when reading a null file");
	file = "../file.txt";
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, readf(file), "Wrong reading the file");
}

void test_basic_SDLwindow()
{
	int row = 200;
	int col = 200;
	SDLwindow(row, col);
	TEST_ASSERT_EQUAL_INT_MESSAGE(0, SDLwindow(row, col), "The program should return 0 when success");
	row = -3;
	col = -300;
	TEST_ASSERT_EQUAL_INT_MESSAGE(1, SDLwindow(row, col), "Wrong reading the file");
}

void test_basic_rw()
{
	
	char* file;
	file = (char*)malloc(sizeof(char));
	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			cells[i][k] = 1;    /*0 means all cells are dead*/
		}
	}
	row = 200;
	col = 200;
	tickspcycle = 200;
	file = "../test.txt";
	writef(file);
	readf(file);
	TEST_ASSERT_INT_WITHIN_MESSAGE(0, 200, row, "wrong in writing or reading the row and col");
	TEST_ASSERT_UINT32_WITHIN_MESSAGE(0, 200, tickspcycle, "Wrong in writing or reading the delay");
}
void setUp() {

}
void tearDown() {

}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_basic_fileread);
	RUN_TEST(test_basic_SDLwindow);
	RUN_TEST(test_basic_rw);
	return UNITY_END();
}