#ifndef TASK_HPP
#define TASK_HPP

#include <gui_generated/containers/TaskBase.hpp>

extern "C" uint8_t RefreshAllTasks(void);
uint8_t RefreshAllTasks(void);

/*
 * Execultar tarefas.
 * */
class Task : public TaskBase
{
public:
    Task();
    virtual ~Task() { finalize(); }
    virtual void initialize();
    virtual void finalize();

    /*
     * Definir o tempo de espera para repetir uma tarefa.
     *
     * */
    virtual void setWaitTime(uint32_t value);

    /*
     * Inicializar a execulção.
     * */
    virtual void run();

    /*
     * Interromper a tarefa.
     * */
    virtual void interrupt();

protected:

    friend void RefreshTasks();

    uint32_t DELTA_TASK = 100;
    uint32_t countThreadCycle= 0;

    bool enableTaskRun = false;

    void refresh()
    {
    	if (enableTaskRun)
    	{
    		if (countThreadCycle >= DELTA_TASK)
    		{
    			countThreadCycle = 0;
    			emitCallCallback();
    		}
    		else
    			countThreadCycle += 50;
    	}
    	else
    		countThreadCycle = 0;
    }

    /*
     * Inicialização de container.
     * */
    void begin()
    {
    	emitBeginCallback();
    }
};

#endif // TASK_HPP
