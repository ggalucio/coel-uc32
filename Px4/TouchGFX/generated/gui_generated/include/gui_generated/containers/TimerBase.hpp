/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef TIMERBASE_HPP
#define TIMERBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/Image.hpp>

class TimerBase : public touchgfx::Container
{
public:
    TimerBase();
    virtual ~TimerBase() {}
    virtual void initialize();

    /*
     * Custom Trigger Callback Setters
     */
    void setTickCallback(touchgfx::GenericCallback<>& callback)
    {
        this->tickCallback = &callback;
    }
    void setBeginCallback(touchgfx::GenericCallback<>& callback)
    {
        this->beginCallback = &callback;
    }

    /*
     * Custom Actions
     */
    virtual void setWaitTime(uint32_t value);
    virtual void start();
    virtual void stop();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Custom Trigger Emitters
     */
    virtual void emitTickCallback()
    {
        if (tickCallback && tickCallback->isValid())
        {
            this->tickCallback->execute();
        }
    }
    virtual void emitBeginCallback()
    {
        if (beginCallback && beginCallback->isValid())
        {
            this->beginCallback->execute();
        }
    }

    /*
     * Member Declarations
     */
    touchgfx::Image image1;

private:

    /*
     * Custom Trigger Callback Declarations
     */
    touchgfx::GenericCallback<>* tickCallback;
    touchgfx::GenericCallback<>* beginCallback;

};

#endif // TIMERBASE_HPP
