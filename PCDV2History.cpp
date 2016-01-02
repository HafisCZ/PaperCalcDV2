#include "PCDV2History.h"

//(*InternalHeaders(PCDV2History)
#include <wx/settings.h>
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
const long PCDV2History::ID_STATICTEXT5 = wxNewId();
const long PCDV2History::ID_STATICTEXT6 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PCDV2History,wxFrame)
	//(*EventTable(PCDV2History)
	//*)
END_EVENT_TABLE()

PCDV2History::PCDV2History(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(PCDV2History)
	wxGridBagSizer* GridBagSizer1;

	Create(parent, wxID_ANY, _("History"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	GridBagSizer1->Add(StaticText8, wxGBPosition(0, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	GridBagSizer1->Add(StaticText7, wxGBPosition(0, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	GridBagSizer1->Add(StaticText3, wxGBPosition(0, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	GridBagSizer1->Add(StaticText2, wxGBPosition(0, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	GridBagSizer1->Add(StaticText1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	GridBagSizer1->Add(StaticText4, wxGBPosition(0, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	GridBagSizer1->Add(StaticText5, wxGBPosition(0, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	GridBagSizer1->Add(StaticText6, wxGBPosition(0, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridBagSizer1);
	GridBagSizer1->Fit(this);
	GridBagSizer1->SetSizeHints(this);
	Center();
	//*)

    selectedLanguage = id;

    StaticText1->SetLabel(_("Length"));
    StaticText2->SetLabel(_("Width"));
    StaticText3->SetLabel(_("Grammage"));
    StaticText4->SetLabel(_("Count"));
    StaticText5->SetLabel(_("Weight"));
    StaticText6->SetLabel(_("Cost/Weight"));
    StaticText7->SetLabel(_("Cost/Count"));
    StaticText8->SetLabel(_("Cost"));
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
