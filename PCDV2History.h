#ifndef PCDV2HISTORY_H
#define PCDV2HISTORY_H

//(*Headers(PCDV2History)
#include <wx/stattext.h>
#include <wx/gbsizer.h>
#include <wx/frame.h>
//*)

class PCDV2History: public wxFrame
{
	public:

		PCDV2History(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~PCDV2History();

		//(*Declarations(PCDV2History)
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxStaticText* StaticText8;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(PCDV2History)
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		//*)

	private:

	    int selectedLanguage;

		//(*Handlers(PCDV2History)
		void OnQuit(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
