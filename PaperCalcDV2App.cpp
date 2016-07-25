/***************************************************************
 * Name:      PaperCalcDV2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Martin 'Hafis' Halfar (hafis@protonmail.com)
 * Created:
 * Copyright:
 * License:
 **************************************************************/

#include "PaperCalcDV2App.h"

//(*AppHeaders
#include "PaperCalcDV2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(PaperCalcDV2App);

bool PaperCalcDV2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	PaperCalcDV2Frame* Frame = new PaperCalcDV2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
