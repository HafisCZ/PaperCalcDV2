#ifndef PCDV2HISTORY_H
#define PCDV2HISTORY_H

//(*Headers(PCDV2History)
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
//*)

class PCDV2History: public wxFrame
{
	public:

		PCDV2History(wxWindow* parent,wxWindowID id=wxID_ANY,wxString historyArray[10][9]=NULL);
		virtual ~PCDV2History();

		//(*Declarations(PCDV2History)
		wxStaticText* StaticText10;
		wxStaticText* StaticText22;
		wxStaticText* StaticText9;
		wxStaticText* StaticText20;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxStaticText* StaticText14;
		wxStaticText* StaticText26;
		wxStaticText* StaticText6;
		wxStaticText* StaticText19;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxStaticText* StaticText18;
		wxStaticText* StaticText1;
		wxStaticText* StaticText27;
		wxStaticText* StaticText3;
		wxStaticText* StaticText21;
		wxStaticText* StaticText23;
		wxStaticText* StaticText24;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticLine* StaticLine1;
		wxStaticText* StaticText15;
		wxStaticText* StaticText12;
		wxStaticText* StaticText25;
		wxStaticText* StaticText17;
		wxStaticText* StaticText4;
		wxStaticText* StaticText16;
		//*)

	protected:

		//(*Identifiers(PCDV2History)
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT18;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT19;
		static const long ID_STATICTEXT20;
		static const long ID_STATICTEXT21;
		static const long ID_STATICTEXT22;
		static const long ID_STATICTEXT23;
		static const long ID_STATICTEXT24;
		static const long ID_STATICTEXT25;
		static const long ID_STATICTEXT26;
		static const long ID_STATICTEXT27;
		//*)

	private:

	    int selectedLanguage;

		//(*Handlers(PCDV2History)
		void OnQuit(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
