/*
 * Copyright (c) 2010-2014 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

#include <Swiften/Base/API.h>
#include <string>
#include <Swiften/Elements/Stanza.h>
#include <Swiften/Parser/ElementParser.h>
#include <Swiften/Parser/AttributeMap.h>

namespace Swift {
	class PayloadParser;
	class PayloadParserFactoryCollection;

	class SWIFTEN_API StanzaParser : public ElementParser, public boost::noncopyable {
		public:
			StanzaParser(PayloadParserFactoryCollection* factories);
			~StanzaParser();

			void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes);
			void handleEndElement(const std::string& element, const std::string& ns);
			void handleCharacterData(const std::string& data);

			virtual boost::shared_ptr<ToplevelElement> getElement() const = 0;
			virtual void handleStanzaAttributes(const AttributeMap&) {}

			virtual boost::shared_ptr<Stanza> getStanza() const {
				return boost::dynamic_pointer_cast<Stanza>(getElement());
			}

		private:
			bool inPayload() const {
				return currentDepth_ > 1;
			}

			bool inStanza() const {
				return currentDepth_ > 0;
			}


		private:
			int currentDepth_;
			PayloadParserFactoryCollection* factories_;
			boost::shared_ptr<PayloadParser> currentPayloadParser_;
	};
}
