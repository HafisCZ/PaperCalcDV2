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

//(*InternalHeaders(PaperCalcDV2Frame)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

// Required variables
const float thPow3 = 1000000000;
wxString ctrlTextDefault = _(" ");
wxString rw;
double rwLen, rwWid, rwGrm, rwCnt, rwWig;

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

wxString calcTypes[] = {
    _("Weight"), _("Count"), _("Gram")
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
const long PaperCalcDV2Frame::idMenuHistory = wxNewId();
const long PaperCalcDV2Frame::idMenuSolve = wxNewId();
const long PaperCalcDV2Frame::idMenuUpdate = wxNewId();
const long PaperCalcDV2Frame::idMenuQuit = wxNewId();
const long PaperCalcDV2Frame::idMenuPriceEnabled = wxNewId();
const long PaperCalcDV2Frame::idMenuLanguageEN = wxNewId();
const long PaperCalcDV2Frame::idMenuLanguageCZ = wxNewId();
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
    wxGridBagSizer* GridBagSizer1;
    wxMenuBar* MenuBar1;

    Create(parent, wxID_ANY, _("PaperCalc 2 Development Version "), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
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
    Choice2->Append(_("1"));
    Choice2->Append(_("2"));
    Choice2->Append(_("3"));
    Choice2->Append(_("4"));
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
    GridBagSizer1->Add(Choice7, wxGBPosition(6, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(GridBagSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu1, idMenuHistory, _("History\tF2"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem2);
    MenuItem1 = new wxMenuItem(Menu1, idMenuSolve, _("Solve\tReturn"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuItem6 = new wxMenuItem(Menu1, idMenuUpdate, _("Update"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    Menu1->AppendSeparator();
    MenuItem3 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu3, idMenuPriceEnabled, _("Enable PriceModule"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(MenuItem4);
    MenuBar1->Append(Menu3, _("Settings"));
    Menu4 = new wxMenu();
    MenuItem7 = new wxMenuItem(Menu4, idMenuLanguageEN, _("English"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuItem7);
    MenuItem8 = new wxMenuItem(Menu4, idMenuLanguageCZ, _("Czech"), wxEmptyString, wxITEM_RADIO);
    Menu4->Append(MenuItem8);
    MenuBar1->Append(Menu4, _("Language"));
    Menu2 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem5);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    GridBagSizer1->Fit(this);
    GridBagSizer1->SetSizeHints(this);
    Center();

    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSizeSelect);
    Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSizeChanged);
    Connect(ID_TEXTCTRL2,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSizeChanged);
    Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(ID_CHOICE3,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(idMenuSolve,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnSolve);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PaperCalcDV2Frame::OnQuit);
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

    StaticText1->SetLabel(_("Size:"));
    StaticText2->SetLabel(_("Length:"));
    StaticText3->SetLabel(_("Width:"));
    StaticText4->SetLabel(_("Gram:"));
    StaticText5->SetLabel(_("Amount:"));
    //wxUNUSED::StaticText6->SetLabel(_("Weight:"));
    StaticText7->SetLabel(_(L"g/m\u00B2"));

    Choice1->SetSelection(0);

    PushObjects(Choice2, lengthUnits, 4);
    PushObjects(Choice3, lengthUnits, 4);
    Choice2->SetSelection(0);
    Choice3->SetSelection(0);

    PushObjects(Choice5, countUnits, 2);
    Choice5->SetSelection(0);

    PushObjects(Choice6, weightUnits, 2);
    Choice6->SetSelection(0);

    PushObjects(Choice7, calcTypes, 3);
    Choice7->SetSelection(0);

    TextCtrl1->ChangeValue(ctrlTextDefault);
    TextCtrl2->ChangeValue(ctrlTextDefault);
    TextCtrl3->ChangeValue(ctrlTextDefault);
    TextCtrl4->ChangeValue(ctrlTextDefault);
    TextCtrl5->ChangeValue(ctrlTextDefault);
    // Unicode code as _(L"\u00E0")

    Fit();
}

void PaperCalcDV2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

// Replace default placeholders in wxChoice with wxString array data
void PaperCalcDV2Frame::PushObjects(wxChoice *ch, wxString data[], int size)
{
    // For each index in wxString array
    for (int i = 0; i < size; i++) {
        // Add wxString into wxChoice object
        ch->SetString(i, data[i]);
    }
}

void PaperCalcDV2Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( _("PaperCalcV2 by Martin 'Hafis' Halfar\nWebsite: http://code.mar21.eu/\nEmail: hafis@protonmail.com\nStability not guaranteed in Development state of this app"), _("About"));
}

bool PaperCalcDV2Frame::validate(wxString str, double *var)
{
    if(!(str).ToDouble(var)){
        StatusBar1->SetLabel(_("Invalid input!"));
        return false;
    }
    return true;
}

// EVENT :: Solve
void PaperCalcDV2Frame::OnSolve(wxCommandEvent& event)
{
    if(validate(TextCtrl1->GetValue(), &rwLen) &&
       validate(TextCtrl2->GetValue(), &rwWid) &&
       validate(TextCtrl3->GetValue(), &rwGrm) &&
       validate(TextCtrl4->GetValue(), &rwCnt) &&
       validate(TextCtrl5->GetValue(), &rwWig)) {

           StatusBar1->SetLabel(ctrlTextDefault);

           rw = ctrlTextDefault;

           parseDecScale(&rwLen, Choice2->GetSelection());
           parseDecScale(&rwWid, Choice3->GetSelection());

           parseThScale(&rwCnt, Choice5->GetSelection());

           double parsedOutput = calculate(rwLen, rwWid, rwGrm, rwCnt, -1);
           parseThScale(&parsedOutput, -Choice6->GetSelection());

           rw << (parsedOutput);

           TextCtrl5->ChangeValue(rw);
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

// Solve function, take -1 as output parameter type & value >= 0 for valid input | else returns error code
double PaperCalcDV2Frame::calculate (double hLenght, double hWidth, double hGram, double hCount, double hWeight)
{
    if (hLenght == -1) {
        if (hWidth <= 0 || hGram <= 0 || hCount <= 0 || hWeight <= 0) return -200;
        return ((hWeight * thPow3) / (hWidth * hGram * hCount));
    } else if (hWidth == -1) {
        if (hLenght <= 0 || hGram <= 0 || hCount <= 0 || hWeight <= 0) return -201;
        return ((hWeight * thPow3) / (hLenght * hGram * hCount));
    } else if (hGram == -1) {
        if (hWidth <= 0 || hLenght <= 0 || hCount <= 0 || hWeight <= 0) return -202;
        return ((hWeight * thPow3) / (hLenght * hWidth * hCount));
    } else if (hCount == -1) {
        if (hWidth <= 0 || hGram <= 0 || hLenght <= 0 || hWeight <= 0) return -203;
        return ((hWeight * thPow3) / (hLenght * hWidth * hGram));
    } else if (hWeight == -1) {
        if (hWidth <= 0 || hGram <= 0 || hCount <= 0 || hLenght <= 0) return -204;
        return ((hLenght * hWidth * hGram * hCount) / thPow3);
    } else {
        return -199;
    }
}
