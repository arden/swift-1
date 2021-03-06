/*
 * Copyright (c) 2010-2014 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <boost/shared_ptr.hpp>

#include <map>
#include <vector>
#include <string>

#include <Swift/Controllers/Contact.h>
#include <Swiften/Base/boost_bsignals.h>
#include <Swiften/Elements/DiscoInfo.h>
#include <Swiften/Elements/DiscoItems.h>
#include <Swiften/Elements/ErrorPayload.h>
#include <Swiften/Elements/Presence.h>
#include <Swiften/Elements/SearchPayload.h>
#include <Swiften/Elements/VCard.h>
#include <Swiften/JID/JID.h>

namespace Swift {
	class UIEventStream;
	class UIEvent;
	class UserSearchWindow;
	class UserSearchWindowFactory;
	class IQRouter;
	class DiscoServiceWalker;
	class RosterController;
	class VCardManager;
	class ContactSuggester;
	class AvatarManager;
	class PresenceOracle;

	class UserSearchResult {
		public:
			UserSearchResult(const JID& jid, const std::map<std::string, std::string>& fields) : jid_(jid), fields_(fields) {}
			const JID& getJID() const {return jid_;}
			const std::map<std::string, std::string>& getFields() const {return fields_;}
		private:
			JID jid_;
			std::map<std::string, std::string> fields_;
	};

	class UserSearchController {
		public:
			enum Type {AddContact, StartChat, InviteToChat};
			UserSearchController(Type type, const JID& jid, UIEventStream* uiEventStream, VCardManager* vcardManager, UserSearchWindowFactory* userSearchWindowFactory, IQRouter* iqRouter, RosterController* rosterController, ContactSuggester* contactSuggester, AvatarManager* avatarManager, PresenceOracle* presenceOracle);
			~UserSearchController();

			UserSearchWindow* getUserSearchWindow();
			void setCanInitiateImpromptuMUC(bool supportsImpromptu);

		private:
			void handleUIEvent(boost::shared_ptr<UIEvent> event);
			void handleFormRequested(const JID& service);
			void handleDiscoServiceFound(const JID& jid, boost::shared_ptr<DiscoInfo> info);
			void handleDiscoWalkFinished();
			void handleFormResponse(boost::shared_ptr<SearchPayload> items, ErrorPayload::ref error);
			void handleSearch(boost::shared_ptr<SearchPayload> fields, const JID& jid);
			void handleSearchResponse(boost::shared_ptr<SearchPayload> results, ErrorPayload::ref error);
			void handleNameSuggestionRequest(const JID& jid);
			void handleContactSuggestionsRequested(std::string text);
			void handleVCardChanged(const JID& jid, VCard::ref vcard);
			void handleAvatarChanged(const JID& jid);
			void handlePresenceChanged(Presence::ref presence);
			void handleJIDUpdateRequested(const std::vector<JID>& jids);
			void handleJIDAddRequested(const std::vector<JID>& jids);
			void handleJIDEditingFinished(const JID& jid);
			Contact::ref convertJIDtoContact(const JID& jid);
			void endDiscoWalker();
			void initializeUserWindow();

		private:
			Type type_;
			JID jid_;
			JID suggestionsJID_;
			UIEventStream* uiEventStream_;
			VCardManager* vcardManager_;
			UserSearchWindowFactory* factory_;
			IQRouter* iqRouter_;
			RosterController* rosterController_;
			UserSearchWindow* window_;
			DiscoServiceWalker* discoWalker_;
			ContactSuggester* contactSuggester_;
			AvatarManager* avatarManager_;
			PresenceOracle* presenceOracle_;
	};
}
