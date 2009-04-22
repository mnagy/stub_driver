/* Authors: Martin Nagy <mnagy@redhat.com>
 *
 * Copyright (C) 2009  Red Hat
 * see file 'COPYING' for use and warranty information
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 only
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include <isc/util.h>

#include <dns/dynamic_db.h>
#include <dns/log.h>

const char *ldapdb_impname = "dynamic-stub";

static void
stub_log(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	isc_log_vwrite(dns_lctx, DNS_LOGCATEGORY_DATABASE, DNS_LOGMODULE_DYNDB,
		      ISC_LOG_ERROR, format, args);
	va_end(args);

}

isc_result_t
dynamic_driver_init(isc_mem_t *mctx, const char *name,
		    const char * const *argv,
		    dns_dyndb_arguments_t *dyndb_args)
{
	REQUIRE(mctx != NULL);
	REQUIRE(name != NULL);
	REQUIRE(argv != NULL);
	REQUIRE(dyndb_args != NULL);

	stub_log("registering dynamic stub driver for %s", name);

	stub_log("arguments passed in:");
	for (int i = 0; argv[i] != NULL; i++)
		stub_log("arg: %s", argv[i]);

	stub_log("pointer to mctx     %p", mctx);
	stub_log("pointer to view     %p", dns_dyndb_get_view(dyndb_args));
	stub_log("pointer to zonemgr  %p", dns_dyndb_get_zonemgr(dyndb_args));
	stub_log("pointer to task     %p", dns_dyndb_get_task(dyndb_args));
	stub_log("pointer to timermgr %p", dns_dyndb_get_timermgr(dyndb_args));

	return ISC_R_SUCCESS;
}

void
dynamic_driver_destroy(void)
{
	stub_log("destroying dynamic stub driver");
}
