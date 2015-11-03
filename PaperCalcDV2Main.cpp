// *** ADDED BY HEADER FIXUP ***
#include <string>
// *** END ***
/***************************************************************
 * Name:      PaperCalcDV2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Martin 'Hafis' Halfar (hafis@protonmail.com)
 * Created:   2015-10-18
 * Copyright: Martin 'Hafis' Halfar (hafiscz.github.io)
 * License:
 **************************************************************/

#include "PaperCalcDV2Main.h"
#include <wx/msgdlg.h>
#include <stdio.h>
#include <string.h>

//(*InternalHeaders(PaperCalcDV2Frame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

/*
* Prototype XYZZ
* X - Application release ID
* Y - 1 means BETA release, otherwise FINAL
* Z - Build number (04 means fourth released build)
*/
const int prototype = 2110;

// Required variables
const float thPow3 = 1000000000;
wxString ctrlTextDefault = _("");
double rwLen, rwWid, rwGrm, rwCnt, rwWig, rcWig, rcCnt, rcEur, rcCst;
int clMode = 0;
int csMode = 0;
int ln = 0;
bool costEnabled = false;

// Language pack for EN and CZ, usage: langPack[1][language] return required
wxString langPack[][2] = {
    {_("#HAFISCZDEV"),_("#HAFISCZDEV")},
    {_("File"),_("Soubor")},
    {_("History"),_("Historie")},
    {_("Solve"),_(L"Vypo\u010D\u00EDst")},
    {_("Update"),_("Aktualizace")},
    {_("Quit"),_("Konec")},
    {_("Settings"),_(L"Nastaven\u00ED")},
    {_("Enable price module"),_(L"Povolit cenov\u00FD modul")},
    {_("Language"),_("Jazyk")},
    {_("English"),_(L"Angli\u010Dtina")},
    {_("Czech"),_(L"\u010Ce\u0161tina")},
    {_("Help"),_(L"N\u00E1pov\u0115da")},
    {_("About"),_("O programu")},
    {_("Size:"),_("Velikost:")},
    {_("Length:"),_(L"D\u00E9lka:")},
    {_("Width:"),_(L"\u0160\u00ED\u0159ka:")},
    {_("Gram:"),_(L"Gram\u00E1\u017E:")},
    {_("Weight:"),_("Hmotnost:")},
    {_("Count:"),_(L"Po\u010Det:")},
    {_("PaperCalcV2\nAuthor: Martin 'Hafis' Halfar\nWebsite: http://code.mar21.eu/\nEmail: hafis@protonmail.com\nStability not guaranteed in Development state of this app"),
       _(L"PaperCalcV2\nAutor: Martin 'Hafis' Halfar\nWeb: http://code.mar21.eu/\nEmail: hafis@protonmail.com\nStabilita nen\u00ED v t\u00E9to f\u00E1zi v\u00FDvoje zaru\u010Dena")},
    {_("Clear"),_(L"Vy\u010Distit")},
    {_("Cost:"),_("Cena:")},
    {_("Cost/Weight:"),_(L"Cena/V\u00E1ha:")},
    {_("Rate:"),_("Kurz:")},
    {_("Cost/Count:"),_(L"Cena/Po\u010Det:")}
};

// Paper formats, in future maybe in .xml type file
double paperFormats[15][2] = {
    {0,0},
    {700,1000},
    {500,700},
    {720,1020},
    {610,860},
    {430,610},
    {297,420},
    {210,297},
    {148,210},
    {480,650},
    {460,640},
    {430,610},
    {450,640},
    {215.9,279.4}
};

int codTrans[][3] = {
    {4, 4, 6},
    {5, 6, 4},
    {6, 5, 5}
};

// Units
wxString lengthUnits[] = {
    _("mm"), _("cm"), _("dm"), _("m")
};

wxString weightUnits[] = {
    _("kg"), _("t")
};

wxString countUnits[] = {
    _("arc"), _("kArc")
};

wxString costCurr[] = {
    _(L"K\u010D"), _(L"\u20AC")
};

wxString costPerWeightUnit[] = {
    _(L"K\u010D/kg"), _(L"K\u010D/t"),
    _(L"\u20AC/kg"), _(L"\u20AC/t")
};

wxString costPerCountUnit[] = {
     _(L"K\u010D/arc"), _(L"K\u010D/kArc"),
     _(L"\u20AC/arc"), _(L"\u20AC/kArc")
};

