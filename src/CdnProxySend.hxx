// SPDX-License-Identifier: BSD-2-Clause
// Copyright CM4all GmbH
// author: Joel Schumacher <joel.schumacher@ionos.com>

#pragma once

class SocketAddress;

void
CdnProxySend(const char* address, const char *pillar, const char *account_id);