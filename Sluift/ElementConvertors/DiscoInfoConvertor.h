/*
 * Copyright (c) 2013 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <Swiften/Base/Override.h>

#include <Sluift/GenericLuaElementConvertor.h>
#include <Swiften/Elements/DiscoInfo.h>

namespace Swift {
	class DiscoInfoConvertor : public GenericLuaElementConvertor<DiscoInfo> {
		public:
			DiscoInfoConvertor();
			virtual ~DiscoInfoConvertor();

			virtual boost::shared_ptr<DiscoInfo> doConvertFromLua(lua_State*) SWIFTEN_OVERRIDE;
			virtual void doConvertToLua(lua_State*, boost::shared_ptr<DiscoInfo>) SWIFTEN_OVERRIDE;
			virtual boost::optional<Documentation> getDocumentation() const SWIFTEN_OVERRIDE;
	};
}
