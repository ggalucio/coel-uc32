#ifndef RECEITA_TEMPERATURAPRESENTER_HPP
#define RECEITA_TEMPERATURAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receita_TemperaturaView;

class Receita_TemperaturaPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receita_TemperaturaPresenter(Receita_TemperaturaView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Receita_TemperaturaPresenter() {};

private:
    Receita_TemperaturaPresenter();

    Receita_TemperaturaView& view;
};

#endif // RECEITA_TEMPERATURAPRESENTER_HPP
