#include "SaveAction.h"
#include "../ApplicationManager.h"
#include <fstream>
#include <iostream>
#include "../GUI/Output.h"
#include "../GUI/Input.h"




save::save(ApplicationManager* pApp) : Action(pApp) {
    // Constructor initializes the save action with the application manager
}

void save::ReadActionParameters() {
    // Get pointers to Input and Output interfaces
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    // Prompt the user to enter the file name for saving
    pOut->PrintMessage("Enter the file name to save: ");

    // Read the file name entered by the user
    fileName = pIn->GetSrting(pOut);

    // Clear the status bar after getting the file name
    pOut->ClearStatusBar();
}

void save::Execute() {
    // Read the file name from the user
    ReadActionParameters();

    // Open the file for writing
    std::ofstream outFile(fileName);
    if (!outFile.is_open()) {
        // If the file could not be opened, display an error message
        Output* pOut = pManager->GetOutput();
        pOut->PrintMessage("Error: Could not open file for saving.");
        return;
    }

    // Save all figures to the file using the ApplicationManager
    pManager->SaveAll(outFile);

    // Close the file after saving
    outFile.close();

    // Display a success message to the user
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("File saved successfully to " + fileName + ".");
}


