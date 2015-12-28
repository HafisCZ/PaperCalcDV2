/***************************************************************
 * Name:      PaperCalcDV2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Martin 'Hafis' Halfar (hafis@protonmail.com)
 * Created:   2015-10-18
 * Copyright: Martin 'Hafis' Halfar (hafiscz.github.io)
 * License:
 ***************************************************************
 * Euro: http://www.cnb.cz/miranda2/m2/cs/financni_trhy/devizovy_trh/kurzy_devizoveho_trhu/vybrane.txt?mena=EUR&od=06.11.2015&do=06.11.2015
 **************************************************************/

#include "PaperCalcDV2Main.h"
#include "PCDV2History.h"
#include "HTTPDownloadRequest.h"
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <ctime>

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
const int prototype = 2116;

// Required variables
const float thPow3 = 1000000000;
wxString ctrlTextDefault = _("");
wxString tmp;
wxString fetch_eur;
double rwLen, rwWid, rwGrm, rwCnt, rwWig;
double rcWig, rcCnt, rcEur, rcCst;
int clMode = 0;
int csMode = 0;
int selectedLanguage = 1;
bool costEnabled = false;

std::string repositoryLink = "http://www.github.com/HafisCZ/PaperCalc2";
std::string storeLink = "http://code.mar21.eu/PaperCalc2";
std::string versionLink = "http://raw.githubusercontent.com/HafisCZ/PaperCalc2/master/version.d";

