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

template<class T, const size_t MAX_SIZE>
class Array
{
private:
	uint8_t maxSize;
	uint8_t size;
	uint8_t buffer[sizeof(T) * MAX_SIZE];
public:
	Array();

	uint8_t getSize();
	uint8_t getMaxSize();
	bool add(T* object);
	T* get(uint8_t index);
	void remove(uint8_t index);
};

template <class T, const size_t MAX_SIZE>
Array<T, MAX_SIZE>::Array() {
	this->maxSize = MAX_SIZE;
	this->size = 0;
}

template <class T, const size_t MAX_SIZE>
uint8_t Array<T, MAX_SIZE>::getSize() {
	return this->size;
}

template <class T, const size_t MAX_SIZE>
uint8_t Array<T, MAX_SIZE>::getMaxSize() {
	return this->maxSize;
}

template <class T, const size_t MAX_SIZE>
bool Array<T, MAX_SIZE>::add(T* object) {
	if(size == maxSize) {
		return false;
	}

	memcpy(buffer + size, object, sizeof(T));
	size ++;

	return true;
}

template <class T, const size_t MAX_SIZE>
T* Array<T, MAX_SIZE>::get(uint8_t index) {
	return (T*) (buffer + index);
}

template <class T, const size_t MAX_SIZE>
void Array<T, MAX_SIZE>::remove(uint8_t index) {
	if(size == 0) {
		return;
	}

	if(index > size -1) {
		return;
	}

	if(index == size -1) {
		size --;

		return;
	}

	// need to shift left
	for(uint8_t q = index ; q < size - 1 ; q ++) {
		memcpy(buffer + q, buffer + q + 1, sizeof(T));
	}

	size --;
}

#endif /* ARRAY_H_ */
