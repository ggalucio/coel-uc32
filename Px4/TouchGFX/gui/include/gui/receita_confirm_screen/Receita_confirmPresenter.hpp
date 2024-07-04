#ifndef RECEITA_CONFIRMPRESENTER_HPP
#define RECEITA_CONFIRMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receita_confirmView;

class Receita_confirmPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receita_confirmPresenter(Receita_confirmView& v);

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

    virtual ~Receita_confirmPresenter() {};

private:
    Receita_confirmPresenter();

    Receita_confirmView& view;
};

#endif // RECEITA_CONFIRMPRESENTER_HPP
