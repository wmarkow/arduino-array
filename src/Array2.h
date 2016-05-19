/*
 * Vector.h
 *
 *  Created on: 10 maj 2016
 *      Author: witek
 */

#ifndef ARRAY2_H_
#define ARRAY2_H_

#include <stdint.h>
#include <string.h>

template<typename T, const size_t MAX_SIZE_>
class Array2
{
private:
	T *internalTable;
	uint8_t maxSize;
	uint8_t size;

	uint8_t buffer[sizeof(T) * MAX_SIZE_];
public:
	Array2();

	uint8_t getSize();
	uint8_t getMaxSize();
	bool add(T* object);
	T* get(uint8_t index);
	void remove(uint8_t index);
};

template <typename T, const size_t MAX_SIZE_>
Array2<T, MAX_SIZE_>::Array2() {
	this->internalTable = buffer;
	this->maxSize = MAX_SIZE_;
	this->size = 0;
}

template <typename T, const size_t MAX_SIZE_>
uint8_t Array2<T, MAX_SIZE_>::getSize() {
	return this->size;
}

template <typename T, const size_t MAX_SIZE_>
uint8_t Array2<T, MAX_SIZE_>::getMaxSize() {
	return this->maxSize;
}

template <typename T, const size_t MAX_SIZE_>
bool Array2<T, MAX_SIZE_>::add(T* object) {
	if(size == maxSize) {
		return false;
	}

	memcpy(internalTable + size, object, sizeof(T));
	size ++;

	return true;
}

template <typename T, const size_t MAX_SIZE_>
T* Array2<T, MAX_SIZE_>::get(uint8_t index) {
	return (internalTable + index);
}

template <typename T, const size_t MAX_SIZE_>
void Array2<T, MAX_SIZE_>::remove(uint8_t index) {
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
		memcpy(internalTable + q, internalTable + q + 1, sizeof(T));
	}

	size --;
}

#endif /* ARRAY2_H_ */
