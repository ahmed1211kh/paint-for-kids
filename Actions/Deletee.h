#include "../Figures/CFigure.h"
#include "Action.h"

// Deletee action class
class Deletee : public Action {
public:
    Deletee(ApplicationManager* pApp); // Constructor

    // Reads parameters required for the delete action
    virtual void ReadActionParameters();

    // Executes the delete action
    virtual void Execute();

    virtual ~Deletee();
};


