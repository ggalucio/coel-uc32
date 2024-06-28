/*
 * ObjectData.hpp
 *
 *  Created on: 24 de jun de 2024
 *      Author: COELMATIC2022
 */

#ifndef GFX_MODULE_INC_OBJECTDATA_HPP_
#define GFX_MODULE_INC_OBJECTDATA_HPP_

#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/RadioButton.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>

#include <AT_module.hpp>

typedef struct{
	touchgfx::Unicode::UnicodeChar* Buffer;
	touchgfx::RadioButton* RadioButton;
	touchgfx::ToggleButton* ToggleButton;
	bool state;
	double value;
}DataObject;

class ObjectData
{
public:
	ObjectData(int size);
	~ObjectData();
	void add(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer, DataType type, uint8_t decimal);
	void add(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* buffer);
	void add(touchgfx::RadioButton* radioButton);
	void add(touchgfx::ToggleButton* toggleButton);
	void remove();

protected:
	DataObject* dataObject;
	int size = 0;
	int nDataObjects = 0;
};

#endif /* GFX_MODULE_INC_OBJECTDATA_HPP_ */
