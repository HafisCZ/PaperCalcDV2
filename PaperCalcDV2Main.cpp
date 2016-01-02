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
#include <wx/textdlg.h>
#include <wx/font.h>
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
const int prototype = 2117;

// Required variables
const float thPow3 = 1000000000;
wxString ctrlTextDefault = _("");
wxString tmp;
wxString fetch_eur;
int modeParameter = 0;
int modeCost = 0;
bool costEnabled = false;

std::string repositoryLink = "http://www.github.com/HafisCZ/PaperCalc2";
std::string storeLink = "http://code.mar21.eu/PaperCalc2";
std::string versionLink = "http://raw.githubusercontent.com/HafisCZ/PaperCalc2/master/version.d";

const wxString langPack[35][2] = {
        {wxString::FromUTF8("#HAFISCZDEV"), //0
            wxString::FromUTF8("#HAFISCZDEV")},
        {wxString::FromUTF8("File"),
            wxString::FromUTF8("Soubor")},
        {wxString::FromUTF8("History"),
            wxString::FromUTF8("Historie")},
        {wxString::FromUTF8("Solve"),
            wxString::FromUTF8("Vypo\u010D\u00EDst")},
        {wxString::FromUTF8("Update"),
            wxString::FromUTF8("Aktualizace")},
        {wxString::FromUTF8("Quit"), //5
            wxString::FromUTF8("Konec")},
        {wxString::FromUTF8("Settings"),
            wxString::FromUTF8("Nastaven\u00ED")},
        {wxString::FromUTF8("Enable price module"),
            wxString::FromUTF8("Povolit cenov\u00FD modul")},
        {wxString::FromUTF8("Language"),
            wxString::FromUTF8("Jazyk")},
        {wxString::FromUTF8("English"),
            wxString::FromUTF8("Angli\u010Dtina")},
        {wxString::FromUTF8("Czech"), //10
            wxString::FromUTF8("\u010Ce\u0161tina")},
        {wxString::FromUTF8("Help"),
            wxString::FromUTF8("N\u00E1pov\u0115da")},
        {wxString::FromUTF8("About"),
            wxString::FromUTF8("O programu")},
        {wxString::FromUTF8("Size:"),
            wxString::FromUTF8("Velikost:")},
        {wxString::FromUTF8("Length:"),
            wxString::FromUTF8("D\u00E9lka:")},
        {wxString::FromUTF8("Width:"), //15
            wxString::FromUTF8("\u0160\u00ED\u0159ka:")},
        {wxString::FromUTF8("Gram:"),
            wxString::FromUTF8("Gram\u00E1\u017E:")},
        {wxString::FromUTF8("Weight:"),
            wxString::FromUTF8("Hmotnost:")},
        {wxString::FromUTF8("Count:"),
            wxString::FromUTF8("Po\u010Det:")},
        {wxString::FromUTF8("Conversion rate not available"),
            wxString::FromUTF8("Aktu\u00E1ln\u00ED kurz nen\u00ED dostupn\u00FD")},
        {wxString::FromUTF8("Clear"), //20
            wxString::FromUTF8("Vy\u010Distit")},
        {wxString::FromUTF8("Cost:"),
            wxString::FromUTF8("Cena:")},
        {wxString::FromUTF8("Cost/Weight:"),
            wxString::FromUTF8("Cena/V\u00E1ha:")},
        {wxString::FromUTF8("Rate:"),
            wxString::FromUTF8("Kurz:")},
        {wxString::FromUTF8("Cost/Count:"),
            wxString::FromUTF8("Cena/Po\u010Det:")},
        {wxString::FromUTF8("Update found"), //25
            wxString::FromUTF8("Nalezena aktualizace")},
        {wxString::FromUTF8("Open download page ..."),
            wxString::FromUTF8("Otev\u0159\u00EDt str\u00E1nku s aktualizac\u00ED ...")},
        {wxString::FromUTF8("Custom"),
            wxString::FromUTF8("Vlastn\u00ED")},
        {wxString::FromUTF8("PaperCalc 2 - Development Version"),
            wxString::FromUTF8("PaperCalc 2 - V\u00FDvoj\u00E1\u0159sk\u00E1 verze")},
        {wxString::FromUTF8("Application created for calculation of parameters of paper"),
            wxString::FromUTF8("Aplikace vytvo\u0159en\u00E1 pro v\u00FDpo\u010Det parametr\u016F pap\u00EDru")},
        {wxString::FromUTF8("(c)2016 Martin Halfar hafis\u0040protonmail.com"), //30
            wxString::FromUTF8("(c)2016 Martin Halfar hafis\u0040protonmail.com")},
        {wxString::FromUTF8("Unexpected error appeared !"),
            wxString::FromUTF8("Nastala nezn\u00E1m\u00E1 chyba !")},
        {wxString::FromUTF8("No update found ..."),
            wxString::FromUTF8("\u017D\u00E1dn\u00E1 aktualizace nebyla nalezena ...")},
        {wxString::FromUTF8("Enter value or leave empty"),
            wxString::FromUTF8("Vlo\u017Ete hodnotu nebo zanechte pr\u00E1zdn\u00E9")},
        {wxString::FromUTF8("Font"),
            wxString::FromUTF8("P\u00EDsmo")}
    };

