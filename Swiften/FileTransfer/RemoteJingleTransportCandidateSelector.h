/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

/*
 * Copyright (c) 2013-2015 Isode Limited.
 * All rights reserved.
 * See the COPYING file for more information.
 */

#pragma once

#include <queue>
#include <vector>

#include <boost/shared_ptr.hpp>

#include <Swiften/Base/Override.h>
#include <Swiften/JID/JID.h>
#include <Swiften/Network/Connection.h>
#include <Swiften/FileTransfer/SOCKS5BytestreamClientSession.h>
#include <Swiften/FileTransfer/RemoteJingleTransportCandidateSelector.h>
#include <Swiften/Elements/JingleS5BTransportPayload.h>
#include <Swiften/FileTransfer/FileTransferOptions.h>


namespace Swift {
	class ConnectionFactory;
	class TimerFactory;

	class RemoteJingleTransportCandidateSelector {
		public:
			RemoteJingleTransportCandidateSelector(ConnectionFactory*, TimerFactory*, const FileTransferOptions&);
			virtual ~RemoteJingleTransportCandidateSelector();

			virtual void addCandidates(const std::vector<JingleS5BTransportPayload::Candidate>&);
			virtual void setSOCKS5DstAddr(const std::string&);
			virtual void startSelectingCandidate();
			virtual void stopSelectingCandidate();

			boost::signal<void (const boost::optional<JingleS5BTransportPayload::Candidate>&, boost::shared_ptr<SOCKS5BytestreamClientSession>)> onCandidateSelectFinished;

		private:
			void tryNextCandidate();
			void handleSessionReady(bool error);

		private:
			ConnectionFactory* connectionFactory;
			TimerFactory* timerFactory;

			std::priority_queue<
				JingleS5BTransportPayload::Candidate, 
				std::vector<JingleS5BTransportPayload::Candidate>, 
				JingleS5BTransportPayload::CompareCandidate> candidates;
			boost::shared_ptr<SOCKS5BytestreamClientSession> s5bSession;
			boost::bsignals::connection sessionReadyConnection;
			JingleS5BTransportPayload::Candidate lastCandidate;
			std::string socks5DstAddr;
			FileTransferOptions options;
		};
}
