/*
 * Copyright (c) 2010 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Parser/GenericPayloadParserFactory.h>
#include <Swiften/Parser/PayloadParsers/SecurityLabelParser.h>

namespace Swift {
	class SecurityLabelParserFactory : public GenericPayloadParserFactory<SecurityLabelParser> {
		public:
			SecurityLabelParserFactory() : GenericPayloadParserFactory<SecurityLabelParser>("securitylabel", "urn:xmpp:sec-label:0") {}
	};
}
