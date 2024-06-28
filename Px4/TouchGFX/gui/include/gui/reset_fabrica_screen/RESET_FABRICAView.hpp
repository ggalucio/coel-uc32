#ifndef RESET_FABRICAVIEW_HPP
#define RESET_FABRICAVIEW_HPP

#include <gui_generated/reset_fabrica_screen/RESET_FABRICAViewBase.hpp>
#include <gui/reset_fabrica_screen/RESET_FABRICAPresenter.hpp>

class RESET_FABRICAView : public RESET_FABRICAViewBase
{
public:
    RESET_FABRICAView();
    virtual ~RESET_FABRICAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RESET_FABRICAVIEW_HPP
