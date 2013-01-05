////////////////////////////////////////////////////////////////////////////////
// (c) 2012 Rolf Meyerhoff. All rights reserved.
////////////////////////////////////////////////////////////////////////////////
///\file    setupdialog.h
///\ingroup dtedit
///\brief   Setup window class definition.
///\author  Rolf Meyerhoff (badlantic@gmail.com)
///\version 1.0
/// This file is part of the DT editor.
////////////////////////////////////////////////////////////////////////////////
///\par License:
/// This program is free software: you can redistribute it and/or modify it
/// under the terms of the GNU General Public License as published by the Free
/// Software Foundation, either version 2 of the License, or (at your option)
/// any later version.
///\par
/// This program is distributed in the hope that it will be useful, but WITHOUT
/// ANY WARRANTY; without even  the implied warranty of MERCHANTABILITY or
/// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
/// more details.
///\par
/// You should have received a copy of the GNU General Public License along with
/// this program; see the file COPYING. If not, see http://www.gnu.org/licenses/
/// or write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
/// Floor, Boston, MA 02110-1301, USA.
////////////////////////////////////////////////////////////////////////////////
#ifndef __SETUPDIALOG_H_INCLUDED__
#define __SETUPDIALOG_H_INCLUDED__

#include <QDialog>

////////////////////////////////////////////////////////////////////////////////
// Forwards:
namespace Ui { class SetupDialog; }

////////////////////////////////////////////////////////////////////////////////
///\class SetupDialog setupdialog.h
///\brief MIDI setup dialog class.
/// This is the configuration dialog of the application.
////////////////////////////////////////////////////////////////////////////////
class SetupDialog : public QDialog
{
  Q_OBJECT // Qt magic...

public:
  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::SetupDialog()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Initialization constructor of this window.
  ///\param   [in] parent: Parent window for this window.
  ///\remarks Basically initializes the entire gui.
  //////////////////////////////////////////////////////////////////////////////
  explicit SetupDialog(QWidget* parent = 0);

  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::~SetupDialog()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Destructor of this window.
  ///\remarks Does the cleanup.
  //////////////////////////////////////////////////////////////////////////////
  ~SetupDialog();

  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::setInputName()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Set accessor for the InputName property.
  ///\param   [in] name: The new name of the input.
  //////////////////////////////////////////////////////////////////////////////
  void setInputName(const QString& name);

  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::getInputName()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Get accessor for the InputName property.
  ///\return  The current name of the input.
  //////////////////////////////////////////////////////////////////////////////
  const QString& getInputName() const;

  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::setOutputName()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Set accessor for the OutputName property.
  ///\param   [in] name: The new name of the output.
  //////////////////////////////////////////////////////////////////////////////
  void setOutputName(const QString& name);

  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::getOutputName()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Get accessor for the OutputName property.
  ///\return  The current name of the output.
  //////////////////////////////////////////////////////////////////////////////
  const QString& getOutputName() const;

protected:
  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::showEvent()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Message handler for the window show event.
  ///\param   [in] e: Description of the event.
  //////////////////////////////////////////////////////////////////////////////
  void showEvent(QShowEvent* e);

private slots:
  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::on_inputComboBox_currentIndexChanged()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Handler for the input combo box selection changed signal.
  ///\remarks Updates the inputName member.
  //////////////////////////////////////////////////////////////////////////////
  void on_inputComboBox_currentIndexChanged(const QString& arg1);

  //////////////////////////////////////////////////////////////////////////////
  // SetupDialog::on_outputComboBox_currentIndexChanged()
  //////////////////////////////////////////////////////////////////////////////
  ///\brief   Handler for the output combo box selection changed signal.
  ///\remarks Updates the outputName member.
  //////////////////////////////////////////////////////////////////////////////
  void on_outputComboBox_currentIndexChanged(const QString& arg1);

private:
  //////////////////////////////////////////////////////////////////////////////
  // Member:
  Ui::SetupDialog* ui;         ///> Design class.
  QString          inputName;  ///> Name of the currently selected input.
  QString          outputName; ///> Name of the currently selected output.
  bool             blocked;    ///> UI udate blocking flag.
};

#endif // #ifndef __SETUPDIALOG_H_INCLUDED__
///////////////////////////////// End of File //////////////////////////////////
