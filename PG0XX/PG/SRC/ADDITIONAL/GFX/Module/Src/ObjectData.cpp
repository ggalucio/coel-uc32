/*
 * ObjectData.cpp
 *
 *  Created on: 24 de jun de 2024
 *      Author: COELMATIC2022
 */


#include "../Inc/ObjectData.hpp"
#include <AT_module_ext.hpp>
#include <cstddef>

ObjectData::ObjectData(int size)
{
	this->size = size;
	dataObject = new DataObject[this->size];

	int i;
	for (i=0; i<size; i++){
		dataObject[i].Buffer = NULL;
		dataObject[i].RadioButton = NULL;
		dataObject[i].ToggleButton = NULL;
		dataObject[i].state = false;
		dataObject[i].value = 0;
	}
}

ObjectData::~ObjectData()
{
	size = 0;
	delete dataObject;
}

void ObjectData::add(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, DataType type, uint8_t decimal)
{
	if (textArea == NULL || buffer == NULL || nDataObjects == size)
		return;

	Update(textArea, buffer, dataObject[nDataObjects].value, type, decimal);

	dataObject[nDataObjects].Buffer = buffer;
	dataObject[nDataObjects].RadioButton = NULL;
	dataObject[nDataObjects].ToggleButton = NULL;
	nDataObjects ++;
}

void ObjectData::add(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer)
{
	add(textArea, buffer, _DOUBLE_, 0);
}

void ObjectData::add(touchgfx::RadioButton* radioButton)
{
	if (radioButton == NULL || nDataObjects == size)
		return;

	Update(radioButton, dataObject[nDataObjects].state);

	dataObject[nDataObjects].Buffer = NULL;
	dataObject[nDataObjects].RadioButton = radioButton;
	dataObject[nDataObjects].ToggleButton = NULL;
	nDataObjects ++;
}

void ObjectData::add(touchgfx::ToggleButton* toggleButton)
{
	if (toggleButton == NULL || nDataObjects == size)
		return;

	Update(toggleButton, dataObject[nDataObjects].state);

	dataObject[nDataObjects].Buffer = NULL;
	dataObject[nDataObjects].RadioButton = NULL;
	dataObject[nDataObjects].ToggleButton = toggleButton;
	nDataObjects ++;
}

void ObjectData::remove()
{
	if (nDataObjects == 0)
		return;

	int i;
	for (i=0; i<nDataObjects; i++){
		if (dataObject[i].Buffer != NULL)
			dataObject[i].value = GetNumberTextArea(dataObject[i].Buffer);
		else if (dataObject[i].RadioButton != NULL)
			dataObject[i].state = dataObject[i].RadioButton->getSelected();
		else if (dataObject[i].ToggleButton)
			dataObject[i].state = dataObject[i].ToggleButton->getState();
	}

	nDataObjects = 0;
}
