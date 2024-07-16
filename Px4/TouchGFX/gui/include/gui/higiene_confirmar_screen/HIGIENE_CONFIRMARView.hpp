#ifndef HIGIENE_CONFIRMARVIEW_HPP
#define HIGIENE_CONFIRMARVIEW_HPP

#include <gui_generated/higiene_confirmar_screen/HIGIENE_CONFIRMARViewBase.hpp>
#include <gui/higiene_confirmar_screen/HIGIENE_CONFIRMARPresenter.hpp>

class HIGIENE_CONFIRMARView : public HIGIENE_CONFIRMARViewBase
{
public:
    HIGIENE_CONFIRMARView();
    virtual ~HIGIENE_CONFIRMARView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // HIGIENE_CONFIRMARVIEW_HPP
