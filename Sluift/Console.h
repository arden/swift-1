/*
 * Copyright (c) 2013 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <string>
#include <boost/optional/optional_fwd.hpp>
#include <Sluift/Completer.h>
#include <Swiften/Base/Override.h>

struct lua_State;

namespace Swift {
	class Terminal;

	class Console : public Completer {
		public:
			Console(lua_State* L, Terminal* terminal);
			virtual ~Console();

			void run();

			static int call(lua_State* L, int numberOfArguments, bool keepResult);

		private:
			std::string getPrompt(bool firstLine) const;
			std::string getErrorMessage() const;
			bool readCommand();
			int tryLoadCommand(const std::string& command);

			virtual std::vector<std::string> getCompletions(const std::string&, int start, int end) SWIFTEN_OVERRIDE;

		private:
			lua_State* L;
			Terminal* terminal;
			int previousNumberOfReturnArguments;
	};
}