// Language pack for EN and CZ, usage: langPack[1][language] return required
wxString langPack[][2] = {
    {_("#HAFISCZDEV"),_("#HAFISCZDEV")}, //0
    {_("File"),_("Soubor")}, //1
    {_("History"),_("Historie")}, //2
    {_("Solve"),_(L"Vypo\u010D\u00EDst")}, //3
    {_("Update"),_("Aktualizace")}, //4
    {_("Quit"),_("Konec")}, //5
    {_("Settings"),_(L"Nastaven\u00ED")}, //6
    {_("Enable price module"),_(L"Povolit cenov\u00FD modul")}, //7
    {_("Language"),_("Jazyk")}, //8
    {_("English"),_(L"Angli\u010Dtina")}, //9
    {_("Czech"),_(L"\u010Ce\u0161tina")}, //10
    {_("Help"),_(L"N\u00E1pov\u0115da")}, //11
    {_("About"),_("O programu")}, //12
    {_("Size:"),_("Velikost:")}, //13
    {_("Length:"),_(L"D\u00E9lka:")}, //14
    {_("Width:"),_(L"\u0160\u00ED\u0159ka:")}, //15
    {_("Gram:"),_(L"Gram\u00E1\u017E:")}, //16
    {_("Weight:"),_("Hmotnost:")}, //17
    {_("Count:"),_(L"Po\u010Det:")}, //18
    {_("-"),_("-")}, //19
    {_("Clear"),_(L"Vy\u010Distit")}, //20
    {_("Cost:"),_("Cena:")}, //21
    {_("Cost/Weight:"),_(L"Cena/V\u00E1ha:")}, //22
    {_("Rate:"),_("Kurz:")}, //23
    {_("Cost/Count:"),_(L"Cena/Po\u010Det:")}, //24
    {_("Update found"),_("Nalezena aktualizace")}, //25
    {_("Open download page ..."),_(L"Otev\u0159\u00EDt str\u00E1nku s aktualizac\u00ED ...")}, //26
    {_("Custom"),_(L"Vlastn\u00ED")}, //27
    {_("PaperCalc 2 - Development Version"),_(L"PaperCalc 2 - V\u00FDvoj\u00E1\u0159sk\u00E1 verze")}, //28
    {_("Application created for calculation of parameters of paper"),_(L"Aplikace vytvo\u0159en\u00E1 pro v\u00FDpo\u010Det parametr\u016F pap\u00EDru")}, //29
    {_("(c)2016 Martin Halfar hafis\u0040protonmail.com"),_("(c)2016 Martin Halfar hafis\u0040protonmail.com")}, //30
    {_("Unexpected error appeared !"),_(L"Nastala nezn\u00E1m\u00E1 chyba !")}, //31
    {_("No update found ..."),_(L"\u017D\u00E1dn\u00E1 aktualizace nebyla nalezena ...")} //32
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

int codTrans2[][3] = {
    {8, 10, 10},
    {10, 8, 11},
    {11, 11, 8}
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
const long PaperCalcDV2Frame::ID_CHOICE10 = wxNewId();
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
    TextCtrl7 = new wxTextCtrl(this, ID_TEXTCTRL7, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL7"));
    GridBagSizer1->Add(TextCtrl7, wxGBPosition(9, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    GridBagSizer1->Add(StaticText9, wxGBPosition(9, 4), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    wxFont StaticText10Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText10->SetFont(StaticText10Font);
    GridBagSizer1->Add(StaticText10, wxGBPosition(9, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    wxFont StaticText11Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText11->SetFont(StaticText11Font);
    GridBagSizer1->Add(StaticText11, wxGBPosition(10, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl8 = new wxTextCtrl(this, ID_TEXTCTRL8, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL8"));
    GridBagSizer1->Add(TextCtrl8, wxGBPosition(11, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl9 = new wxTextCtrl(this, ID_TEXTCTRL9, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL9"));
    GridBagSizer1->Add(TextCtrl9, wxGBPosition(10, 1), wxGBSpan(1, 3), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice8 = new wxChoice(this, ID_CHOICE8, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE8"));
    Choice8->Append(_("1"));
    Choice8->Append(_("2"));
    GridBagSizer1->Add(Choice8, wxGBPosition(11, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice9 = new wxChoice(this, ID_CHOICE9, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE9"));
    Choice9->Append(_("5"));
    Choice9->Append(_("6"));
    Choice9->Append(_("7"));
    Choice9->Append(_("8"));
    GridBagSizer1->Add(Choice9, wxGBPosition(10, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice10 = new wxChoice(this, ID_CHOICE10, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE10"));
    Choice10->Append(_("1"));
    Choice10->Append(_("2"));
    Choice10->Append(_("3"));
    wxFont Choice10Font(10,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Choice10->SetFont(Choice10Font);
    GridBagSizer1->Add(Choice10, wxGBPosition(8, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
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
    MenuItem4 = new wxMenuItem(Menu3, idMenuPriceEnabled, _("1\tF5"), wxEmptyString, wxITEM_CHECK);
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
    Connect(ID_TEXTCTRL6,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE4,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_TEXTCTRL7,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_TEXTCTRL8,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE8,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE9,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE10,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnCostWayChanged);
    Connect(idMenuHistory,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnHistoryOpened);
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

std::string iToS (int intg) {
    std::stringstream stream;
    stream << intg;
    return stream.str();
}

void PaperCalcDV2Frame::RedrawOnLaunch() {

    PushObjects(Choice2, lengthUnits, 4);
    PushObjects(Choice3, lengthUnits, 4);
    PushObjects(Choice5, countUnits, 2);
    PushObjects(Choice6, weightUnits, 2);
    PushObjects(Choice4, costPerWeightUnit, 4);
    PushObjects(Choice9, costPerCountUnit, 4);
    PushObjects(Choice8, costCurr, 2);

    MenuItem8->Check(true);
    ExchangeLanguage(langPack, selectedLanguage);

    Choice1->SetSelection(0);
    Choice2->SetSelection(0);
    Choice3->SetSelection(0);
    Choice4->SetSelection(0);
    Choice5->SetSelection(0);
    Choice6->SetSelection(0);
    Choice7->SetSelection(0);
    Choice8->SetSelection(0);
    Choice9->SetSelection(0);
    Choice10->SetSelection(0);

    TextCtrl1->ChangeValue(ctrlTextDefault);
    TextCtrl2->ChangeValue(ctrlTextDefault);
    TextCtrl3->ChangeValue(ctrlTextDefault);
    TextCtrl4->ChangeValue(ctrlTextDefault);
    TextCtrl5->ChangeValue(ctrlTextDefault);
    TextCtrl6->ChangeValue(ctrlTextDefault);
    TextCtrl7->ChangeValue(_("10"));
    TextCtrl8->ChangeValue(ctrlTextDefault);
    TextCtrl9->ChangeValue(ctrlTextDefault);

    EnableCost(false);

    time_t raw;
    struct tm * prepTime;
    time(&raw);
    prepTime = localtime(&raw);
    std::string historyDate = "1.1." + iToS(prepTime->tm_year + 1900);
    std::string todayDate = iToS(prepTime->tm_mday + 1) + '.' + iToS(prepTime->tm_mon + 1) + '.' + iToS(prepTime->tm_year + 1900);

    HTTPDownloadRequest rq;
    wxString euroRaw = _(rq.request("http://www.cnb.cz/miranda2/m2/cs/financni_trhy/devizovy_trh/kurzy_devizoveho_trhu/vybrane.txt?mena=EUR&od=" + historyDate + "&do=" + todayDate));
    fetch_eur = euroRaw.SubString(euroRaw.length()-8 ,euroRaw.length()-7);
    fetch_eur << _(".") << euroRaw.SubString(euroRaw.length()-5 ,euroRaw.length()-3);
    TextCtrl7->ChangeValue(fetch_eur);
    rq.~HTTPDownloadRequest();

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
    wxAboutDialogInfo info;
    info.SetName(langPack[28][selectedLanguage]);
    info.SetVersion(_(iToS(prototype)));
    info.SetDescription(langPack[29][selectedLanguage]);
    info.SetCopyright(langPack[30][selectedLanguage]);
    info.SetWebSite(_(storeLink));
    wxAboutBox(info);
}

bool PaperCalcDV2Frame::validate(wxString str, double *var)
{
    if (!(str).ToDouble(var) || (*var) <= 0){
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

    rw = _("");

    if (costEnabled) {
        switch (csMode) {

            case 0 : {
                if (validate(TextCtrl5->GetValue(), &rwWig) && validate(TextCtrl6->GetValue(), &rcWig)){

                    parseThScale(&rwWig, Choice6->GetSelection());

                    if (!validate(TextCtrl7->GetValue(), &rcEur)
                        && (Choice4->GetSelection() > 1 || Choice9->GetSelection() > 1 || Choice8->GetSelection() != 0 )) {
                        ThrowError(-400);
                        return;
                    }

                    cparseThScale(&rcWig, Choice4->GetSelection(), rcEur);

                    output = rwWig * rcWig;

                    if (validate(TextCtrl4->GetValue(), &rwCnt)) {
                        parseThScale(&rwCnt, Choice5->GetSelection());
                        wxString rc;
                        double comOutput = output / rwCnt;
                        cparseThScale(&comOutput, -Choice9->GetSelection(), rcEur);
                        rc << (comOutput);
                        TextCtrl9->ChangeValue(rc);
                    }

                    if (Choice8->GetSelection() != 0) output /= rcEur;
                    rw << (output);
                    TextCtrl8->ChangeValue(rw);

                    break;
                } else {
                    ThrowError(-300);
                    return;
                }
            }

            case 1: {
                if (validate(TextCtrl4->GetValue(), &rwCnt) && validate(TextCtrl9->GetValue(), &rcCnt)) {

                    parseThScale(&rwCnt, Choice5->GetSelection());

                    if (!validate(TextCtrl7->GetValue(), &rcEur)
                        && (Choice4->GetSelection() > 1 || Choice9->GetSelection() > 1 || Choice8->GetSelection() != 0 )) {
                        ThrowError(-400);
                        return;
                    }

                    cparseThScale(&rcCnt, Choice9->GetSelection(), rcEur);

                    output = rwCnt * rcCnt;

                    if (validate(TextCtrl5->GetValue(), &rwWig)) {
                        parseThScale(&rwWig, Choice6->GetSelection());
                        wxString rc;
                        double comOutput = output / rwWig;
                        cparseThScale(&comOutput, -Choice4->GetSelection(), rcEur);
                        rc << (comOutput);
                        TextCtrl6->ChangeValue(rc);
                    }

                    if (Choice8->GetSelection() != 0) output /= rcEur;
                    rw << (output);
                    TextCtrl8->ChangeValue(rw);

                    break;
                } else {
                    ThrowError(-300);
                    return;
                }
            }

            case 2 : {

                if (validate(TextCtrl8->GetValue(), &rcCst)) {

					if (!validate(TextCtrl7->GetValue(), &rcEur)
						&& (Choice4->GetSelection() > 1 || Choice9->GetSelection() > 1 || Choice8->GetSelection() != 0 )) {
						ThrowError(-400);
						return;
					}

					if (Choice8->GetSelection() != 0) rcCst *= rcEur;

					if (validate(TextCtrl4->GetValue(), &rwCnt)) {
						parseThScale(&rwCnt, Choice5->GetSelection());
						wxString rc(_(""));
						double comOutput1 = rcCst / rwCnt;
						cparseThScale(&comOutput1, -Choice9->GetSelection(), rcEur);
						rc << (comOutput1);
						TextCtrl9->ChangeValue(rc);
					}

					if (validate(TextCtrl5->GetValue(), &rwWig)) {
						parseThScale(&rwWig, Choice6->GetSelection());
						wxString rc(_(""));
						double comOutput1 = rcCst / rwWig;
						cparseThScale(&comOutput1, -Choice4->GetSelection(), rcEur);
						rc << (comOutput1);
						TextCtrl6->ChangeValue(rc);
					}

					break;
				} else {
					ThrowError(-300);
					return;
				}

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

void PaperCalcDV2Frame::cparseThScale (double *value, int scale, double eur)
{
    if (scale < 0) {
        scale *= -1;
        *value *= pow(1000, scale % 2);
        if (scale > 1) {
            *value /= eur;
        }
        return;
    }
    *value = (((*value) / pow(1000, scale % 2)) * (scale > 1 ? eur : 1));
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
    selectedLanguage = l;
    //Labels
    StaticText1->SetLabel(pack[13][l]);
    StaticText2->SetLabel(pack[14][l]);
    StaticText3->SetLabel(pack[15][l]);
    StaticText4->SetLabel(pack[((clMode == 0 || clMode == 1) ? 16 : 18)][l]);
    StaticText5->SetLabel(pack[((clMode == 1 || clMode == 2) ? 17 : 18)][l]);
    StaticText7->SetLabel(_(L"g/m\u00B2"));
    StaticText8->SetLabel(pack[((csMode == 2) ? 24 : 21)][l]);
    StaticText9->SetLabel(_(L"K\u010D/\u20AC"));
    StaticText10->SetLabel(pack[23][l]);
    StaticText11->SetLabel(pack[((csMode == 0) ? 24 : 22)][l]);

    //Toolbar
    MenuBar1->SetMenuLabel(0, pack[1][l]);
    MenuBar1->SetMenuLabel(1, pack[6][l]);
    MenuBar1->SetMenuLabel(2, pack[8][l]);
    MenuBar1->SetMenuLabel(3, pack[11][l]);

    //Sub-Toolbar
    MenuItem1->SetItemLabel(pack[3][l] + _("\tReturn"));
    MenuItem2->SetItemLabel(pack[2][l] + _("\tF2"));
    MenuItem3->SetItemLabel(pack[5][l] + _("\tAlt-F4"));
    MenuItem4->SetItemLabel(pack[7][l] + _("\tF5"));
    MenuItem5->SetItemLabel(pack[12][l] + _("\tF1"));
    MenuItem6->SetItemLabel(pack[4][l]);
    MenuItem7->SetItemLabel(pack[9][l]);
    MenuItem8->SetItemLabel(pack[10][l]);
    MenuItem9->SetItemLabel(pack[20][l]);

    Choice7->SetString(0, pack[17][l]);
    Choice7->SetString(1, pack[18][l]);
    Choice7->SetString(2, pack[16][l]);

    Choice10->SetString(0, pack[22][l]);
    Choice10->SetString(1, pack[24][l]);
    Choice10->SetString(2, pack[21][l]);

    Choice1->SetString(0, pack[27][l]);

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
    PlaceToSizer(Choice6, 22, 4);

    this->Fit();

    PlaceToSizer(TextCtrl3, codTrans[0][clMode], 1);
    PlaceToSizer(StaticText7, codTrans[0][clMode], 4);
    PlaceToSizer(TextCtrl4, codTrans[1][clMode], 1);
    PlaceToSizer(Choice5, codTrans[1][clMode], 4);
    PlaceToSizer(TextCtrl5, codTrans[2][clMode], 1);
    PlaceToSizer(Choice6, codTrans[2][clMode], 4);

    StaticText4->SetLabel(langPack[((clMode == 0 || clMode == 1) ? 16 : 18)][selectedLanguage]);
    StaticText5->SetLabel(langPack[((clMode == 1 || clMode == 2) ? 17 : 18)][selectedLanguage]);

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
    HTTPDownloadRequest rq;
    double newest;
    wxString newestVer = _(rq.request(versionLink));
    newestVer.ToDouble(&newest);
    if (newest > prototype) {
        if (wxMessageBox(langPack[26][selectedLanguage],langPack[25][selectedLanguage], wxYES_NO | wxCENTRE) == wxYES) {
            ShellExecute(0, 0, L"http://code.mar21.eu/PaperCalc2", 0, 0 , SW_SHOW );
        }
    } else if (newest == -1) {
        StatusBar1->SetLabelText(langPack[31][selectedLanguage]);
    } else {
        StatusBar1->SetLabelText(langPack[32][selectedLanguage]);
    }
    rq.~HTTPDownloadRequest();
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
    TextCtrl7->ChangeValue(fetch_eur);
    TextCtrl8->Clear();
    TextCtrl9->Clear();
}

void PaperCalcDV2Frame::OnCostEnabled(wxCommandEvent& event)
{
    bool costE = MenuItem4->IsChecked();
    EnableCost(costE);
}

void PaperCalcDV2Frame::EnableCost(bool e)
{
    costEnabled = e;

    StaticLine2->Show(e);
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
    Choice10->Show(e);

    Fit();
}

void PaperCalcDV2Frame::OnCostWayChanged(wxCommandEvent& event)
{
    csMode = Choice10->GetSelection();

    TextCtrl6->Show(false);
    Choice4->Show(false);
    TextCtrl9->Show(false);
    Choice9->Show(false);
    TextCtrl8->Show(false);
    Choice8->Show(false);

    PlaceToSizer(TextCtrl6, 20, 1);
    PlaceToSizer(Choice4, 20, 4);
    PlaceToSizer(TextCtrl9, 21, 1);
    PlaceToSizer(Choice9, 21, 4);
    PlaceToSizer(TextCtrl8, 22, 1);
    PlaceToSizer(Choice8, 22, 4);

    this->Fit();

    PlaceToSizer(TextCtrl6, codTrans2[0][csMode], 1);
    PlaceToSizer(Choice4, codTrans2[0][csMode], 4);
    PlaceToSizer(TextCtrl9, codTrans2[1][csMode], 1);
    PlaceToSizer(Choice9, codTrans2[1][csMode], 4);
    PlaceToSizer(TextCtrl8, codTrans2[2][csMode], 1);
    PlaceToSizer(Choice8, codTrans2[2][csMode], 4);

    StaticText11->SetLabel(langPack[((csMode == 0) ? 24 : 22)][selectedLanguage]);
    StaticText8->SetLabel(langPack[((csMode == 2) ? 24 : 21)][selectedLanguage]);

    TextCtrl6->Show(true);
    Choice4->Show(true);
    TextCtrl9->Show(true);
    Choice9->Show(true);
    TextCtrl8->Show(true);
    Choice8->Show(true);

    this->Fit();
}

void PaperCalcDV2Frame::OnHistoryOpened(wxCommandEvent& event)
{
	PCDV2History *sframe = new PCDV2History(NULL, 0);
	sframe->Show(true);
}
