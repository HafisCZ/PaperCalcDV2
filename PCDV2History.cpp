#include "PCDV2History.h"

#include <wx/listctrl.h>

//(*InternalHeaders(PCDV2History)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

static wxString langPack[][2] = {
    {_("#HAFISCZDEV"),_("#HAFISCZDEV")} //0
};

//(*IdInit(PCDV2History)
const long PCDV2History::ID_STATICTEXT8 = wxNewId();
const long PCDV2History::ID_STATICTEXT7 = wxNewId();
const long PCDV2History::ID_STATICTEXT3 = wxNewId();
const long PCDV2History::ID_STATICTEXT2 = wxNewId();
const long PCDV2History::ID_STATICTEXT1 = wxNewId();
const long PCDV2History::ID_STATICTEXT4 = wxNewId();
const long PCDV2History::ID_STATICLINE1 = wxNewId();
const long PCDV2History::ID_STATICTEXT5 = wxNewId();
const long PCDV2History::ID_STATICTEXT6 = wxNewId();
const long PCDV2History::ID_STATICTEXT9 = wxNewId();
const long PCDV2History::ID_STATICTEXT10 = wxNewId();
const long PCDV2History::ID_STATICTEXT11 = wxNewId();
const long PCDV2History::ID_STATICTEXT12 = wxNewId();
const long PCDV2History::ID_STATICTEXT13 = wxNewId();
const long PCDV2History::ID_STATICTEXT14 = wxNewId();
const long PCDV2History::ID_STATICTEXT15 = wxNewId();
const long PCDV2History::ID_STATICTEXT18 = wxNewId();
const long PCDV2History::ID_STATICTEXT16 = wxNewId();
const long PCDV2History::ID_STATICTEXT17 = wxNewId();
const long PCDV2History::ID_STATICTEXT19 = wxNewId();
const long PCDV2History::ID_STATICTEXT20 = wxNewId();
const long PCDV2History::ID_STATICTEXT21 = wxNewId();
const long PCDV2History::ID_STATICTEXT22 = wxNewId();
const long PCDV2History::ID_STATICTEXT23 = wxNewId();
const long PCDV2History::ID_STATICTEXT24 = wxNewId();
const long PCDV2History::ID_STATICTEXT25 = wxNewId();
const long PCDV2History::ID_STATICTEXT26 = wxNewId();
const long PCDV2History::ID_STATICTEXT27 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PCDV2History,wxFrame)
	//(*EventTable(PCDV2History)
	//*)
END_EVENT_TABLE()

