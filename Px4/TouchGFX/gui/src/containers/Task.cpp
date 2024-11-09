#include <gui/containers/Task.hpp>

Task* task[20];
int nTasks = 0;

/*
 * Adicionar uma nova intância Task na lista.
 * */
void addTaskContainer(Task* t){
	if (nTasks == 20)
		return;

	task[nTasks] = t;
	nTasks ++;
}

/*
 * Remover todos as Task da lista.
 * */
void clearTaskContainer(){
	nTasks = 0;
}

/*
 * Atualizar lista de Task.
 * */
void RefreshTasks(){
	if (nTasks == 0)
		return;

	int i;
	for (i=0; i<nTasks; i++)
		task[i]->refresh();
}

uint8_t RefreshAllTasks(){
	RefreshTasks();
	return 0;
}

Task::Task()
{

}

void Task::initialize()
{
    TaskBase::initialize();
    addTaskContainer(this);
    begin();
}

void Task::finalize()
{
	clearTaskContainer();
}

void Task::setWaitTime(uint32_t value)
{
	DELTA_TASK = value;
}

void Task::run()
{
	enableTaskRun = true;
}

void Task::interrupt()
{
	enableTaskRun = false;
}