// Paper formats, in future maybe in .xml type file
const double paperFormats[15][2] = {
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

const int codTrans[][3] = {
    {4, 4, 6},
    {5, 6, 4},
    {6, 5, 5}
};

const int codTrans2[][3] = {
    {8, 10, 10},
    {10, 8, 11},
    {11, 11, 8}
};

// Units
const wxString lengthUnits[] = {
    _("mm"), _("cm"), _("dm"), _("m")
};

const wxString weightUnits[] = {
    _("kg"), _("t")
};

const wxString countUnits[] = {
    _("arc"), _("kArc")
};

const wxString costCurr[] = {
    _(L"K\u010D"), _(L"\u20AC")
};

const wxString costPerWeightUnit[] = {
    _(L"K\u010D/kg"), _(L"K\u010D/t"),
    _(L"\u20AC/kg"), _(L"\u20AC/t")
};

const wxString costPerCountUnit[] = {
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
const long PaperCalcDV2Frame::idChangeFont = wxNewId();
const long PaperCalcDV2Frame::idMenuLanguageEN = wxNewId();
const long PaperCalcDV2Frame::idMenuLanguageCZ = wxNewId();
const long PaperCalcDV2Frame::idMenuClear = wxNewId();
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
    MenuItem10 = new wxMenuItem(Menu3, idChangeFont, _("2"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem10);
    MenuBar1->Append(Menu3, _("2"));
    Menu4 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu4, idMenuLanguageEN, _("1"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu4, idMenuLanguageCZ, _("2"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuItem8);
    MenuBar1->Append(Menu4, _("3"));
    Menu2 = new wxMenu();
    MenuItem9 = new wxMenuItem(Menu2, idMenuClear, _("2"), wxEmptyString, wxITEM_NORMAL);
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
    Connect(idChangeFont,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnFontChanged);
    Connect(idMenuLanguageEN,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnLanguageChanged);
    Connect(idMenuLanguageCZ,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnLanguageChanged);
    Connect(idMenuClear,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnClear);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnAbout);
    //*)

    selectedLanguage = 1;
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
    ExchangeLanguage(selectedLanguage);

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

    LoadEuroRate();

    Fit();
}

void PaperCalcDV2Frame::OnQuit(wxCommandEvent& event)
{
    // Close window
    Close();
}

void PaperCalcDV2Frame::LoadEuroRate(){
    time_t raw;
    struct tm * prepTime;
    time(&raw);
    prepTime = localtime(&raw);
    std::string historyDate = "01.01." + iToS(prepTime->tm_year + 1899);
    std::string todayDate = iToS(prepTime->tm_mday) + '.' + iToS(prepTime->tm_mon + 1) + '.' + iToS(prepTime->tm_year + 1900);
    HTTPDownloadRequest* rq = new HTTPDownloadRequest();
    wxString euroRaw = _(rq->request("http://www.cnb.cz/miranda2/m2/cs/financni_trhy/devizovy_trh/kurzy_devizoveho_trhu/vybrane.txt?mena=EUR&od=" + historyDate + "&do=" + todayDate));
    fetch_eur = euroRaw.SubString(euroRaw.length()-8 ,euroRaw.length()-7);
    fetch_eur << _(".") << euroRaw.SubString(euroRaw.length()-5 ,euroRaw.length()-3);

    double temp_eur;
    if (!fetch_eur.ToDouble(&temp_eur)) {
        fetch_eur = wxGetTextFromUser(langPack[33][selectedLanguage], langPack[19][selectedLanguage], _("27.000"));
    }

    TextCtrl7->ChangeValue(fetch_eur);
    delete rq;
}

void PaperCalcDV2Frame::PushObjects(wxChoice *ch, const wxString data[], int size)
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

    if (validate(TextCtrl1->GetValue(), &mod1Length) && validate(TextCtrl2->GetValue(), &mod1Width)) {

        parseDecScale(&mod1Length, Choice2->GetSelection());
        parseDecScale(&mod1Width, Choice3->GetSelection());

        switch (modeParameter) {

            case 0 : {
                if (!validate(TextCtrl3->GetValue(), &mod1Grammage) || !validate(TextCtrl4->GetValue(), &mod1Count)) {
                    ThrowError(-200);
                    return;
                } else {
                    parseThScale(&mod1Count, Choice5->GetSelection());
                    output = calculate(mod1Length, mod1Width, mod1Grammage, mod1Count, -1);
                    parseThScale(&output, -Choice6->GetSelection());
                    rw << (output);
                    TextCtrl5->ChangeValue(rw);
                }
                break;
            }

            case 1 : {
                if (!validate(TextCtrl3->GetValue(), &mod1Grammage) || !validate(TextCtrl5->GetValue(), &mod1Weight)) {
                    ThrowError(-200);
                    return;
                } else {
                    parseThScale(&mod1Weight, Choice6->GetSelection());
                    output = calculate(mod1Length, mod1Width, mod1Grammage, -1, mod1Weight);
                    parseThScale(&output, -Choice5->GetSelection());
                    rw << (output);
                    TextCtrl4->ChangeValue(rw);
                }
                break;
            }

            case 2 : {
                if (!validate(TextCtrl5->GetValue(), &mod1Weight) || !validate(TextCtrl4->GetValue(), &mod1Count)) {
                    ThrowError(-200);
                    return;
                } else {
                    parseThScale(&mod1Weight, Choice6->GetSelection());
                    output = calculate(mod1Length, mod1Width, -1, mod1Count, mod1Weight);
                    rw << (output);
                    TextCtrl3->ChangeValue(rw);
                }
                break;
            }
        }
    }

    rw = _("");

    if (costEnabled) {
        switch (modeCost) {

            case 0 : {
                if (validate(TextCtrl5->GetValue(), &mod1Weight) && validate(TextCtrl6->GetValue(), &mod2Weight)){

                    parseThScale(&mod1Weight, Choice6->GetSelection());

                    if (!validate(TextCtrl7->GetValue(), &mod2EuroCR)
                        && (Choice4->GetSelection() > 1 || Choice9->GetSelection() > 1 || Choice8->GetSelection() != 0 )) {
                        ThrowError(-400);
                        return;
                    }

                    cparseThScale(&mod2Weight, Choice4->GetSelection(), mod2EuroCR);

                    output = mod1Weight * mod2Weight;

                    if (validate(TextCtrl4->GetValue(), &mod1Count)) {
                        parseThScale(&mod1Count, Choice5->GetSelection());
                        wxString rc;
                        double comOutput = output / mod1Count;
                        cparseThScale(&comOutput, -Choice9->GetSelection(), mod2EuroCR);
                        rc << (comOutput);
                        TextCtrl9->ChangeValue(rc);
                    }

                    if (Choice8->GetSelection() != 0) output /= mod2EuroCR;
                    rw << (output);
                    TextCtrl8->ChangeValue(rw);

                    break;
                } else {
                    ThrowError(-300);
                    return;
                }
            }

            case 1: {
                if (validate(TextCtrl4->GetValue(), &mod1Count) && validate(TextCtrl9->GetValue(), &mod2Count)) {

                    parseThScale(&mod1Count, Choice5->GetSelection());

                    if (!validate(TextCtrl7->GetValue(), &mod2EuroCR)
                        && (Choice4->GetSelection() > 1 || Choice9->GetSelection() > 1 || Choice8->GetSelection() != 0 )) {
                        ThrowError(-400);
                        return;
                    }

                    cparseThScale(&mod2Count, Choice9->GetSelection(), mod2EuroCR);

                    output = mod1Count * mod2Count;

                    if (validate(TextCtrl5->GetValue(), &mod1Weight)) {
                        parseThScale(&mod1Weight, Choice6->GetSelection());
                        wxString rc;
                        double comOutput = output / mod1Weight;
                        cparseThScale(&comOutput, -Choice4->GetSelection(), mod2EuroCR);
                        rc << (comOutput);
                        TextCtrl6->ChangeValue(rc);
                    }

                    if (Choice8->GetSelection() != 0) output /= mod2EuroCR;
                    rw << (output);
                    TextCtrl8->ChangeValue(rw);

                    break;
                } else {
                    ThrowError(-300);
                    return;
                }
            }

            case 2 : {

                if (validate(TextCtrl8->GetValue(), &mod2Cost)) {

					if (!validate(TextCtrl7->GetValue(), &mod2EuroCR)
						&& (Choice4->GetSelection() > 1 || Choice9->GetSelection() > 1 || Choice8->GetSelection() != 0 )) {
						ThrowError(-400);
						return;
					}

					if (Choice8->GetSelection() != 0) mod2Cost *= mod2EuroCR;

					if (validate(TextCtrl4->GetValue(), &mod1Count)) {
						parseThScale(&mod1Count, Choice5->GetSelection());
						wxString rc(_(""));
						double comOutput1 = mod2Cost / mod1Count;
						cparseThScale(&comOutput1, -Choice9->GetSelection(), mod2EuroCR);
						rc << (comOutput1);
						TextCtrl9->ChangeValue(rc);
					}

					if (validate(TextCtrl5->GetValue(), &mod1Weight)) {
						parseThScale(&mod1Weight, Choice6->GetSelection());
						wxString rc(_(""));
						double comOutput1 = mod2Cost / mod1Weight;
						cparseThScale(&comOutput1, -Choice4->GetSelection(), mod2EuroCR);
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

void PaperCalcDV2Frame::ExchangeLanguage(int l)
{
    selectedLanguage = l;
    //Labels
    StaticText1->SetLabel(langPack[13][l]);
    StaticText2->SetLabel(langPack[14][l]);
    StaticText3->SetLabel(langPack[15][l]);
    StaticText4->SetLabel(langPack[((modeParameter == 0 || modeParameter == 1) ? 16 : 18)][l]);
    StaticText5->SetLabel(langPack[((modeParameter == 1 || modeParameter == 2) ? 17 : 18)][l]);
    StaticText7->SetLabel(_(L"g/m\u00B2"));
    StaticText8->SetLabel(langPack[((modeCost == 2) ? 24 : 21)][l]);
    StaticText9->SetLabel(_(L"K\u010D/\u20AC"));
    StaticText10->SetLabel(langPack[23][l]);
    StaticText11->SetLabel(langPack[((modeCost == 0) ? 24 : 22)][l]);

    //Toolbar
    MenuBar1->SetMenuLabel(0, langPack[1][l]);
    MenuBar1->SetMenuLabel(1, langPack[6][l]);
    MenuBar1->SetMenuLabel(2, langPack[8][l]);
    MenuBar1->SetMenuLabel(3, langPack[11][l]);

    //Sub-Toolbar
    MenuItem1->SetItemLabel(langPack[3][l] + _("\tReturn"));
    MenuItem2->SetItemLabel(langPack[2][l] + _("\tF2"));
    MenuItem3->SetItemLabel(langPack[5][l] + _("\tAlt-F4"));
    MenuItem4->SetItemLabel(langPack[7][l] + _("\tF5"));
    MenuItem5->SetItemLabel(langPack[12][l] + _("\tF1"));
    MenuItem6->SetItemLabel(langPack[4][l]);
    MenuItem7->SetItemLabel(langPack[9][l]);
    MenuItem8->SetItemLabel(langPack[10][l]);
    MenuItem9->SetItemLabel(langPack[20][l]);
    MenuItem10->SetItemLabel(langPack[34][l]);

    Choice7->SetString(0, langPack[17][l]);
    Choice7->SetString(1, langPack[18][l]);
    Choice7->SetString(2, langPack[16][l]);

    Choice10->SetString(0, langPack[22][l]);
    Choice10->SetString(1, langPack[24][l]);
    Choice10->SetString(2, langPack[21][l]);

    Choice1->SetString(0, langPack[27][l]);

    Fit();
}

void PaperCalcDV2Frame::OnCalcTypeChanged(wxCommandEvent& event)
{
    modeParameter = Choice7->GetSelection();

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

    PlaceToSizer(TextCtrl3, codTrans[0][modeParameter], 1);
    PlaceToSizer(StaticText7, codTrans[0][modeParameter], 4);
    PlaceToSizer(TextCtrl4, codTrans[1][modeParameter], 1);
    PlaceToSizer(Choice5, codTrans[1][modeParameter], 4);
    PlaceToSizer(TextCtrl5, codTrans[2][modeParameter], 1);
    PlaceToSizer(Choice6, codTrans[2][modeParameter], 4);

    StaticText4->SetLabel(langPack[((modeParameter == 0 || modeParameter == 1) ? 16 : 18)][selectedLanguage]);
    StaticText5->SetLabel(langPack[((modeParameter == 1 || modeParameter == 2) ? 17 : 18)][selectedLanguage]);

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
    ExchangeLanguage((MenuItem7->IsChecked() ? 0 : 1));
}

// Check for update
void PaperCalcDV2Frame::OnUpdate(wxCommandEvent& event)
{
    double newest;
    HTTPDownloadRequest* rq = new HTTPDownloadRequest();
    wxString newestVer = _(rq->request(versionLink));
    delete rq;
    newestVer.ToDouble(&newest);
    if (newest > prototype) {
        int openBrowser = wxMessageBox(langPack[26][selectedLanguage],langPack[25][selectedLanguage], wxYES_NO | wxICON_QUESTION);
        if (openBrowser == wxYES) {
            ShellExecute(0, L"open", L"http://code.mar21.eu/PaperCalc2", 0, 0 , SW_SHOW );
        }
    } else if (newest == -1) {
        StatusBar1->SetLabelText(langPack[31][selectedLanguage]);
    } else {
        StatusBar1->SetLabelText(langPack[32][selectedLanguage]);
    }

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
    modeCost = Choice10->GetSelection();

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

    PlaceToSizer(TextCtrl6, codTrans2[0][modeCost], 1);
    PlaceToSizer(Choice4, codTrans2[0][modeCost], 4);
    PlaceToSizer(TextCtrl9, codTrans2[1][modeCost], 1);
    PlaceToSizer(Choice9, codTrans2[1][modeCost], 4);
    PlaceToSizer(TextCtrl8, codTrans2[2][modeCost], 1);
    PlaceToSizer(Choice8, codTrans2[2][modeCost], 4);

    StaticText11->SetLabel(langPack[((modeCost == 0) ? 24 : 22)][selectedLanguage]);
    StaticText8->SetLabel(langPack[((modeCost == 2) ? 24 : 21)][selectedLanguage]);

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
	PCDV2History *history = new PCDV2History(NULL, selectedLanguage);
	history->Show(true);
}

void PaperCalcDV2Frame::OnFontChanged(wxCommandEvent& event)
{
    wxFont f(12, wxFONTFAMILY_DEFAULT,
         wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, true, "Courier");
    this->Refresh();
}
