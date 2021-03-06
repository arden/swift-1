/*
 * Copyright (c) 2010 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Parser/GenericElementParser.h>
#include <Swiften/Elements/CompressFailure.h>

namespace Swift {
	class CompressFailureParser : public GenericElementParser<CompressFailure> {
		public:
			CompressFailureParser() : GenericElementParser<CompressFailure>() {}
	};
}
