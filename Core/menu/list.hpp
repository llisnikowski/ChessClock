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

template <int16_t Size, typename T = Element>
class List : public ListBase
{
public:
	List(const char* name)
		:ListBase(name), elements_{}, currentIndex_{}, loopList_{}
	{}
	virtual ~List() = default;

	T* getElement(int16_t index);
	bool setElement(int16_t index, T *element);

	void setLooping(bool isLoop){ loopList_ = isLoop;}

	void nextElement();
	void prevElement();

	int16_t getCurIndex(){return currentIndex_;}
	void setCurIndex(int16_t index);
	void reMarkInList(){elements_.markInList();};
	int16_t getSize() const override {return Size;}
	T * getCurElement(){ return elements_[currentIndex_];}

	virtual void changedIndex(){}

private:
	T * elements_[Size];
	int16_t currentIndex_;
	bool loopList_;
};



//-------------------------

template <int16_t Size, typename T>
T* List<Size, T>::getElement(int16_t index)
{
	if(currentIndex_ < 0 || currentIndex_ >= Size)
		return nullptr;
	return elements_[index];
}

template <int16_t Size, typename T>
bool List<Size, T>::setElement(int16_t index, T *element)
{
	if(currentIndex_ < 0 || currentIndex_ >= Size)
		return false;
	elements_[index] = element;
	return true;
}

template <int16_t Size, typename T>
void List<Size, T>::nextElement()
{
	currentIndex_++;
	if(currentIndex_ >= Size ){
		if(loopList_)
			currentIndex_ = 0;
		else
			currentIndex_ = Size - 1;
	}
	changedIndex();
	elements_.markInList();
}

template <int16_t Size, typename T>
void List<Size, T>::prevElement()
{
	currentIndex_--;
	if(currentIndex_ < 0 ){
		if(loopList_)
			currentIndex_ = Size - 1;
		else
			currentIndex_ = 0;
	}

	changedIndex();
	elements_.markInList();
}

template <int16_t Size, typename T>
void List<Size, T>::setCurIndex(int16_t index)
{
	currentIndex_ = index;
	if(currentIndex_ >= Size) currentIndex_ = Size - 1;
	else if(currentIndex_ < 0) currentIndex_ = 0;

	changedIndex();
	elements_.markInList();
}



} /* namespace Menu */

#endif /* MENU_LIST_HPP_ */
