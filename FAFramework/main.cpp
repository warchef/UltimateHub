#include "FAFramework.h"

GUI_APP_MAIN
{
	TopWindow win;
	fa::FAFieldCtrl ctrl;
	CtrlLayout(ctrl);
	RichTextView view;
	ctrl.ctrl.Add(view.SizePos());
	ctrl.label.SetLabel("HELLÓ világ");
	AutoScroller s;
	s.AddPane(ctrl);
	win.Add(s.SizePos());
	win.Sizeable().Execute();
}
