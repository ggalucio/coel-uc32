#ifndef NUMPADCONTAINER_HPP
#define NUMPADCONTAINER_HPP

#include <gui_generated/containers/numpadContainerBase.hpp>

void AddNumpadReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t id);
void UpdateOutNumpad(void);
void RemoveAllNumpad(void);

class numpadContainer : public numpadContainerBase
{
public:
    numpadContainer();
    virtual ~numpadContainer() {}
    virtual void initialize();

    friend void SetRangeNumpadContainer(numpadContainer &numpad, double min, double max);
    friend void SetValueNumpadContainer(numpadContainer &numpad, double value, DataType dataType, uint8_t decimal);
    friend void UpdateOutNumpad(void);

protected:
};

typedef struct{
	numpadContainer *numpad;
	touchgfx::TextArea *textArea;
	touchgfx::Unicode::UnicodeChar *buffer;
	DataType dataType;
	uint8_t decimal;
}NumpadContainerItem;

#endif // NUMPADCONTAINER_HPP