//(*IdInit(PaperCalcDV2Frame)
const long PaperCalcDV2Frame::ID_STATICTEXT1 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT5 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT3 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT2 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT4 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE1 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL1 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL2 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL3 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL4 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL5 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE2 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE3 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE5 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE6 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICLINE1 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT7 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE7 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICLINE2 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT6 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL6 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE4 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT8 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL7 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT9 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT10 = wxNewId();
const long PaperCalcDV2Frame::ID_STATICTEXT11 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL8 = wxNewId();
const long PaperCalcDV2Frame::ID_TEXTCTRL9 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE8 = wxNewId();
const long PaperCalcDV2Frame::ID_CHOICE9 = wxNewId();
const long PaperCalcDV2Frame::idMenuHistory = wxNewId();
const long PaperCalcDV2Frame::idMenuSolve = wxNewId();
const long PaperCalcDV2Frame::idMenuUpdate = wxNewId();
const long PaperCalcDV2Frame::idMenuQuit = wxNewId();
const long PaperCalcDV2Frame::idMenuPriceEnabled = wxNewId();
const long PaperCalcDV2Frame::idMenuLanguageEN = wxNewId();
const long PaperCalcDV2Frame::idMenuLanguageCZ = wxNewId();
const long PaperCalcDV2Frame::ID_MENUITEM1 = wxNewId();
const long PaperCalcDV2Frame::idMenuAbout = wxNewId();
const long PaperCalcDV2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PaperCalcDV2Frame,wxFrame)
    //(*EventTable(PaperCalcDV2Frame)
    //*)
END_EVENT_TABLE()

