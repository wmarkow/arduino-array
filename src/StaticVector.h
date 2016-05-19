/*
 * Vector.h
 *
 *  Created on: 10 maj 2016
 *      Author: witek
 */

#ifndef STATICVECTOR_H_
#define STATICVECTOR_H_

#include <stdint.h>
#include <string.h>

template<class T>
class StaticVector
{
private:
	T *internalTable;
	uint8_t maxSize;

	uint8_t size;
public:
	StaticVector(T* internalTable, uint8_t maxSize);

	uint8_t getSize();
	uint8_t getMaxSize();
	bool add(T* object);
	T* get(uint8_t index);
	void remove(uint8_t index);
};

template <class T>
StaticVector<T>::StaticVector(T* internalTable, uint8_t maxSize) {
	this->internalTable = internalTable;
	this->maxSize = maxSize;
	this->size = 0;
}

template <class T>
uint8_t StaticVector<T>::getSize() {
	return this->size;
}

template <class T>
uint8_t StaticVector<T>::getMaxSize() {
	return this->maxSize;
}

template <class T>
bool StaticVector<T>::add(T* object) {
	if(size == maxSize) {
		return false;
	}

	memcpy(internalTable + size, object, sizeof(T));
	size ++;

	return true;
}

template <class T>
T* StaticVector<T>::get(uint8_t index) {
	return (internalTable + index);
}

template <class T>
void StaticVector<T>::remove(uint8_t index) {
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

#endif /* STATICVECTOR_H_ */
