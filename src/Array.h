/*
 * Vector.h
 *
 *  Created on: 10 maj 2016
 *      Author: witek
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdint.h>
#include <string.h>

template<class T>
class Array
{
public:
	virtual uint8_t getSize() = 0;
	virtual uint8_t getMaxSize() = 0;
	virtual T get(uint8_t index) = 0;
	virtual T* peek(uint8_t index) = 0;
	virtual bool add(T object) = 0;
	virtual bool add(T* object) = 0;
	virtual void remove(uint8_t index) = 0;
};

#endif /* ARRAY_H_ */