PaperCalcDV2Frame::PaperCalcDV2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(PaperCalcDV2Frame)
    Create(parent, wxID_ANY, _("PaperCalc 2 Development Version "), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(254,282));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText5Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    GridBagSizer1->Add(StaticText5, wxGBPosition(5, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    GridBagSizer1->Add(StaticText3, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    GridBagSizer1->Add(StaticText2, wxGBPosition(1, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    GridBagSizer1->Add(StaticText4, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->Append(_("Custom"));
    Choice1->Append(_("Print B1 [ 700 x 1000 ]"));
    Choice1->Append(_("Print B2 [ 500 x 700 ]"));
    Choice1->Append(_("Print B1+ [ 720 x 1020 ]"));
    Choice1->Append(_("Print A1 [ 610 x 860 ]"));
    Choice1->Append(_("Print A2 [ 430 x 610 ]"));
    Choice1->Append(_("A3 [ 297 x 420 ]"));
    Choice1->Append(_("A4 [ 210 x 297 ]"));
    Choice1->Append(_("A5 [ 148 x 210 ]"));
    Choice1->Append(_("Custom 1 [ 480 x 650 ]"));
    Choice1->Append(_("Custom 2 [ 460 x 640 ]"));
    Choice1->Append(_("Custom 3 [ 430 x 610 ]"));
    Choice1->Append(_("Custom 4 [ 450 x 640 ]"));
    Choice1->Append(_("USA-A [215.9 x 279.4]"));
    GridBagSizer1->Add(Choice1, wxGBPosition(0, 1), wxGBSpan(1, 4), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridBagSizer1->Add(TextCtrl1, wxGBPosition(1, 2), wxGBSpan(1, 2), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    GridBagSizer1->Add(TextCtrl2, wxGBPosition(2, 2), wxGBSpan(1, 2), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    GridBagSizer1->Add(TextCtrl3, wxGBPosition(4, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    GridBagSizer1->Add(TextCtrl4, wxGBPosition(5, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    GridBagSizer1->Add(TextCtrl5, wxGBPosition(6, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->Append(_("0"));
    Choice2->Append(_("1"));
    Choice2->Append(_("2"));
    Choice2->Append(_("3"));
    GridBagSizer1->Add(Choice2, wxGBPosition(1, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice3 = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    Choice3->Append(_("1"));
    Choice3->Append(_("2"));
    Choice3->Append(_("3"));
    Choice3->Append(_("4"));
    GridBagSizer1->Add(Choice3, wxGBPosition(2, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice5 = new wxChoice(this, ID_CHOICE5, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE5"));
    Choice5->Append(_("1"));
    Choice5->Append(_("2"));
    GridBagSizer1->Add(Choice5, wxGBPosition(5, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice6 = new wxChoice(this, ID_CHOICE6, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE6"));
    Choice6->Append(_("1"));
    Choice6->Append(_("2"));
    GridBagSizer1->Add(Choice6, wxGBPosition(6, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    GridBagSizer1->Add(StaticLine1, wxGBPosition(3, 0), wxGBSpan(1, 5), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridBagSizer1->Add(StaticText7, wxGBPosition(4, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice7 = new wxChoice(this, ID_CHOICE7, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE7"));
    Choice7->Append(_("1"));
    Choice7->Append(_("2"));
    Choice7->Append(_("3"));
    wxFont Choice7Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Choice7->SetFont(Choice7Font);
    GridBagSizer1->Add(Choice7, wxGBPosition(6, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    GridBagSizer1->Add(StaticLine2, wxGBPosition(7, 0), wxGBSpan(1, 5), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticText6Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText6->SetFont(StaticText6Font);
    GridBagSizer1->Add(StaticText6, wxGBPosition(8, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    GridBagSizer1->Add(TextCtrl6, wxGBPosition(8, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice4 = new wxChoice(this, ID_CHOICE4, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE4"));
    Choice4->Append(_("1"));
    Choice4->Append(_("2"));
    Choice4->Append(_("3"));
    Choice4->Append(_("4"));
    GridBagSizer1->Add(Choice4, wxGBPosition(8, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    wxFont StaticText8Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText8->SetFont(StaticText8Font);
    GridBagSizer1->Add(StaticText8, wxGBPosition(11, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    GridBagSizer1->Add(TextCtrl7, wxGBPosition(10, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    GridBagSizer1->Add(StaticText9, wxGBPosition(10, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    wxFont StaticText10Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText10->SetFont(StaticText10Font);
    GridBagSizer1->Add(StaticText10, wxGBPosition(10, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    wxFont StaticText11Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText11->SetFont(StaticText11Font);
    GridBagSizer1->Add(StaticText11, wxGBPosition(9, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl8 = new wxTextCtrl(this, ID_TEXTCTRL8, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    GridBagSizer1->Add(TextCtrl8, wxGBPosition(11, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl9 = new wxTextCtrl(this, ID_TEXTCTRL9, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    GridBagSizer1->Add(TextCtrl9, wxGBPosition(9, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice8 = new wxChoice(this, ID_CHOICE8, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
    Choice8->Append(_("1"));
    Choice8->Append(_("2"));
    GridBagSizer1->Add(Choice8, wxGBPosition(11, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice9 = new wxChoice(this, ID_CHOICE9, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
    Choice9->Append(_("5"));
    Choice9->Append(_("6"));
    Choice9->Append(_("7"));
    Choice9->Append(_("8"));
    GridBagSizer1->Add(Choice9, wxGBPosition(9, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridBagSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu1, idMenuHistory, _("1\tF2"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem2);
    MenuItem1 = new wxMenuItem(Menu1, idMenuSolve, _("2\tReturn"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem6 = new wxMenuItem(Menu1, idMenuUpdate, _("3"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    Menu1->AppendSeparator();
    MenuItem3 = new wxMenuItem(Menu1, idMenuQuit, _("4\tAlt-F4"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuBar1->Append(Menu1, _("1"));
    Menu3 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu3, idMenuPriceEnabled, _("1"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuItem4);
    MenuBar1->Append(Menu3, _("2"));
    Menu4 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu4, idMenuLanguageEN, _("1"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu4, idMenuLanguageCZ, _("2"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuItem8);
    MenuBar1->Append(Menu4, _("3"));
    Menu2 = new wxMenu();
    MenuItem9 = new wxMenuItem(Menu2, ID_MENUITEM1, _("2"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem9);
    MenuItem5 = new wxMenuItem(Menu2, idMenuAbout, _("1\tF1"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem5);
    MenuBar1->Append(Menu2, _("4"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    SetSizer(GridBagSizer1);
    Layout();
    Center();

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSizeSelect);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSizeChanged);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSizeChanged);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_TEXTCTRL4,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_TEXTCTRL5,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE5,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE6,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE7,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnCalcTypeChanged);
    Connect(idMenuSolve,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(idMenuUpdate,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnUpdate);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnQuit);
    Connect(idMenuPriceEnabled,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnCostEnabled);
    Connect(idMenuLanguageEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnLanguageChanged);
    Connect(idMenuLanguageCZ,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnLanguageChanged);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnClear);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnAbout);
    //*)

    RedrawOnLaunch();
}

PaperCalcDV2Frame::~PaperCalcDV2Frame()
{
    //(*Destroy(PaperCalcDV2Frame)
    //*)
}

void PaperCalcDV2Frame::RedrawOnLaunch() {

    PushObjects(Choice2, lengthUnits, 4);
    PushObjects(Choice3, lengthUnits, 4);
    PushObjects(Choice5, countUnits, 2);
    PushObjects(Choice6, weightUnits, 2);
    PushObjects(Choice4, costPerWeightUnit, 4);
    PushObjects(Choice9, costPerCountUnit, 4);
    PushObjects(Choice8, costCurr, 2);

    ExchangeLanguage(langPack, 0);

    Choice1->SetSelection(0);
    Choice2->SetSelection(0);
    Choice3->SetSelection(0);
    Choice4->SetSelection(0);
    Choice5->SetSelection(0);
    Choice6->SetSelection(0);
    Choice7->SetSelection(0);
    Choice8->SetSelection(0);
    Choice9->SetSelection(0);

    TextCtrl1->ChangeValue(ctrlTextDefault);
    TextCtrl2->ChangeValue(ctrlTextDefault);
    TextCtrl3->ChangeValue(ctrlTextDefault);
    TextCtrl4->ChangeValue(ctrlTextDefault);
    TextCtrl5->ChangeValue(ctrlTextDefault);
    TextCtrl6->ChangeValue(ctrlTextDefault);
    TextCtrl7->ChangeValue(ctrlTextDefault);
    TextCtrl8->ChangeValue(ctrlTextDefault);
    TextCtrl9->ChangeValue(ctrlTextDefault);

    EnableCost(false);

    Fit();
}

void PaperCalcDV2Frame::OnQuit(wxCommandEvent& event)
{
    // Close window
    Close();
}

void PaperCalcDV2Frame::PushObjects(wxChoice *ch, wxString data[], int size)
{
    // For every wxString object in array
    for (int i = 0; i < size; i++) {
        // Rename item on position i with matching string
        ch->SetString(i, data[i]);
    }
}

void PaperCalcDV2Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( langPack[19][ln], langPack[12][ln]);
}

bool PaperCalcDV2Frame::validate(wxString str, double *var)
{
    if (!(str).ToDouble(var) || (*var) <= 0){
        StatusBar1->SetLabel(_("Invalid input!"));
        return false;
    }
    return true;
}

// EVENT :: Solve
void PaperCalcDV2Frame::OnSolve(wxCommandEvent& event)
{
    double output;
    wxString rw (ctrlTextDefault);

    StatusBar1->SetLabel(ctrlTextDefault);

    if (validate(TextCtrl1->GetValue(), &rwLen) && validate(TextCtrl2->GetValue(), &rwWid)) {

        parseDecScale(&rwLen, Choice2->GetSelection());
        parseDecScale(&rwWid, Choice3->GetSelection());

        switch (clMode) {

            case 0 : {
                if (!validate(TextCtrl3->GetValue(), &rwGrm) || !validate(TextCtrl4->GetValue(), &rwCnt)) {
                    ThrowError(-200);
                    return;
                } else {
                    parseThScale(&rwCnt, Choice5->GetSelection());
                    output = calculate(rwLen, rwWid, rwGrm, rwCnt, -1);
                    parseThScale(&output, -Choice6->GetSelection());
                    rw << (output);
                    TextCtrl5->ChangeValue(rw);
                }
                break;
            }

            case 1 : {
                if (!validate(TextCtrl3->GetValue(), &rwGrm) || !validate(TextCtrl5->GetValue(), &rwWig)) {
                    ThrowError(-200);
                    return;
                } else {
                    parseThScale(&rwWig, Choice6->GetSelection());
                    output = calculate(rwLen, rwWid, rwGrm, -1, rwWig);
                    parseThScale(&output, -Choice5->GetSelection());
                    rw << (output);
                    TextCtrl4->ChangeValue(rw);
                }
                break;
            }

            case 2 : {
                if (!validate(TextCtrl5->GetValue(), &rwWig) || !validate(TextCtrl4->GetValue(), &rwCnt)) {
                    ThrowError(-200);
                    return;
                } else {
                    parseThScale(&rwWig, Choice6->GetSelection());
                    output = calculate(rwLen, rwWid, -1, rwCnt, rwWig);
                    rw << (output);
                    TextCtrl3->ChangeValue(rw);
                }
                break;
            }
        }
    }

    if (costEnabled) {
        switch (csMode) {

            case 0 : {
                if (!validate(TextCtrl5->GetValue(), &rwWig) || !validate(TextCtrl6->GetValue(), &rcWig)) {
                    ThrowError(-300);
                    return;
                } else {
                    parseThScale(&rwWig, Choice5->GetSelection());
                    //output = calculate(rwLen, rwWid, rwGrm, rwCnt, -1);
                    //parseThScale(&output, -Choice6->GetSelection());
                    //rw << (output);
                    //TextCtrl5->ChangeValue(rw);
                }
                break;
            }

        }
    }
}

// EVENT :: Selecting size presets
void PaperCalcDV2Frame::OnSizeSelect(wxCommandEvent& event)
{
    // Get selected index
    int formSz =  Choice1->GetSelection();
    if (formSz != 0) {
        // Paste 'mm' size - length & width into proper cell from 2D array paperFormats
        TextCtrl1->ChangeValue(wxString::Format(wxT("%.2lf"), paperFormats[formSz][0]));
        TextCtrl2->ChangeValue(wxString::Format(wxT("%.2lf"), paperFormats[formSz][1]));
        // Reset scaling to default 'mm' value
        Choice2->SetSelection(0);
        Choice3->SetSelection(0);
    }
}

void PaperCalcDV2Frame::ThrowError(int id)
{
    return;
}

// EVENT :: Changing size preset to custom when W and H are changed by user
void PaperCalcDV2Frame::OnSizeChanged(wxCommandEvent& event)
{
    Choice1->SetSelection(0);
}

// Scaling to 'mm' in 10s
void PaperCalcDV2Frame::parseDecScale (double *value, int scale)
{
    *value = ((*value) * pow(10, scale));
}

// Scaling to 'mm' in 1000s
void PaperCalcDV2Frame::parseThScale (double *value, int scale)
{
    *value = ((*value) * pow(1000, scale));
}

/** \brief This is a brief description.
 *
 * \param	value Pointer to variable which holds used value
 * \param	scale Scaling parameter for thousands, 1000^i
 * \param   eur EUR/CZK exchange rate
 *
 * Function used to downscale double amounts, for example: cost per weight unit or cost per amount unit
 */
void PaperCalcDV2Frame::cparseThScale (double *value, int scale, double eur)
{
    *value = (((*value) / pow(1000, scale % 2)) / (scale > 1 ? eur : 1));
}

// Solve function, take -1 as output parameter type & value >= 0 for valid input
double PaperCalcDV2Frame::calculate (double hLenght, double hWidth, double hGram, double hCount, double hWeight)
{
    if (hLenght == -1) {
        return ((hWeight * thPow3) / (hWidth * hGram * hCount));
    } else if (hWidth == -1) {
        return ((hWeight * thPow3) / (hLenght * hGram * hCount));
    } else if (hGram == -1) {
        return ((hWeight * thPow3) / (hLenght * hWidth * hCount));
    } else if (hCount == -1) {
        return ((hWeight * thPow3) / (hLenght * hWidth * hGram));
    } else if (hWeight == -1) {
        return ((hLenght * hWidth * hGram * hCount) / thPow3);
    } else {
        return -199;
    }
}

void PaperCalcDV2Frame::ExchangeLanguage(wxString pack[][2], int l)
{
    ln = l;
    //Labels
    StaticText1->SetLabel(pack[13][l]);
    StaticText2->SetLabel(pack[14][l]);
    StaticText3->SetLabel(pack[15][l]);
    StaticText4->SetLabel(pack[16][l]);
    StaticText5->SetLabel(pack[18][l]);
    StaticText7->SetLabel(_(L"g/m\u00B2"));
    StaticText6->SetLabel(pack[22][l]);
    StaticText8->SetLabel(pack[23][l]);
    StaticText9->SetLabel(_(L"K\u010D/\u20AC"));
    StaticText10->SetLabel(pack[21][l]);
    StaticText11->SetLabel(pack[24][l]);

    //Toolbar
    MenuBar1->SetMenuLabel(0, pack[1][l]);
    MenuBar1->SetMenuLabel(1, pack[6][l]);
    MenuBar1->SetMenuLabel(2, pack[8][l]);
    MenuBar1->SetMenuLabel(3, pack[11][l]);

    //Sub-Toolbar
    MenuItem1->SetItemLabel(pack[3][l] + _("\tReturn"));
    MenuItem2->SetItemLabel(pack[2][l] + _("\tF2"));
    MenuItem3->SetItemLabel(pack[5][l] + _("\tAlt-F4"));
    MenuItem4->SetItemLabel(pack[7][l]);
    MenuItem5->SetItemLabel(pack[12][l] + _("\tF1"));
    MenuItem6->SetItemLabel(pack[4][l]);
    MenuItem7->SetItemLabel(pack[9][l]);
    MenuItem8->SetItemLabel(pack[10][l]);
    MenuItem9->SetItemLabel(pack[20][l]);

    Choice7->SetString(0, pack[17][l]);
    Choice7->SetString(1, pack[18][l]);
    Choice7->SetString(2, pack[16][l]);

    Fit();
}

void PaperCalcDV2Frame::OnCalcTypeChanged(wxCommandEvent& event)
{
    clMode = Choice7->GetSelection();

    TextCtrl3->Show(false);
    StaticText7->Show(false);
    TextCtrl4->Show(false);
    Choice5->Show(false);
    TextCtrl5->Show(false);
    Choice6->Show(false);

    PlaceToSizer(TextCtrl3, 20, 1);
    PlaceToSizer(StaticText7, 20, 4);
    PlaceToSizer(TextCtrl4, 21, 1);
    PlaceToSizer(Choice5, 21, 4);
    PlaceToSizer(TextCtrl5, 22, 1);
    PlaceToSizer(Choice6, 12, 4);

    this->Fit();

    PlaceToSizer(TextCtrl3, codTrans[0][clMode], 1);
    PlaceToSizer(StaticText7, codTrans[0][clMode], 4);
    PlaceToSizer(TextCtrl4, codTrans[1][clMode], 1);
    PlaceToSizer(Choice5, codTrans[1][clMode], 4);
    PlaceToSizer(TextCtrl5, codTrans[2][clMode], 1);
    PlaceToSizer(Choice6, codTrans[2][clMode], 4);

    StaticText4->SetLabel(langPack[((clMode == 0 || clMode == 1) ? 16 : 18)][ln]);
    StaticText5->SetLabel(langPack[((clMode == 1 || clMode == 2) ? 17 : 18)][ln]);

    TextCtrl3->Show(true);
    StaticText7->Show(true);
    TextCtrl4->Show(true);
    Choice5->Show(true);
    TextCtrl5->Show(true);
    Choice6->Show(true);

    this->Fit();
}

// Move any widget to X Y coordinates
bool PaperCalcDV2Frame::PlaceToSizer(wxControl *w, int x, int y)
{
    return (GridBagSizer1->SetItemPosition(w, *(new wxGBPosition(x,y))));
}

// Language exchange event
void PaperCalcDV2Frame::OnLanguageChanged(wxCommandEvent& event)
{
    ExchangeLanguage(langPack, (MenuItem7->IsChecked() ? 0 : 1));
}

// Check for update
void PaperCalcDV2Frame::OnUpdate(wxCommandEvent& event)
{

}

// Clear content of all used wxTextCtrls
void PaperCalcDV2Frame::OnClear(wxCommandEvent& event)
{
    TextCtrl1->Clear();
    TextCtrl2->Clear();
    TextCtrl3->Clear();
    TextCtrl4->Clear();
    TextCtrl5->Clear();
    TextCtrl6->Clear();
    TextCtrl7->Clear();
    TextCtrl8->Clear();
    TextCtrl9->Clear();
}

void PaperCalcDV2Frame::OnCostEnabled(wxCommandEvent& event)
{
    EnableCost(MenuItem4->IsChecked());
}

void PaperCalcDV2Frame::EnableCost(bool e)
{
    costEnabled = e;

    StaticLine2->Show(e);
    StaticText6->Show(e);
    TextCtrl6->Show(e);
    Choice4->Show(e);
    StaticText8->Show(e);
    TextCtrl7->Show(e);
    StaticText9->Show(e);
    StaticText10->Show(e);
    TextCtrl8->Show(e);
    Choice8->Show(e);
    StaticText11->Show(e);
    TextCtrl9->Show(e);
    Choice9->Show(e);

    Fit();
}
