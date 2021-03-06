/*
Copyright (C) 2006 - 2015 Evan Teran
                          evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "ProcessProperties.h"
#include "DialogProcessProperties.h"
#include "edb.h"

#include <QMenu>

namespace ProcessPropertiesPlugin {

//------------------------------------------------------------------------------
// Name: ProcessProperties
// Desc:
//------------------------------------------------------------------------------
ProcessProperties::ProcessProperties(QObject *parent) : QObject(parent) {
	dialog_ = new DialogProcessProperties(edb::v1::debugger_ui);
}

//------------------------------------------------------------------------------
// Name: ~ProcessProperties
// Desc:
//------------------------------------------------------------------------------
ProcessProperties::~ProcessProperties() {
#if 0
	delete dialog_;
#endif
}

//------------------------------------------------------------------------------
// Name: menu
// Desc:
//------------------------------------------------------------------------------
QMenu *ProcessProperties::menu(QWidget *parent) {

	Q_ASSERT(parent);

	if(!menu_) {
		menu_ = new QMenu(tr("Process Properties"), parent);
		menu_->addAction(tr("&Process Properties"), this, SLOT(show_menu()), QKeySequence(tr("Ctrl+P")));
		menu_->addAction(tr("Process &Strings"), dialog_, SLOT(on_btnStrings_clicked()), QKeySequence(tr("Ctrl+S")));
	}

	return menu_;
}

//------------------------------------------------------------------------------
// Name: show_menu
// Desc:
//------------------------------------------------------------------------------
void ProcessProperties::show_menu() {
	dialog_->show();
}

}
