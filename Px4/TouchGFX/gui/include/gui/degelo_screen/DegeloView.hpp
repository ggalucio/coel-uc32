#ifndef DEGELOVIEW_HPP
#define DEGELOVIEW_HPP

#include <gui_generated/degelo_screen/DegeloViewBase.hpp>
#include <gui/degelo_screen/DegeloPresenter.hpp>

class DegeloView : public DegeloViewBase
{
public:
    DegeloView();
    virtual ~DegeloView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DEGELOVIEW_HPP
