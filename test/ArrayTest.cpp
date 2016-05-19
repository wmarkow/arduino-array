
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE StaticListTest
#include <boost/test/unit_test.hpp>


#include "../src/Array.h"

#define MAX_COUNT 3

BOOST_AUTO_TEST_CASE(testConstructor)
{
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	BOOST_CHECK(list.getMaxSize() == MAX_COUNT);
	BOOST_CHECK(list.getSize() == 0);
}

BOOST_AUTO_TEST_CASE(testConstructor2)
{
	Array<uint8_t, 5> list = Array<uint8_t, 5>();

	BOOST_CHECK(list.getMaxSize() == 5);
	BOOST_CHECK(list.getSize() == 0);
}


BOOST_AUTO_TEST_CASE(testAddUntilFull) {
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	uint8_t value = 123;

	BOOST_CHECK(list.add(&value));
	BOOST_CHECK(list.getMaxSize() == MAX_COUNT);
	BOOST_CHECK(list.getSize() == 1);

	BOOST_CHECK(list.add(&value));
	BOOST_CHECK(list.getMaxSize() == MAX_COUNT);
	BOOST_CHECK(list.getSize() == 2);

	BOOST_CHECK(list.add(&value));
	BOOST_CHECK(list.getMaxSize() == MAX_COUNT);
	BOOST_CHECK(list.getSize() == 3);

	BOOST_CHECK(!list.add(&value));
	BOOST_CHECK(list.getMaxSize() == MAX_COUNT);
	BOOST_CHECK(list.getSize() == 3);
}

BOOST_AUTO_TEST_CASE(testGet) {
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	uint8_t value1 = 123;
	uint8_t value2 = 23;
	uint8_t value3 = 254;

	list.add(&value1);
	list.add(&value2);
	list.add(&value3);

	BOOST_CHECK((*list.get(0)) == 123);
	BOOST_CHECK((*list.get(1)) == 23);
	BOOST_CHECK((*list.get(2)) == 254);
}

BOOST_AUTO_TEST_CASE(testRemoveWhenZeroSize) {
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	list.remove(0);

	BOOST_CHECK(list.getSize() == 0);
}

BOOST_AUTO_TEST_CASE(testRemoveWhenIndexOutOfArray) {
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	uint8_t value1 = 123;
	uint8_t value2 = 23;
	uint8_t value3 = 254;

	list.add(&value1);
	list.add(&value2);
	list.add(&value3);

	list.remove(3);

	BOOST_CHECK(list.getSize() == 3);
	BOOST_CHECK((*list.get(0)) == 123);
	BOOST_CHECK((*list.get(1)) == 23);
	BOOST_CHECK((*list.get(2)) == 254);
}

BOOST_AUTO_TEST_CASE(testRemoveLast) {
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	uint8_t value1 = 123;
	uint8_t value2 = 23;
	uint8_t value3 = 254;

	list.add(&value1);
	list.add(&value2);
	list.add(&value3);

	list.remove(2);

	BOOST_CHECK(list.getSize() == 2);
	BOOST_CHECK((*list.get(0)) == 123);
	BOOST_CHECK((*list.get(1)) == 23);
}

BOOST_AUTO_TEST_CASE(testRemoveInside) {
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	uint8_t value1 = 123;
	uint8_t value2 = 23;
	uint8_t value3 = 254;

	list.add(&value1);
	list.add(&value2);
	list.add(&value3);

	list.remove(1);

	BOOST_CHECK(list.getSize() == 2);
	BOOST_CHECK((*list.get(0)) == 123);
	BOOST_CHECK((*list.get(1)) == 254);
}

BOOST_AUTO_TEST_CASE(testRemoveFirst) {
	Array<uint8_t, MAX_COUNT> list = Array<uint8_t, MAX_COUNT>();

	uint8_t value1 = 123;
	uint8_t value2 = 23;
	uint8_t value3 = 254;

	list.add(&value1);
	list.add(&value2);
	list.add(&value3);

	list.remove(0);

	BOOST_CHECK(list.getSize() == 2);
	BOOST_CHECK((*list.get(0)) == 23);
	BOOST_CHECK((*list.get(1)) == 254);
}
