#include "PCDV2History.h"

//(*InternalHeaders(PCDV2History)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(PCDV2History)
const long PCDV2History::ID_BUTTON1 = wxNewId();
const long PCDV2History::ID_STATUSBAR1 = wxNewId();
const long PCDV2History::ID_MENUITEM1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(PCDV2History,wxFrame)
	//(*EventTable(PCDV2History)
	//*)
END_EVENT_TABLE()

PCDV2History::PCDV2History(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(PCDV2History)
	wxGridBagSizer* GridBagSizer1;

	Create(parent, id, _("History"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	GridBagSizer1 = new wxGridBagSizer(0, 0);
	Button1 = new wxButton(this, ID_BUTTON1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	GridBagSizer1->Add(Button1, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(GridBagSizer1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("1\tAlt-F4"), wxEmptyString, wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuBar1->Append(Menu1, _("1"));
	SetMenuBar(MenuBar1);
	GridBagSizer1->Fit(this);
	GridBagSizer1->SetSizeHints(this);

	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&PCDV2History::OnQuit);
	//*)
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
