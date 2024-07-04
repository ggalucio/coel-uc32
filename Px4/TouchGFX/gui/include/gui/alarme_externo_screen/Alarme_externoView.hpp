#ifndef ALARME_EXTERNOVIEW_HPP
#define ALARME_EXTERNOVIEW_HPP

#include <gui_generated/alarme_externo_screen/Alarme_externoViewBase.hpp>
#include <gui/alarme_externo_screen/Alarme_externoPresenter.hpp>

class Alarme_externoView : public Alarme_externoViewBase
{
public:
    Alarme_externoView();
    virtual ~Alarme_externoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ALARME_EXTERNOVIEW_HPP
