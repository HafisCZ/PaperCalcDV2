#include "PCDV2History.h"

#include <wx/listctrl.h>

//(*InternalHeaders(PCDV2History)
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

// Jazykové pole
const wxString langPack[12][2] = {
    {wxString::FromUTF8("#HAFISCZDEV"), //0
        wxString::FromUTF8("#HAFISCZDEV")},
    {wxString::FromUTF8("Length: [mm]"),
        wxString::FromUTF8("D\u00E9lka: [mm]")},
    {wxString::FromUTF8("Width: [mm]"),
        wxString::FromUTF8("\u0160\u00ED\u0159ka: [mm]")},
    {wxString::FromUTF8("Gram: [g/m\u00B2]"),
        wxString::FromUTF8("Gram\u00E1\u017E: [g/m\u00B2]")},
    {wxString::FromUTF8("Weight: [kg]"),
        wxString::FromUTF8("Hmotnost: [kg]")},
    {wxString::FromUTF8("Count: [arc]"), //5
        wxString::FromUTF8("Po\u010Det: [arc]")},
    {wxString::FromUTF8("Cost: [K\u010D]"),
        wxString::FromUTF8("Cena: [K\u010D]")},
    {wxString::FromUTF8("Cost/Weight: [K\u010D/kg]"),
        wxString::FromUTF8("Cena/V\u00E1ha: [K\u010D/kg]")},
    {wxString::FromUTF8("Rate: [K\u010D/\u20AC]"),
        wxString::FromUTF8("Kurz: [K\u010D/\u20AC]")},
    {wxString::FromUTF8("Cost/Count: [K\u010D/arc]"),
        wxString::FromUTF8("Cena/Po\u010Det: [K\u010D/arc]")},
    {wxString::FromUTF8("History"),
        wxString::FromUTF8("Historie")},
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
const long PCDV2History::ID_STATICTEXT30 = wxNewId();
const long PCDV2History::ID_STATICTEXT25 = wxNewId();
const long PCDV2History::ID_STATICTEXT26 = wxNewId();
const long PCDV2History::ID_STATICTEXT27 = wxNewId();
const long PCDV2History::ID_STATICTEXT28 = wxNewId();
const long PCDV2History::ID_STATICTEXT29 = wxNewId();
const long PCDV2History::ID_STATICTEXT31 = wxNewId();
const long PCDV2History::ID_STATICTEXT32 = wxNewId();
const long PCDV2History::ID_STATICTEXT51 = wxNewId();
const long PCDV2History::ID_STATICTEXT73 = wxNewId();
const long PCDV2History::ID_STATICTEXT53 = wxNewId();
const long PCDV2History::ID_STATICTEXT33 = wxNewId();
const long PCDV2History::ID_STATICTEXT34 = wxNewId();
const long PCDV2History::ID_STATICTEXT52 = wxNewId();
const long PCDV2History::ID_STATICTEXT35 = wxNewId();
const long PCDV2History::ID_STATICTEXT36 = wxNewId();
const long PCDV2History::ID_STATICTEXT37 = wxNewId();
const long PCDV2History::ID_STATICTEXT38 = wxNewId();
const long PCDV2History::ID_STATICTEXT39 = wxNewId();
const long PCDV2History::ID_STATICTEXT40 = wxNewId();
const long PCDV2History::ID_STATICTEXT41 = wxNewId();
const long PCDV2History::ID_STATICTEXT42 = wxNewId();
const long PCDV2History::ID_STATICTEXT43 = wxNewId();
const long PCDV2History::ID_STATICTEXT60 = wxNewId();
const long PCDV2History::ID_STATICTEXT44 = wxNewId();
const long PCDV2History::ID_STATICTEXT45 = wxNewId();
const long PCDV2History::ID_STATICTEXT46 = wxNewId();
const long PCDV2History::ID_STATICTEXT47 = wxNewId();
const long PCDV2History::ID_STATICTEXT48 = wxNewId();
const long PCDV2History::ID_STATICTEXT49 = wxNewId();
const long PCDV2History::ID_STATICTEXT82 = wxNewId();
const long PCDV2History::ID_STATICTEXT62 = wxNewId();
const long PCDV2History::ID_STATICTEXT50 = wxNewId();
const long PCDV2History::ID_STATICTEXT54 = wxNewId();
const long PCDV2History::ID_STATICTEXT55 = wxNewId();
const long PCDV2History::ID_STATICTEXT56 = wxNewId();
const long PCDV2History::ID_STATICTEXT57 = wxNewId();
const long PCDV2History::ID_STATICTEXT58 = wxNewId();
const long PCDV2History::ID_STATICTEXT59 = wxNewId();
const long PCDV2History::ID_STATICTEXT61 = wxNewId();
const long PCDV2History::ID_STATICTEXT80 = wxNewId();
const long PCDV2History::ID_STATICTEXT63 = wxNewId();
const long PCDV2History::ID_STATICTEXT64 = wxNewId();
const long PCDV2History::ID_STATICTEXT65 = wxNewId();
const long PCDV2History::ID_STATICTEXT66 = wxNewId();
const long PCDV2History::ID_STATICTEXT67 = wxNewId();
const long PCDV2History::ID_STATICTEXT68 = wxNewId();
const long PCDV2History::ID_STATICTEXT77 = wxNewId();
const long PCDV2History::ID_STATICTEXT69 = wxNewId();
const long PCDV2History::ID_STATICTEXT70 = wxNewId();
const long PCDV2History::ID_STATICTEXT85 = wxNewId();
const long PCDV2History::ID_STATICTEXT71 = wxNewId();
const long PCDV2History::ID_STATICTEXT72 = wxNewId();
const long PCDV2History::ID_STATICTEXT74 = wxNewId();
const long PCDV2History::ID_STATICTEXT75 = wxNewId();
const long PCDV2History::ID_STATICTEXT76 = wxNewId();
const long PCDV2History::ID_STATICTEXT78 = wxNewId();
const long PCDV2History::ID_STATICTEXT79 = wxNewId();
const long PCDV2History::ID_STATICTEXT81 = wxNewId();
const long PCDV2History::ID_STATICTEXT83 = wxNewId();
const long PCDV2History::ID_STATICTEXT84 = wxNewId();
const long PCDV2History::ID_STATICTEXT86 = wxNewId();
const long PCDV2History::ID_STATICTEXT87 = wxNewId();
const long PCDV2History::ID_STATICTEXT88 = wxNewId();
const long PCDV2History::ID_STATICTEXT89 = wxNewId();
const long PCDV2History::ID_STATICTEXT90 = wxNewId();
const long PCDV2History::ID_STATICTEXT91 = wxNewId();
const long PCDV2History::ID_STATICTEXT92 = wxNewId();
const long PCDV2History::ID_STATICTEXT93 = wxNewId();
const long PCDV2History::ID_STATICTEXT94 = wxNewId();
const long PCDV2History::ID_STATICTEXT95 = wxNewId();
const long PCDV2History::ID_STATICTEXT96 = wxNewId();
const long PCDV2History::ID_STATICTEXT97 = wxNewId();
const long PCDV2History::ID_STATICTEXT98 = wxNewId();
const long PCDV2History::ID_STATICTEXT99 = wxNewId();
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
	StaticText30 = new wxStaticText(this, ID_STATICTEXT30, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
	GridBagSizer1->Add(StaticText30, wxGBPosition(4, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText25 = new wxStaticText(this, ID_STATICTEXT25, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	GridBagSizer1->Add(StaticText25, wxGBPosition(3, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText26 = new wxStaticText(this, ID_STATICTEXT26, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	GridBagSizer1->Add(StaticText26, wxGBPosition(3, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText27 = new wxStaticText(this, ID_STATICTEXT27, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
	GridBagSizer1->Add(StaticText27, wxGBPosition(3, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText28 = new wxStaticText(this, ID_STATICTEXT28, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
	GridBagSizer1->Add(StaticText28, wxGBPosition(4, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText29 = new wxStaticText(this, ID_STATICTEXT29, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
	GridBagSizer1->Add(StaticText29, wxGBPosition(4, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText31 = new wxStaticText(this, ID_STATICTEXT31, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
	GridBagSizer1->Add(StaticText31, wxGBPosition(4, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText32 = new wxStaticText(this, ID_STATICTEXT32, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
	GridBagSizer1->Add(StaticText32, wxGBPosition(4, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText51 = new wxStaticText(this, ID_STATICTEXT51, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
	GridBagSizer1->Add(StaticText51, wxGBPosition(6, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText73 = new wxStaticText(this, ID_STATICTEXT73, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT73"));
	GridBagSizer1->Add(StaticText73, wxGBPosition(9, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText53 = new wxStaticText(this, ID_STATICTEXT53, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
	GridBagSizer1->Add(StaticText53, wxGBPosition(6, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText33 = new wxStaticText(this, ID_STATICTEXT33, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
	GridBagSizer1->Add(StaticText33, wxGBPosition(4, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText34 = new wxStaticText(this, ID_STATICTEXT34, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
	GridBagSizer1->Add(StaticText34, wxGBPosition(4, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText52 = new wxStaticText(this, ID_STATICTEXT52, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT52"));
	GridBagSizer1->Add(StaticText52, wxGBPosition(6, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText35 = new wxStaticText(this, ID_STATICTEXT35, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
	GridBagSizer1->Add(StaticText35, wxGBPosition(4, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText36 = new wxStaticText(this, ID_STATICTEXT36, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
	GridBagSizer1->Add(StaticText36, wxGBPosition(4, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText37 = new wxStaticText(this, ID_STATICTEXT37, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
	GridBagSizer1->Add(StaticText37, wxGBPosition(5, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText38 = new wxStaticText(this, ID_STATICTEXT38, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
	GridBagSizer1->Add(StaticText38, wxGBPosition(5, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText39 = new wxStaticText(this, ID_STATICTEXT39, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
	GridBagSizer1->Add(StaticText39, wxGBPosition(5, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText40 = new wxStaticText(this, ID_STATICTEXT40, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
	GridBagSizer1->Add(StaticText40, wxGBPosition(5, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText41 = new wxStaticText(this, ID_STATICTEXT41, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
	GridBagSizer1->Add(StaticText41, wxGBPosition(5, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText42 = new wxStaticText(this, ID_STATICTEXT42, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
	GridBagSizer1->Add(StaticText42, wxGBPosition(5, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText43 = new wxStaticText(this, ID_STATICTEXT43, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT43"));
	GridBagSizer1->Add(StaticText43, wxGBPosition(5, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText60 = new wxStaticText(this, ID_STATICTEXT60, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT60"));
	GridBagSizer1->Add(StaticText60, wxGBPosition(7, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText44 = new wxStaticText(this, ID_STATICTEXT44, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
	GridBagSizer1->Add(StaticText44, wxGBPosition(5, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText45 = new wxStaticText(this, ID_STATICTEXT45, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
	GridBagSizer1->Add(StaticText45, wxGBPosition(5, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText46 = new wxStaticText(this, ID_STATICTEXT46, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
	GridBagSizer1->Add(StaticText46, wxGBPosition(6, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText47 = new wxStaticText(this, ID_STATICTEXT47, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
	GridBagSizer1->Add(StaticText47, wxGBPosition(6, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText48 = new wxStaticText(this, ID_STATICTEXT48, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
	GridBagSizer1->Add(StaticText48, wxGBPosition(6, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText49 = new wxStaticText(this, ID_STATICTEXT49, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
	GridBagSizer1->Add(StaticText49, wxGBPosition(6, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText82 = new wxStaticText(this, ID_STATICTEXT82, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT82"));
	GridBagSizer1->Add(StaticText82, wxGBPosition(10, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText62 = new wxStaticText(this, ID_STATICTEXT62, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT62"));
	GridBagSizer1->Add(StaticText62, wxGBPosition(7, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText50 = new wxStaticText(this, ID_STATICTEXT50, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT50"));
	GridBagSizer1->Add(StaticText50, wxGBPosition(6, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText54 = new wxStaticText(this, ID_STATICTEXT54, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT54"));
	GridBagSizer1->Add(StaticText54, wxGBPosition(6, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText55 = new wxStaticText(this, ID_STATICTEXT55, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT55"));
	GridBagSizer1->Add(StaticText55, wxGBPosition(7, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText56 = new wxStaticText(this, ID_STATICTEXT56, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT56"));
	GridBagSizer1->Add(StaticText56, wxGBPosition(7, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText57 = new wxStaticText(this, ID_STATICTEXT57, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT57"));
	GridBagSizer1->Add(StaticText57, wxGBPosition(7, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText58 = new wxStaticText(this, ID_STATICTEXT58, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT58"));
	GridBagSizer1->Add(StaticText58, wxGBPosition(7, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText59 = new wxStaticText(this, ID_STATICTEXT59, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT59"));
	GridBagSizer1->Add(StaticText59, wxGBPosition(7, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText61 = new wxStaticText(this, ID_STATICTEXT61, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT61"));
	GridBagSizer1->Add(StaticText61, wxGBPosition(7, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText80 = new wxStaticText(this, ID_STATICTEXT80, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT80"));
	GridBagSizer1->Add(StaticText80, wxGBPosition(9, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText63 = new wxStaticText(this, ID_STATICTEXT63, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT63"));
	GridBagSizer1->Add(StaticText63, wxGBPosition(7, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText64 = new wxStaticText(this, ID_STATICTEXT64, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT64"));
	GridBagSizer1->Add(StaticText64, wxGBPosition(8, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText65 = new wxStaticText(this, ID_STATICTEXT65, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT65"));
	GridBagSizer1->Add(StaticText65, wxGBPosition(8, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText66 = new wxStaticText(this, ID_STATICTEXT66, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT66"));
	GridBagSizer1->Add(StaticText66, wxGBPosition(8, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText67 = new wxStaticText(this, ID_STATICTEXT67, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT67"));
	GridBagSizer1->Add(StaticText67, wxGBPosition(8, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText68 = new wxStaticText(this, ID_STATICTEXT68, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT68"));
	GridBagSizer1->Add(StaticText68, wxGBPosition(8, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText77 = new wxStaticText(this, ID_STATICTEXT77, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT77"));
	GridBagSizer1->Add(StaticText77, wxGBPosition(9, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText69 = new wxStaticText(this, ID_STATICTEXT69, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT69"));
	GridBagSizer1->Add(StaticText69, wxGBPosition(8, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText70 = new wxStaticText(this, ID_STATICTEXT70, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT70"));
	GridBagSizer1->Add(StaticText70, wxGBPosition(8, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText85 = new wxStaticText(this, ID_STATICTEXT85, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT85"));
	GridBagSizer1->Add(StaticText85, wxGBPosition(10, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText71 = new wxStaticText(this, ID_STATICTEXT71, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT71"));
	GridBagSizer1->Add(StaticText71, wxGBPosition(8, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText72 = new wxStaticText(this, ID_STATICTEXT72, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT72"));
	GridBagSizer1->Add(StaticText72, wxGBPosition(8, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText74 = new wxStaticText(this, ID_STATICTEXT74, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT74"));
	GridBagSizer1->Add(StaticText74, wxGBPosition(9, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText75 = new wxStaticText(this, ID_STATICTEXT75, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT75"));
	GridBagSizer1->Add(StaticText75, wxGBPosition(9, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText76 = new wxStaticText(this, ID_STATICTEXT76, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT76"));
	GridBagSizer1->Add(StaticText76, wxGBPosition(9, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText78 = new wxStaticText(this, ID_STATICTEXT78, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT78"));
	GridBagSizer1->Add(StaticText78, wxGBPosition(9, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText79 = new wxStaticText(this, ID_STATICTEXT79, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT79"));
	GridBagSizer1->Add(StaticText79, wxGBPosition(9, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText81 = new wxStaticText(this, ID_STATICTEXT81, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT81"));
	GridBagSizer1->Add(StaticText81, wxGBPosition(9, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText83 = new wxStaticText(this, ID_STATICTEXT83, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT83"));
	GridBagSizer1->Add(StaticText83, wxGBPosition(10, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText84 = new wxStaticText(this, ID_STATICTEXT84, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT84"));
	GridBagSizer1->Add(StaticText84, wxGBPosition(10, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText86 = new wxStaticText(this, ID_STATICTEXT86, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT86"));
	GridBagSizer1->Add(StaticText86, wxGBPosition(10, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText87 = new wxStaticText(this, ID_STATICTEXT87, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT87"));
	GridBagSizer1->Add(StaticText87, wxGBPosition(10, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText88 = new wxStaticText(this, ID_STATICTEXT88, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT88"));
	GridBagSizer1->Add(StaticText88, wxGBPosition(10, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText89 = new wxStaticText(this, ID_STATICTEXT89, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT89"));
	GridBagSizer1->Add(StaticText89, wxGBPosition(10, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText90 = new wxStaticText(this, ID_STATICTEXT90, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT90"));
	GridBagSizer1->Add(StaticText90, wxGBPosition(10, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText91 = new wxStaticText(this, ID_STATICTEXT91, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT91"));
	GridBagSizer1->Add(StaticText91, wxGBPosition(11, 0), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText92 = new wxStaticText(this, ID_STATICTEXT92, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT92"));
	GridBagSizer1->Add(StaticText92, wxGBPosition(11, 1), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText93 = new wxStaticText(this, ID_STATICTEXT93, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT93"));
	GridBagSizer1->Add(StaticText93, wxGBPosition(11, 2), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText94 = new wxStaticText(this, ID_STATICTEXT94, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT94"));
	GridBagSizer1->Add(StaticText94, wxGBPosition(11, 3), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText95 = new wxStaticText(this, ID_STATICTEXT95, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT95"));
	GridBagSizer1->Add(StaticText95, wxGBPosition(11, 4), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText96 = new wxStaticText(this, ID_STATICTEXT96, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT96"));
	GridBagSizer1->Add(StaticText96, wxGBPosition(11, 5), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText97 = new wxStaticText(this, ID_STATICTEXT97, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT97"));
	GridBagSizer1->Add(StaticText97, wxGBPosition(11, 6), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText98 = new wxStaticText(this, ID_STATICTEXT98, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT98"));
	GridBagSizer1->Add(StaticText98, wxGBPosition(11, 7), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText99 = new wxStaticText(this, ID_STATICTEXT99, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT99"));
	GridBagSizer1->Add(StaticText99, wxGBPosition(11, 8), wxDefaultSpan, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridBagSizer1);
	GridBagSizer1->Fit(this);
	GridBagSizer1->SetSizeHints(this);
	Center();
	//*)

    this->SetTitle(langPack[10][id]);

    StaticText1->SetLabel(langPack[1][id]);
    StaticText2->SetLabel(langPack[2][id]);
    StaticText3->SetLabel(langPack[3][id]);
    StaticText4->SetLabel(langPack[5][id]);
    StaticText5->SetLabel(langPack[4][id]);
    StaticText6->SetLabel(langPack[7][id]);
    StaticText7->SetLabel(langPack[9][id]);
    StaticText8->SetLabel(langPack[8][id]);
    StaticText9->SetLabel(langPack[6][id]);

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

    StaticText28->SetLabel(historyArray[2][0]);
    StaticText29->SetLabel(historyArray[2][1]);
    StaticText30->SetLabel(historyArray[2][2]);
    StaticText31->SetLabel(historyArray[2][3]);
    StaticText32->SetLabel(historyArray[2][4]);
    StaticText33->SetLabel(historyArray[2][5]);
    StaticText34->SetLabel(historyArray[2][6]);
    StaticText35->SetLabel(historyArray[2][7]);
    StaticText36->SetLabel(historyArray[2][8]);

    StaticText37->SetLabel(historyArray[3][0]);
    StaticText38->SetLabel(historyArray[3][1]);
    StaticText39->SetLabel(historyArray[3][2]);
    StaticText40->SetLabel(historyArray[3][3]);
    StaticText41->SetLabel(historyArray[3][4]);
    StaticText42->SetLabel(historyArray[3][5]);
    StaticText43->SetLabel(historyArray[3][6]);
    StaticText44->SetLabel(historyArray[3][7]);
    StaticText45->SetLabel(historyArray[3][8]);

    StaticText46->SetLabel(historyArray[4][0]);
    StaticText47->SetLabel(historyArray[4][1]);
    StaticText48->SetLabel(historyArray[4][2]);
    StaticText49->SetLabel(historyArray[4][3]);
    StaticText50->SetLabel(historyArray[4][4]);
    StaticText51->SetLabel(historyArray[4][5]);
    StaticText52->SetLabel(historyArray[4][6]);
    StaticText53->SetLabel(historyArray[4][7]);
    StaticText54->SetLabel(historyArray[4][8]);

    StaticText55->SetLabel(historyArray[5][0]);
    StaticText56->SetLabel(historyArray[5][1]);
    StaticText57->SetLabel(historyArray[5][2]);
    StaticText58->SetLabel(historyArray[5][3]);
    StaticText59->SetLabel(historyArray[5][4]);
    StaticText60->SetLabel(historyArray[5][5]);
    StaticText61->SetLabel(historyArray[5][6]);
    StaticText62->SetLabel(historyArray[5][7]);
    StaticText63->SetLabel(historyArray[5][8]);

    StaticText64->SetLabel(historyArray[6][0]);
    StaticText65->SetLabel(historyArray[6][1]);
    StaticText66->SetLabel(historyArray[6][2]);
    StaticText67->SetLabel(historyArray[6][3]);
    StaticText68->SetLabel(historyArray[6][4]);
    StaticText69->SetLabel(historyArray[6][5]);
    StaticText70->SetLabel(historyArray[6][6]);
    StaticText71->SetLabel(historyArray[6][7]);
    StaticText72->SetLabel(historyArray[6][8]);

    StaticText73->SetLabel(historyArray[7][0]);
    StaticText74->SetLabel(historyArray[7][1]);
    StaticText75->SetLabel(historyArray[7][2]);
    StaticText76->SetLabel(historyArray[7][3]);
    StaticText77->SetLabel(historyArray[7][4]);
    StaticText78->SetLabel(historyArray[7][5]);
    StaticText79->SetLabel(historyArray[7][6]);
    StaticText80->SetLabel(historyArray[7][7]);
    StaticText81->SetLabel(historyArray[7][8]);

    StaticText82->SetLabel(historyArray[8][0]);
    StaticText83->SetLabel(historyArray[8][1]);
    StaticText84->SetLabel(historyArray[8][2]);
    StaticText85->SetLabel(historyArray[8][3]);
    StaticText86->SetLabel(historyArray[8][4]);
    StaticText87->SetLabel(historyArray[8][5]);
    StaticText88->SetLabel(historyArray[8][6]);
    StaticText89->SetLabel(historyArray[8][7]);
    StaticText90->SetLabel(historyArray[8][8]);

    StaticText91->SetLabel(historyArray[9][0]);
    StaticText92->SetLabel(historyArray[9][1]);
    StaticText93->SetLabel(historyArray[9][2]);
    StaticText94->SetLabel(historyArray[9][3]);
    StaticText95->SetLabel(historyArray[9][4]);
    StaticText96->SetLabel(historyArray[9][5]);
    StaticText97->SetLabel(historyArray[9][6]);
    StaticText98->SetLabel(historyArray[9][7]);
    StaticText99->SetLabel(historyArray[9][8]);

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
