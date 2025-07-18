// SPDX-License-Identifier: BSD-2-Clause
// Copyright CM4all GmbH
// author: Joel Schumacher <joel.schumacher@ionos.com>

#include "CdnProxySend.hxx"
#include "net/AllocatedSocketAddress.hxx"
#include "net/ConnectSocket.hxx"
#include "net/UniqueSocketDescriptor.hxx"
#include "system/Error.hxx"
#include "util/SpanCast.hxx"

void
CdnProxySend(const char* address, const char *pillar, const char *account_id)
{
	AllocatedSocketAddress saddr;
	saddr.SetLocal(address);

	auto sock = CreateConnectDatagramSocket(saddr);
	std::string data;
	data.append(pillar);
	data.push_back('\0');
	data.append(account_id);
	const auto n = sock.Send(AsBytes(data));
	if (n < 0) {
		throw MakeErrno("Error sending to CDN proxy");
	}
}
