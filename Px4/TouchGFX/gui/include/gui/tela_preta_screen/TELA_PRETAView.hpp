#ifndef TELA_PRETAVIEW_HPP
#define TELA_PRETAVIEW_HPP

#include <gui_generated/tela_preta_screen/TELA_PRETAViewBase.hpp>
#include <gui/tela_preta_screen/TELA_PRETAPresenter.hpp>

class TELA_PRETAView : public TELA_PRETAViewBase
{
public:
    TELA_PRETAView();
    virtual ~TELA_PRETAView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // TELA_PRETAVIEW_HPP
