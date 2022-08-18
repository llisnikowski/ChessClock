/*
 * list.h
 *
 *  Created on: Aug 17, 2022
 *      Author: Łukasz
 */

#ifndef MENU_LIST_HPP_
#define MENU_LIST_HPP_

#include "listBase.hpp"
#include "element.hpp"
#include <stdint.h>

namespace Menu {

template <int16_t size, typename T = Element>
class List : public ListBase
{
public:
	List(const char* name)
		:ListBase(name), elements_{}, currentIndex_{}, loopList_{}
	{}
	virtual ~List() = default;

	unsigned int size() const override { return size_;}

	T* getElement(int16_t index);
	void setElement(int16_t index, T *element);

	void setLooping(bool isLoop){ loopList_ = isLoop;}

	void nextElement();
	void prevElement();

	int16_t getCurIndex(){ return currentIndex_;}
	void setCurIndex(int16_t index);
	void reMarkInList(){elements_.markInList();};
	int16_t getSize(){ retrun size;}
	T * getCurElement(){ return elements_[currentIndex_];}

	virtual void changedIndex(){}

private:
	T * elements_[size];
	int16_t currentIndex_;
	bool loopList_;
};



//-------------------------

template <int16_t size>
T* List<size>::getElement(int16_t index)
{
	if (index < 0 || index >= size_)
		return nullptr;
	return elements_[index];
}

template <int16_t size>
void List<size>::setElement(int16_t index, T *element)
{
	if (index < 0 || index >= size_)
		return;
	elements_[index] = element;
}

template <int16_t size>
void List<size>::nextElement()
{
	currentIndex_++;
	if(currentIndex_ >= size ){
		if(loopList)
			currentIndex_ = 0;
		else
			currentIndex_ = size - 1;
	}
	changedIndex();
	elements_.markInList();
}

template <int16_t size>
void List<size>::prevElement()
{
	currentIndex_--;
	if(currentIndex_ < 0 ){
		if(loopList)
			currentIndex_ = size - 1;
		else
			currentIndex_ = 0;
	}

	changedIndex();
	elements_.markInList();
}

template <int16_t size>
void List<size>::setCurIndex(int16_t index)
{
	currentIndex_ = index;
	if(currentIndex_ >= size) currentIndex_ = size - 1;
	else if(currentIndex_ < 0) currentIndex_ = 0;

	changedIndex();
	elements_.markInList();
}



} /* namespace Menu */

#endif /* MENU_LIST_HPP_ */
