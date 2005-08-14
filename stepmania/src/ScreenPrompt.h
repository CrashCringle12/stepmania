/* ScreenPrompt - Displays a prompt on top of another screen. */

#ifndef SCREEN_PROMPT_H
#define SCREEN_PROMPT_H

#include "ScreenWithMenuElements.h"
#include "BitmapText.h"

enum PromptType
{
	PROMPT_OK,
	PROMPT_YES_NO,
	PROMPT_YES_NO_CANCEL
};

enum PromptAnswer
{
	ANSWER_YES,
	ANSWER_NO,
	ANSWER_CANCEL,
	NUM_PROMPT_ANSWERS
};

class ScreenPrompt : public ScreenWithMenuElements
{
public:
	static void Prompt( ScreenMessage smSendOnPop, const CString &sText, PromptType type = PROMPT_OK, PromptAnswer defaultAnswer = ANSWER_NO, void(*OnYes)(void*) = NULL, void(*OnNo)(void*) = NULL, void* pCallbackData = NULL );

	ScreenPrompt( const CString &sScreenName );
	virtual void Init();
	virtual void BeginScreen();
	void Load( 
		CString sText, 
		PromptType type = PROMPT_OK, 
		PromptAnswer defaultAnswer = ANSWER_NO, 
		void(*OnYes)(void*) = NULL, 
		void(*OnNo)(void*) = NULL, 
		void* pCallbackData = NULL 
		);
	virtual void Input( const DeviceInput& DeviceI, const InputEventType type, const GameInput &GameI, const MenuInput &MenuI, const StyleInput &StyleI );

	static PromptAnswer s_LastAnswer;
	static bool s_bCancelledLast;

protected:
	bool CanGoLeft() { return m_Answer > 0; }
	bool CanGoRight();
	void Change( int dir );
	void MenuLeft( PlayerNumber pn );
	void MenuRight( PlayerNumber pn );
	void MenuBack( PlayerNumber pn );
	void MenuStart( PlayerNumber pn );

	virtual void End( bool bCancelled );
	void PositionCursor();

	BitmapText		m_textQuestion;
	AutoActor		m_sprCursor;
	BitmapText		m_textAnswer[NUM_PROMPT_ANSWERS];
	PromptAnswer	m_Answer;

	RageSound		m_sndChange;
};

#endif

/*
 * (c) 2001-2004 Chris Danford
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, and/or sell copies of the Software, and to permit persons to
 * whom the Software is furnished to do so, provided that the above
 * copyright notice(s) and this permission notice appear in all copies of
 * the Software and that both the above copyright notice(s) and this
 * permission notice appear in supporting documentation.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF
 * THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS
 * INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT
 * OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS
 * OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */
