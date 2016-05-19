#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE StaticListTest
#include <boost/test/unit_test.hpp>


#include "../src/StaticVector.h"
#include "../src/StaticVector2.h"

#define MAX_COUNT 3

BOOST_AUTO_TEST_CASE(testConstructor)
{
	uint8_t internalTable[MAX_COUNT];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

	BOOST_CHECK(list.getMaxSize() == MAX_COUNT);
	BOOST_CHECK(list.getSize() == 0);
}

BOOST_AUTO_TEST_CASE(testConstructor2)
{
	StaticVector2<uint8_t, 5> list = StaticVector2<uint8_t, 5>();

	BOOST_CHECK(list.getMaxSize() == 5);
	BOOST_CHECK(list.getSize() == 0);
}


BOOST_AUTO_TEST_CASE(testAddUntilFull) {
	uint8_t internalTable[3];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

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
	uint8_t internalTable[3];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

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
	uint8_t internalTable[3];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

	list.remove(0);

	BOOST_CHECK(list.getSize() == 0);
}

BOOST_AUTO_TEST_CASE(testRemoveWhenIndexOutOfArray) {
	uint8_t internalTable[3];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

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
	uint8_t internalTable[3];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

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
	uint8_t internalTable[3];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

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
	uint8_t internalTable[3];
	StaticVector<uint8_t> list = StaticVector<uint8_t>(internalTable, MAX_COUNT);

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
