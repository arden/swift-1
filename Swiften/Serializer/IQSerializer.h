/*
 * Copyright (c) 2010-2014 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Serializer/GenericStanzaSerializer.h>
#include <Swiften/Elements/IQ.h>
#include <Swiften/Serializer/XML/XMLElement.h>

#include <boost/optional.hpp>

namespace Swift {
	class IQSerializer : public GenericStanzaSerializer<IQ> {
		public:
			IQSerializer(PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS = boost::optional<std::string>()) :
					GenericStanzaSerializer<IQ>("iq", payloadSerializers, explicitNS) {
			}

		private:
			virtual void setStanzaSpecificAttributesGeneric(
					boost::shared_ptr<IQ> iq, 
					XMLElement& element) const {
				switch (iq->getType()) {
					case IQ::Get: element.setAttribute("type","get"); break;
					case IQ::Set: element.setAttribute("type","set"); break;
					case IQ::Result: element.setAttribute("type","result"); break;
					case IQ::Error: element.setAttribute("type","error"); break;
				}
			}
	};
}
