#include <gui/containers/programContainer.hpp>

extern void (*pReadJobNameAt)(int, char*);

programContainer::programContainer()
{

}

void programContainer::initialize()
{
    programContainerBase::initialize();
}

void programContainer::update(int idx){
	if(pReadJobNameAt){
		char name[PROGRAMTXT_SIZE];
		(*pReadJobNameAt)(idx, name);
		touchgfx::Unicode::strncpy(programTxtBuffer, name, PROGRAMTXT_SIZE);
		programTxt.invalidate();
	}

	Unicode::snprintf(idTxtBuffer, IDTXT_SIZE, "%d", idx + 1);
	idTxt.invalidate();
}
