/*
 * Copyright (c) 2013 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Base/Override.h>
#include <Swiften/Base/API.h>
#include <Swiften/Elements/Payload.h>
#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

#include <Swiften/Elements/Form.h>
#include <Swiften/Elements/PubSubPayload.h>
#include <Swiften/JID/JID.h>

namespace Swift {
	class SWIFTEN_API PubSubOptions : public PubSubPayload {
		public:
			
			PubSubOptions();
			
			virtual ~PubSubOptions();

			const std::string& getNode() const {
				return node;
			}

			void setNode(const std::string& value) {
				this->node = value ;
			}

			const JID& getJID() const {
				return jid;
			}

			void setJID(const JID& value) {
				this->jid = value ;
			}

			boost::shared_ptr<Form> getData() const {
				return data;
			}

			void setData(boost::shared_ptr<Form> value) {
				this->data = value ;
			}

			const boost::optional< std::string >& getSubscriptionID() const {
				return subscriptionID;
			}

			void setSubscriptionID(const boost::optional< std::string >& value) {
				this->subscriptionID = value ;
			}


		private:
			std::string node;
			JID jid;
			boost::shared_ptr<Form> data;
			boost::optional< std::string > subscriptionID;
	};
}
