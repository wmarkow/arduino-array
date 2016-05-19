/*
 * Fixture.h
 *
 *  Created on: 20 maj 2016
 *      Author: witek
 */

#ifndef FIXTURE_H_
#define FIXTURE_H_

#define DEFAULT_FIXTURE_SIZE 3

class Fixture
{
public:
	uint8_t a;
	uint8_t b;
	uint16_t c;
	uint8_t buffer[DEFAULT_FIXTURE_SIZE];
};

#endif /* FIXTURE_H_ */
