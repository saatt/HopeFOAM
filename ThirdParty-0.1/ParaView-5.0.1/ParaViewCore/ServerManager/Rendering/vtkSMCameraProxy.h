/*=========================================================================

  Program:   ParaView
  Module:    vtkSMCameraProxy.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMCameraProxy - proxy for a camera.
// .SECTION Description
// This a proxy for a vtkCamera. This class optimizes UpdatePropertyInformation
// to use the client side object.

#ifndef vtkSMCameraProxy_h
#define vtkSMCameraProxy_h

#include "vtkPVServerManagerRenderingModule.h" //needed for exports
#include "vtkSMProxy.h"

class VTKPVSERVERMANAGERRENDERING_EXPORT vtkSMCameraProxy : public vtkSMProxy
{
public:
  static vtkSMCameraProxy* New();
  vtkTypeMacro(vtkSMCameraProxy, vtkSMProxy);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Updates all property informations by calling UpdateInformation()
  // and populating the values.
  virtual void UpdatePropertyInformation();
  virtual void UpdatePropertyInformation(vtkSMProperty* prop)
    { this->Superclass::UpdatePropertyInformation(prop); }
protected:
  vtkSMCameraProxy();
  ~vtkSMCameraProxy();

private:
  vtkSMCameraProxy(const vtkSMCameraProxy&); // Not implemented.
  void operator=(const vtkSMCameraProxy&); // Not implemented.
};

#endif

