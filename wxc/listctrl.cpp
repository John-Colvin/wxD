//-----------------------------------------------------------------------------
// wxD - listctrl.cpp
// (C) 2005 bero <berobero.sourceforge.net>
// based on
// wx.NET - listctrl.cxx
//
// The wxListCtrl proxy interface
//
// Written by Bryan Bulten (bryan@bulten.ca)
// (C) 2003 by Bryan Bulten
// Licensed under the wxWidgets license, see LICENSE.txt for details.
//-----------------------------------------------------------------------------

#include <wx/wx.h>
#include "common.h"
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include "local_events.h"

//-----------------------------------------------------------------------------

class _ListCtrl : public wxListCtrl
{
public:
    DECLARE_OBJECTDELETED(_ListCtrl)
};

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxListCtrl* wxListCtrl_ctor()
{
    return new _ListCtrl();
}

extern "C" WXEXPORT
dbit wxListCtrl_Create(wxListCtrl *self, wxWindow *parent, wxWindowID id, const wxPoint* pos, const wxSize* size, int style, const wxValidator* validator, dstr name)
{
    if (pos == NULL)
        pos = &wxDefaultPosition;

    if (size == NULL)
        size = &wxDefaultSize;

    if (validator == NULL)
        validator = &wxDefaultValidator;

    if (name.data==NULL)
        name = dstr("listctrl");

    return self->Create(parent, id, *pos, *size, style, *validator, wxString(name.data, wxConvUTF8, name.length))?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_dtor(wxListCtrl* self)
{
    delete self;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_GetColumn(wxListCtrl* self, int col, wxListItem* item)
{
    return self->GetColumn(col, *item)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_SetColumn(wxListCtrl* self, int col, wxListItem* item)
{
    return self->SetColumn(col, *item)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetColumnWidth(wxListCtrl* self, int col)
{
    return self->GetColumnWidth(col);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_SetColumnWidth(wxListCtrl* self, int col, int width)
{
    return self->SetColumnWidth(col, width)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetCountPerPage(wxListCtrl* self)
{
    return self->GetCountPerPage();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxListItem* wxListCtrl_GetItem(wxListCtrl* self, wxListItem* info, dbit* retval)
{
    *retval = self->GetItem(*info);
    return info;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_SetItem(wxListCtrl* self, wxListItem* info)
{
    return self->SetItem(*info)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_SetItem_By_Row_Col(wxListCtrl* self, int index, int col, dstr label, int imageId)
{
    return self->SetItem(index, col, wxString(label.data, wxConvUTF8, label.length), imageId);
}


//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_SetTextImageItem(wxListCtrl* self, int index, int col, dstr label, int imageId)
{
    return self->SetItem(index, col, wxString(label.data, wxConvUTF8, label.length), imageId);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetItemState(wxListCtrl* self, int item, int stateMask)
{
    return self->GetItemState(item, stateMask);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_SetItemState(wxListCtrl* self, int item, int state, int stateMask)
{
    return self->SetItemState(item, state, stateMask)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_SetItemImage(wxListCtrl* self, int item, int image, int selImage)
{
    return self->SetItemImage(item, image, selImage)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dstrret wxListCtrl_GetItemText(wxListCtrl* self, int item)
{
    return dstr_ret(self->GetItemText(item).c_str());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetItemText(wxListCtrl* self, int item, dstr str)
{
    self->SetItemText(item, wxString(str.data, wxConvUTF8, str.length));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void* wxListCtrl_GetItemData(wxListCtrl* self, int item) 	
{
    return (void*)self->GetItemData(item);
}

//-----------------------------------------------------------------------------
 
extern "C" WXEXPORT
dbit wxListCtrl_SetItemData(wxListCtrl* self, int item, void* data)
{
    return self->SetItemData(item, (int)data)?1:0;
}

//-----------------------------------------------------------------------------
 
extern "C" WXEXPORT
dbit wxListCtrl_SetItemData2(wxListCtrl* self, int item, int data)
{
    return self->SetItemData(item, data)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_GetItemRect(wxListCtrl* self, int item, wxRect* rect, int code)
{
    return self->GetItemRect(item, *rect, code)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_GetItemPosition(wxListCtrl* self, int item, wxPoint* pos)
{
    return self->GetItemPosition(item, *pos)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_SetItemPosition(wxListCtrl* self, int item, const wxPoint* pos)
{
    return self->SetItemPosition(item, *pos)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetItemCount(wxListCtrl* self)
{
    return self->GetItemCount();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetColumnCount(wxListCtrl* self)
{
    return self->GetColumnCount();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetItemTextColour(wxListCtrl* self, int item, const wxColour* col)
{
    self->SetItemTextColour(item, *col);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxColour* wxListCtrl_GetItemTextColour(wxListCtrl* self, int item)
{
    return new wxColour(self->GetItemTextColour(item));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetItemBackgroundColour(wxListCtrl* self, int item, const wxColour *col)
{
    self->SetItemBackgroundColour(item, *col);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxColour* wxListCtrl_GetItemBackgroundColour(wxListCtrl* self, int item)
{
    return new wxColour(self->GetItemBackgroundColour(item));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetSelectedItemCount(wxListCtrl* self)
{
    return self->GetSelectedItemCount();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxColour* wxListCtrl_GetTextColour(wxListCtrl* self)
{
    return new wxColour(self->GetTextColour());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetTextColour(wxListCtrl* self, const wxColour* col)
{
    self->SetTextColour(*col);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetTopItem(wxListCtrl* self)
{
    return self->GetTopItem();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetSingleStyle(wxListCtrl* self, int style, dbit add)
{
    self->SetSingleStyle(style, add);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetWindowStyleFlag(wxListCtrl* self, int style)
{
    self->SetWindowStyleFlag(style);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_GetNextItem(wxListCtrl* self, int item, int geometry, int state)
{
    return self->GetNextItem(item, geometry, state);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxImageList* wxListCtrl_GetImageList(wxListCtrl* self, int which)
{
    return self->GetImageList(which);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetImageList(wxListCtrl* self, wxImageList* imageList, int which)
{
    self->SetImageList(imageList, which);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_AssignImageList(wxListCtrl* self, wxImageList* imageList, int which)
{
    self->AssignImageList(imageList, which);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_Arrange(wxListCtrl* self, int flag)
{
    return self->Arrange(flag)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_ClearAll(wxListCtrl* self)
{
    self->ClearAll();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_DeleteItem(wxListCtrl* self, int item)
{
    return self->DeleteItem(item)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_DeleteAllItems(wxListCtrl* self)
{
    return self->DeleteAllItems()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_DeleteAllColumns(wxListCtrl* self)
{
    return self->DeleteAllColumns()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_DeleteColumn(wxListCtrl* self, int col)
{
    return self->DeleteColumn(col)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_SetItemCount(wxListCtrl* self, int count)
{
    self->SetItemCount(count);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_EditLabel(wxListCtrl* self, int item)
{
    self->EditLabel(item);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_EnsureVisible(wxListCtrl* self, int item)
{
    return self->EnsureVisible(item)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_FindItem(wxListCtrl* self, int start, dstr str, dbit partial)
{
    return self->FindItem(start, wxString(str.data, wxConvUTF8, str.length), partial)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_FindItemData(wxListCtrl* self, int start, int data)
{
    return self->FindItem(start, data);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_FindItemPoint(wxListCtrl* self, int start, const wxPoint* pt, int direction)
{
    return self->FindItem(start, *pt, direction);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_HitTest(wxListCtrl* self, const wxPoint* point, int flags)
{
    return self->HitTest(*point, flags);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_InsertItem(wxListCtrl* self, wxListItem* info)
{
    return self->InsertItem(*info);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_InsertTextItem(wxListCtrl* self, int index, dstr label)
{
    return self->InsertItem(index, wxString(label.data, wxConvUTF8, label.length));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_InsertImageItem(wxListCtrl* self, int index, int imageIndex)
{
    return self->InsertItem(index, imageIndex);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_InsertTextImageItem(wxListCtrl* self, int index, dstr label, int imageIndex)
{
    return self->InsertItem(index, wxString(label.data, wxConvUTF8, label.length), imageIndex);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_InsertColumn(wxListCtrl* self, int col, wxListItem* info)
{
    return self->InsertColumn(col, *info);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListCtrl_InsertTextColumn(wxListCtrl* self, int col, dstr heading, int format, int width)
{
    return self->InsertColumn(col, wxString(heading.data, wxConvUTF8, heading.length), format, width);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_ScrollList(wxListCtrl* self, int dx, int dy)
{
    return self->ScrollList(dx, dy)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListCtrl_SortItems(wxListCtrl* self, wxListCtrlCompare fn, long data)
{
    return self->SortItems(fn, data)?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_GetViewRect(wxListCtrl* self, wxRect* rect)
{
	*rect=self->GetViewRect();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_RefreshItem(wxListCtrl* self, long item)
{
	self->RefreshItem(item);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListCtrl_RefreshItems(wxListCtrl* self, long itemFrom, long itemTo)
{
	self->RefreshItems(itemFrom, itemTo);
}

//-----------------------------------------------------------------------------
// wxListItem

extern "C" WXEXPORT
wxListItem* wxListItem_ctor()
{
    return new wxListItem();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_Clear(wxListItem* self)
{
    self->Clear();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_ClearAttributes(wxListItem* self)
{
	self->ClearAttributes();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListItem_GetAlign(wxListItem* self)
{
    return self->GetAlign();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxColour* wxListItem_GetBackgroundColour(wxListItem* self)
{
    return new wxColour(self->GetBackgroundColour());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListItem_GetColumn(wxListItem* self)
{
    return self->GetColumn();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void* wxListItem_GetData(wxListItem* self)
{
    return (void*)self->GetData();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxFont* wxListItem_GetFont(wxListItem* self)
{
    return new wxFont(self->GetFont());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListItem_GetId(wxListItem* self)
{
    return self->GetId();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListItem_GetImage(wxListItem* self)
{
    return self->GetImage();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListItem_GetMask(wxListItem* self)
{
    return self->GetMask();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListItem_GetState(wxListItem* self)
{
    return self->GetState();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dstrret wxListItem_GetText(wxListItem* self)
{
    return dstr_ret(self->GetText());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxColour* wxListItem_GetTextColour(wxListItem* self)
{
    return new wxColour(self->GetTextColour());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListItem_GetWidth(wxListItem* self)
{
    return self->GetWidth();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetAlign(wxListItem* self, int align)
{
    self->SetAlign((wxListColumnFormat)align);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetBackgroundColour(wxListItem* self, wxColour* col)
{
    self->SetBackgroundColour(*col);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetColumn(wxListItem* self, int col)
{
    self->SetColumn(col);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetData(wxListItem* self, void* data)
{
	self->SetData((int)data);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetFont(wxListItem* self, wxFont* font)
{
    self->SetFont(*font);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetId(wxListItem* self, int id)
{
    self->SetId(id);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetImage(wxListItem* self, int image)
{
    self->SetImage(image);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetMask(wxListItem* self, int mask)
{
    self->SetMask(mask);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetState(wxListItem* self, int state)
{
    self->SetState(state);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetStateMask(wxListItem* self, int stateMask)
{
    self->SetStateMask(stateMask);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetText(wxListItem* self, dstr text)
{
    self->SetText(wxString(text.data, wxConvUTF8, text.length));
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetTextColour(wxListItem* self, wxColour* col)
{
    self->SetTextColour(*col);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItem_SetWidth(wxListItem* self, int width)
{
    self->SetWidth(width);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxListItemAttr* wxListItem_GetAttributes(wxListItem* self)
{
	return self->GetAttributes();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListItem_HasAttributes(wxListItem* self)
{
	return self->HasAttributes()?1:0;
}

//----------------------------------------------------------------------------
// wxListEvent

extern "C" WXEXPORT
wxListEvent* wxListEvent_ctor(wxEventType commandType, int id)
{
    return new wxListEvent(commandType, id);
}

//----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListEvent_GetCacheFrom(wxListEvent* self)
{
    return self->GetCacheFrom();
}
//----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListEvent_GetCacheTo(wxListEvent* self)
{
    return self->GetCacheTo();
}
//----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListEvent_GetKeyCode(wxListEvent* self)
{
    return self->GetKeyCode();
}
//----------------------------------------------------------------------------

extern "C" WXEXPORT
long wxListEvent_GetIndex(wxListEvent* self)
{
    return self->GetIndex();
}
//----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListEvent_GetColumn(wxListEvent* self)
{
    return self->GetColumn();
}
//----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListEvent_IsEditCancelled(wxListEvent* self)
{
    return self->IsEditCancelled()?1:0;
}

//----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListEvent_SetEditCanceled(wxListEvent* self, dbit editCancelled)
{
    self->SetEditCanceled(editCancelled);
}

//----------------------------------------------------------------------------

extern "C" WXEXPORT
dstrret wxListEvent_GetLabel(wxListEvent* self)
{
    return dstr_ret(self->GetLabel());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListEvent_GetPoint(wxListEvent* self, wxPoint* pt)
{
    *pt = self->GetPoint();
}

//-----------------------------------------------------------------------------
extern "C" WXEXPORT
int wxListEvent_GetImage(wxListEvent* self)
{
    return self->GetImage();
}

//-----------------------------------------------------------------------------


extern "C" WXEXPORT
dstrret wxListEvent_GetText(wxListEvent* self)
{
    return dstr_ret(self->GetText());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
int wxListEvent_GetMask(wxListEvent* self)
{
    return self->GetMask();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxListItem* wxListEvent_GetItem(wxListEvent* self)
{
    return new wxListItem(self->GetItem());
}

extern "C" WXEXPORT
int wxListEvent_GetData(wxListEvent* self)
{
	return self->GetData();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListEvent_Veto(wxListEvent* self)
{
    self->Veto();
}

extern "C" WXEXPORT
void wxListEvent_Allow(wxListEvent* self)
{
    self->Allow();
}

extern "C" WXEXPORT
dbit wxListEvent_IsAllowed(wxListEvent* self)
{
    return self->IsAllowed()?1:0;
}

//-----------------------------------------------------------------------------
// wxListView

class _ListView : public wxListView
{
public:
    DECLARE_OBJECTDELETED(_ListView)
};

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxListView* wxListView_ctor()
{
    return new _ListView();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListView_Create(wxListCtrl *self, wxWindow *parent, wxWindowID id, const wxPoint* pos, const wxSize* size, int style, const wxValidator* validator, dstr name)
{
    if (pos == NULL)
        pos = &wxDefaultPosition;

    if (size == NULL)
        size = &wxDefaultSize;

    if (validator == NULL)
        validator = &wxDefaultValidator;

    if (name.data==NULL)
        name = dstr("listview");

    return self->Create(parent, id, *pos, *size, style, *validator, wxString(name.data, wxConvUTF8, name.length))?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListView_Select(wxListView* self, long n, dbit on)
{
	self->Select(n, on);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListView_Focus(wxListView* self, long index)
{
	self->Focus(index);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
long wxListView_GetFocusedItem(wxListView* self)
{
	return self->GetFocusedItem();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
long wxListView_GetNextSelected(wxListView* self, long item)
{
	return self->GetNextSelected(item);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
long wxListView_GetFirstSelected(wxListView* self)
{
	return self->GetFirstSelected();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
long wxListView_IsSelected(wxListView* self, long index)
{
	return self->IsSelected(index);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListView_SetColumnImage(wxListView* self, int col, int image)
{
	self->SetColumnImage(col, image);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListView_ClearColumnImage(wxListView* self, int col)
{
	self->ClearColumnImage(col);
}

//-----------------------------------------------------------------------------
// wxListItemAttr

class _ListItemAttr : public wxListItemAttr
{
public:
	_ListItemAttr()
		: wxListItemAttr() {}
		
	_ListItemAttr(const wxColour& colText,
                   const wxColour& colBack,
                   const wxFont& font)
		: wxListItemAttr(colText, colBack, font) {}
		
	DECLARE_DISPOSABLE(_ListItemAttr)
};

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxListItemAttr* wxListItemAttr_ctor()
{
	return new _ListItemAttr();
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxListItemAttr* wxListItemAttr_ctor2(wxColour* colText, wxColour* colBack, wxFont* font)
{
	return new _ListItemAttr(*colText, *colBack, *font);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItemAttr_dtor(wxListItemAttr* self)
{
	if (self != NULL)
		delete self;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItemAttr_RegisterDisposable(_ListItemAttr* self, Virtual_Dispose onDispose)
{
	self->RegisterDispose(onDispose);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItemAttr_SetTextColour(wxListItemAttr* self, wxColour* colText)
{
	self->SetTextColour(*colText);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItemAttr_SetBackgroundColour(wxListItemAttr* self, wxColour* colBack)
{
	self->SetBackgroundColour(*colBack);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
void wxListItemAttr_SetFont(wxListItemAttr* self, wxFont* font)
{
	self->SetFont(*font);
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListItemAttr_HasTextColour(wxListItemAttr* self)
{
	return self->HasTextColour()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListItemAttr_HasBackgroundColour(wxListItemAttr* self)
{
	return self->HasBackgroundColour()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
dbit wxListItemAttr_HasFont(wxListItemAttr* self)
{
	return self->HasFont()?1:0;
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxColour* wxListItemAttr_GetTextColour(wxListItemAttr* self)
{
	return new wxColour(self->GetTextColour());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxColour* wxListItemAttr_GetBackgroundColour(wxListItemAttr* self)
{
	return new wxColour(self->GetBackgroundColour());
}

//-----------------------------------------------------------------------------

extern "C" WXEXPORT
wxFont* wxListItemAttr_GetFont(wxListItemAttr* self)
{
	return new wxFont(self->GetFont());
}

extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_BEGIN_DRAG()             { return wxEVT_COMMAND_LIST_BEGIN_DRAG; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_BEGIN_RDRAG()            { return wxEVT_COMMAND_LIST_BEGIN_RDRAG; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_BEGIN_LABEL_EDIT()       { return wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_END_LABEL_EDIT()         { return wxEVT_COMMAND_LIST_END_LABEL_EDIT; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_DELETE_ITEM()            { return wxEVT_COMMAND_LIST_DELETE_ITEM; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_DELETE_ALL_ITEMS()       { return wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_GET_INFO()			{ return wxEVT_COMMAND_LIST_GET_INFO; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_SET_INFO()			{ return wxEVT_COMMAND_LIST_SET_INFO; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_ITEM_SELECTED()          { return wxEVT_COMMAND_LIST_ITEM_SELECTED; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_ITEM_DESELECTED()        { return wxEVT_COMMAND_LIST_ITEM_DESELECTED; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_ITEM_ACTIVATED()         { return wxEVT_COMMAND_LIST_ITEM_ACTIVATED; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_ITEM_FOCUSED()           { return wxEVT_COMMAND_LIST_ITEM_FOCUSED; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_ITEM_MIDDLE_CLICK()      { return wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_ITEM_RIGHT_CLICK()       { return wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_KEY_DOWN()               { return wxEVT_COMMAND_LIST_KEY_DOWN; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_INSERT_ITEM()            { return wxEVT_COMMAND_LIST_INSERT_ITEM; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_COL_CLICK()              { return wxEVT_COMMAND_LIST_COL_CLICK; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_COL_RIGHT_CLICK()        { return wxEVT_COMMAND_LIST_COL_RIGHT_CLICK; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_COL_BEGIN_DRAG()         { return wxEVT_COMMAND_LIST_COL_BEGIN_DRAG; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_COL_DRAGGING()           { return wxEVT_COMMAND_LIST_COL_DRAGGING; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_COL_END_DRAG()           { return wxEVT_COMMAND_LIST_COL_END_DRAG; }
extern "C" WXEXPORT int wxEvent_EVT_COMMAND_LIST_CACHE_HINT()             { return wxEVT_COMMAND_LIST_CACHE_HINT; }

