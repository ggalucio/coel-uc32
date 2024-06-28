#ifndef TELA_INICIALPRESENTER_HPP
#define TELA_INICIALPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Tela_InicialView;

class Tela_InicialPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Tela_InicialPresenter(Tela_InicialView& v);

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

    virtual ~Tela_InicialPresenter() {};

private:
    Tela_InicialPresenter();

    Tela_InicialView& view;
};

#endif // TELA_INICIALPRESENTER_HPP
