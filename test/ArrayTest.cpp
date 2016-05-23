
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE StaticListTest
#include <boost/test/unit_test.hpp>


#include "../src/Array.h"
#include "../src/FixedSizeArray.h"
#include "Fixture.h"

#define MAX_COUNT 3

BOOST_AUTO_TEST_CASE(testConstructor)
{
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

	BOOST_CHECK(list.getMaxSize() == MAX_COUNT);
	BOOST_CHECK(list.getSize() == 0);
}

BOOST_AUTO_TEST_CASE(testConstructor2)
{
	FixedSizeArray<uint8_t, 5> list;// = FixedSizeArray<uint8_t, 5>();

	BOOST_CHECK(list.getMaxSize() == 5);
	BOOST_CHECK(list.getSize() == 0);
}


BOOST_AUTO_TEST_CASE(testAddUntilFull) {
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

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
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

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
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

	list.remove(0);

	BOOST_CHECK(list.getSize() == 0);
}

BOOST_AUTO_TEST_CASE(testRemoveWhenIndexOutOfArray) {
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

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
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

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
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

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
	FixedSizeArray<uint8_t, MAX_COUNT> list = FixedSizeArray<uint8_t, MAX_COUNT>();

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

BOOST_AUTO_TEST_CASE(testFixture) {
	FixedSizeArray<Fixture, MAX_COUNT> list = FixedSizeArray<Fixture, MAX_COUNT>();

	Fixture first;
	Fixture second;
	second.a = 1;
	second.b = 2;
	second.c = 12345;
	second.buffer[0] = 255;
	second.buffer[1] = 128;
	second.buffer[2] = 25;

	list.add(&first);
	list.add(&second);
	list.remove(0);

	Fixture *result = list.get(0);
	BOOST_CHECK(result->a == 1);
	BOOST_CHECK(result->b == 2);
	BOOST_CHECK(result->c == 12345);
	BOOST_CHECK(result->buffer[0] == 255);
	BOOST_CHECK(result->buffer[1] == 128);
	BOOST_CHECK(result->buffer[2] == 25);
}

BOOST_AUTO_TEST_CASE(testFixtureWithCastingToPointer) {
	FixedSizeArray<Fixture, MAX_COUNT> list = FixedSizeArray<Fixture, MAX_COUNT>();
	Array<Fixture> *array = &list;

	Fixture first;
	Fixture second;
	second.a = 1;
	second.b = 2;
	second.c = 12345;
	second.buffer[0] = 255;
	second.buffer[1] = 128;
	second.buffer[2] = 25;

	array->add(&first);
	array->add(&second);
	array->remove(0);

	Fixture *result = array->get(0);
	BOOST_CHECK(result->a == 1);
	BOOST_CHECK(result->b == 2);
	BOOST_CHECK(result->c == 12345);
	BOOST_CHECK(result->buffer[0] == 255);
	BOOST_CHECK(result->buffer[1] == 128);
	BOOST_CHECK(result->buffer[2] == 25);
}
