/*
 * Copyright (c) 2010-2014 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

#include <Swiften/Base/API.h>
#include <Swiften/JID/JID.h>
#include <Swiften/Elements/Payload.h>
#include <Swiften/Elements/SecurityLabel.h>

namespace Swift {
	class SWIFTEN_API SecurityLabelsCatalog : public Payload {
		public:
			typedef boost::shared_ptr<SecurityLabelsCatalog> ref;
			class Item {
				public:
					Item() : default_(false) {}
					boost::shared_ptr<SecurityLabel> getLabel() const {
						return label_;
					}

					void setLabel(boost::shared_ptr<SecurityLabel> label) {
						label_ = label;
					}

					const std::string& getSelector() const { return selector_; }

					void setSelector(const std::string& selector) {
						selector_ = selector;
					}

					bool getIsDefault() const { return default_; }

					void setIsDefault(bool isDefault) {
						default_ = isDefault;
					}
				private:
					boost::shared_ptr<SecurityLabel> label_;
					std::string selector_;
					bool default_;
			};
			SecurityLabelsCatalog(const JID& to = JID()) : to_(to) {}

			const std::vector<Item>& getItems() const {
				return items_;
			}

			void addItem(const Item& item) {
				items_.push_back(item);
			}

			const JID& getTo() const {
				return to_;
			}

			void setTo(const JID& to) {
				to_ = to;
			}

			const std::string& getName() const {
				return name_;
			}

			void setName(const std::string& name) {
				name_ = name;
			}

			const std::string& getDescription() const {
				return description_;
			}

			void setDescription(const std::string& description) {
				description_ = description;
			}

		private:
			JID to_;
			std::string name_;
			std::string description_;
			std::vector<Item> items_;
	};
}
