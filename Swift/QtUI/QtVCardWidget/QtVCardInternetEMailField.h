/*
 * Copyright (c) 2012 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#pragma once

#include <Swiften/Elements/VCard.h>

#include "QtResizableLineEdit.h"
#include "QtVCardFieldInfo.h"
#include "QtVCardGeneralField.h"
#include "QtVCardHomeWork.h"

namespace Swift {

class QtVCardInternetEMailField : public QtVCardGeneralField, public QtVCardHomeWork {
	Q_OBJECT

	public:
		GENERIC_QT_VCARD_FIELD_INFO("E-Mail", UNLIMITED_INSTANCES, QtVCardInternetEMailField)

		QtVCardInternetEMailField(QWidget* parent = 0, QGridLayout* layout = 0, bool editable = false);
		virtual ~QtVCardInternetEMailField();

		virtual bool isEmpty() const;

		void setInternetEMailAddress(const VCard::EMailAddress& address);
		VCard::EMailAddress getInternetEMailAddress() const;

	protected:
		virtual void setupContentWidgets();

	public slots:
		void handleEditibleChanged(bool isEditable);

	private:
		QtResizableLineEdit* emailLineEdit;
		QLabel* emailLabel;
};

}
