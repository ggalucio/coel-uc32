#ifndef RECEITAS_1_EDITPRESENTER_HPP
#define RECEITAS_1_EDITPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Receitas_1_EDITView;

class Receitas_1_EDITPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Receitas_1_EDITPresenter(Receitas_1_EDITView& v);

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

    virtual ~Receitas_1_EDITPresenter() {};

private:
    Receitas_1_EDITPresenter();

    Receitas_1_EDITView& view;
};

#endif // RECEITAS_1_EDITPRESENTER_HPP
