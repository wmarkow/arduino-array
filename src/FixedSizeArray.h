/*
 * FixedSizeArray.h
 *
 *  Created on: 24 maj 2016
 *      Author: witek
 */

#ifndef FIXEDSIZEARRAY_H_
#define FIXEDSIZEARRAY_H_

#include "Array.h"

template<class T, const size_t MAX_SIZE>
class FixedSizeArray : public Array<T>
{
private:
	uint8_t maxSize;
	uint8_t size;
	T buffer[MAX_SIZE];
public:
	FixedSizeArray();

	uint8_t getSize();
	uint8_t getMaxSize();
	T get(uint8_t index);
	T* peek(uint8_t index);
	bool add(T object);
	bool add(T* object);
	void remove(uint8_t index);
};

template <class T, const size_t MAX_SIZE>
FixedSizeArray<T, MAX_SIZE>::FixedSizeArray() {
	this->maxSize = MAX_SIZE;
	this->size = 0;
}

template <class T, const size_t MAX_SIZE>
uint8_t FixedSizeArray<T, MAX_SIZE>::getSize() {
	return this->size;
}

template <class T, const size_t MAX_SIZE>
uint8_t FixedSizeArray<T, MAX_SIZE>::getMaxSize() {
	return this->maxSize;
}

template <class T, const size_t MAX_SIZE>
bool FixedSizeArray<T, MAX_SIZE>::add(T object) {
	if(this->size == this->maxSize) {
		return false;
	}

	memcpy(buffer + this->size, &object, sizeof(T));
	this->size ++;

	return true;
}

template <class T, const size_t MAX_SIZE>
bool FixedSizeArray<T, MAX_SIZE>::add(T* object) {
	if(this->size == this->maxSize) {
		return false;
	}

	memcpy(buffer + this->size, object, sizeof(T));
	this->size ++;

	return true;
}

template <class T, const size_t MAX_SIZE>
T FixedSizeArray<T, MAX_SIZE>::get(uint8_t index) {
	return buffer[index];
}

template <class T, const size_t MAX_SIZE>
T* FixedSizeArray<T, MAX_SIZE>::peek(uint8_t index) {
	return (T*) (buffer + index);
}

template <class T, const size_t MAX_SIZE>
void FixedSizeArray<T, MAX_SIZE>::remove(uint8_t index) {
	if(this->size == 0) {
		return;
	}

	if(index > this->size -1) {
		return;
	}

	if(index == this->size -1) {
		this->size --;

		return;
	}

	// need to shift left
	for(uint8_t q = index ; q < this->size - 1 ; q ++) {
		memcpy(buffer + q, buffer + q + 1, sizeof(T));
	}

	this->size --;
}

#endif /* FIXEDSIZEARRAY_H_ */
