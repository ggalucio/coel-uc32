#ifndef RECEITA_TEMPERATURAVIEW_HPP
#define RECEITA_TEMPERATURAVIEW_HPP

#include <gui_generated/receita_temperatura_screen/Receita_TemperaturaViewBase.hpp>
#include <gui/receita_temperatura_screen/Receita_TemperaturaPresenter.hpp>

class Receita_TemperaturaView : public Receita_TemperaturaViewBase
{
public:
    Receita_TemperaturaView();
    virtual ~Receita_TemperaturaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // RECEITA_TEMPERATURAVIEW_HPP
