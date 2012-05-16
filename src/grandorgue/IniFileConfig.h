/*
 * GrandOrgue - free pipe organ simulator
 *
 * Copyright 2006 Milan Digital Audio LLC
 * Copyright 2009-2012 GrandOrgue contributors (see AUTHORS)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * MA 02111-1307, USA.
 */

#ifndef INIFILECONFIG_H
#define INIFILECONFIG_H

#include <wx/wx.h>

class wxColour;
class wxString;
class wxFileConfig;

struct IniFileEnumEntry {
	wxString name;
	int value;
};

typedef enum { ODFSetting, UserSetting, CMBSetting } GOSettingType;

class IniFileConfig
{

private:
	wxFileConfig& m_ODFIni;
	wxString m_LastGroup;
	bool m_LastGroupExists;

public:
	IniFileConfig(wxFileConfig& iCfg);
	bool ReadBoolean(GOSettingType type, wxString group, wxString key, bool required = true);
	bool ReadBoolean(GOSettingType type, wxString group, wxString key, bool required, bool defaultValue);
	wxColour ReadColor(GOSettingType type, wxString group, wxString key, bool required = true);
	wxColour ReadColor(GOSettingType type, wxString group, wxString key, bool required, wxString defaultValue);
	wxString ReadString(GOSettingType type, wxString group, wxString key, unsigned nmax = 4096, bool required = true);
	wxString ReadString(GOSettingType type, wxString group, wxString key, unsigned nmax, bool required, wxString defaultValue);
	int ReadInteger(GOSettingType type, wxString group, wxString key, int nmin = 0, int nmax = 0, bool required = true);
	int ReadInteger(GOSettingType type, wxString group, wxString key, int nmin, int nmax, bool required, int defaultValue);
	int ReadLong(GOSettingType type, wxString group, wxString key, int nmin = 0, int nmax = 0, bool required = true);
	int ReadLong(GOSettingType type, wxString group, wxString key, int nmin, int nmax, bool required, int defaultValue);
	double ReadFloat(GOSettingType type, wxString group, wxString key, double nmin = 0, double nmax = 0, bool required = true);
	double ReadFloat(GOSettingType type, wxString group, wxString key, double nmin, double nmax, bool required, double defaultValue);
	unsigned ReadSize(GOSettingType type, wxString group, wxString key, unsigned size_type = 0, bool required = true);
	unsigned ReadSize(GOSettingType type, wxString group, wxString key, unsigned size_type, bool required, wxString defaultValue);
	unsigned ReadFontSize(GOSettingType type, wxString group, wxString key, bool required = true);
	unsigned ReadFontSize(GOSettingType type, wxString group, wxString key, bool required, wxString defaultValue);
	int ReadEnum(GOSettingType type, wxString group, wxString key, const struct IniFileEnumEntry* entry, unsigned count, bool required = true);
	int ReadEnum(GOSettingType type, wxString group, wxString key, const struct IniFileEnumEntry* entry, unsigned count, bool required, int defaultValue);
	void SaveHelper(bool prefix, wxString group, wxString key, wxString value);
	void SaveHelper( bool prefix, wxString group, wxString key, int value, bool sign = false, bool force = false);
	void SaveHelper(bool prefix, wxString group, wxString key, int value, const struct IniFileEnumEntry* entry, unsigned count);
	void SaveHelper(bool prefix, wxString group, wxString key, float value);

};

#endif
