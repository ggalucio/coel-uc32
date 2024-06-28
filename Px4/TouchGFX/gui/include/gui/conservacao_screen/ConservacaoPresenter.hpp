#ifndef CONSERVACAOPRESENTER_HPP
#define CONSERVACAOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ConservacaoView;

class ConservacaoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ConservacaoPresenter(ConservacaoView& v);

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

    virtual ~ConservacaoPresenter() {};

private:
    ConservacaoPresenter();

    ConservacaoView& view;
};

#endif // CONSERVACAOPRESENTER_HPP
