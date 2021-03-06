/*=========================================================================

  Program:   ParaView
  Module:    vtkSMComparativeViewProxy.h

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkSMComparativeViewProxy - view for comparative visualization/
// film-strips.
// .SECTION Description
// vtkSMComparativeViewProxy is the view used to generate/view comparative
// visualizations/film-strips. vtkSMComparativeViewProxy works together with
// vtkPVComparativeView -- the vtk-object for which this represents the proxy.
// vtkPVComparativeView is a client-side VTK object which literally uses the
// view and representation proxies to simulate the comparative view. Refer to
// vtkPVComparativeView for details.
#ifndef vtkSMComparativeViewProxy_h
#define vtkSMComparativeViewProxy_h

#include "vtkPVServerManagerRenderingModule.h" //needed for exports
#include "vtkSMViewProxy.h"

class vtkCollection;

class VTKPVSERVERMANAGERRENDERING_EXPORT vtkSMComparativeViewProxy : public vtkSMViewProxy
{
public:
  static vtkSMComparativeViewProxy* New();
  vtkTypeMacro(vtkSMComparativeViewProxy, vtkSMViewProxy);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Updates the data pipelines for all visible representations.
  virtual void Update();

  // Description:
  // Get all the internal views. The views should only be used to be layed out
  // by the GUI. It's not recommended to directly change the properties of the
  // views.
  void GetViews(vtkCollection* collection);

  // Description:
  // Get all internal vtkSMRepresentations for a given view.  If the given
  // view is not managed by this comparative view it will be ignored.  The
  // representations should only be used by the GUI for creating representation
  // clones.  It is not recommended to directly change the properties of the returned
  // representations.
  void GetRepresentationsForView(vtkSMViewProxy*, vtkCollection*);
  void GetRepresentations(int x, int y, vtkCollection*);

  // Description:
  // Returns the root view proxy.
  vtkSMViewProxy* GetRootView();

  // Description:
  // Dirty means this algorithm will execute during next update.
  // This all marks all consumers as dirty.
  virtual void MarkDirty(vtkSMProxy* modifiedProxy);

  // Description:
  // Overridden to forward the call to the internal root view proxy.
  virtual const char* GetRepresentationType(
    vtkSMSourceProxy* producer, int outputPort);

  // Description:
  // Returns the render-window used by the root view, if any.
  virtual vtkRenderWindow* GetRenderWindow()
    { return this->GetRootView()? this->GetRootView()->GetRenderWindow() : NULL; }
  virtual vtkRenderWindowInteractor* GetInteractor()
    { return this->GetRootView()? this->GetRootView()->GetInteractor() : NULL; }

  // Description:
  // To avoid misuse of this method for comparative views, this method will
  // raise an error. Client code should set up interactor for each of the
  // internal views explicitly.
  virtual void SetupInteractor(vtkRenderWindowInteractor* iren);

  // Description:
  // Overridden to call MakeRenderWindowInteractor() on each of the internal
  // views.
  virtual bool MakeRenderWindowInteractor(bool quiet=false);

protected:
  vtkSMComparativeViewProxy();
  ~vtkSMComparativeViewProxy();


  void InvokeConfigureEvent();

  // Description:
  virtual void CreateVTKObjects();

private:
  vtkSMComparativeViewProxy(const vtkSMComparativeViewProxy&); // Not implemented
  void operator=(const vtkSMComparativeViewProxy&); // Not implemented
};

#endif
