/*
* Copyright 2006 Milan Digital Audio LLC
* Copyright 2009-2021 GrandOrgue contributors (see AUTHORS)
* License GPL-2.0 or later (https://www.gnu.org/licenses/old-licenses/gpl-2.0.html).
*/

#ifndef GOSETTINGSMIDIDEVICELIST_H
#define GOSETTINGSMIDIDEVICELIST_H

#include <wx/button.h>
#include <wx/checklst.h>
#include <wx/window.h>

#include "ptrvector.h"

#include "midi/ports/GOMidiPort.h"

#include "GOMidiDeviceConfigList.h"
#include "GOPortsConfig.h"

class GOSettingsMidiDeviceList
{
private:
  wxWindow* m_parent;
  const ptr_vector<GOMidiPort>& m_Ports;
  GOMidiDeviceConfigList& m_ConfList;
  GOMidiDeviceConfig::List m_ListedConfs;
  wxCheckListBox* m_LbDevices;
  
  // temporary storage for configs when edited
  GOMidiDeviceConfigList m_ConfListTmp;

  void ClearDevices();

  void OnChecked(wxCommandEvent& event);
  
public:
  GOSettingsMidiDeviceList(
    const ptr_vector<GOMidiPort>& ports,
    GOMidiDeviceConfigList& configListPersist,
    wxWindow* parent,
    wxWindowID id
  );

  wxCheckListBox* GetListbox() const { return m_LbDevices; }

  void Init();

  void RefreshDevices(
    const GOPortsConfig& portsConfig,
    const bool isToAutoEnable,
    const GOSettingsMidiDeviceList* pOutDevList = NULL
  );

  unsigned GetDeviceCount() const;
  GOMidiDeviceConfig& GetDeviceConf(unsigned i) const { return *m_ListedConfs[i]; }
  GOMidiDeviceConfig& GetSelectedDeviceConf() const;

  void OnSelected(wxCommandEvent& event);

  void Save(const GOSettingsMidiDeviceList* pOutDevList = NULL);
};


#endif /* GOSETTINGSMIDIDEVICELIST_H */

