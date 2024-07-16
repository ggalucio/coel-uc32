#ifndef HIGIENE_CONFIRMARPRESENTER_HPP
#define HIGIENE_CONFIRMARPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class HIGIENE_CONFIRMARView;

class HIGIENE_CONFIRMARPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    HIGIENE_CONFIRMARPresenter(HIGIENE_CONFIRMARView& v);

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

    virtual ~HIGIENE_CONFIRMARPresenter() {};

private:
    HIGIENE_CONFIRMARPresenter();

    HIGIENE_CONFIRMARView& view;
};

#endif // HIGIENE_CONFIRMARPRESENTER_HPP
