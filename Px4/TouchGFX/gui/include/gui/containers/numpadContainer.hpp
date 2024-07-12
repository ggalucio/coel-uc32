#ifndef NUMPADCONTAINER_HPP
#define NUMPADCONTAINER_HPP

#include <gui_generated/containers/numpadContainerBase.hpp>

void AddNumpadReference(touchgfx::TextArea *textArea, touchgfx::Unicode::UnicodeChar* textBuffer, double min, double max, DataType dataType, uint8_t decimal, uint8_t id);
void RemoveAllNumpad(void);

class numpadContainer : public numpadContainerBase
{
public:
    numpadContainer();
    virtual ~numpadContainer() {}
    virtual void initialize();

    bool setRange(double min, double max);
    void setInput(touchgfx::Unicode::UnicodeChar* inBuffer, DataType dataType, uint8_t decimal);
    void loadInput(void);

protected:
    touchgfx::Unicode::UnicodeChar* outBuffer;
	DataType dataType;
    uint8_t decimal;
};

typedef struct{
	numpadContainer *numpad;
}NumpadContainerItem;

#endif // NUMPADCONTAINER_HPP
