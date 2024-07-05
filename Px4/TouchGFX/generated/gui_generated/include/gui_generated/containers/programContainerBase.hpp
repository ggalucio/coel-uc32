/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef PROGRAMCONTAINERBASE_HPP
#define PROGRAMCONTAINERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class programContainerBase : public touchgfx::Container
{
public:
    programContainerBase();
    virtual ~programContainerBase() {}
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextAreaWithOneWildcard programTxt;
    touchgfx::TextAreaWithOneWildcard idTxt;

    /*
     * Wildcard Buffers
     */
    static const uint16_t PROGRAMTXT_SIZE = 20;
    touchgfx::Unicode::UnicodeChar programTxtBuffer[PROGRAMTXT_SIZE];
    static const uint16_t IDTXT_SIZE = 20;
    touchgfx::Unicode::UnicodeChar idTxtBuffer[IDTXT_SIZE];

private:

};

#endif // PROGRAMCONTAINERBASE_HPP