PCDV2History::PCDV2History(wxWindow* parent,wxWindowID id, wxString historyArray[10][9])
{
	//(*Initialize(PCDV2History)
	wxGridBagSizer* GridBagSizer1;

	Create(parent, wxID_ANY, _("History"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	wxFont thisFont(10,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
	SetFont(thisFont);
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	wxFont StaticText8Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText8->SetFont(StaticText8Font);
	GridBagSizer1->Add(StaticText8, wxGBPosition(0, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	wxFont StaticText7Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText7->SetFont(StaticText7Font);
	GridBagSizer1->Add(StaticText7, wxGBPosition(0, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	GridBagSizer1->Add(StaticText3, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	GridBagSizer1->Add(StaticText2, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	GridBagSizer1->Add(StaticText4, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	GridBagSizer1->Add(StaticLine1, wxGBPosition(1, 0), wxGBSpan(1, 10), wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	GridBagSizer1->Add(StaticText5, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	GridBagSizer1->Add(StaticText6, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	wxFont StaticText9Font(11,wxSWISS,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText9->SetFont(StaticText9Font);
	GridBagSizer1->Add(StaticText9, wxGBPosition(0, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	GridBagSizer1->Add(StaticText10, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	GridBagSizer1->Add(StaticText11, wxGBPosition(2, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	GridBagSizer1->Add(StaticText12, wxGBPosition(2, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	GridBagSizer1->Add(StaticText13, wxGBPosition(2, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	GridBagSizer1->Add(StaticText14, wxGBPosition(2, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	GridBagSizer1->Add(StaticText15, wxGBPosition(2, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText18 = new wxStaticText(this, ID_STATICTEXT18, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
	GridBagSizer1->Add(StaticText18, wxGBPosition(2, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	GridBagSizer1->Add(StaticText16, wxGBPosition(2, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	GridBagSizer1->Add(StaticText17, wxGBPosition(2, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText19 = new wxStaticText(this, ID_STATICTEXT19, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
	GridBagSizer1->Add(StaticText19, wxGBPosition(3, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText20 = new wxStaticText(this, ID_STATICTEXT20, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	GridBagSizer1->Add(StaticText20, wxGBPosition(3, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText21 = new wxStaticText(this, ID_STATICTEXT21, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	GridBagSizer1->Add(StaticText21, wxGBPosition(3, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText22 = new wxStaticText(this, ID_STATICTEXT22, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	GridBagSizer1->Add(StaticText22, wxGBPosition(3, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText23 = new wxStaticText(this, ID_STATICTEXT23, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	GridBagSizer1->Add(StaticText23, wxGBPosition(3, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText24 = new wxStaticText(this, ID_STATICTEXT24, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	GridBagSizer1->Add(StaticText24, wxGBPosition(3, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText25 = new wxStaticText(this, ID_STATICTEXT25, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	GridBagSizer1->Add(StaticText25, wxGBPosition(3, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText26 = new wxStaticText(this, ID_STATICTEXT26, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	GridBagSizer1->Add(StaticText26, wxGBPosition(3, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText27 = new wxStaticText(this, ID_STATICTEXT27, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
	GridBagSizer1->Add(StaticText27, wxGBPosition(3, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridBagSizer1);
	GridBagSizer1->Fit(this);
	GridBagSizer1->SetSizeHints(this);
	Center();
	//*)

    selectedLanguage = id;

    StaticText1->SetLabel(_("Length [mm]"));
    StaticText2->SetLabel(_("Width [mm]"));
    StaticText3->SetLabel(_("Grammage [g/m2]"));
    StaticText4->SetLabel(_("Count [arc]"));
    StaticText5->SetLabel(_("Weight [kg]"));
    StaticText6->SetLabel(_("Cost/Weight [czk/kg]"));
    StaticText7->SetLabel(_("Cost/Count [czk/arc]"));
    StaticText8->SetLabel(_("Rate [euro/czk]"));
    StaticText9->SetLabel(_("Cost [czk]"));

    StaticText10->SetLabel(historyArray[0][0]);
    StaticText11->SetLabel(historyArray[0][1]);
    StaticText12->SetLabel(historyArray[0][2]);
    StaticText13->SetLabel(historyArray[0][3]);
    StaticText14->SetLabel(historyArray[0][4]);
    StaticText15->SetLabel(historyArray[0][5]);
    StaticText16->SetLabel(historyArray[0][6]);
    StaticText17->SetLabel(historyArray[0][7]);
    StaticText18->SetLabel(historyArray[0][8]);

    StaticText19->SetLabel(historyArray[1][0]);
    StaticText20->SetLabel(historyArray[1][1]);
    StaticText21->SetLabel(historyArray[1][2]);
    StaticText22->SetLabel(historyArray[1][3]);
    StaticText23->SetLabel(historyArray[1][4]);
    StaticText24->SetLabel(historyArray[1][5]);
    StaticText25->SetLabel(historyArray[1][6]);
    StaticText26->SetLabel(historyArray[1][7]);
    StaticText27->SetLabel(historyArray[1][8]);

    Fit();

}

PCDV2History::~PCDV2History()
{
	//(*Destroy(PCDV2History)
	//*)
}


void PCDV2History::OnQuit(wxCommandEvent& event)
{
    Close();
}
