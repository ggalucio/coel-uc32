#ifndef FRONTENDAPPLICATION_HPP
#define FRONTENDAPPLICATION_HPP

#include <gui_generated/common/FrontendApplicationBase.hpp>

class FrontendHeap;

using namespace touchgfx;

class FrontendApplication : public FrontendApplicationBase
{
public:
    FrontendApplication(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplication() { }

    virtual void handleTickEvent()
    {
        model.tick();
        FrontendApplicationBase::handleTickEvent();
        UploaderTick();
    }

    void LaunchApp();
    void StartReadingFw();
    void BackToStart();

private:
    void UploaderTick(void);
    int currScreen;
};

#endif // FRONTENDAPPLICATION_HPP
