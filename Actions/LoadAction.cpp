#include "LoadAction.h"
#include "../ApplicationManager.h"
#include <fstream>
#include <iostream>
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexagon.h"

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp) {
    // Constructor implementation
}

void LoadAction::ReadActionParameters() {
    // Get pointers to Input and Output
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();

    // Display a message to the user to enter the file name
    pOut->PrintMessage("Enter the file name to load: ");

    // Get the file name from the user
    fileName = pIn->GetSrting(pOut);

    // Clear the status bar after getting the file name
    pOut->ClearStatusBar();
}

void LoadAction::Execute() {
    // Ensure the file name is read
    ReadActionParameters();

    // Open the file for reading
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        // If the file cannot be opened, display an error message
        Output* pOut = pManager->GetOutput();
        pOut->PrintMessage("Error: Could not open file for loading.");
        return;
    }

    // Clear the current drawing area
    pManager->ClearFigures();

    // Read and create figures from the file
    std::string figureType;
    while (inputFile >> figureType) {
        CFigure* newFigure = nullptr;

        if (figureType == "Rectangle") {
            Point P1, P2;
            GfxInfo gfxInfo;
            inputFile >> P1.x >> P1.y >> P2.x >> P2.y;
            inputFile >> gfxInfo.DrawClr.ucRed >> gfxInfo.DrawClr.ucGreen >> gfxInfo.DrawClr.ucBlue;
            inputFile >> gfxInfo.isFilled;
            if (gfxInfo.isFilled) {
                inputFile >> gfxInfo.FillClr.ucRed >> gfxInfo.FillClr.ucGreen >> gfxInfo.FillClr.ucBlue;
            }
            inputFile >> gfxInfo.BorderWdth;
            newFigure = new CRectangle(P1, P2, gfxInfo);
        }
        else if (figureType == "Circle") {
            Point center, pointOnCurve;
            GfxInfo gfxInfo;
            inputFile >> center.x >> center.y >> pointOnCurve.x >> pointOnCurve.y;
            inputFile >> gfxInfo.DrawClr.ucRed >> gfxInfo.DrawClr.ucGreen >> gfxInfo.DrawClr.ucBlue;
            inputFile >> gfxInfo.isFilled;
            if (gfxInfo.isFilled) {
                inputFile >> gfxInfo.FillClr.ucRed >> gfxInfo.FillClr.ucGreen >> gfxInfo.FillClr.ucBlue;
            }
            inputFile >> gfxInfo.BorderWdth;
            newFigure = new cCircle(center, pointOnCurve, gfxInfo);
        }
        else if (figureType == "Triangle") {
            Point P1, P2, P3;
            GfxInfo gfxInfo;
            inputFile >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y;
            inputFile >> gfxInfo.DrawClr.ucRed >> gfxInfo.DrawClr.ucGreen >> gfxInfo.DrawClr.ucBlue;
            inputFile >> gfxInfo.isFilled;
            if (gfxInfo.isFilled) {
                inputFile >> gfxInfo.FillClr.ucRed >> gfxInfo.FillClr.ucGreen >> gfxInfo.FillClr.ucBlue;
            }
            inputFile >> gfxInfo.BorderWdth;
            newFigure = new CTriangle(P1, P2, P3, gfxInfo);
        }
        else if (figureType == "Square") {
            Point center;
            int sidelength;
            GfxInfo gfxInfo;
            inputFile >> center.x >> center.y >> sidelength;
            inputFile >> gfxInfo.DrawClr.ucRed >> gfxInfo.DrawClr.ucGreen >> gfxInfo.DrawClr.ucBlue;
            inputFile >> gfxInfo.isFilled;
            if (gfxInfo.isFilled) {
                inputFile >> gfxInfo.FillClr.ucRed >> gfxInfo.FillClr.ucGreen >> gfxInfo.FillClr.ucBlue;
            }
            inputFile >> gfxInfo.BorderWdth;
            newFigure = new cSquare(center, sidelength, gfxInfo);
        }
        else if (figureType == "Hexagon") {
            Point center;
            GfxInfo gfxInfo;

            inputFile >> center.x >> center.y;
            inputFile >> gfxInfo.DrawClr.ucRed >> gfxInfo.DrawClr.ucGreen >> gfxInfo.DrawClr.ucBlue;
            inputFile >> gfxInfo.isFilled;
            if (gfxInfo.isFilled) {
                inputFile >> gfxInfo.FillClr.ucRed >> gfxInfo.FillClr.ucGreen >> gfxInfo.FillClr.ucBlue;
            }
            inputFile >> gfxInfo.BorderWdth;
            newFigure = new cHexagon(center, gfxInfo);
        }
        else {
            std::cerr << "Error: Unknown figure type '" << figureType << "' in file." << std::endl;
            continue;
        }
        if (newFigure) {
            pManager->AddFigure(newFigure);
            std::cout << "Added figure of type: " << figureType << std::endl;
        }
    }

    inputFile.close();

    // Re-draw the loaded figures
    pManager->UpdateInterface();
    // Display a success message
    Output* pOut = pManager->GetOutput();
    pOut->PrintMessage("File loaded successfully from " + fileName + ".");
}